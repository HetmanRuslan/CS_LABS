#pragma once
#ifndef NUMGEN_H
#define NUMGEN_H

struct numgen : sc_module {
	sc_out<double> out1;      
	sc_out<double> out2;      
	sc_in<bool>    clk;       

	void generate();	      


	//Constructor
	SC_CTOR(numgen) {
		SC_METHOD(generate);     
		sensitive_pos << clk;    

	}
};
#endif


