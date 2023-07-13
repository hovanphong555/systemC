#include"systemc.h"
#include <iostream>


SC_MODULE(ram) {
	sc_in_clk clock;
	sc_in <bool > reset;
	sc_in <bool > enable_write;
	sc_in <sc_uint<11> > addr_write;
	sc_in <sc_uint<11> > addr_read;

	sc_out <sc_uint<32> > data_read;
	sc_in <sc_uint<32> > data_write;
	sc_out <sc_uint<32> > demo;


	sc_uint<11> ram_data[2048];

	//void read_data();
	//void write_data();
	//ram_data[1]=4;
	//sc_uint<8> cnt = 2;
	//sc_uint<8>  dem = 10;
	//int static  tem=0;

	void read_data()
	{

		ram_data[cnt] = dem;


		if (reset == 0) {

			data_read = ram_data[addr_read.read()];

		}
		else {
			data_read = 0;

		}
	}
	void write_data() {
		if ((reset == 0) && enable_write) {

			ram_data[addr_write.read()] = data_write;
			demo = ram_data[addr_write.read()];

		}
		else {
			demo = 0;
		}
	}
	SC_CTOR(ram) {
		SC_METHOD(read_data);
		sensitive << addr_read << reset;
		// sensitive << reset;

		SC_METHOD(write_data);
		sensitive << addr_write << enable_write << data_write << reset;


	}
};