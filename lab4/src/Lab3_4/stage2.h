#pragma once
#ifndef STAGE2_H
#define STAGE2_H

struct stage2 : sc_module {

	sc_in<double> a;   
	sc_in<double> b;  
	sc_out<double> r1; 
	sc_out<double> r2; 
	sc_in<bool> clk;   

	void user_funk2();
	
	SC_CTOR(stage2) {
		SC_METHOD(user_funk2);
		sensitive_pos << clk;  
	}

public:

};
#endif
