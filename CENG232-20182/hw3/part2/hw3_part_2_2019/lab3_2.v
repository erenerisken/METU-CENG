`timescale 1ns / 1ps 

module lab3_2(
			input[3:0] number,
			input CLK, 
			input selection,
			input mode,
			input clear,
			output reg [7:0] digit1,
			output reg [7:0] digit0,
			output reg [7:0] count1,
			output reg [7:0] count0,
			output reg warning
    );
   //Modify the lines below to implement your design .
	reg prime;
	reg[7:0] count00;
	reg[7:0] count01;
	reg[7:0] count10;
	reg[7:0] count11;
	initial 
	begin
		digit1 = 8'd0;
		digit0 = 8'd0;
		count1 = 8'd0;
		count0 = 8'd0;
		count00 = 8'd0;
		count01 = 8'd0;
		count10 = 8'd0;
		count11 = 8'd0;
		warning = 0;
	end
	always@(posedge CLK)
	begin
		case(number)
			4'd0: prime = 0;
			4'd1: prime = 0;
			4'd2: prime = 1;
			4'd3: prime = 1;
			4'd4: prime = 0;
			4'd5: prime = 1;
			4'd6: prime = 0;
			4'd7: prime = 1;
			4'd8: prime = 0;
			4'd9: prime = 0;
			4'd10: prime = 0;
			4'd11: prime = 1;
			4'd12: prime = 0;
			4'd13: prime = 1;
			4'd14: prime = 0;
			4'd15: prime = 0;
		endcase
		if(clear)
		begin
			digit1 = 8'd0;
			digit0 = 8'd0;
			count1 = 8'd0;
			count0 = 8'd0;
			count00 = 8'd0;
			count01 = 8'd0;
			count10 = 8'd0;
			count11 = 8'd0;
			warning = 0;	
		end
		else
		begin
			if(selection)//non-prime
			begin
				if(prime)
				begin
					warning = 1;
				end
				else
				begin
					warning = 0;
					digit0[0] = number[0];
					digit0[1] = number[1];
					digit0[2] = number[2];
					digit0[3] = number[3];
					if(mode)
					begin
						case(number)
							4'd0: digit1 = 8'd0;
							4'd1: digit1 = 8'd2;
							4'd2: digit1 = 8'd4;
							4'd3: digit1 = 8'd6;
							4'd4: digit1 = 8'd8;
							4'd5: digit1 = 8'd10;
							4'd6: digit1 = 8'd12;
							4'd7: digit1 = 8'd14;
							4'd8: digit1 = 8'd0;
							4'd9: digit1 = 8'd2;
							4'd10: digit1 = 8'd4;
							4'd11: digit1 = 8'd6;
							4'd12: digit1 = 8'd8;
							4'd13: digit1 = 8'd10;
							4'd14: digit1 = 8'd12;
							4'd15: digit1 = 8'd14;
						endcase
						count11 = count11 + 1;
						if(count11 > 8'd9)
						begin
							count11 = 8'd0;
						end
						count1 = count11;
						count0 = count10;
					end
					else//mode = 0
					begin
						case(number)
							4'd0: digit1 = 8'd0;
							4'd1: digit1 = 8'd2;
							4'd2: digit1 = 8'd4;
							4'd3: digit1 = 8'd6;
							4'd4: digit1 = 8'd8;
							4'd5: digit1 = 8'd10;
							4'd6: digit1 = 8'd12;
							4'd7: digit1 = 8'd14;
							4'd8: digit1 = 8'd0;
							4'd9: digit1 = 8'd2;
							4'd10: digit1 = 8'd4;
							4'd11: digit1 = 8'd6;
							4'd12: digit1 = 8'd8;
							4'd13: digit1 = 8'd10;
							4'd14: digit1 = 8'd12;
							4'd15: digit1 = 8'd14;
						endcase
						count10 = count10 + 1;
						if(count10 > 8'd9)
						begin
							count10 = 8'd0;
						end
						count1 = count11;
						count0 = count10;
					end
				end
			end
			else//prime
			begin
				if(~prime)
				begin
					warning = 1;
				end
				else
				begin
					warning = 0;
					digit0[0] = number[0];
					digit0[1] = number[1];
					digit0[2] = number[2];
					digit0[3] = number[3];
					if(mode)
					begin
						case(number)
							4'd2: digit1 = 8'd3;
							4'd3: digit1 = 8'd5;
							4'd5: digit1 = 8'd7;
							4'd7: digit1 = 8'd11;
							4'd11: digit1 = 8'd13;
							4'd13: digit1 = 8'd2;
						endcase
						count01 = count01 + 1;
						if(count01 > 8'd9)
						begin
							count01 = 8'd0;
						end
						count1 = count01;
						count0 = count00;
					end
					else
					begin
						case(number)
							4'd2: digit1 = 8'd13;
							4'd3: digit1 = 8'd2;
							4'd5: digit1 = 8'd3;
							4'd7: digit1 = 8'd5;
							4'd11: digit1 = 8'd7;
							4'd13: digit1 = 8'd11;
						endcase
						count00 = count00 + 1;
						if(count00 > 8'd9)
						begin
							count00 = 8'd0;
						end
						count1 = count01;
						count0 = count00;
					end
				end
			end
		end	
	end

endmodule


