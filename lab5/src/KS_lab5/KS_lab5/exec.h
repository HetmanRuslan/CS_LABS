/******************************************************************************
    Copyright (c) 1996-2000 Synopsys, Inc.    ALL RIGHTS RESERVED
 
  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC(TM) Open Community License Software Download and
  Use License Version 1.1 (the "License"); you may not use this file except
  in compliance with such restrictions and limitations. You may obtain
  instructions on how to receive a copy of the License at
  http://www.systemc.org/. Software distributed by Original Contributor
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.
 
******************************************************************************/
 

/******************************************************************************
 
    exec.h -- Integer Execution Unit 
 
    Original Author: Martin Wang. Synopsys, Inc. (mwang@synopsys.com)
 
******************************************************************************/
 
/******************************************************************************
 
    MODIFICATION LOG - modifiers, enter your name, affliation and
    changes you are making here:
 
    Modifier Name & Affiliation:
    Description of Modification:
 
 
******************************************************************************/



struct exec : sc_module {
  sc_in<bool>   	       	reset;			// reset not used.
  sc_in<bool>   	       	in_valid;		// input valid
  sc_in<int>  	      		opcode;			// opcode from ID
  sc_in<bool>  	      		negate;			// not implemented
  sc_in<int>        		add1;			// not implemented
  sc_in<bool>   	     	shift_sel;		// not implemented
  sc_in<signed int>        	dina;			// operand A
  sc_in<signed int>        	dinb;			// operand B
  sc_in<bool>        		forward_A;		// data forwarding A valid
  sc_in<bool>        		forward_B;		// data forwarding B valid
  sc_in<unsigned>        	dest;			// destination register number
  sc_out<bool>              	C;			// Carry bit 
  sc_out<bool>              	V;			// Overflow bit
  sc_out<bool>              	Z;			// Zero bit
  sc_out<signed int>        	dout;			// output data
  sc_out<bool>   	       	out_valid;		// output valid
  sc_out<unsigned>        	destout;		// write to which registers?
  sc_in_clk 			CLK;


  SC_CTOR(exec) {
      SC_CTHREAD(entry, CLK.pos());
  }
  
  void entry();
};

// EOF
