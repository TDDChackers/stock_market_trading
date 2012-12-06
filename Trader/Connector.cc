//
//  Connector.cc
//  Kommunikation_Test
//
//  Created by Victor Bergelin on 2012-11-05.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>

#include <CkHttpRequest.h>
#include <CkHttp.h>
#include <CkHttpResponse.h>
#include <CkCrypt2.h>
#include <CkSocket.h>

#include "Connector.h"
#include "Connector_error.h"

using namespace std;

const bool DEBUG = 1;

// Session_key = "1234yuytrew1234";

void Send_message(int importance, std::string title, std::string message)
{
    cout << "IMPORTANT MESSAGE!" << endl;
}

const char * Connector::To_base64(const char * convert)
{
    cout << "Convert To_Base64: " << convert << endl;
    
    CkCrypt2 crypt;
    
    //cout << "Convert To_Base64: " << convert << endl;
    
    crypt.UnlockComponent("Anything for 30-day trial");
    
    //cout << "Convert To_Base64: " << convert << endl;
    
    //  Indicate that no encryption should be performed,
    //  only encoding/decoding.
    crypt.put_CryptAlgorithm("none");
    
    crypt.put_EncodingMode("base64");
    //  Other possible EncodingMode settings are:
    //  "quoted-printable", "hex", "uu", "base32", and "url"
    
    const char * strBase64;
    
    //cout << "Convert To_Base64: " << convert << endl;
    
    strBase64 = crypt.encryptStringENC(convert);

    //cout << "Convert To_Base64: " << convert << endl;
    
    if (DEBUG) 
    {
        cout << "To base 64: ";
        cout << convert << " -> " << strBase64 << endl;
        
    }
    
    return strBase64;
}

const char * Connector::From_base64(const char * convert)
{
    CkCrypt2 crypt;
    
    crypt.UnlockComponent("Anything for 30-day trial");
    
    //  Indicate that no encryption should be performed,
    //  only encoding/decoding.
    crypt.put_CryptAlgorithm("none");
    
    crypt.put_EncodingMode("base64");
    //  Other possible EncodingMode settings are:
    //  "quoted-printable", "hex", "uu", "base32", and "url"
    
    const char * decoded = crypt.decryptStringENC(convert);
    
    return decoded;
}

const char * Connector::To_uft8(const char * convert)
{
    if (DEBUG) 
    {
        cout << "To utf-8: ";
        cout << convert << endl;
        
    }
    
    const char * converted = convert;
    return converted;    
}

const char * Connector::Get_time_stamp()
{
    time_t t;
    t=time(NULL) * 1000 ;
    
    stringstream sstr;
    sstr << t;
    string str = sstr.str();
    
    if (DEBUG)
    {
        cout << "Timestamp: " << str << endl;
    }
    
    return str.c_str();
}

const char * Connector::Get_system_info()
{
    CkHttp http;
    
    bool success;
    
    //  Any string unlocks the component for the 1st 30-days.
    success = http.UnlockComponent("Anything for 30-day trial");
    if (success != true) {
        printf("%s\n",http.lastErrorText());
    }
    
    //  Send the HTTP GET and return the content in a string.
    const char * html;
//    string url = BASE_URL + "/" + API_VERSION;
//    const char * url_post = url.c_str();
    
    return http.quickGetStr("https://api.test.nordnet.se/next/1/");
    
    printf("%s\n",html);
    return html;
}

