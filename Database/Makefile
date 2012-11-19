#Bygger Database.
#

# Filkataloger d‰r andra delar av programet finns.
 DatabasePath = /Users/victorbirath/Dropbox/LIU/Y/Victor_och_Victor/TDDC76/Projekt/TestProgram/database/database

# Kompilator
#CCC = g++
CXX = g++

# Kompilatorflaggor, lägg till '-g' om kompilering fˆr avlusning ska gˆras. -Wextra -pedantic -Wall
CCFLAGS +=

# Preprocessorflaggor, -I l‰gger till en filkatalog i inkluderingssˆkv‰gen.
CPPFLAGS += -I$(DatabasePath)

# L‰nkflaggor - Fix fˆr att lˆsa lokala problem med C++ l‰nkbibliotek.
# LDFLAGS += -L/sw/gcc-$(GCC4_V)/lib -static-libstdc++

# Objektkodsmoduler som ingÂr i den kompletta kalkylatorn.
OBJECTS = Database.o Stock.o Test.o

# HuvudmÂl - skapas med kommandot 'make' eller 'make kalkylator'.
Test: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -o Test $(OBJECTS)

# DelmÂl 

Test.o: Test.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Test.cpp

Database.o: Database.cpp Database.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Database.cpp
 
Stock.o: Stock.cpp Stock.h Stock_Error.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Stock.cpp

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core 

# 'make zap' tar ‰ven bort det kˆrbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf kalkylator *~
