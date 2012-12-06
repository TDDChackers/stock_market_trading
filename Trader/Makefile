# 			Kommunikation_start			#

# Include:
CHILKAT = /Users/victorbirath/Dropbox/LIU/Y/Victor_och_Victor/TDDC76/Projekt/chilkat-9.3.2-macosx/include
LIB = -L/Users/victorbirath/Dropbox/LIU/Y/Victor_och_Victor/TDDC76/Projekt/chilkat-9.3.2-macosx/libStatic

# Kompilator m.m.
CCC = gcc
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra
CPPFLAGS += -I$(CHILKAT)

main.out: main.o Connector.o Login.o Trader.o GUI.o Portfolio.o Holding.o
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LIB) -lCHILKAT -o main.out main.o Connector.o Portfolio.o Login.o Trader.o GUI.o Holding.o

main.o: Trader.h Trader_error.h main.cc 
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c main.cc

Trader.o: Trader.h Login.h Connector.h GUI.h Trader_error.h Trader.cc Portfolio.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Trader.cc

Connector.o: Connector.h Connector_error.h Connector.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Connector.cc

Login.o: Login.h Login_error.h Connector.h Login.cc 
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Login.cc

GUI.o: GUI.h GUI.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c GUI.cc

Portfolio.o: Portfolio.h Portfolio_Error.h Holding.h 
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Portfolio.cpp 

Holding.o: Holding.h Holding_Error.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Holding.cpp


clean:
	@ \rm -rf *.o core 

zap: clean
	@ \rm -rf main.out *~ 