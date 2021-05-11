TARGET = strlib
TARTAG = $(TARGET).tgz

SRCDIR = src
OBJDIR = obj
INCDIR = inc
CC = gcc
AR = ar
FLAG = -Wall -O3 -fPIC
#-Werror
SRC += $(wildcard $(SRCDIR)/*.c)
STR = $(SRCDIR)/str
STRLIB = $(SRCDIR)/strlib
STRBUF = $(SRCDIR)/strbuf
STR_SRC += $(wildcard $(STR)/*.c)
STRLIB_SRC += $(wildcard $(STRLIB)/*.c)
STRBUF_SRC += $(wildcard $(STRBUF)/*.c)
OBJ += $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
OBJ += $(addprefix $(OBJDIR)/,$(notdir $(STR_SRC:.c=.o)))
OBJ += $(addprefix $(OBJDIR)/,$(notdir $(STRLIB_SRC:.c=.o)))
OBJ += $(addprefix $(OBJDIR)/,$(notdir $(STRBUF_SRC:.c=.o)))
INC += -I $(INCDIR)
TEST_SRC += test.c

STATIC = lib$(TARGET).a
SHARED = lib$(TARGET).so

all:$(OBJDIR) static
static:$(STATIC)
shared:$(SHARED)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) -o $@ -c $^ $(FLAG) $(INC)
$(OBJDIR)/%.o:$(STR)/%.c
	$(CC) -o $@ -c $^ $(FLAG) $(INC)
$(OBJDIR)/%.o:$(STRLIB)/%.c
	$(CC) -o $@ -c $^ $(FLAG) $(INC)
$(OBJDIR)/%.o:$(STRBUF)/%.c
	$(CC) -o $@ -c $^ $(FLAG) $(INC)

$(STATIC):$(OBJ)
	$(AR) -rcs $@ $^

$(SHARED):$(OBJ)
	$(CC) -o $@ $^ -shared -Wl,-soname,lib$(TARGET)

a:$(TEST_SRC) $(STATIC)
	$(CC) -o $@ $^ $(FLAG) $(INC)
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