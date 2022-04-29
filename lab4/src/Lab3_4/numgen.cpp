#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "numgen.h"

void numgen::generate()
{
	double a = 6;
	double b = 153;
	out1.write(a);
	out2.write(b);

}