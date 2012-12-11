//
//  main.cpp
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//
//#define _XOPEN_SOURCE /* glibc2 needs this */
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <unistd.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <ctime>
#include "Database.h"
#include "Time_Parser.h"
//#include "Print_To_File.h"


using namespace std;
using namespace Time_Parser;
int main()
{
    bool DEBUG_ = true;
    Database* _Database = new Database();
    std::string path, timestamp, stock_id;
    
    cout << "DEBUG_ = " << DEBUG_ << endl;
    
    cout << "Input path to database." << endl;
    if (! DEBUG_)
    {
        cin >> path;
    }
    else
    {
        //#warning ändra sökvägen till aktiens "PATH" om du använder DEBUG_.
        path = "/Users/victorbirath/Desktop/stock_market_trading-master/Database/aktie.txt";
        cout << path << endl;
    }
    
    _Database->import_file(path);
    
    cout << "Input stock_id: ";
    if (! DEBUG_)
    {
    cin >> stock_id;
    }
    else
    {
    stock_id = "Eric.b-st";
        cout << stock_id << endl;
    }
    
    cout << "Input timestamp: ";
    time_t tTimestamp;
    if (! DEBUG_)
    {
        cin >> timestamp;
    }
    else
    {
        timestamp = "2012-10-11";
        cout << timestamp << endl;;
    }
    
    
    tTimestamp = Time_Parser::time_parser(timestamp);
    cout << " Is_timestamp:  " << _Database->is_timestamp(stock_id,tTimestamp)<<endl;
    std::cout << Time_Parser::date(tTimestamp)<< endl;
    std::cout << "add a day" << endl;
    increase_day(tTimestamp);
    std::cout << Time_Parser::date(tTimestamp)<< endl;
    std::vector<double> data = _Database->get(stock_id, tTimestamp);
    
    
    cout << data[OPEN] <<" ," << data[CLOSE] <<" ," <<data[HIGH] <<" ,"<<data[LOW] <<endl;
//    #warning ändra denna sökväg till en plats där du vill spara databasen. Funktionalitet på väg!
//    make_file("/Users/victorbirath/Desktop/stock_market_trading-master/Database", "Print");
    
    cout <<_Database->get_latest_close_price(stock_id) <<endl;
    delete _Database;
}



