//-----------------------------------------------------
// Testbench for the 4-bit up-counter ---------------->
// Example from www.asic-world.com (with fixes)
//-----------------------------------------------------
#include "systemc.h"
#include "design.cpp"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool>   clock;
    sc_signal<bool>   reset;
    sc_signal<bool>   enable_write;
    sc_signal<sc_uint<11> > addr_write;
    sc_signal<sc_uint<11> > addr_read;

    sc_signal<sc_uint<32> > data_read;
    sc_signal<sc_uint<32> > data_write;

    sc_signal<sc_uint<32> > demo;

    int i = 0;
    // Connect the DUT
    ram counter("COUNTER");
    counter.clock(clock);
    counter.reset(reset);
    counter.enable_write(enable_write);

    counter.addr_write(addr_write);
    counter.addr_read(addr_read);

    counter.data_read(data_read);
    counter.data_write(data_write);
    counter.demo(demo);

    addr_read = 2;
    addr_write = 1;

    data_write = 5;



    sc_start(1, SC_NS);

    // Open VCD file
    sc_trace_file* wf = sc_create_vcd_trace_file("counter");
    // Dump the desired signals
    sc_trace(wf, clock, "clock");
    sc_trace(wf, reset, "reset");
    sc_trace(wf, enable_write, "enable_write");

    sc_trace(wf, addr_write, "addr_write");
    sc_trace(wf, addr_read, "addr_read");


    sc_trace(wf, data_write, "data_write");
    sc_trace(wf, data_read, "data_read");


    sc_trace(wf, demo, "demo_data_write");

    reset = 0;
    enable_write = 1;
    for (i = 0; i < 5; i++) {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }






    reset = 1;
    enable_write = 0;

    for (i = 0; i < 10; i++) {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }








    data_write = 6;

    reset = 0;
    enable_write = 0;

    for (i = 0; i < 5; i++) {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }








    enable_write = 1;
    reset = 1;
    for (i = 0; i < 10; i++) {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }









    data_write = 7;

    reset = 1;
    for (i = 0; i < 10; i++) {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }




    reset = 0;
    enable_write = 1;
    for (i = 0; i < 10; i++) {
        clock = 0;
        sc_start(1, SC_NS);
        clock = 1;
        sc_start(1, SC_NS);
    }

    //cout << "@" << sc_time_stamp() <<" De-Asserting Enable\n" << endl;
    //enable = 0; // De-assert enable

    //cout << "@" << sc_time_stamp() <<" Terminating simulation\n" << endl;
    sc_close_vcd_trace_file(wf);
    return 0;// Terminate simulation

}
