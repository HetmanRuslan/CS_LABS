#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "stage2.h"

void stage2::user_funk2()
{
	double a_val = a.read();
	double b_val = b.read();
	r1.write(a_val * b_val);
	r2.write(6);
}