//vector<double> 
void Connector::Get_stock_data(string stock_name, unsigned long int timestamp)
{
    // 1. Skicka ett login-request med session_key
    
    //const char * S_key = Session_key.c_str();
    
    //cout << Session_key << "::" << "S_key" << endl;
    
    
    CkHttpRequest req;
    CkHttp http;
    
    bool success;
    
    success = http.UnlockComponent("Anything for 30-day trial");
    if (success != true) 
    {
        throw Connector_error("Problem med CHILKAT");
    }
    
    http.put_AcceptCharset("");
    http.put_UserAgent("");
    http.put_AcceptLanguage("");
    
    //  Suppress the Accept-Encoding header by disallowing
    //  a gzip response:
    http.put_AllowGzip(false);
    
    CkHttpResponse * resp = 0;
    stringstream strings;
    strings << "{\"cmd\":\"login\", \"args\":{ \"session_key\":\"" << "S_key" << "\", \"service\":\"NEXTAPI\"}}" << "\n";;
    
    resp = http.PostJson("https://priv.api.test.nordnet.se",strings.str().c_str());
    
    if (resp == 0 )
    {
        if (DEBUG) 
        {
            cout << "DEBUG: Felrapport från Nordnet API: " << string(http.lastErrorText()) << endl;
        }
        else
        {
            string error = "Login fail:\n" + string(http.lastErrorText());
            throw Connector_error(error);
        }
    }
    
    // Fånga heartbeat?
    // 2. Skicka och fråga om uppgifterna
    
    
    
    int stock_nr = Get_stock_nr(stock_name);
    
    // Konvertera till rätt index för marknad och aktie
    // {"cmd":"subscribe", "args":{"t":"price", "i":"1869", "m":30}}
    
    CkHttpRequest req_2;
    CkHttp http_2;
    
    bool success_2;
    
    success_2 = http_2.UnlockComponent("Anything for 30-day trial");
    if (success_2 != true) 
    {
        throw Connector_error("Problem med CHILKAT");
    }
    
    http_2.put_AcceptCharset("");
    http_2.put_UserAgent("");
    http_2.put_AcceptLanguage("");
    
    //  Suppress the Accept-Encoding header by disallowing
    //  a gzip response:
    http_2.put_AllowGzip(false);
    
    CkHttpResponse * resp_2 = 0;
    
    stringstream strings_2;
    
    strings_2 << "{\"cmd\":\"subscribe\", \"args\":{\"t\":\"price\", \"i\":\"1869\", \"m\":30}}" << "\n";
    
    resp_2 = http_2.PostJson("https://priv.api.test.nordnet.se",strings_2.str().c_str());
    
    if (resp_2 == 0 )
    {
        if (DEBUG) 
        {
            cout << "DEBUG: Felrapport från Nordnet API: " << http_2.lastErrorText() << endl;
            // return "Fail";
        }
        else
        {
            string error_2 = "Login fail:\n" + string(http_2.lastErrorText());
            throw Connector_error(error_2); 
        }
    }    
}

void Connector::Get_stock_data_socket(string stock_name, unsigned long int timestamp)
{
    stringstream strings;
    strings << "{\"cmd\":\"login\", \"args\":{ \"session_key\":\"" << "Session_key" << "\", \"service\":\"NEXTAPI\"}}" << "\n";
    
    CkSocket socket;
    
    bool success;
    success = socket.UnlockComponent("Anything for 30-day trial");
    if (success != true) {
        printf("%s\n",socket.lastErrorText());
    }
    
    bool ssl;
    ssl = true;
    long maxWaitMillisec;
    maxWaitMillisec = 20000;
    
    //  The SSL server hostname may be an IP address, a domain name,
    //  or "localhost".  You'll need to change this:
    const char * sslServerHost;
    sslServerHost = "https://pub.api.test.nordnet.se";
    long sslServerPort;
    sslServerPort = 443;
    
    //  Connect to the SSL server:
    success = socket.Connect(sslServerHost,sslServerPort,ssl,maxWaitMillisec);
    if (success != true) 
    {
        printf("%s\n",socket.lastErrorText());
    }
    
    //  Set maximum timeouts for reading an writing (in millisec)
    socket.put_MaxReadIdleMs(20000);
    socket.put_MaxSendIdleMs(20000);
    
    //  Send a "Hello Server! -EOM-" message:
    success = socket.SendString(strings.str().c_str());
    if (success != true) {
        printf("%s\n",socket.lastErrorText());
    }
    
    //  The server (in this example) is going to send a "Hello Client! -EOM-"
    //  message.  Read it:
    const char * receivedMsg;
    receivedMsg = socket.receiveUntilMatch("");
    if (receivedMsg == 0 ) 
    {
        printf("%s\n",socket.lastErrorText());
    }
    
    //  Close the connection with the server
    //  Wait a max of 20 seconds (20000 millsec)
    socket.Close(20000);
    printf("%s\n",receivedMsg);
}



void Connector::Clock_Network(int iterations)
{
    long double Time = time(0);
    
    for(int i = 0; i < iterations; i++)
    {
        Get_system_info();
    }
    
    Time = time(0) - Time;
    long double TimeMS = Time*1000;
    
    cout << "\nTime of :" << iterations << " was clocked to: " << TimeMS << "." << endl;
}

int Connector::Get_stock_nr(string stock_string)
{
    if (stock_string != "") 
    {
        // Nordnet on Burgendy
        return 1869;
    }
    return -1;
}

