CC := $(PLAT)gcc 
CPP := $(PLAT)g++
LD := $(PLAT)ld
AR := $(PLAT)ar rcu 
RANLIB := $(PLAT)ranlib
STRIP := $(PLAT)strip
RM := rm -f

CFLAGS := 
CFLAGS += -g -O2
CFLAGS += 
CFLAGS += -I. -Iinclude

OBJECTS := 
OBJECTS += LookupTable.o LuaFloat.o
OBJECTS += LuaFunction.o LuaObject.o
OBJECTS += LuaString.o 
OBJECTS += LuaTokenizer.o LuaParser.o

BIN := LuaParser

all: $(BIN)

$(BIN) : LuaParser.cpp $(OBJECTS)
	$(CPP) $(CFLAGS) -o $@ $(OBJECTS)

%.o : %.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

LuaTokenizer.cpp : LuaTokenizer.l
	flex --stdinit -o $@ $<

LuaParser.cpp : LuaParser.y
	bison -d -o $@ -y $<

clean:
	$(RM) $(OBJECTS) LuaParser.cpp LuaParser.hpp LuaTokenizer.cpp *.o *.exe $(BIN)

test:
	./$(BIN)

# flex -o LuaTokenizer.cpp LuaTokenizer.l
# bison --defines=LuaParser.hpp -o LuaParser.cpp -y LuaParser.y
# bison -d -o LuaParser.cpp -y LuaParser.y
