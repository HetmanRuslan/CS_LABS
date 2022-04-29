#pragma once
#ifndef TEST_SYSTEMC_DISPLAY_H 
#define TEST_SYSTEMC_DISPLAY_H
#include "systemc.h"
#include "iomanip"

SC_MODULE(DISPLAY) {
	sc_in<int> x;
	sc_in<int> y;
	sc_in<int> o1;
	sc_in<int> o2;
	sc_in<int> r1;
	sc_in<int> r2;
	sc_in<int> r3;
	sc_in<int> r4;
	sc_in<int> r5;


	sc_in<bool> clk;

	SC_CTOR(DISPLAY) {
		SC_THREAD(display);
		sensitive << clk.pos();
	}
	void display()
	{
		cout << std::setw(15) << "Time";
		cout << std::setw(7) << "x";
		cout << std::setw(7) << "y";
		cout << std::setw(7) << "o1";
		cout << std::setw(7) << "o2";
		cout << std::setw(7) << "r1";
		cout << std::setw(7) << "r2";
		cout << std::setw(7) << "r3";
		cout << std::setw(7) << "r4" ;
		cout << std::setw(7) << "r5" << endl;


		for (int i = 0; i < 3; i++)
		{
			cout << std::setw(15) << sc_time_stamp();
			cout << std::setw(7) << x.read();
			cout << std::setw(7) << y.read();
			cout << std::setw(7) << o1.read();
			cout << std::setw(7) << o2.read();
			cout << std::setw(7) << r1.read();
			cout << std::setw(7) << r2.read();
			cout << std::setw(7) << r3.read();
			cout << std::setw(7) << r4.read() ;
			cout << std::setw(7) << r5.read() << endl;
			wait();
		}
		sc_stop();
	}

};
#endif
