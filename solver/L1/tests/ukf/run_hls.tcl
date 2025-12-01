# Copyright (C) 2019-2023, Xilinx/AMD

set CSIM 1
set CSYNTH 1
set COSIM 1
set VIVADO_SYN 1
set VIVADO_IMPL 1
set CUR_DIR [pwd]
set SCRIPT_DIR [file dirname [info script]]
set XF_PROJ_ROOT $CUR_DIR/../../../..
set XPART xc7z020-clg484-1

set PROJ "$SCRIPT_DIR/ukf.prj"
set SOLN "sol1"

if {![info exists CLKP]} { 
    set CLKP 10.0
    }

open_project -reset $PROJ

add_files "${XF_PROJ_ROOT}/solver/L1/tests/ukf/ukf_accel.cpp" -cflags " -I./ -I${XF_PROJ_ROOT}/solver/L1/include/hw -std=c++14"
add_files -tb "${XF_PROJ_ROOT}/solver/L1/tests/ukf/ukf_tb.cpp" -cflags " -I./ -I${XF_PROJ_ROOT}/solver/L1/include/hw -std=c++14"

set_top ukf_accel_step

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
set cosim_rpt "$PROJ/$SOLN/sim/report/ukf_accel_cosim.rpt"
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
if {![string equal $est_clk ""] && ![string equal $total_cycles ""]} {
  set t_exec [format "%.3f" [expr {$est_clk * $total_cycles}]]
}

# Write summary and copy reports
file mkdir reports
set summary_file "reports/summary_T_exec.txt"
set sfp [open $summary_file w]
puts $sfp "TargetClockPeriod = $CLKP ns"
puts $sfp "EstimatedClockPeriod = $est_clk ns"
puts $sfp "TotalExecution(cycles) = $total_cycles cycles"
puts $sfp "T_exec = EstimatedClockPeriod × TotalExecution(cycles) = $t_exec ns"
close $sfp

# Also write summary under solution1/syn/report for submission
set sol_report_dir "$PROJ/$SOLN/syn/report"
file mkdir $sol_report_dir
set summary_file2 "$sol_report_dir/summary_T_exec.txt"
set sfp2 [open $summary_file2 w]
puts $sfp2 "TargetClockPeriod = $CLKP ns"
puts $sfp2 "EstimatedClockPeriod = $est_clk ns"
puts $sfp2 "TotalExecution(cycles) = $total_cycles cycles"
puts $sfp2 "T_exec = EstimatedClockPeriod × TotalExecution(cycles) = $t_exec ns"

close $sfp2


if {$VIVADO_SYN == 1} {
  export_design -flow syn -rtl verilog
}

if {$VIVADO_IMPL == 1} {
  export_design -flow impl -rtl verilog
}
exit
