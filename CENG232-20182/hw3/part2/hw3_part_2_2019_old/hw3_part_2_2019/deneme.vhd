
module testBench;
	 reg[3:0] n;
    wire p;

	isPrime INSTANCE(n, p);

initial
		begin
			$monitor($time,,,
				"n3=%b n2=%b n1=%b n0=%b out=%b",
				n[3],n[2],n[1],n[0],p);

			// waveform for simulating binary_to_eseg instance
			#10; //10
			$display("Setting all inputs to 0");
			n = [1,1,1,1];

			#10; //20
			$display("Setting D to 1");
			n = [1,1,1,0];
			
			#10; //30
			$display("Setting C to 1, D to 0");
			n = [0,0,0,1];
			
			#10; //40
			$display("Ending simulation");
			$finish;
		end

endmodule


