//
//          Trader.cc
//

#include "Trader.h"
#include "Connector.h"
#include "Trader_error.h"

#include <string>
#include <sstream>
#include <vector>

using namespace std;
//// Try error in tester debug mode
bool TESTER_DEBUG = 0;

Trader::Trader()
{
    _Portfolio = new Portfolio();
    std::string stock_id = "Eric-b.ST";
    
    std::cout << "Buy 100 shares: " << stock_id << std::endl;
    _Portfolio->entry(stock_id, 100, 10);
    
    std::string stock_id_2 = "abb-a.ST";
    std::cout << "Buy 200 shares: " << stock_id_2 << std::endl;
    _Portfolio->entry(stock_id_2, 200, 20);


}


Trader::~Trader()
{
    ;
}

void Trader::Debug_mode(bool debug)
{
    TESTER_DEBUG = debug;
    
    if (TESTER_DEBUG) 
    {
        cout << "\n----------------------------------\nTest mode is on \n----------------------------------\n\nSystem Info:\n" << System_info() << endl; 
    }
}

void Trader::Send_message(int importance, string title, string message)
{
    AutoTrader_GUI->Important_message(importance, title, message);
}

void Trader::Login_cmd(const string username, const string password)
{
    login_ = new Login(username, password);
}

void Trader::Logout()
{
    if (TESTER_DEBUG) 
    {
        cout << "LOGOUT." << endl;
    }
    login_->Logout();
    
    delete login_;
}

void Trader::Touch()
{
    login_->Touch();
}

void Trader::Initialize(GUI* Gui, Database* Db, Evaluation_Master* E_M)
{
    if (TESTER_DEBUG) 
    {
        cout << "System initialized." << endl;
    }
    
    AutoTrader_GUI = Gui;
    AutoTrader_Db = Db;
    AutoTrader_E_M = E_M;
}

void Trader::Buy(string stock_name, unsigned int amount, float price)
{
    if (TESTER_DEBUG) 
    {
        stringstream ss;
        
        ss << "BUY. Stock name: " << stock_name << ", amount: " << amount << ", price: " << price;
        
        throw Trader_error(ss.str());
    }
}

void Trader::Sell(string stock_name, unsigned int amount, float price)
{
    if (TESTER_DEBUG) 
    {
        throw Trader_error("SELL");
    }
}

string Trader::Get_username()
{
    return login_->get_username();
}

void Trader::System_test()
{
    connector->Get_time_stamp();

    connector->Clock_Network(1);
}

std::string Trader::System_info()
{
    string str = connector->Get_system_info();
    return str;
}

//vector<double> 
void Trader::Get_stock_data(std::string stock_name, unsigned long int timestamp)
{
    connector->Get_stock_data_socket(stock_name, timestamp);
}

//-----------------Portfolio functions----------------------
double Trader::get_share_profit(const std::string stock_id) const
{
    return _Portfolio->get_profit(stock_id);
}

unsigned int Trader::get_number_of_shares(const std::string stock_id) const
{
    return _Portfolio->get_number_of_shares(stock_id);
}

double Trader::get_mean_buying_price(const std::string stock_id) const
{
    return _Portfolio->get_mean_buying_price(stock_id);
}

std::vector<std::string> Trader::get_stock_ids() const
{
    return _Portfolio->get_ids();
}

double Trader::get_balance() const
{
    return _Portfolio->get_balance();
}

