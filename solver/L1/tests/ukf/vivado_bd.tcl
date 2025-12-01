set cur_dir [pwd]
set proj_name "ukf_bd"
set proj_dir "$cur_dir/vivado_bd"
set part "xc7z020-clg400-1"

file mkdir $proj_dir

create_project $proj_name $proj_dir -part $part -force

set ip_repo "$cur_dir/ukf.prj/sol1/impl/ip"
if {[file exists $ip_repo]} {
    set_property ip_repo_paths [list $ip_repo] [current_project]
    update_ip_catalog
}



create_bd_design "design_1"

set ps7 [create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 ps7]
apply_bd_automation -rule xilinx.com:bd_rule:processing_system7 -config {make_external "true" } $ps7
set_property -dict [list CONFIG.PCW_USE_M_AXI_GP0 {1} CONFIG.FCLK_CLK0_ENABLE {true} CONFIG.FCLK_CLK0_FREQ {100000000} CONFIG.PCW_USE_FABRIC_INTERRUPT {1}] $ps7

set axi_ic [create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_ic]
set_property -dict [list CONFIG.NUM_SI {1} CONFIG.NUM_MI {1}] $axi_ic

set ukf_cell {}
if {[llength [get_ipdefs xilinx.com:hls:ukf_accel_step:1.0]]} {
    set ukf_cell [create_bd_cell -type ip -vlnv xilinx.com:hls:ukf_accel_step:1.0 ukf0]
} else {
    puts "ERROR: ukf_accel_step HLS IP not found in repo $ip_repo"
    exit 1
}

connect_bd_intf_net [get_bd_intf_pins ps7/M_AXI_GP0] [get_bd_intf_pins axi_ic/S00_AXI]
connect_bd_intf_net [get_bd_intf_pins axi_ic/M00_AXI] [get_bd_intf_pins ukf0/s_axi_control]

set rst0 [create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset:5.0 rst0]
connect_bd_net [get_bd_pins rst0/slowest_sync_clk] [get_bd_pins ps7/FCLK_CLK0]

connect_bd_net [get_bd_pins rst0/ext_reset_in]       [get_bd_pins ps7/FCLK_RESET0_N]
connect_bd_net [get_bd_pins ps7/FCLK_CLK0] [get_bd_pins ps7/M_AXI_GP0_ACLK]

connect_bd_net [get_bd_pins ps7/FCLK_CLK0]           [get_bd_pins axi_ic/ACLK]
connect_bd_net [get_bd_pins ps7/FCLK_CLK0]           [get_bd_pins axi_ic/S00_ACLK]
connect_bd_net [get_bd_pins ps7/FCLK_CLK0]           [get_bd_pins axi_ic/M00_ACLK]
connect_bd_net [get_bd_pins rst0/interconnect_aresetn] [get_bd_pins axi_ic/ARESETN]
connect_bd_net [get_bd_pins rst0/peripheral_aresetn]   [get_bd_pins axi_ic/S00_ARESETN]
connect_bd_net [get_bd_pins rst0/peripheral_aresetn]   [get_bd_pins axi_ic/M00_ARESETN]

connect_bd_net [get_bd_pins ps7/FCLK_CLK0]           [get_bd_pins ukf0/ap_clk]
connect_bd_net [get_bd_pins rst0/peripheral_aresetn] [get_bd_pins ukf0/ap_rst_n]
if {[llength [get_bd_pins ps7/IRQ_F2P[0]]] > 0} {
    connect_bd_net [get_bd_pins ukf0/interrupt] [get_bd_pins ps7/IRQ_F2P[0]]
} else {
    puts "WARNING: PS7 F2P interrupt pin not available; skipping interrupt wiring."
}

assign_bd_address

validate_bd_design
save_bd_design

generate_target all [get_files "$proj_dir/$proj_name.srcs/sources_1/bd/design_1/design_1.bd"]
make_wrapper -files [get_files "$proj_dir/$proj_name.srcs/sources_1/bd/design_1/design_1.bd"] -top
add_files -norecurse "$proj_dir/$proj_name.gen/sources_1/bd/design_1/hdl/design_1_wrapper.v"
update_compile_order -fileset sources_1

launch_runs synth_1 -jobs 4
wait_on_run synth_1
launch_runs impl_1 -to_step write_bitstream -jobs 4
wait_on_run impl_1

# Robustly locate the generated bitstream in the run directory
set impl_dir [file join $proj_dir "$proj_name.runs" "impl_1"]
set bit_path [file join $impl_dir "design_1_wrapper.bit"]
if {[file exists $bit_path]} {
    file copy -force $bit_path [file join $proj_dir "design_1.bit"]
} else {
    puts "WARNING: Bitstream not found at $bit_path"
}

write_hw_platform -fixed -include_bit -force [file join $proj_dir "design_1.xsa"]

# Generate hardware definition (.hdf) then provide .hwh for PYNQ
write_hwdef -force -file [file join $proj_dir "design_1.hdf"]
if {[file exists [file join $proj_dir "design_1.hdf"]]} {
    file copy -force [file join $proj_dir "design_1.hdf"] [file join $proj_dir "design_1.hwh"]
}

exit