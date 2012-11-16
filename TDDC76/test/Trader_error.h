//
//          Trader_error.h
//


#ifndef Kommunikation_Test_Trader_error_h
#define Kommunikation_Test_Trader_error_h

#include <iostream>
#include <stdexcept>

class Trader_error : public std::logic_error
{
public:
    explicit Trader_error(const std::string& what_arg)
    : logic_error(what_arg) {};
};

#endif
