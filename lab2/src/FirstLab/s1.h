#pragma once
#ifndef TEST_SYSTEMC_S1_H 
#define TEST_SYSTEMC_S1_H
#include "systemc.h"
#include "cmath"
#include "s2.h"
SC_MODULE(S1) {
	sc_in<int> x;
	sc_in<int> y;
	sc_out<int> o1;
	sc_out<int> o2;
	sc_in<bool> clk;
	sc_out<int> o3;
	sc_out<int> o4;
	sc_out<int> o5;

	SC_CTOR(S1) {
		SC_METHOD(calc_o1);
		sensitive << x << y;
		sensitive_pos << clk;
		SC_METHOD(calc_o2);
		sensitive << x << y;
		sensitive_pos << clk;

		SC_METHOD(calc_o3);
		sensitive_pos << clk;

		SC_METHOD(calc_o4);
		sensitive_pos << clk;

		SC_METHOD(calc_o5);
		sensitive_pos << clk;

	}
	void calc_o1() {
		int x_val = x.read();
		int y_val = y.read();
		o1.write(x_val - y_val);
	}

	void calc_o3() {
		
		o3.write(77);
	}

	void calc_o4() {

		o4.write(88);
	}

	void calc_o5() {

		o5.write(99);
	}

	void calc_o2() {
		int x_val = x.read();
		int y_val = y.read();
		int temp1 = ((x_val + y_val) / 2);
		int temp2 = (x_val >> 2);
		o2.write(temp1 && temp2);
	}
};
#endif