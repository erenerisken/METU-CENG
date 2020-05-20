
module testBench;
	 reg[3:0] n;
    wire[6:0] p;

	nextPrime INSTANCE(n, p);

initial
		begin
			$monitor($time,,,
				"n:%b%b%b%b ---- p:%b%b%b%b %d",
				n[3],n[2],n[1],n[0],p[3], p[2], p[1], p[0], p);

			// waveform for simulating binary_to_eseg instance
			#10; //10
			$display("Setting all inputs to 0");
			n[3] = 0;
			n[2] = 0;
			n[1] = 0;
			n[0] = 0;

			#10;
			n[3] = 0;
			n[2] = 0;
			n[1] = 0;
			n[0] = 1;
			
			#10;
			n[3] = 0;
			n[2] = 0;
			n[1] = 1;
			n[0] = 0;
			
			#10;
			n[3] = 0;
			n[2] = 0;
			n[1] = 1;
			n[0] = 1;
			#10;
			n[3] = 0;
			n[2] = 1;
			n[1] = 0;
			n[0] = 0;
			#10;
			n[3] = 0;
			n[2] = 1;
			n[1] = 0;
			n[0] = 1;
			#10;
			n[3] = 0;
			n[2] = 1;
			n[1] = 1;
			n[0] = 0;
			#10;
			n[3] = 0;
			n[2] = 1;
			n[1] = 1;
			n[0] = 1;
			#10;
			n[3] = 1;
			n[2] = 0;
			n[1] = 0;
			n[0] = 0;
			#10;
			n[3] = 1;
			n[2] = 0;
			n[1] = 0;
			n[0] = 1;
			#10;
			n[3] = 1;
			n[2] = 0;
			n[1] = 1;
			n[0] = 0;
			#10;
			n[3] = 1;
			n[2] = 0;
			n[1] = 1;
			n[0] = 1;
			#10;
			n[3] = 1;
			n[2] = 1;
			n[1] = 0;
			n[0] = 0;
			#10;
			n[3] = 1;
			n[2] = 1;
			n[1] = 0;
			n[0] = 1;
			#10;
			n[3] = 1;
			n[2] = 1;
			n[1] = 1;
			n[0] = 0;
			#10;
			n[3] = 1;
			n[2] = 1;
			n[1] = 1;
			n[0] = 1;
			
			#10; //40
			$display("Ending simulation");
			$finish;
		end

endmodule


