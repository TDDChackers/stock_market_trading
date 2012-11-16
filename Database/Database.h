//
//  Database.h
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//

#ifndef __database__Database__
#define __database__Database__

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include "Stock.h"



    class Database
    {
        
    public:
        void update(std::string stock_id,std::string data);
        void inport_file(std::string path);
        void inport_web(const std::string stock_id,const time_t from,const time_t to,const float freq);
        bool is_id(std::string id);
        std::vector<double> get(std::string id, time_t timestamp);
        
    private:
        std::map<std::string, Stock*> _Stocks;
        
        
    };

#endif /* defined(__database__Database__) */
