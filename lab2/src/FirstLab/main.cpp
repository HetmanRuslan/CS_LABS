
#include "systemc.h"
#include <iostream>
#include "display.h"
#include "s1.h"
#include "s2.h"


int sc_main(int argc, char* argv[]) {
	sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated",
		sc_core::SC_DO_NOTHING);
	sc_signal<int> x{ "x", 6 };
	sc_signal<int> y{ "y", 153 };
	sc_signal<int> o1{ "o1" };
	sc_signal<int> o2{ "o2" };
	sc_signal<int> s3{ "s3" };
	sc_signal<int> s4{ "s4" };
	sc_signal<int> s5{ "s5" };
	sc_signal<int> r1{ "r2" };
	sc_signal<int> r2{ "r1" };
	sc_clock clk("clk", 1, SC_NS, 0.5);

	S1 s1("s1");
	S2 s2("s2");
	DISPLAY display("display");
	s1.clk(clk);
	s2.clk(clk);
	display.clk(clk);

	s1.x(x);
	s1.y(y);
	s1.o1(o1);
	s1.o2(o2);
	s1.o3(s3);
	s1.o4(s4);
	s1.o5(s5);

	s2.a(o1);
	s2.b(o2);
	s2.r1(r1);
	s2.r2(r2);

	display.x(x);
	display.y(y);
	display.o1(o1);
	display.o2(o2);
	display.r3(s3);
	display.r4(s4);
	display.r5(s5);

	display.r1(r1);
	display.r2(r2);

	sc_start(10, SC_NS);

	return 0;
}
