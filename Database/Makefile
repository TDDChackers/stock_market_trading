#Bygger Database.
#

# Filkataloger d‰r andra delar av programet finns.

CHILKAT = /Users/victorbirath/Dropbox/LIU/Y/Victor_och_Victor/TDDC76/Projekt/chilkat-9.3.2-macosx/include

LIB = -L/Users/victorbirath/Dropbox/LIU/Y/Victor_och_Victor/TDDC76/Projekt/chilkat-9.3.2-macosx/libStatic

CPPFLAGS += -I$(CHILKAT)
# Kompilator
#CCC = g++

# Kompilatorflaggor, lägg till '-g' om kompilering fˆr avlusning ska gˆras. -Wextra -pedantic -Wall
CCFLAGS += -std=c++11 -pedantic

# L‰nkflaggor - Fix fˆr att lˆsa lokala problem med C++ l‰nkbibliotek.
# LDFLAGS += -L/sw/gcc-$(GCC4_V)/lib -static-libstdc++

# Objektkodsmoduler som ingÂr i den kompletta kalkylatorn.
OBJECTS = Database.o Stock.o Test.o Time_Parser.o

# HuvudmÂl
Test: $(OBJECTS) Test.cpp Database.cpp Database.h Stock.h Stock.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LIB) -o Test $(OBJECTS)

Test2: Test2.o Time_Parser.o Stock.o Database.o Print_To_File.o Stock.h Time_Parser.h Database.h Print_To_File.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LIB) -lCHILKAT -o Test2 Stock.o Test2.o Database.o Time_Parser.o Print_To_File.o

# DelmÂl 
Test.o: Test.cpp 
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Test.cpp

Test2.o: Test2.cpp Stock.h Time_Parser.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Test2.cpp Stock.h Time_Parser.h

Database.o: Database.cpp Database.h Stock.h Time_parser.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Database.cpp
 
Stock.o: Stock.cpp Stock.h Stock_Error.h  Print_To_File.h Time_Parser.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Stock.cpp Stock.h Stock_Error.h Time_Parser.h Print_To_File.h

Print_To_File.o: Print_To_File.cpp Print_To_File.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LIB) -c Print_To_File.cpp

Time_Parser.o: Time_Parser.cpp Time_Parser.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Time_Parser.cpp

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core 

# 'make zap' tar ‰ven bort det kˆrbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf kalkylator *~
