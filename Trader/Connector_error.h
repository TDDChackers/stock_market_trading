//
//          Connector_error.h
//


#ifndef Kommunikation_Test_Trader_error_h
#define Kommunikation_Test_Trader_error_h

#include <iostream>
#include <stdexcept>
#include "Trader_error.h"

// *** Arv från trader error borde det vara!
// Går ej att lägga till nu
class Connector_error : public std::logic_error
{
public:
    explicit Connector_error(const std::string& what_arg)
    : logic_error(what_arg) {};
};

#endif
