//
//          Trader.cc
//

//#include "Database.h"
#include "Trader.h"
#include "Trader_error.h"
#include <string>
#include <sstream>

bool _DEBUG = false;

void Trader::Debug_mode(bool debug)
{
    _DEBUG = debug;
}


void Trader::Login(const std::string username, const std::string password)
{
    if (_DEBUG) 
    {
        throw Trader_error("LOGIN. Username: " + username + ", Password: " + password);
    }
}

void Trader::Logout()
{
    if (_DEBUG) 
    {
        throw Trader_error("LOGOUT");
    }
}

void Trader::Buy(std::string stock_name, unsigned int amount, float price)
{
    if (_DEBUG) 
    {
        std::stringstream ss;
        
        ss << "BUY. Stock name: " << stock_name << ", amount: " << amount << ", price: " << price;
        
        throw Trader_error(ss.str());
    }
}

void Trader::Sell(std::string stock_name, unsigned int amount, float price)
{
    if (_DEBUG) 
    {
        throw Trader_error("SELL");
    }
}
