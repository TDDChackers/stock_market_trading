//
//  JSON_parser.cpp
//  JSON
//
//  Created by Victor Birath on 2012-12-11.
//  Copyright (c) 2012 database. All rights reserved.
//

#include "JSON_parser.h"
#include <string>
#include <algorithm>
void JSON_Parser(std::string& JSON,std::string& data,std::string& var_name2 ,std::string var_name1)
{
    if (var_name1 != "") //If nested in vector.
    {
        size_t open = JSON.find(var_name1+"\":{");
        size_t close = JSON.find("},\"",open);
        JSON =  JSON.substr(open,close);
    }
    
        
    size_t var_name_beg = JSON.find(var_name2+"\":");
    size_t data_end1 = JSON.find(",",var_name_beg);
    size_t data_end2 = JSON.find("}",var_name_beg);
    
    size_t data_end = std::min(data_end1,data_end2);

    //subtract one (") if data is a number;
    bool num_fix = isalnum(JSON[var_name_beg+var_name2.size()+2]);
    if (var_name_beg != std::string::npos &&
        data_end     != std::string::npos)
    {
        size_t length = data_end-(var_name_beg+2+var_name2.length()+2)+2*num_fix;
        data = JSON.substr(var_name_beg+var_name2.length()+3-num_fix,length);
    }
    
}