`timescale 1ns / 1ps

module lab4_2(
  input [1:0] mode,
  input [2:0] n_gasoline_pumps,      // for setup mode, max 6
  input [2:0] n_diesel_pumps,        // for setup mode, max 6
  input [3:0] fuel_amount,           // for add car mode, max 8
  input fuel_type,                   // for add car mode, gas(0) or diesel(1)
  input CLK, 

  output reg [0:5] pump_status,                // pump is working or not, max 6 pumps
  output reg is_gasoline_queue_not_full,       // gasoline queue full warning
  output reg is_diesel_queue_not_full,         // diesel queue full warning

  output reg [3:0] n_cars_in_gasoline_queue,   // to represent max 9 on 1 7-seg display
  output reg [3:0] n_cars_in_diesel_queue,     // to represent max 9 on 1 7-seg display

  output reg [7:0] total_gasoline_needed,      // to represent max 99 on 2 7-seg displays
  output reg [7:0] total_diesel_needed,        // to represent max 99 on 2 7-seg displays

  // reset these after one clock
  output reg invalid_gasoline_car,             // to lightup dot at an2
  output reg invalid_diesel_car,               // to lightup dot at an0
  output reg invalid_setup_params              // to lightup all dots
);

// write your code here

integer i;
integer j;
reg[3:0] queueGasoline[7:0];
reg[3:0] queueDiesel[7:0];
reg[3:0] pumps[5:0];
reg[3:0] tmpN;
reg[3:0] tmpM;
reg[3:0] n;
reg[3:0] m;
reg flag;
reg flag2;
reg setup;

	initial
	begin
		for(i = 0; i<8; i=i+1)
		begin
			queueGasoline[i] = 4'd0;
			queueDiesel[i] = 4'd0;
			if(i<6)
			begin
				pumps[i] = 4'd0;
			end
		end
		setup = 0;
		tmpN = 4'd0;
		tmpM = 4'd0;
		m = 4'd0;
		n = 4'd0;
		flag = 0;
		invalid_diesel_car = 0;
		invalid_gasoline_car = 0;
		invalid_setup_params = 0;
		total_diesel_needed = 8'd255;
		total_gasoline_needed = 8'd255;
		n_cars_in_diesel_queue = 4'd15;
		n_cars_in_gasoline_queue = 4'd15;
		is_diesel_queue_not_full = 0;
		is_gasoline_queue_not_full = 0;
		pump_status = 6'b000000;
	end

	always@(posedge CLK)
	begin
		invalid_diesel_car = 0;
		invalid_gasoline_car = 0;
		invalid_setup_params = 0;
		if(mode[1] == 1)
		begin
			tmpN[2:0] = n_gasoline_pumps;
			tmpM[2:0] = n_diesel_pumps;
			if(tmpN+tmpM > 4'd6 || tmpN+tmpM == 4'd0)
			begin
				invalid_setup_params = 1;
			end
			else
			begin
				setup = 1;
				for(i = 0; i<8; i=i+1)
				begin
					queueGasoline[i] = 4'd0;
					queueDiesel[i] = 4'd0;
					if(i<6)
					begin
						pumps[i] = 4'd0;
					end
				end
				n = tmpN;
				m = tmpM;
				for(i = 0; i<6; i=i+1)
				begin
					pump_status[i] = (i<n+m);
				end
			end//setup
		end//setup mode
		
		else
		begin
			if(setup == 1)
			begin
				for(i = 0; i<6; i = i+1)
				begin
					if(pumps[i]>4'd0)
					begin
						pumps[i] = pumps[i]-4'd1;
					end
				end
				for(i = 0; i<6; i = i+1)
				begin
					if(i<n && pump_status[i]==1 && queueGasoline[0]>4'd0)
					begin
						pump_status[i]=0;
						pumps[i]=queueGasoline[0];
						for(j=0; j<7; j = j+1)
						begin
							queueGasoline[j] = queueGasoline[j+1];
						end
						queueGasoline[7] = 4'd0;
					end
					if(i>=n && i<n+m && pump_status[i]==1 && queueDiesel[0]>4'd0)
					begin
						pump_status[i]=0;
						pumps[i]=queueDiesel[0];
						for(j=0; j<7; j = j+1)
						begin
							queueDiesel[j] = queueDiesel[j+1];
						end
						queueDiesel[7] = 4'd0;
					end
				end
				if(mode[0] == 1)
				begin
					if(fuel_type == 0)
					begin
						if(fuel_amount == 4'd0 || fuel_amount > 4'd8 || queueGasoline[7]>4'd0 || n == 4'd0)
						begin
							invalid_gasoline_car = 1;
						end
						else
						begin
							flag = 0;
							for(i = 0; i<6; i = i+1)
							begin
								if(flag == 0 && i<n && pump_status[i] == 1)
								begin
									flag = 1;
									pump_status[i] = 1;
									pumps[i] = fuel_amount;
								end
							end
							if(flag == 0)
							begin
								flag2 = 0;
								for(i = 0; i<8; i = i+1)
								begin
									if(queueGasoline[i] == 4'd0 && flag2 == 0)
									begin
										flag2 = 1;
										queueGasoline[i] = fuel_amount;
									end
								end
							end
						end
					end
					else
					begin
						if(fuel_amount == 4'd0 || fuel_amount > 4'd8 || queueDiesel[7]>4'd0 || m == 4'd0)
						begin
							invalid_diesel_car = 1;
						end
						else
						begin
							flag = 0;
							for(i = 0; i<6; i = i+1)
							begin
								if(flag == 0 && i>=n && i<m+n && pump_status[i] == 1)
								begin
									flag = 1;
									pump_status[i] = 1;
									pumps[i] = fuel_amount;
								end
							end
							if(flag == 0)
							begin
								flag2 = 0;
								for(i = 0; i<8; i = i+1)
								begin
									if(queueDiesel[i] == 4'd0 && flag2 == 0)
									begin
										flag2 = 1;
										queueDiesel[i] = fuel_amount;
									end
								end
							end
						end
					end
				end//add car
			end//simulation mode
		end//simulation mode
		if(n == 4'd0)
		begin
			total_gasoline_needed = 8'd255;
			n_cars_in_gasoline_queue = 4'd15;
			is_gasoline_queue_not_full = 0;
		end
		else
		begin
			is_gasoline_queue_not_full = queueGasoline[7] == 4'd0;
			total_gasoline_needed = 8'd0;
			n_cars_in_gasoline_queue = 4'd0;
			for(i = 0; i<8; i=i+1)
			begin
				if(i<n && i<6)
				begin
					total_gasoline_needed = total_gasoline_needed + pumps[i];
				end
				total_gasoline_needed = total_gasoline_needed + queueGasoline[i];
				if(queueGasoline[i] > 4'd0)
				begin
					n_cars_in_gasoline_queue = n_cars_in_gasoline_queue + 4'd1;
				end
			end
		end
		//---
		if(m == 4'd0)
		begin
			total_diesel_needed = 8'd255;
			n_cars_in_diesel_queue = 4'd15;
			is_diesel_queue_not_full = 0;
		end
		else
		begin
			is_diesel_queue_not_full = queueDiesel[7] == 4'd0;
			total_diesel_needed = 8'd0;
			n_cars_in_diesel_queue = 4'd0;
			for(i = 0; i<8; i=i+1)
			begin
				if(i>=n && i<n+m && i<6)
				begin
					total_diesel_needed = total_diesel_needed + pumps[i];
				end
				total_diesel_needed = total_diesel_needed + queueDiesel[i];
				if(queueDiesel[i] > 4'd0)
				begin
					n_cars_in_diesel_queue = n_cars_in_diesel_queue + 4'd1;
				end
			end
		end
		for(i = 0; i<6; i = i+1)
		begin
			pump_status[i] = (pumps[i] == 4'd0) & (i<n+m);
		end
	end//always

endmodule

