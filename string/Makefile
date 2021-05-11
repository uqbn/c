TARGET = string
TARTAG = $(TARGET).tgz

CC = gcc
AR = ar
FLAG = -Wall -O3 -fPIC
#-Werror
SRC = $(TARGET).c
OBJ = $(patsubst %.c, %.o, $(SRC))
TEST_SRC = test.c

STATIC = lib$(TARGET).a
SHARED = lib$(TARGET).so

all:static
static:$(STATIC)
shared:$(SHARED)

%.o:%.c
	$(CC) -o $@ -c $^ $(FLAG) $(INC)

$(STATIC):$(OBJ)
	$(AR) -rcs $@ $^

$(SHARED):$(OBJ)
	$(CC) -o $@ $^ -shared -Wl,-soname,lib$(TARGET)

a:$(TEST_SRC) $(STATIC)
	$(CC) -o $@ $^ $(FLAG) $(INC)

.PHONY:clean t x
t:
	rm -rf $(TARTAG)
	tar -czf $(TARTAG) Makefile *.c *.h
x:$(TARTAG)
	tar -xzf $(TARTAG)
clean:
	rm -rf $(TARGET) $(TARTAG) $(OBJ) *.a *.so a
