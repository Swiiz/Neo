#include "io/print.h"

extern "C" void kernel_main(void) 
{
    using namespace neo::kernel;

	print::screen::clear();
    print::setColor(print::Color::YELLOW, print::Color::BLACK);
    print::printString("Welcome to Neo kernel!\n");
}

extern "C" void __cxa_pure_virtual()
{
    // Do nothing or print an error message.
}