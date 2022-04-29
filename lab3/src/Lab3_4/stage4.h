#pragma once
#ifndef STAGE4_H
#define STAGE4_H

struct stage4 : sc_module {

	sc_in<double>  sum;      
	sc_in<double>  diff;     
	sc_out<double> prod;     
	sc_out<double> quot;     
	sc_in<bool>    clk;      

	void multdiv();          

							 
	SC_CTOR(stage4) {
		SC_METHOD(multdiv);
		sensitive_pos << clk;   
	}
};
#endif
