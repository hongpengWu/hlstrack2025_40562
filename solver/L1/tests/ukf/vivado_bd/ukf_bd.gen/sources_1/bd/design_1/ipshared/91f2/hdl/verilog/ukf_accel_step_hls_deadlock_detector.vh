
    wire dl_reset;
    wire dl_clock;
    assign dl_reset = ap_rst_n;
    assign dl_clock = ap_clk;
    wire [3:0] proc_0_data_FIFO_blk;
    wire [3:0] proc_0_data_PIPO_blk;
    wire [3:0] proc_0_start_FIFO_blk;
    wire [3:0] proc_0_TLF_FIFO_blk;
    wire [3:0] proc_0_input_sync_blk;
    wire [3:0] proc_0_output_sync_blk;
    wire [3:0] proc_dep_vld_vec_0;
    reg [3:0] proc_dep_vld_vec_0_reg;
    wire [3:0] in_chan_dep_vld_vec_0;
    wire [23:0] in_chan_dep_data_vec_0;
    wire [3:0] token_in_vec_0;
    wire [3:0] out_chan_dep_vld_vec_0;
    wire [5:0] out_chan_dep_data_0;
    wire [3:0] token_out_vec_0;
    wire dl_detect_out_0;
    wire dep_chan_vld_1_0;
    wire [5:0] dep_chan_data_1_0;
    wire token_1_0;
    wire dep_chan_vld_2_0;
    wire [5:0] dep_chan_data_2_0;
    wire token_2_0;
    wire dep_chan_vld_3_0;
    wire [5:0] dep_chan_data_3_0;
    wire token_3_0;
    wire dep_chan_vld_5_0;
    wire [5:0] dep_chan_data_5_0;
    wire token_5_0;
    wire [1:0] proc_1_data_FIFO_blk;
    wire [1:0] proc_1_data_PIPO_blk;
    wire [1:0] proc_1_start_FIFO_blk;
    wire [1:0] proc_1_TLF_FIFO_blk;
    wire [1:0] proc_1_input_sync_blk;
    wire [1:0] proc_1_output_sync_blk;
    wire [1:0] proc_dep_vld_vec_1;
    reg [1:0] proc_dep_vld_vec_1_reg;
    wire [2:0] in_chan_dep_vld_vec_1;
    wire [17:0] in_chan_dep_data_vec_1;
    wire [2:0] token_in_vec_1;
    wire [1:0] out_chan_dep_vld_vec_1;
    wire [5:0] out_chan_dep_data_1;
    wire [1:0] token_out_vec_1;
    wire dl_detect_out_1;
    wire dep_chan_vld_0_1;
    wire [5:0] dep_chan_data_0_1;
    wire token_0_1;
    wire dep_chan_vld_2_1;
    wire [5:0] dep_chan_data_2_1;
    wire token_2_1;
    wire dep_chan_vld_5_1;
    wire [5:0] dep_chan_data_5_1;
    wire token_5_1;
    wire [2:0] proc_2_data_FIFO_blk;
    wire [2:0] proc_2_data_PIPO_blk;
    wire [2:0] proc_2_start_FIFO_blk;
    wire [2:0] proc_2_TLF_FIFO_blk;
    wire [2:0] proc_2_input_sync_blk;
    wire [2:0] proc_2_output_sync_blk;
    wire [2:0] proc_dep_vld_vec_2;
    reg [2:0] proc_dep_vld_vec_2_reg;
    wire [3:0] in_chan_dep_vld_vec_2;
    wire [23:0] in_chan_dep_data_vec_2;
    wire [3:0] token_in_vec_2;
    wire [2:0] out_chan_dep_vld_vec_2;
    wire [5:0] out_chan_dep_data_2;
    wire [2:0] token_out_vec_2;
    wire dl_detect_out_2;
    wire dep_chan_vld_0_2;
    wire [5:0] dep_chan_data_0_2;
    wire token_0_2;
    wire dep_chan_vld_3_2;
    wire [5:0] dep_chan_data_3_2;
    wire token_3_2;
    wire dep_chan_vld_4_2;
    wire [5:0] dep_chan_data_4_2;
    wire token_4_2;
    wire dep_chan_vld_5_2;
    wire [5:0] dep_chan_data_5_2;
    wire token_5_2;
    wire [2:0] proc_3_data_FIFO_blk;
    wire [2:0] proc_3_data_PIPO_blk;
    wire [2:0] proc_3_start_FIFO_blk;
    wire [2:0] proc_3_TLF_FIFO_blk;
    wire [2:0] proc_3_input_sync_blk;
    wire [2:0] proc_3_output_sync_blk;
    wire [2:0] proc_dep_vld_vec_3;
    reg [2:0] proc_dep_vld_vec_3_reg;
    wire [2:0] in_chan_dep_vld_vec_3;
    wire [17:0] in_chan_dep_data_vec_3;
    wire [2:0] token_in_vec_3;
    wire [2:0] out_chan_dep_vld_vec_3;
    wire [5:0] out_chan_dep_data_3;
    wire [2:0] token_out_vec_3;
    wire dl_detect_out_3;
    wire dep_chan_vld_0_3;
    wire [5:0] dep_chan_data_0_3;
    wire token_0_3;
    wire dep_chan_vld_4_3;
    wire [5:0] dep_chan_data_4_3;
    wire token_4_3;
    wire dep_chan_vld_5_3;
    wire [5:0] dep_chan_data_5_3;
    wire token_5_3;
    wire [2:0] proc_4_data_FIFO_blk;
    wire [2:0] proc_4_data_PIPO_blk;
    wire [2:0] proc_4_start_FIFO_blk;
    wire [2:0] proc_4_TLF_FIFO_blk;
    wire [2:0] proc_4_input_sync_blk;
    wire [2:0] proc_4_output_sync_blk;
    wire [2:0] proc_dep_vld_vec_4;
    reg [2:0] proc_dep_vld_vec_4_reg;
    wire [0:0] in_chan_dep_vld_vec_4;
    wire [5:0] in_chan_dep_data_vec_4;
    wire [0:0] token_in_vec_4;
    wire [2:0] out_chan_dep_vld_vec_4;
    wire [5:0] out_chan_dep_data_4;
    wire [2:0] token_out_vec_4;
    wire dl_detect_out_4;
    wire dep_chan_vld_5_4;
    wire [5:0] dep_chan_data_5_4;
    wire token_5_4;
    wire [4:0] proc_5_data_FIFO_blk;
    wire [4:0] proc_5_data_PIPO_blk;
    wire [4:0] proc_5_start_FIFO_blk;
    wire [4:0] proc_5_TLF_FIFO_blk;
    wire [4:0] proc_5_input_sync_blk;
    wire [4:0] proc_5_output_sync_blk;
    wire [4:0] proc_dep_vld_vec_5;
    reg [4:0] proc_dep_vld_vec_5_reg;
    wire [4:0] in_chan_dep_vld_vec_5;
    wire [29:0] in_chan_dep_data_vec_5;
    wire [4:0] token_in_vec_5;
    wire [4:0] out_chan_dep_vld_vec_5;
    wire [5:0] out_chan_dep_data_5;
    wire [4:0] token_out_vec_5;
    wire dl_detect_out_5;
    wire dep_chan_vld_0_5;
    wire [5:0] dep_chan_data_0_5;
    wire token_0_5;
    wire dep_chan_vld_1_5;
    wire [5:0] dep_chan_data_1_5;
    wire token_1_5;
    wire dep_chan_vld_2_5;
    wire [5:0] dep_chan_data_2_5;
    wire token_2_5;
    wire dep_chan_vld_3_5;
    wire [5:0] dep_chan_data_3_5;
    wire token_3_5;
    wire dep_chan_vld_4_5;
    wire [5:0] dep_chan_data_4_5;
    wire token_4_5;
    wire [5:0] dl_in_vec;
    wire dl_detect_out;
    wire token_clear;
    reg [5:0] origin;

    reg ap_done_reg_0;// for module grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            ap_done_reg_0 <= 'b0;
        end
        else begin
            ap_done_reg_0 <= grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_done & ~grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_continue;
        end
    end

    reg ap_done_reg_1;// for module grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            ap_done_reg_1 <= 'b0;
        end
        else begin
            ap_done_reg_1 <= grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_done & ~grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_continue;
        end
    end

    reg ap_done_reg_2;// for module grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            ap_done_reg_2 <= 'b0;
        end
        else begin
            ap_done_reg_2 <= grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_done & ~grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_continue;
        end
    end

    reg ap_done_reg_3;// for module grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            ap_done_reg_3 <= 'b0;
        end
        else begin
            ap_done_reg_3 <= grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_done & ~grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_continue;
        end
    end

    // Process: grp_ukf_step_3_2_s_fu_124.entry_proc_U0
    ukf_accel_step_hls_deadlock_detect_unit #(6, 0, 4, 4) ukf_accel_step_hls_deadlock_detect_unit_0 (
        .reset(dl_reset),
        .clock(dl_clock),
        .proc_dep_vld_vec(proc_dep_vld_vec_0),
        .in_chan_dep_vld_vec(in_chan_dep_vld_vec_0),
        .in_chan_dep_data_vec(in_chan_dep_data_vec_0),
        .token_in_vec(token_in_vec_0),
        .dl_detect_in(dl_detect_out),
        .origin(origin[0]),
        .token_clear(token_clear),
        .out_chan_dep_vld_vec(out_chan_dep_vld_vec_0),
        .out_chan_dep_data(out_chan_dep_data_0),
        .token_out_vec(token_out_vec_0),
        .dl_detect_out(dl_in_vec[0]));

    assign proc_0_data_FIFO_blk[0] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.entry_proc_U0.q_c_blk_n);
    assign proc_0_data_PIPO_blk[0] = 1'b0;
    assign proc_0_start_FIFO_blk[0] = 1'b0;
    assign proc_0_TLF_FIFO_blk[0] = 1'b0;
    assign proc_0_input_sync_blk[0] = 1'b0;
    assign proc_0_output_sync_blk[0] = 1'b0;
    assign proc_dep_vld_vec_0[0] = dl_detect_out ? proc_dep_vld_vec_0_reg[0] : (proc_0_data_FIFO_blk[0] | proc_0_data_PIPO_blk[0] | proc_0_start_FIFO_blk[0] | proc_0_TLF_FIFO_blk[0] | proc_0_input_sync_blk[0] | proc_0_output_sync_blk[0]);
    assign proc_0_data_FIFO_blk[1] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.entry_proc_U0.r_c_blk_n);
    assign proc_0_data_PIPO_blk[1] = 1'b0;
    assign proc_0_start_FIFO_blk[1] = 1'b0;
    assign proc_0_TLF_FIFO_blk[1] = 1'b0;
    assign proc_0_input_sync_blk[1] = 1'b0;
    assign proc_0_output_sync_blk[1] = 1'b0;
    assign proc_dep_vld_vec_0[1] = dl_detect_out ? proc_dep_vld_vec_0_reg[1] : (proc_0_data_FIFO_blk[1] | proc_0_data_PIPO_blk[1] | proc_0_start_FIFO_blk[1] | proc_0_TLF_FIFO_blk[1] | proc_0_input_sync_blk[1] | proc_0_output_sync_blk[1]);
    assign proc_0_data_FIFO_blk[2] = 1'b0;
    assign proc_0_data_PIPO_blk[2] = 1'b0;
    assign proc_0_start_FIFO_blk[2] = 1'b0;
    assign proc_0_TLF_FIFO_blk[2] = 1'b0;
    assign proc_0_input_sync_blk[2] = 1'b0 | (grp_ukf_step_3_2_s_fu_124.ap_sync_entry_proc_U0_ap_ready & grp_ukf_step_3_2_s_fu_124.entry_proc_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.ap_sync_make_sigma_points_3_U0_ap_ready);
    assign proc_0_output_sync_blk[2] = 1'b0;
    assign proc_dep_vld_vec_0[2] = dl_detect_out ? proc_dep_vld_vec_0_reg[2] : (proc_0_data_FIFO_blk[2] | proc_0_data_PIPO_blk[2] | proc_0_start_FIFO_blk[2] | proc_0_TLF_FIFO_blk[2] | proc_0_input_sync_blk[2] | proc_0_output_sync_blk[2]);
    assign proc_0_data_FIFO_blk[3] = 1'b0;
    assign proc_0_data_PIPO_blk[3] = 1'b0;
    assign proc_0_start_FIFO_blk[3] = 1'b0;
    assign proc_0_TLF_FIFO_blk[3] = 1'b0;
    assign proc_0_input_sync_blk[3] = 1'b0 | (grp_ukf_step_3_2_s_fu_124.ap_sync_entry_proc_U0_ap_ready & grp_ukf_step_3_2_s_fu_124.entry_proc_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.ap_sync_ukf_update_3_2_2_U0_ap_ready);
    assign proc_0_output_sync_blk[3] = 1'b0;
    assign proc_dep_vld_vec_0[3] = dl_detect_out ? proc_dep_vld_vec_0_reg[3] : (proc_0_data_FIFO_blk[3] | proc_0_data_PIPO_blk[3] | proc_0_start_FIFO_blk[3] | proc_0_TLF_FIFO_blk[3] | proc_0_input_sync_blk[3] | proc_0_output_sync_blk[3]);
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            proc_dep_vld_vec_0_reg <= 'b0;
        end
        else begin
            proc_dep_vld_vec_0_reg <= proc_dep_vld_vec_0;
        end
    end
    assign in_chan_dep_vld_vec_0[0] = dep_chan_vld_1_0;
    assign in_chan_dep_data_vec_0[5 : 0] = dep_chan_data_1_0;
    assign token_in_vec_0[0] = token_1_0;
    assign in_chan_dep_vld_vec_0[1] = dep_chan_vld_2_0;
    assign in_chan_dep_data_vec_0[11 : 6] = dep_chan_data_2_0;
    assign token_in_vec_0[1] = token_2_0;
    assign in_chan_dep_vld_vec_0[2] = dep_chan_vld_3_0;
    assign in_chan_dep_data_vec_0[17 : 12] = dep_chan_data_3_0;
    assign token_in_vec_0[2] = token_3_0;
    assign in_chan_dep_vld_vec_0[3] = dep_chan_vld_5_0;
    assign in_chan_dep_data_vec_0[23 : 18] = dep_chan_data_5_0;
    assign token_in_vec_0[3] = token_5_0;
    assign dep_chan_vld_0_2 = out_chan_dep_vld_vec_0[0];
    assign dep_chan_data_0_2 = out_chan_dep_data_0;
    assign token_0_2 = token_out_vec_0[0];
    assign dep_chan_vld_0_3 = out_chan_dep_vld_vec_0[1];
    assign dep_chan_data_0_3 = out_chan_dep_data_0;
    assign token_0_3 = token_out_vec_0[1];
    assign dep_chan_vld_0_1 = out_chan_dep_vld_vec_0[2];
    assign dep_chan_data_0_1 = out_chan_dep_data_0;
    assign token_0_1 = token_out_vec_0[2];
    assign dep_chan_vld_0_5 = out_chan_dep_vld_vec_0[3];
    assign dep_chan_data_0_5 = out_chan_dep_data_0;
    assign token_0_5 = token_out_vec_0[3];

    // Process: grp_ukf_step_3_2_s_fu_124.make_sigma_points_3_U0
    ukf_accel_step_hls_deadlock_detect_unit #(6, 1, 3, 2) ukf_accel_step_hls_deadlock_detect_unit_1 (
        .reset(dl_reset),
        .clock(dl_clock),
        .proc_dep_vld_vec(proc_dep_vld_vec_1),
        .in_chan_dep_vld_vec(in_chan_dep_vld_vec_1),
        .in_chan_dep_data_vec(in_chan_dep_data_vec_1),
        .token_in_vec(token_in_vec_1),
        .dl_detect_in(dl_detect_out),
        .origin(origin[1]),
        .token_clear(token_clear),
        .out_chan_dep_vld_vec(out_chan_dep_vld_vec_1),
        .out_chan_dep_data(out_chan_dep_data_1),
        .token_out_vec(token_out_vec_1),
        .dl_detect_out(dl_in_vec[1]));

    assign proc_1_data_FIFO_blk[0] = 1'b0;
    assign proc_1_data_PIPO_blk[0] = 1'b0;
    assign proc_1_start_FIFO_blk[0] = 1'b0;
    assign proc_1_TLF_FIFO_blk[0] = 1'b0;
    assign proc_1_input_sync_blk[0] = 1'b0 | (grp_ukf_step_3_2_s_fu_124.ap_sync_make_sigma_points_3_U0_ap_ready & grp_ukf_step_3_2_s_fu_124.make_sigma_points_3_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.ap_sync_entry_proc_U0_ap_ready);
    assign proc_1_output_sync_blk[0] = 1'b0;
    assign proc_dep_vld_vec_1[0] = dl_detect_out ? proc_dep_vld_vec_1_reg[0] : (proc_1_data_FIFO_blk[0] | proc_1_data_PIPO_blk[0] | proc_1_start_FIFO_blk[0] | proc_1_TLF_FIFO_blk[0] | proc_1_input_sync_blk[0] | proc_1_output_sync_blk[0]);
    assign proc_1_data_FIFO_blk[1] = 1'b0;
    assign proc_1_data_PIPO_blk[1] = 1'b0;
    assign proc_1_start_FIFO_blk[1] = 1'b0;
    assign proc_1_TLF_FIFO_blk[1] = 1'b0;
    assign proc_1_input_sync_blk[1] = 1'b0 | (grp_ukf_step_3_2_s_fu_124.ap_sync_make_sigma_points_3_U0_ap_ready & grp_ukf_step_3_2_s_fu_124.make_sigma_points_3_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.ap_sync_ukf_update_3_2_2_U0_ap_ready);
    assign proc_1_output_sync_blk[1] = 1'b0;
    assign proc_dep_vld_vec_1[1] = dl_detect_out ? proc_dep_vld_vec_1_reg[1] : (proc_1_data_FIFO_blk[1] | proc_1_data_PIPO_blk[1] | proc_1_start_FIFO_blk[1] | proc_1_TLF_FIFO_blk[1] | proc_1_input_sync_blk[1] | proc_1_output_sync_blk[1]);
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            proc_dep_vld_vec_1_reg <= 'b0;
        end
        else begin
            proc_dep_vld_vec_1_reg <= proc_dep_vld_vec_1;
        end
    end
    assign in_chan_dep_vld_vec_1[0] = dep_chan_vld_0_1;
    assign in_chan_dep_data_vec_1[5 : 0] = dep_chan_data_0_1;
    assign token_in_vec_1[0] = token_0_1;
    assign in_chan_dep_vld_vec_1[1] = dep_chan_vld_2_1;
    assign in_chan_dep_data_vec_1[11 : 6] = dep_chan_data_2_1;
    assign token_in_vec_1[1] = token_2_1;
    assign in_chan_dep_vld_vec_1[2] = dep_chan_vld_5_1;
    assign in_chan_dep_data_vec_1[17 : 12] = dep_chan_data_5_1;
    assign token_in_vec_1[2] = token_5_1;
    assign dep_chan_vld_1_0 = out_chan_dep_vld_vec_1[0];
    assign dep_chan_data_1_0 = out_chan_dep_data_1;
    assign token_1_0 = token_out_vec_1[0];
    assign dep_chan_vld_1_5 = out_chan_dep_vld_vec_1[1];
    assign dep_chan_data_1_5 = out_chan_dep_data_1;
    assign token_1_5 = token_out_vec_1[1];

    // Process: grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0
    ukf_accel_step_hls_deadlock_detect_unit #(6, 2, 4, 3) ukf_accel_step_hls_deadlock_detect_unit_2 (
        .reset(dl_reset),
        .clock(dl_clock),
        .proc_dep_vld_vec(proc_dep_vld_vec_2),
        .in_chan_dep_vld_vec(in_chan_dep_vld_vec_2),
        .in_chan_dep_data_vec(in_chan_dep_data_vec_2),
        .token_in_vec(token_in_vec_2),
        .dl_detect_in(dl_detect_out),
        .origin(origin[2]),
        .token_clear(token_clear),
        .out_chan_dep_vld_vec(out_chan_dep_vld_vec_2),
        .out_chan_dep_data(out_chan_dep_data_2),
        .token_out_vec(token_out_vec_2),
        .dl_detect_out(dl_in_vec[2]));

    assign proc_2_data_FIFO_blk[0] = 1'b0;
    assign proc_2_data_PIPO_blk[0] = 1'b0;
    assign proc_2_start_FIFO_blk[0] = 1'b0;
    assign proc_2_TLF_FIFO_blk[0] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.X_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_1_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_1_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_2_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_2_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_3_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_3_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_4_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_4_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_5_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_5_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_6_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_6_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_7_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_7_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_8_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_8_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_9_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_9_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_10_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_10_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_11_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_11_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_12_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_12_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_13_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_13_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_14_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_14_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_15_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_15_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_16_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_16_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_17_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_17_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_18_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_18_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_19_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_19_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X_20_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X_20_U.if_write);
    assign proc_2_input_sync_blk[0] = 1'b0;
    assign proc_2_output_sync_blk[0] = 1'b0;
    assign proc_dep_vld_vec_2[0] = dl_detect_out ? proc_dep_vld_vec_2_reg[0] : (proc_2_data_FIFO_blk[0] | proc_2_data_PIPO_blk[0] | proc_2_start_FIFO_blk[0] | proc_2_TLF_FIFO_blk[0] | proc_2_input_sync_blk[0] | proc_2_output_sync_blk[0]);
    assign proc_2_data_FIFO_blk[1] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.q_blk_n);
    assign proc_2_data_PIPO_blk[1] = 1'b0;
    assign proc_2_start_FIFO_blk[1] = 1'b0;
    assign proc_2_TLF_FIFO_blk[1] = 1'b0;
    assign proc_2_input_sync_blk[1] = 1'b0;
    assign proc_2_output_sync_blk[1] = 1'b0;
    assign proc_dep_vld_vec_2[1] = dl_detect_out ? proc_dep_vld_vec_2_reg[1] : (proc_2_data_FIFO_blk[1] | proc_2_data_PIPO_blk[1] | proc_2_start_FIFO_blk[1] | proc_2_TLF_FIFO_blk[1] | proc_2_input_sync_blk[1] | proc_2_output_sync_blk[1]);
    assign proc_2_data_FIFO_blk[2] = 1'b0;
    assign proc_2_data_PIPO_blk[2] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.x1_U.i_full_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_done & ap_done_reg_0 & ~grp_ukf_step_3_2_s_fu_124.x1_U.t_read) | (~grp_ukf_step_3_2_s_fu_124.S1_U.i_full_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_process_3_2_U0.ap_done & ap_done_reg_0 & ~grp_ukf_step_3_2_s_fu_124.S1_U.t_read);
    assign proc_2_start_FIFO_blk[2] = 1'b0;
    assign proc_2_TLF_FIFO_blk[2] = 1'b0;
    assign proc_2_input_sync_blk[2] = 1'b0;
    assign proc_2_output_sync_blk[2] = 1'b0;
    assign proc_dep_vld_vec_2[2] = dl_detect_out ? proc_dep_vld_vec_2_reg[2] : (proc_2_data_FIFO_blk[2] | proc_2_data_PIPO_blk[2] | proc_2_start_FIFO_blk[2] | proc_2_TLF_FIFO_blk[2] | proc_2_input_sync_blk[2] | proc_2_output_sync_blk[2]);
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            proc_dep_vld_vec_2_reg <= 'b0;
        end
        else begin
            proc_dep_vld_vec_2_reg <= proc_dep_vld_vec_2;
        end
    end
    assign in_chan_dep_vld_vec_2[0] = dep_chan_vld_0_2;
    assign in_chan_dep_data_vec_2[5 : 0] = dep_chan_data_0_2;
    assign token_in_vec_2[0] = token_0_2;
    assign in_chan_dep_vld_vec_2[1] = dep_chan_vld_3_2;
    assign in_chan_dep_data_vec_2[11 : 6] = dep_chan_data_3_2;
    assign token_in_vec_2[1] = token_3_2;
    assign in_chan_dep_vld_vec_2[2] = dep_chan_vld_4_2;
    assign in_chan_dep_data_vec_2[17 : 12] = dep_chan_data_4_2;
    assign token_in_vec_2[2] = token_4_2;
    assign in_chan_dep_vld_vec_2[3] = dep_chan_vld_5_2;
    assign in_chan_dep_data_vec_2[23 : 18] = dep_chan_data_5_2;
    assign token_in_vec_2[3] = token_5_2;
    assign dep_chan_vld_2_1 = out_chan_dep_vld_vec_2[0];
    assign dep_chan_data_2_1 = out_chan_dep_data_2;
    assign token_2_1 = token_out_vec_2[0];
    assign dep_chan_vld_2_0 = out_chan_dep_vld_vec_2[1];
    assign dep_chan_data_2_0 = out_chan_dep_data_2;
    assign token_2_0 = token_out_vec_2[1];
    assign dep_chan_vld_2_5 = out_chan_dep_vld_vec_2[2];
    assign dep_chan_data_2_5 = out_chan_dep_data_2;
    assign token_2_5 = token_out_vec_2[2];

    // Process: grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0
    ukf_accel_step_hls_deadlock_detect_unit #(6, 3, 3, 3) ukf_accel_step_hls_deadlock_detect_unit_3 (
        .reset(dl_reset),
        .clock(dl_clock),
        .proc_dep_vld_vec(proc_dep_vld_vec_3),
        .in_chan_dep_vld_vec(in_chan_dep_vld_vec_3),
        .in_chan_dep_data_vec(in_chan_dep_data_vec_3),
        .token_in_vec(token_in_vec_3),
        .dl_detect_in(dl_detect_out),
        .origin(origin[3]),
        .token_clear(token_clear),
        .out_chan_dep_vld_vec(out_chan_dep_vld_vec_3),
        .out_chan_dep_data(out_chan_dep_data_3),
        .token_out_vec(token_out_vec_3),
        .dl_detect_out(dl_in_vec[3]));

    assign proc_3_data_FIFO_blk[0] = 1'b0;
    assign proc_3_data_PIPO_blk[0] = 1'b0;
    assign proc_3_start_FIFO_blk[0] = 1'b0;
    assign proc_3_TLF_FIFO_blk[0] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.X1p_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_1_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_1_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_2_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_2_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_3_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_3_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_4_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_4_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_5_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_5_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_6_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_6_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_7_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_7_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_8_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_8_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_9_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_9_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_10_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_10_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_11_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_11_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_12_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_12_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X1p_13_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X1p_13_U.if_write);
    assign proc_3_input_sync_blk[0] = 1'b0;
    assign proc_3_output_sync_blk[0] = 1'b0;
    assign proc_dep_vld_vec_3[0] = dl_detect_out ? proc_dep_vld_vec_3_reg[0] : (proc_3_data_FIFO_blk[0] | proc_3_data_PIPO_blk[0] | proc_3_start_FIFO_blk[0] | proc_3_TLF_FIFO_blk[0] | proc_3_input_sync_blk[0] | proc_3_output_sync_blk[0]);
    assign proc_3_data_FIFO_blk[1] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.r_blk_n);
    assign proc_3_data_PIPO_blk[1] = 1'b0;
    assign proc_3_start_FIFO_blk[1] = 1'b0;
    assign proc_3_TLF_FIFO_blk[1] = 1'b0;
    assign proc_3_input_sync_blk[1] = 1'b0;
    assign proc_3_output_sync_blk[1] = 1'b0;
    assign proc_dep_vld_vec_3[1] = dl_detect_out ? proc_dep_vld_vec_3_reg[1] : (proc_3_data_FIFO_blk[1] | proc_3_data_PIPO_blk[1] | proc_3_start_FIFO_blk[1] | proc_3_TLF_FIFO_blk[1] | proc_3_input_sync_blk[1] | proc_3_output_sync_blk[1]);
    assign proc_3_data_FIFO_blk[2] = 1'b0;
    assign proc_3_data_PIPO_blk[2] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.z1_U.i_full_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_done & ap_done_reg_1 & ~grp_ukf_step_3_2_s_fu_124.z1_U.t_read) | (~grp_ukf_step_3_2_s_fu_124.S2_U.i_full_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_done & ap_done_reg_1 & ~grp_ukf_step_3_2_s_fu_124.S2_U.t_read) | (~grp_ukf_step_3_2_s_fu_124.S2_1_U.i_full_n & grp_ukf_step_3_2_s_fu_124.ukf_ut_meas_3_2_U0.ap_done & ap_done_reg_1 & ~grp_ukf_step_3_2_s_fu_124.S2_1_U.t_read);
    assign proc_3_start_FIFO_blk[2] = 1'b0;
    assign proc_3_TLF_FIFO_blk[2] = 1'b0;
    assign proc_3_input_sync_blk[2] = 1'b0;
    assign proc_3_output_sync_blk[2] = 1'b0;
    assign proc_dep_vld_vec_3[2] = dl_detect_out ? proc_dep_vld_vec_3_reg[2] : (proc_3_data_FIFO_blk[2] | proc_3_data_PIPO_blk[2] | proc_3_start_FIFO_blk[2] | proc_3_TLF_FIFO_blk[2] | proc_3_input_sync_blk[2] | proc_3_output_sync_blk[2]);
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            proc_dep_vld_vec_3_reg <= 'b0;
        end
        else begin
            proc_dep_vld_vec_3_reg <= proc_dep_vld_vec_3;
        end
    end
    assign in_chan_dep_vld_vec_3[0] = dep_chan_vld_0_3;
    assign in_chan_dep_data_vec_3[5 : 0] = dep_chan_data_0_3;
    assign token_in_vec_3[0] = token_0_3;
    assign in_chan_dep_vld_vec_3[1] = dep_chan_vld_4_3;
    assign in_chan_dep_data_vec_3[11 : 6] = dep_chan_data_4_3;
    assign token_in_vec_3[1] = token_4_3;
    assign in_chan_dep_vld_vec_3[2] = dep_chan_vld_5_3;
    assign in_chan_dep_data_vec_3[17 : 12] = dep_chan_data_5_3;
    assign token_in_vec_3[2] = token_5_3;
    assign dep_chan_vld_3_2 = out_chan_dep_vld_vec_3[0];
    assign dep_chan_data_3_2 = out_chan_dep_data_3;
    assign token_3_2 = token_out_vec_3[0];
    assign dep_chan_vld_3_0 = out_chan_dep_vld_vec_3[1];
    assign dep_chan_data_3_0 = out_chan_dep_data_3;
    assign token_3_0 = token_out_vec_3[1];
    assign dep_chan_vld_3_5 = out_chan_dep_vld_vec_3[2];
    assign dep_chan_data_3_5 = out_chan_dep_data_3;
    assign token_3_5 = token_out_vec_3[2];

    // Process: grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0
    ukf_accel_step_hls_deadlock_detect_unit #(6, 4, 1, 3) ukf_accel_step_hls_deadlock_detect_unit_4 (
        .reset(dl_reset),
        .clock(dl_clock),
        .proc_dep_vld_vec(proc_dep_vld_vec_4),
        .in_chan_dep_vld_vec(in_chan_dep_vld_vec_4),
        .in_chan_dep_data_vec(in_chan_dep_data_vec_4),
        .token_in_vec(token_in_vec_4),
        .dl_detect_in(dl_detect_out),
        .origin(origin[4]),
        .token_clear(token_clear),
        .out_chan_dep_vld_vec(out_chan_dep_vld_vec_4),
        .out_chan_dep_data(out_chan_dep_data_4),
        .token_out_vec(token_out_vec_4),
        .dl_detect_out(dl_in_vec[4]));

    assign proc_4_data_FIFO_blk[0] = 1'b0;
    assign proc_4_data_PIPO_blk[0] = 1'b0;
    assign proc_4_start_FIFO_blk[0] = 1'b0;
    assign proc_4_TLF_FIFO_blk[0] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.X2_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_21_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_21_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_22_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_22_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_23_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_23_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_24_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_24_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_25_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_25_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_26_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_26_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_27_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_27_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_28_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_28_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_29_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_29_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_30_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_30_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_31_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_31_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_32_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_32_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_33_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_33_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_34_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_34_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_35_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_35_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_36_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_36_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_37_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_37_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_38_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_38_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_39_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_39_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.X2_40_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.X2_40_U.if_write);
    assign proc_4_input_sync_blk[0] = 1'b0;
    assign proc_4_output_sync_blk[0] = 1'b0;
    assign proc_dep_vld_vec_4[0] = dl_detect_out ? proc_dep_vld_vec_4_reg[0] : (proc_4_data_FIFO_blk[0] | proc_4_data_PIPO_blk[0] | proc_4_start_FIFO_blk[0] | proc_4_TLF_FIFO_blk[0] | proc_4_input_sync_blk[0] | proc_4_output_sync_blk[0]);
    assign proc_4_data_FIFO_blk[1] = 1'b0;
    assign proc_4_data_PIPO_blk[1] = 1'b0;
    assign proc_4_start_FIFO_blk[1] = 1'b0;
    assign proc_4_TLF_FIFO_blk[1] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.Z2_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_14_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_14_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_15_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_15_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_16_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_16_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_17_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_17_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_18_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_18_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_19_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_19_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_20_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_20_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_21_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_21_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_22_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_22_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_23_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_23_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_24_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_24_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_25_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_25_U.if_write) | (~grp_ukf_step_3_2_s_fu_124.Z2_26_U.if_empty_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.Z2_26_U.if_write);
    assign proc_4_input_sync_blk[1] = 1'b0;
    assign proc_4_output_sync_blk[1] = 1'b0;
    assign proc_dep_vld_vec_4[1] = dl_detect_out ? proc_dep_vld_vec_4_reg[1] : (proc_4_data_FIFO_blk[1] | proc_4_data_PIPO_blk[1] | proc_4_start_FIFO_blk[1] | proc_4_TLF_FIFO_blk[1] | proc_4_input_sync_blk[1] | proc_4_output_sync_blk[1]);
    assign proc_4_data_FIFO_blk[2] = 1'b0;
    assign proc_4_data_PIPO_blk[2] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.P12_U.i_full_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_done & ap_done_reg_2 & ~grp_ukf_step_3_2_s_fu_124.P12_U.t_read) | (~grp_ukf_step_3_2_s_fu_124.P12_1_U.i_full_n & grp_ukf_step_3_2_s_fu_124.cross_cov_3_2_U0.ap_done & ap_done_reg_2 & ~grp_ukf_step_3_2_s_fu_124.P12_1_U.t_read);
    assign proc_4_start_FIFO_blk[2] = 1'b0;
    assign proc_4_TLF_FIFO_blk[2] = 1'b0;
    assign proc_4_input_sync_blk[2] = 1'b0;
    assign proc_4_output_sync_blk[2] = 1'b0;
    assign proc_dep_vld_vec_4[2] = dl_detect_out ? proc_dep_vld_vec_4_reg[2] : (proc_4_data_FIFO_blk[2] | proc_4_data_PIPO_blk[2] | proc_4_start_FIFO_blk[2] | proc_4_TLF_FIFO_blk[2] | proc_4_input_sync_blk[2] | proc_4_output_sync_blk[2]);
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            proc_dep_vld_vec_4_reg <= 'b0;
        end
        else begin
            proc_dep_vld_vec_4_reg <= proc_dep_vld_vec_4;
        end
    end
    assign in_chan_dep_vld_vec_4[0] = dep_chan_vld_5_4;
    assign in_chan_dep_data_vec_4[5 : 0] = dep_chan_data_5_4;
    assign token_in_vec_4[0] = token_5_4;
    assign dep_chan_vld_4_2 = out_chan_dep_vld_vec_4[0];
    assign dep_chan_data_4_2 = out_chan_dep_data_4;
    assign token_4_2 = token_out_vec_4[0];
    assign dep_chan_vld_4_3 = out_chan_dep_vld_vec_4[1];
    assign dep_chan_data_4_3 = out_chan_dep_data_4;
    assign token_4_3 = token_out_vec_4[1];
    assign dep_chan_vld_4_5 = out_chan_dep_vld_vec_4[2];
    assign dep_chan_data_4_5 = out_chan_dep_data_4;
    assign token_4_5 = token_out_vec_4[2];

    // Process: grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0
    ukf_accel_step_hls_deadlock_detect_unit #(6, 5, 5, 5) ukf_accel_step_hls_deadlock_detect_unit_5 (
        .reset(dl_reset),
        .clock(dl_clock),
        .proc_dep_vld_vec(proc_dep_vld_vec_5),
        .in_chan_dep_vld_vec(in_chan_dep_vld_vec_5),
        .in_chan_dep_data_vec(in_chan_dep_data_vec_5),
        .token_in_vec(token_in_vec_5),
        .dl_detect_in(dl_detect_out),
        .origin(origin[5]),
        .token_clear(token_clear),
        .out_chan_dep_vld_vec(out_chan_dep_vld_vec_5),
        .out_chan_dep_data(out_chan_dep_data_5),
        .token_out_vec(token_out_vec_5),
        .dl_detect_out(dl_in_vec[5]));

    assign proc_5_data_FIFO_blk[0] = 1'b0;
    assign proc_5_data_PIPO_blk[0] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.x1_U.t_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.x1_U.i_write) | (~grp_ukf_step_3_2_s_fu_124.S1_U.t_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.S1_U.i_write);
    assign proc_5_start_FIFO_blk[0] = 1'b0;
    assign proc_5_TLF_FIFO_blk[0] = 1'b0;
    assign proc_5_input_sync_blk[0] = 1'b0;
    assign proc_5_output_sync_blk[0] = 1'b0;
    assign proc_dep_vld_vec_5[0] = dl_detect_out ? proc_dep_vld_vec_5_reg[0] : (proc_5_data_FIFO_blk[0] | proc_5_data_PIPO_blk[0] | proc_5_start_FIFO_blk[0] | proc_5_TLF_FIFO_blk[0] | proc_5_input_sync_blk[0] | proc_5_output_sync_blk[0]);
    assign proc_5_data_FIFO_blk[1] = 1'b0;
    assign proc_5_data_PIPO_blk[1] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.z1_U.t_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.z1_U.i_write) | (~grp_ukf_step_3_2_s_fu_124.S2_U.t_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.S2_U.i_write) | (~grp_ukf_step_3_2_s_fu_124.S2_1_U.t_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.S2_1_U.i_write);
    assign proc_5_start_FIFO_blk[1] = 1'b0;
    assign proc_5_TLF_FIFO_blk[1] = 1'b0;
    assign proc_5_input_sync_blk[1] = 1'b0;
    assign proc_5_output_sync_blk[1] = 1'b0;
    assign proc_dep_vld_vec_5[1] = dl_detect_out ? proc_dep_vld_vec_5_reg[1] : (proc_5_data_FIFO_blk[1] | proc_5_data_PIPO_blk[1] | proc_5_start_FIFO_blk[1] | proc_5_TLF_FIFO_blk[1] | proc_5_input_sync_blk[1] | proc_5_output_sync_blk[1]);
    assign proc_5_data_FIFO_blk[2] = 1'b0;
    assign proc_5_data_PIPO_blk[2] = 1'b0 | (~grp_ukf_step_3_2_s_fu_124.P12_U.t_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.P12_U.i_write) | (~grp_ukf_step_3_2_s_fu_124.P12_1_U.t_empty_n & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.P12_1_U.i_write);
    assign proc_5_start_FIFO_blk[2] = 1'b0;
    assign proc_5_TLF_FIFO_blk[2] = 1'b0;
    assign proc_5_input_sync_blk[2] = 1'b0;
    assign proc_5_output_sync_blk[2] = 1'b0;
    assign proc_dep_vld_vec_5[2] = dl_detect_out ? proc_dep_vld_vec_5_reg[2] : (proc_5_data_FIFO_blk[2] | proc_5_data_PIPO_blk[2] | proc_5_start_FIFO_blk[2] | proc_5_TLF_FIFO_blk[2] | proc_5_input_sync_blk[2] | proc_5_output_sync_blk[2]);
    assign proc_5_data_FIFO_blk[3] = 1'b0;
    assign proc_5_data_PIPO_blk[3] = 1'b0;
    assign proc_5_start_FIFO_blk[3] = 1'b0;
    assign proc_5_TLF_FIFO_blk[3] = 1'b0;
    assign proc_5_input_sync_blk[3] = 1'b0 | (grp_ukf_step_3_2_s_fu_124.ap_sync_ukf_update_3_2_2_U0_ap_ready & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.ap_sync_entry_proc_U0_ap_ready);
    assign proc_5_output_sync_blk[3] = 1'b0;
    assign proc_dep_vld_vec_5[3] = dl_detect_out ? proc_dep_vld_vec_5_reg[3] : (proc_5_data_FIFO_blk[3] | proc_5_data_PIPO_blk[3] | proc_5_start_FIFO_blk[3] | proc_5_TLF_FIFO_blk[3] | proc_5_input_sync_blk[3] | proc_5_output_sync_blk[3]);
    assign proc_5_data_FIFO_blk[4] = 1'b0;
    assign proc_5_data_PIPO_blk[4] = 1'b0;
    assign proc_5_start_FIFO_blk[4] = 1'b0;
    assign proc_5_TLF_FIFO_blk[4] = 1'b0;
    assign proc_5_input_sync_blk[4] = 1'b0 | (grp_ukf_step_3_2_s_fu_124.ap_sync_ukf_update_3_2_2_U0_ap_ready & grp_ukf_step_3_2_s_fu_124.ukf_update_3_2_2_U0.ap_idle & ~grp_ukf_step_3_2_s_fu_124.ap_sync_make_sigma_points_3_U0_ap_ready);
    assign proc_5_output_sync_blk[4] = 1'b0;
    assign proc_dep_vld_vec_5[4] = dl_detect_out ? proc_dep_vld_vec_5_reg[4] : (proc_5_data_FIFO_blk[4] | proc_5_data_PIPO_blk[4] | proc_5_start_FIFO_blk[4] | proc_5_TLF_FIFO_blk[4] | proc_5_input_sync_blk[4] | proc_5_output_sync_blk[4]);
    always @ (negedge dl_reset or posedge dl_clock) begin
        if (~dl_reset) begin
            proc_dep_vld_vec_5_reg <= 'b0;
        end
        else begin
            proc_dep_vld_vec_5_reg <= proc_dep_vld_vec_5;
        end
    end
    assign in_chan_dep_vld_vec_5[0] = dep_chan_vld_0_5;
    assign in_chan_dep_data_vec_5[5 : 0] = dep_chan_data_0_5;
    assign token_in_vec_5[0] = token_0_5;
    assign in_chan_dep_vld_vec_5[1] = dep_chan_vld_1_5;
    assign in_chan_dep_data_vec_5[11 : 6] = dep_chan_data_1_5;
    assign token_in_vec_5[1] = token_1_5;
    assign in_chan_dep_vld_vec_5[2] = dep_chan_vld_2_5;
    assign in_chan_dep_data_vec_5[17 : 12] = dep_chan_data_2_5;
    assign token_in_vec_5[2] = token_2_5;
    assign in_chan_dep_vld_vec_5[3] = dep_chan_vld_3_5;
    assign in_chan_dep_data_vec_5[23 : 18] = dep_chan_data_3_5;
    assign token_in_vec_5[3] = token_3_5;
    assign in_chan_dep_vld_vec_5[4] = dep_chan_vld_4_5;
    assign in_chan_dep_data_vec_5[29 : 24] = dep_chan_data_4_5;
    assign token_in_vec_5[4] = token_4_5;
    assign dep_chan_vld_5_2 = out_chan_dep_vld_vec_5[0];
    assign dep_chan_data_5_2 = out_chan_dep_data_5;
    assign token_5_2 = token_out_vec_5[0];
    assign dep_chan_vld_5_3 = out_chan_dep_vld_vec_5[1];
    assign dep_chan_data_5_3 = out_chan_dep_data_5;
    assign token_5_3 = token_out_vec_5[1];
    assign dep_chan_vld_5_4 = out_chan_dep_vld_vec_5[2];
    assign dep_chan_data_5_4 = out_chan_dep_data_5;
    assign token_5_4 = token_out_vec_5[2];
    assign dep_chan_vld_5_0 = out_chan_dep_vld_vec_5[3];
    assign dep_chan_data_5_0 = out_chan_dep_data_5;
    assign token_5_0 = token_out_vec_5[3];
    assign dep_chan_vld_5_1 = out_chan_dep_vld_vec_5[4];
    assign dep_chan_data_5_1 = out_chan_dep_data_5;
    assign token_5_1 = token_out_vec_5[4];


`include "ukf_accel_step_hls_deadlock_report_unit.vh"
