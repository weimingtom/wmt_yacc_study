CC := $(PLAT)gcc 
CPP := $(PLAT)g++
LD := $(PLAT)ld
AR := $(PLAT)ar rcu 
RANLIB := $(PLAT)ranlib
STRIP := $(PLAT)strip
RM := rm -f

CFLAGS := 
CFLAGS += -g -O2
CFLAGS += -std=c++0x -U__STRICT_ANSI__
CFLAGS += -I. -Iinclude
# #undef __STRICT_ANSI__

OBJECTS := 
OBJECTS += casting.o compiler.o
OBJECTS += naive-compiler.o
OBJECTS += visitor.o
OBJECTS += vm.o

OBJECTS += runtime/hash.o
OBJECTS += runtime/operate.o
OBJECTS += runtime/runtime.o
OBJECTS += runtime/scope.o
OBJECTS += runtime/table.o
OBJECTS += runtime/value.o

OBJECTS += main.o

BIN := cua

all: $(BIN)

$(BIN) : $(OBJECTS)
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
	$(RM) $(OBJECTS) LuaParser.cpp LuaParser.hpp LuaTokenizer.cpp *.o *.exe $(BIN) a.txt

test:
	./$(BIN)

# flex -o LuaTokenizer.cpp LuaTokenizer.l
# bison --defines=LuaParser.hpp -o LuaParser.cpp -y LuaParser.y
# bison -d -o LuaParser.cpp -y LuaParser.y
