//
//          Trader.h
//

#ifndef Kommunikation_Test_Trader_h
#define Kommunikation_Test_Trader_h

// Ska denna inkluderas?
//#include "Database.h"

#include <string>
#include <vector>

#include "Trader_error.h"
#include "Login.h"
#include "GUI.h"
#include "Database.h"
#include "Evaluation_master.h"
#include "Portfolio.h"

class Trader
{
public:
    Trader();
    void Debug_mode(bool debug);
         ~Trader();
    
    // Tar referenser till de andra klasserna för kommande kommunikation.
    void Initialize(GUI* Gui, Database* Db, Evaluation_Master* E_M);
    void Login_cmd(const std::string username, const std::string password);
    void Logout();
    void Buy(std::string stock_name, unsigned int amount, float price); 
    void Sell(std::string stock_name, unsigned int amount, float price);
    void Send_message(int importance, std::string title, std::string message);
    std::string Get_username();
    void System_test();
//    std::vector<double> 
    void Get_stock_data(std::string stock_name, unsigned long int timestamp);
    std::string System_info();
    
    double get_share_profit(const std::string stock_id) const;
    unsigned int get_number_of_shares(const std::string stock_id) const;
    double get_mean_buying_price(const std::string stock_id) const;
    std::vector<std::string> get_stock_ids() const;
    double get_balance() const;
    void Touch();
    
    
private:
    Connector* connector;
    Login* login_;
    Portfolio* _Portfolio;
    
    GUI* AutoTrader_GUI;
    Database* AutoTrader_Db;
    Evaluation_Master* AutoTrader_E_M;
};
#endif
