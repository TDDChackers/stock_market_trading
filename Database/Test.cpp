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

using namespace std;
int main()
{
    bool DEBUG_ = false;
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
        #warning ändra sökvägen till aktiens "PATH" om du använder DEBUG_. 
        path = "/Users/victorbirath/Dropbox/Victor_och_Victor/TDDC76/Projekt/TestProgram/database/database/aktie.txt";
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
    
    
    tTimestamp = Stock::time_parser(timestamp);
    std::vector<double> data = _Database->get(stock_id, tTimestamp);
    
    
    cout << data[OPEN] <<" ," << data[CLOSE] <<" ," <<data[HIGH] <<" ,"<<data[LOW] <<endl; //OSV..
}


