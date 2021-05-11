TARGET = expcc
TARTAG = $(TARGET).tgz

SRCDIR = src
OBJDIR = obj
INCDIR = inc

CC = gcc
AR = ar
FLAG = -Wall -Werror -O3 -fPIC

DECIMAL = decimal/src
SRC = $(wildcard $(DECIMAL)/*.c) $(STR_SRC) $(wildcard $(SRCDIR)/*.c)
OBJ += $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
INC += -I $(INCDIR)
INC += -I decimal/inc
INC += -I cJSON
INC += -I termux_api
MAIN_SRC = main.c
TEST_SRC = texpcc.c

STATIC = lib$(TARGET).a
SHARED = lib$(TARGET).so

all:$(OBJDIR) static $(TARGET)
static:$(STATIC)
shared:$(SHARED)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) -o $@ -c $^ $(FLAG) $(INC)
$(OBJDIR)/%.o:$(DECIMAL)/%.c
	$(CC) -o $@ -c $^ $(FLAG) $(INC)

$(STATIC):$(OBJ)
	$(AR) -rcs $@ $^

$(SHARED):$(OBJ)
	$(CC) -o $@ $^ -shared -Wl,-soname,lib$(TARGET)

$(TARGET):$(MAIN_SRC) $(STATIC)
	$(CC) -o $@ $^ $(FLAG) $(INC) -lm
	-termux-elf-cleaner $@

libdecimal.a:
	cd decimal;make;mv $@ ..;make clean
libcjson.a:
	cd cJSON;make;mv $@ ..;make clean
libtermux_api.a:
	cd termux_api;make;mv $@ ..;make clean

a:$(TEST_SRC) $(STATIC) libtermux_api.a libcjson.a
	$(CC) -o $@ $^ $(FLAG) $(INC) -fstack-protector-all -lm
	-termux-elf-cleaner $@

$(OBJDIR):
	-mkdir $@

.PHONY:clean t x
t:
	rm -rf $(TARTAG)
	tar -czf $(TARTAG) Makefile $(INCDIR) $(SRCDIR) *.c str decimal cJSON termux_api
x:$(TARTAG)
	tar -xzf $(TARTAG)
clean:
	rm -rf $(TARGET) $(TARTAG) $(OBJ) *.a *.so a