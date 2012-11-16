//
//  Stock_error.h
//  database
//
//  Created by Victor Birath on 2012-11-04.
//  Copyright (c) 2012 Victor Birath. All rights reserved.
//

#ifndef database_Stock_error_h
#define database_Stock_error_h

#include <iostream>
#include <stdexcept>

class Stock_Error : public std::logic_error
{
public:
explicit Stock_Error(const std::string& what_arg)
: logic_error(what_arg) {};

};
#endif
