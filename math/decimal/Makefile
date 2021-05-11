TARGET = decimal
TARTAG = $(TARGET).tgz

SRCDIR = src
OBJDIR = obj
INCDIR = inc
CC = gcc
AR = ar
FLAG = -Wall -O3 -fPIC
#-Werror
SRC += $(wildcard $(SRCDIR)/*.c)
#OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ += $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
INC += -I $(INCDIR)
TEST_SRC += test.c

STATIC = lib$(TARGET).a
SHARED = lib$(TARGET).so

all:$(OBJDIR) static
static:$(STATIC)
shared:$(SHARED)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) -o $@ -c $^ $(FLAG) $(INC)

$(STATIC):$(OBJ)
	$(AR) -rcs $@ $^

$(SHARED):$(OBJ)
	$(CC) -o $@ $^ -shared -Wl,-soname,lib$(TARGET)

a:$(TEST_SRC) $(STATIC)
	$(CC) -o $@ $^ $(FLAG) $(INC) -lm
	@-termux-elf-cleaner $@

$(OBJDIR):
	-mkdir $@

.PHONY:clean t x
t:
	rm -rf $(TARTAG)
	tar -czf $(TARTAG) Makefile $(SRCDIR) $(INCDIR)
x:$(TARTAG)
	tar -xzf $(TARTAG)
clean:
	rm -rf $(TARGET) $(TARTAG) $(OBJ) *.a *.so a