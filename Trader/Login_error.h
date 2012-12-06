//
//  Login_error.h
//  Kommunikation_Test
//
//  Created by Victor Bergelin on 2012-11-05.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Kommunikation_Test_Login_error_h
#define Kommunikation_Test_Login_error_h

#include <iostream>
#include <stdexcept>
#include "Connector_error.h"

class Login_error : public Connector_error
{
public:
    explicit Login_error(const std::string& what_arg)
    : Connector_error(what_arg) {};
};

#endif
