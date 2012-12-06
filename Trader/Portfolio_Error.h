//
//  Portfolio_Error.h
//  Portfolio
//
//  Created by Victor Birath on 2012-12-01.
//  Copyright (c) 2012 database. All rights reserved.
//

#ifndef __Portfolio__Portfolio_Error__
#define __Portfolio__Portfolio_Error__

#include <iostream>
#include <stdexcept>

class Portfolio_Error : public std::logic_error
{
public:
    explicit Portfolio_Error(const std::string& what_arg)
    : logic_error(what_arg) {};
};

#endif /* defined(__Portfolio__Portfolio_Error__) */
