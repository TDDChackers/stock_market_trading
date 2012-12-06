
//
//  main.cpp
//  Kommunikation_Test
//

#include <iostream>
#include "Trader.h"
#include "Trader_error.h"

int main()
{
    Trader* trader = new Trader();
    GUI* Gui = new GUI();
    Database* Db = new Database(); 
    Evaluation_Master* E_M = new Evaluation_Master();
    
    trader->Initialize(Gui, Db, E_M);
    
    // Koden kommer kasta felmeddelande tillbaka för varje gång någon funktion kallas på om satt till true.
    trader->Debug_mode(false);
    
    try 
    {
        trader->Login_cmd("victorbergelin","6932");
        
        // trader->Touch();
        
        trader->Get_stock_data("Test", 1234567898765);
        
        // trader->Logout();
        
        
    } 
    catch (const Trader_error& error) 
    {
        printf("1.");
        std::cout << error.what() << std::endl;
    }
    delete trader;
    return 0;
}

