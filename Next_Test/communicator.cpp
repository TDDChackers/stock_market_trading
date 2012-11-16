/*
 * communicator.cpp
 *
 *  Created on: 1 nov 2012
 *      Author: victorbirath
 */

#include "communicator.h"
#include <CkHttpRequest.h>
#include <CkHttp.h>
#include <CkHttpResponse.h>
#include <iostream>
#include <cstdio>

communicator::communicator() {
	// TODO Auto-generated constructor stub

}

communicator::~communicator() {
	// TODO Auto-generated destructor stub
}

bool communicator::login()
{

    CkHttpRequest req;
    CkHttp http;

    bool success;

    //  Any string unlocks the component for the 1st 30 days.
    success = http.UnlockComponent("Anything for 30-day trial");
    if (success != true) {
        printf("%s\n",http.lastErrorText());
        return -1;
    }

    //  This example duplicates the HTTP POST shown at
    //  http://json.org/JSONRequest.html

    //  Specifically, the request to be sent looks like this:
    //
//    POST /request HTTP/1.1
//Accept: application/jsonrequest
//    Content-Encoding: identity
//    Content-Length: 72
//    Content-Type: application/jsonrequest
//Host: json.penzance.org
//
//    {"user":"doctoravatar@penzance.com","forecast":7,"t":"vlIj","zip":94089}
//

    //  First, remove default header fields that would be automatically
    //  sent.  (These headers are harmless, and shouldn't need to
    //  be suppressed, but just in case...)
    http.put_AcceptCharset("");
    http.put_UserAgent("");
    http.put_AcceptLanguage("");
    //  Suppress the Accept-Encoding header by disallowing
    //  a gzip response:
    http.put_AllowGzip(false);

    //  If a Cookie needs to be added, it may be added by calling
    //  AddQuickHeader:
    http.AddQuickHeader("Cookie","JSESSIONID=1234");


    const char* jsonText = "{\"service\":\"MY_APP\",\"auth\":\"\"}";

    //  To use SSL/TLS, simply use "https://" in the URL.

    //  IMPORTANT: Make sure to change the URL, JSON text,
    //  and other data items to your own values.  The URL used
    //  in this example will not actually work.

    CkHttpResponse *resp = 0;
    resp = http.PostJson("https://api.test.nordnet.se/next/1/login",jsonText);
    if (resp == 0 ) {
        printf("%s\n",http.lastErrorText());
    }
    else {
        //  Display the JSON response.
        printf("%s\n",resp->bodyStr());
        delete resp;
    }
	return true;

}
