#pragma once
#ifndef STAGE3_H
#define STAGE3_H

struct stage3 : sc_module {

	sc_in<double> r1;    
	sc_in<double> r2;   
	sc_out<double> sum;  
	sc_out<double> diff; 
	sc_in<bool>    clk;  

	void addsub();       
						 
	SC_CTOR(stage3) {
		SC_METHOD(addsub);
		sensitive_pos << clk;  
	}

public:

};

#endif
