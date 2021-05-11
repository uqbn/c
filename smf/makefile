#directory
PWD = .
LIBPATH = .
SRCDIR = $(PWD)/src
INCDIR = $(PWD)/inc
OBJDIR = $(PWD)/obj
LIBDIR = $(PWD)/lib
BINDIR = $(PWD)/bin
TARDIR = $(PWD)/tar
ALLDIR = $(SRCDIR) $(INCDIR) $(OBJDIR) $(LIBDIR) $(BINDIR) $(TARDIR)

#--------------------------------------------------------------------

#TERMUX = 1

#--------------------------------------------------------------------

#target
#tar
TARTAG = $(TARDIR)/all.tgz
#bin
APP = smf
PD = smf_pd
TARGET = $(PD) $(APP)

#--------------------------------------------------------------------

#compiler
CC = gcc
AR = ar

#flag
FLAG = -g -O0
LINK = -g -O0

SRC = $(wildcard $(SRCDIR)/*.c)

#include
INC = -I $(INCDIR)

#library
LIB = $(wildcard $(LIBDIR)/*.a)
ifdef TERMUX
LIB_CJSON = -lcjson
else
LIB_CJSON = $(wildcard $(LIBDIR)/cjson/*.a)
endif

all: $(ALLDIR) $(TARGET)

#--------------------------------------------------------------------

#pd
PD_OBJDIR := $(OBJDIR)/$(PD)
PD_SRCDIR := $(SRCDIR)/$(PD)
PD_LIBDIR := $(LIBDIR)/$(PD)

PD_FLAG := $(FLAG)

PD_SRC += $(wildcard $(PD_SRCDIR)/*.c)
PD_OBJ += $(addprefix $(PD_OBJDIR)/,$(notdir $(PD_SRC:.c=.o)))
PD_INC += $(INC)
PD_STATIC = $(PD_LIBDIR)/libsmf_pd.a

$(PD):$(PD_OBJ) $(PD_STATIC)

$(PD_STATIC):$(PD_OBJ)
	$(AR) -rcs $@ $^

$(PD_OBJDIR)/%.o:$(PD_SRCDIR)/%.c $(PD_OBJDIR)
	$(CC) -o $@ -c $< $(PD_FLAG) $(PD_INC)

$(PD_OBJDIR):
	@-mkdir $@

#app
APP_OBJDIR := $(OBJDIR)/$(APP)
APP_SRCDIR := $(SRCDIR)/$(APP)
APP_BIN := $(BINDIR)/$(APP)

APP_FLAG := $(FLAG)
APP_LINK := $(LINK) -fstack-protector-strong

APP_SRC += $(wildcard $(APP_SRCDIR)/*.c)
APP_OBJ += $(addprefix $(APP_OBJDIR)/,$(notdir $(APP_SRC:.c=.o)))
APP_INC += $(INC)
APP_LIB += $(LIB) $(LIB_CJSON)

$(APP):$(APP_BIN)
ifdef TERMUX
	termux-elf-cleaner $^
endif

$(APP_BIN): $(PD_OBJ) $(APP_OBJ)
	$(CC) -o $@  $^ $(APP_LIB) $(APP_LINK) $(APP_INC)

$(APP_OBJDIR)/%.o:$(APP_SRCDIR)/%.c $(APP_OBJDIR)
	$(CC) -o $@ -c $< $(APP_FLAG) $(APP_INC)

$(APP_OBJDIR):
	@-mkdir $@

#--------------------------------------------------------------------

#mkdir 1
$(OBJDIR):
	@-mkdir $@
$(BINDIR):
	@-mkdir $@
$(INCDIR):
	@-mkdir $@
$(LIBDIR):
	@-mkdir $@

#--------------------------------------------------------------------

.PHONY:clean t x
t:$(TARDIR)
	rm -rf $(TARTAG)
	tar -czf $(TARTAG) makefile $(SRCDIR) $(INCDIR) $(LIBDIR)
$(TARDIR):
	mkdir $@
x:$(TARTAG)
	tar -xzf $(TARTAG)
clean:
	rm -rf $(TARGET) $(OBJDIR) $(BINDIR)