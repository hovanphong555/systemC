#include"systemc.h"

SC_MODULE(ram) {
	sc_in_clk clock;
	sc_in <bool > reset;
	sc_in <bool > enable_write;
	sc_in <sc_uint<11> > addr_write;
	sc_in <sc_uint<11> > addr_read;

	sc_out <sc_uint<32> > data_read;
	sc_in <sc_uint<32> > data_write;

	 
	sc_uint<12> ram_data[2048];

	void read_data();
	void write_data();

	SC_CTOR(ram) {
		SC_METHOD(read_data);
		sensitive << addr_read << reset;

		SC_METHOD(write_data);
		sensitive << addr_write << enable_write << data_write << reset;

	}

};