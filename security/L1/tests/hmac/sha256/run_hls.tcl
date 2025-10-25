# Copyright (C) 2019-2022, Xilinx, Inc.
# Copyright (C) 2022-2023, Advanced Micro Devices, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# vitis hls makefile-generator v2.0.0

set CSIM 1
set CSYNTH 1
set COSIM 1
set VIVADO_SYN 1
set VIVADO_IMPL 1
set CUR_DIR [pwd]
set XF_PROJ_ROOT $CUR_DIR/../../../..
set XPART xc7z020-clg484-1

set PROJ "hmac_sha256_test.prj"
set SOLN "solution1"

if {![info exists CLKP]} {
    set CLKP "10.1"
}

open_project -reset $PROJ

add_files "test.cpp" -cflags "-I${XF_PROJ_ROOT}/L1/include"
add_files -tb "test.cpp gld.dat" -cflags "-I${XF_PROJ_ROOT}/L1/include"
set_top test_hmac_sha256

open_solution -reset $SOLN



set_part $XPART
create_clock -period $CLKP
set_clock_uncertainty 10%

if {$CSIM == 1} {
  csim_design
}

if {$CSYNTH == 1} {
  csynth_design
}

if {$COSIM == 1} {
  cosim_design
}

# Summarize Estimated Clock and Cosim Latency to compute T_exec
set csynth_xml "$PROJ/$SOLN/syn/report/csynth.xml"
set cosim_rpt "$PROJ/$SOLN/sim/report/test_hmac_sha256_cosim.rpt"
set est_clk ""
set lat_min ""
set lat_avg ""
set lat_max ""
set total_cycles ""

if {[file exists $csynth_xml]} {
  set fp [open $csynth_xml r]
  set data [read $fp]
  close $fp
  if {[regexp -line {<EstimatedClockPeriod>([0-9.]+)</EstimatedClockPeriod>} $data -> est]} {
    set est_clk $est
  }
}

if {[file exists $cosim_rpt]} {
  set fp [open $cosim_rpt r]
  set rpt [read $fp]
  close $fp
  # Parse the Verilog row
  if {[regexp -line {\|\s*Verilog\|\s*Pass\|\s*([0-9]+)\|\s*([0-9]+)\|\s*([0-9]+)\|.*\|\s*([0-9]+)\|} $rpt -> lat_min lat_avg lat_max total_cycles]} {
    # ok
  }
}

set t_exec ""
if {![string equal $est_clk ""] && ![string equal $lat_max ""]} {
  set t_exec [format "%.3f" [expr {$est_clk * $lat_max}]]
}

# Write summary and copy reports
file mkdir reports
set summary_file "reports/summary_T_exec.txt"
set sfp [open $summary_file w]
puts $sfp "TargetClockPeriod = $CLKP ns"
puts $sfp "EstimatedClockPeriod = $est_clk ns"
puts $sfp "CosimLatency(max) = $lat_max cycles"
puts $sfp "T_exec = EstimatedClockPeriod × CosimLatency(max) = $t_exec ns"
close $sfp

# Also write summary under solution1/syn/report for submission
set sol_report_dir "$PROJ/$SOLN/syn/report"
file mkdir $sol_report_dir
set summary_file2 "$sol_report_dir/summary_T_exec.txt"
set sfp2 [open $summary_file2 w]
puts $sfp2 "TargetClockPeriod = $CLKP ns"
puts $sfp2 "EstimatedClockPeriod = $est_clk ns"
puts $sfp2 "CosimLatency(max) = $lat_max cycles"
puts $sfp2 "T_exec = EstimatedClockPeriod × CosimLatency(max) = $t_exec ns"
close $sfp2

# Copy canonical reports into reports/
if {[file exists $csynth_xml]} {
  file copy -force $csynth_xml reports/csynth.xml
}
if {[file exists $cosim_rpt]} {
  file copy -force $cosim_rpt reports/test_hmac_sha256_cosim.rpt
}
# Also dump CSim log if available
if {[file exists vitis_hls.log]} {
  file copy -force vitis_hls.log reports/test_hmac_sha256_csim.log
}

if {$VIVADO_SYN == 1} {
  export_design -flow syn -rtl verilog
}

if {$VIVADO_IMPL == 1} {
  export_design -flow impl -rtl verilog
}

exit