#pragma once
#ifndef TEST_SYSTEMC_S2_H 
#define TEST_SYSTEMC_S2_H
#include "systemc.h"
SC_MODULE(S2) {
	sc_in<int> a;
	sc_in<int> b;
	sc_out<int> r1;
	sc_out<int> r2;
	sc_in<bool> clk;
	SC_CTOR(S2) {
		SC_METHOD(calc_r1);
		sensitive << a << b;
		sensitive_pos << clk;
		SC_METHOD(calc_r2)
			sensitive << a << b;
		sensitive_pos << clk;
	}
	void calc_r1() {
		int a_val = a.read();
		int b_val = b.read();
		r1.write(a_val * b_val);
	}
	void calc_r2() {
		int b_val = b.read();
		r2.write(6);
	}
};
#endif