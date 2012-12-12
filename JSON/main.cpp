//
//  main.cpp
//  JSON
//
//  Created by Victor Birath on 2012-12-11.
//  Copyright (c) 2012 database. All rights reserved.
//

#include <iostream>
#include <string>
#include "JSON_parser.h"

int main()
{
    std::string JSON, var_name, data, headder;
    std::cout << "Input JSONstring and Variablename: " << std::endl;
    std::cin >> JSON >>headder >> var_name;
    
    JSON_Parser(JSON,data,var_name,headder);
    std::cout << var_name << " = " << data;
    
    
    return 0;
}