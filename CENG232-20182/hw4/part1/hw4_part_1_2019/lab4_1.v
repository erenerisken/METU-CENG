`timescale 1ns / 1ps
module MaskROM (input [3:0] RomAddress, output reg[7:0] RomDataOut);
/*  Please write your code below  */
always@(RomAddress)
	begin
		case(RomAddress)
			4'd0: RomDataOut <= 8'b00000000;
			4'd1: RomDataOut <= 8'b00001111;
			4'd2: RomDataOut <= 8'b00011110;
			4'd3: RomDataOut <= 8'b00110000;
			4'd4: RomDataOut <= 8'b01010000;
			4'd5: RomDataOut <= 8'b01100110;
			4'd6: RomDataOut <= 8'b01101010;
			4'd7: RomDataOut <= 8'b01111110;
			4'd8: RomDataOut <= 8'b10000001;
			4'd9: RomDataOut <= 8'b10100000;
			4'd10: RomDataOut <= 8'b10100110;
			4'd11: RomDataOut <= 8'b10111101;
			4'd12: RomDataOut <= 8'b11000000;
			4'd13: RomDataOut <= 8'b11010000;
			4'd14: RomDataOut <= 8'b11010011;
			4'd15: RomDataOut <= 8'b11100110;
			default: RomDataOut <= 8'd14;
		endcase
	end
/*  Please write your code above  */
endmodule



/*mode 0:read, 1:write*/																							
module RgbRAM (input Mode,input [3:0] RamAddress, input [23:0] RamDataIn,
					input [7:0] Mask,input [2:0] Op, input CLK, output reg [23:0] RamDataOut);
/*  Please write your code below  */

integer i;
reg[23:0] mem[15:0];
reg[8:0] tmp1,tmp2;
initial
begin
	for(i = 0; i<=15; i=i+1)
		mem[i] = 0;
	tmp1 = 0;
	tmp2 = 0;
end
always@(negedge Mode or RamAddress)
begin
	if(Mode == 0)
	begin
		RamDataOut <= mem[RamAddress];
	end
end

always@(posedge CLK)
begin
	if(Mode == 1)
	begin
		case(Op)
		3'd0:
		begin
			mem[RamAddress][23:16] = RamDataIn[23:16] & Mask;
			mem[RamAddress][15:8] = RamDataIn[15:8] & Mask;
			mem[RamAddress][7:0] = RamDataIn[7:0] & Mask;
		end
		3'd1:
		begin
			mem[RamAddress][23:16] = RamDataIn[23:16] | Mask;
			mem[RamAddress][15:8] = RamDataIn[15:8] | Mask;
			mem[RamAddress][7:0] = RamDataIn[7:0] | Mask;
		end
		3'd2:
		begin
			mem[RamAddress][23:16] = RamDataIn[23:16] ^ Mask;
			mem[RamAddress][15:8] = RamDataIn[15:8] ^ Mask;
			mem[RamAddress][7:0] = RamDataIn[7:0] ^ Mask;
		end
		3'd3:
		begin
			tmp1[7:0] = RamDataIn[23:16];
			tmp1[8] = 0;
			tmp2[7:0] = Mask;
			tmp2[8] = 0;
			if(tmp1 + tmp2 < 256)
			begin
				mem[RamAddress][23:16] = RamDataIn[23:16] + Mask;
			end	
			else
			begin
				mem[RamAddress][23:16] = 8'd255;
			end
			/*  */
			tmp1[7:0] = RamDataIn[15:8];
			tmp1[8] = 0;
			if(tmp1 + tmp2 < 256)
			begin
				mem[RamAddress][15:8] = RamDataIn[15:8] + Mask;
			end	
			else
			begin
				mem[RamAddress][15:8] = 8'd255;
			end
			/*  */
			tmp1[7:0] = RamDataIn[7:0];
			tmp1[8] = 0;
			if(tmp1 + tmp2 < 256)
			begin
				mem[RamAddress][7:0] = RamDataIn[7:0] + Mask;
			end	
			else
			begin
				mem[RamAddress][7:0] = 8'd255;
			end
		end
		3'd4:
		begin
			if(Mask > RamDataIn[23:16])
			begin
				mem[RamAddress][23:16] = 0;
			end
			else
			begin
				mem[RamAddress][23:16] = RamDataIn[23:16] - Mask;
			end
			/*  */
			if(Mask > RamDataIn[15:8])
			begin
				mem[RamAddress][15:8] = 0;
			end
			else
			begin
				mem[RamAddress][15:8] = RamDataIn[15:8] - Mask;
			end
			/*  */
			if(Mask > RamDataIn[7:0])
			begin
				mem[RamAddress][7:0] = 0;
			end
			else
			begin
				mem[RamAddress][7:0] = RamDataIn[7:0] - Mask;
			end
			/*  */
		end
		3'd5:
		begin
			if(RamDataIn[23:16] < 8'd255)
			begin
				mem[RamAddress][23:16] = RamDataIn[23:16] + 8'd1;
			end
			/*  */
			if(RamDataIn[15:8] < 8'd255)
			begin
				mem[RamAddress][15:8] = RamDataIn[15:8] + 8'd1;
			end
			/*  */
			if(RamDataIn[7:0] < 8'd255)
			begin
				mem[RamAddress][7:0] = RamDataIn[7:0] + 8'd1;
			end
			/*  */
		end
		3'd6:
		begin
			if(RamDataIn[23:16] > 0)
			begin
				mem[RamAddress][23:16] = RamDataIn[23:16] - 8'd1;
			end
			/*  */
			if(RamDataIn[15:8] > 0)
			begin
				mem[RamAddress][15:8] = RamDataIn[15:8] - 8'd1;
			end
			/*  */
			if(RamDataIn[7:0] > 0)
			begin
				mem[RamAddress][7:0] = RamDataIn[7:0] - 8'd1;
			end
			/*  */
		end
		3'd7:
		begin
			mem[RamAddress][23:17] = RamDataIn[22:16];
			mem[RamAddress][16] = RamDataIn[23];
			/*  */
			mem[RamAddress][15:9] = RamDataIn[14:8];
			mem[RamAddress][8] = RamDataIn[15];
			/*  */
			mem[RamAddress][7:1] = RamDataIn[6:0];
			mem[RamAddress][0] = RamDataIn[7];
			/*  */
		end
		endcase
	end
end

/*  Please write your code above  */
endmodule


module RgbMaskModule(input Mode, input [3:0] Address, input [23:0] RGBin,input [2:0] Op,  input CLK, output wire [23:0] RGBout);
	
	/*  DO NOT edit this module  */
	
	wire [7:0]  romResult;

	MaskROM RO(Address, romResult);
	RgbRAM RA(Mode, Address, RGBin,romResult, Op, CLK, RGBout);
endmodule
