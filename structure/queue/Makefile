TARGET = queue
TARTAG = $(TARGET).tgz

SRCDIR = src
OBJDIR = obj
INCDIR = inc
#CFLAG += -Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough -Wsequence-point -Wswitch-default -Wswitch-unreachable -Wswitch-enum -Wstringop-truncation -Wbool-compare -Wtautological-compare -Wfloat-equal -Wshadow=global -Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual -Wwrite-strings -Wdangling-else -Wlogical-op -Wconversion -Wno-pedantic-ms-format
CFLAG += -Wall -O3 -fPIC
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
	$(CC) -o $@ -c $^ $(CFLAG) $(INC)

$(STATIC):$(OBJ)
	$(AR) -rcs $@ $^

$(SHARED):$(OBJ)
	$(CC) -o $@ $^ -shared -Wl,-soname,lib$(TARGET)

a:$(TEST_SRC) $(STATIC)
	$(CC) -o $@ $^ $(CFLAG) $(INC)

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