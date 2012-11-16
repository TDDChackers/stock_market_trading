//
//          Trader.h
//

#ifndef Kommunikation_Test_Trader_h
#define Kommunikation_Test_Trader_h

//#include "Database.h"
#include "Trader_error.h"
#include <string>

class Trader
{
public:
    
    void Debug_mode(bool debug);
    
    void Login(const std::string username, const std::string password);
    void Logout();
    void Buy(std::string stock_name, unsigned int amount, float price); 
    void Sell(std::string stock_name, unsigned int amount, float price); 
    
private:

};

#endif
