#directory
PWD = .
LIBPATH = .
SRCDIR = $(PWD)/src
INCDIR = $(PWD)/inc
OBJDIR = $(PWD)/obj
LIBDIR = $(PWD)/lib
BINDIR = $(PWD)/bin
TARDIR = $(PWD)/tar
ALLDIR = $(SRCDIR) $(INCDIR) $(OBJDIR) $(LIBDIR) $(BINDIR) 

#--------------------------------------------------------------------

#TERMUX = 1

#--------------------------------------------------------------------

#target
#tar
TARTAG = $(TARDIR)/all.tgz
#bin
CJSON = cjson
APP = smf
PD = smf_pd
TERMUX_API = termux_api
TERMUX_TEST = termux_test
TERMUX_PD = termux_pd
TARGET = $(CJSON) $(PD) $(TERMUX_API) $(TERMUX_TEST) $(TERMUX_PD) $(APP)

#--------------------------------------------------------------------

#compiler
CC = gcc
AR = ar

#flag
FLAG = -O3 -Wall -Werror
LINK = -O3 -Wall -Werror

SRC = $(wildcard $(SRCDIR)/*.c)

#include
INC = -I $(INCDIR)

#library
LIB = $(wildcard $(LIBDIR)/*.a)

all: $(ALLDIR) $(TARGET)

#--------------------------------------------------------------------

#cJSON
CJSON_OBJDIR := $(OBJDIR)/$(CJSON)
CJSON_SRCDIR := $(SRCDIR)/$(CJSON)
CJSON_LIBDIR := $(LIBDIR)/$(CJSON)

CJSON_FLAG := $(FLAG) -std=c89 -fstack-protector-all -fPIC -pedantic -Werror -Wstrict-prototypes -Wwrite-strings -Wshadow -Winit-self -Wcast-align -Wformat=2 -Wmissing-prototypes -Wstrict-overflow=2 -Wcast-qual -Wc++-compat -Wundef -Wswitch-default -Wconversion

CJSON_SRC += $(wildcard $(CJSON_SRCDIR)/*.c)
CJSON_OBJ += $(addprefix $(CJSON_OBJDIR)/,$(notdir $(CJSON_SRC:.c=.o)))
CJSON_INC += $(INC)
CJSON_DEF += 
CJSON_STATIC = $(CJSON_LIBDIR)/libcjson.a

$(CJSON):$(CJSON_OBJ) $(CJSON_STATIC)

$(CJSON_STATIC): $(CJSON_OBJ) $(CJSON_LIBDIR)
	$(AR) -rcs $@ $(CJSON_OBJ)

$(CJSON_OBJDIR)/%.o:$(CJSON_SRCDIR)/%.c $(CJSON_OBJDIR)
	$(CC) -o $@ -c $< $(CJSON_DEF) $(CJSON_FLAG) $(CJSON_INC)

$(CJSON_OBJDIR):
	@-mkdir $@
$(CJSON_LIBDIR):
	@-mkdir $@

#pd
PD_OBJDIR := $(OBJDIR)/$(PD)
PD_SRCDIR := $(SRCDIR)/$(PD)
PD_LIBDIR := $(LIBDIR)/$(PD)

PD_FLAG := $(FLAG)

PD_SRC += $(wildcard $(PD_SRCDIR)/*.c)
PD_OBJ += $(addprefix $(PD_OBJDIR)/,$(notdir $(PD_SRC:.c=.o)))
PD_INC += $(INC)
PD_DEF += 
PD_STATIC = $(PD_LIBDIR)/libsmf_pd.a

$(PD):$(PD_OBJ) $(PD_STATIC)

$(PD_STATIC): $(PD_OBJ) $(PD_LIBDIR)
	$(AR) -rcs $@ $(PD_OBJ)

$(PD_OBJDIR)/%.o:$(PD_SRCDIR)/%.c $(PD_OBJDIR)
	$(CC) -o $@ -c $< $(PD_DEF) $(PD_FLAG) $(PD_INC)

$(PD_OBJDIR):
	@-mkdir $@
$(PD_LIBDIR):
	@-mkdir $@

#TERMUX_API
TERMUX_API_OBJDIR := $(OBJDIR)/$(TERMUX_API)
TERMUX_API_SRCDIR := $(SRCDIR)/$(TERMUX_API)
TERMUX_API_LIBDIR := $(LIBDIR)/$(TERMUX_API)

TERMUX_API_FLAG := $(FLAG)

TERMUX_API_SRC += $(wildcard $(TERMUX_API_SRCDIR)/*.c)
TERMUX_API_OBJ += $(addprefix $(TERMUX_API_OBJDIR)/,$(notdir $(TERMUX_API_SRC:.c=.o)))
TERMUX_API_INC += $(INC)

ifdef TERMUX_TEST_SHOW
TERMUX_API_DEF += -DCMD_SHOW
endif

TERMUX_API_STATIC = $(TERMUX_API_LIBDIR)/libtermux_api.a

$(TERMUX_API):$(TERMUX_API_OBJ) $(TERMUX_API_STATIC)

ifndef TERMUX_TEST_SHOW
$(TERMUX_API_STATIC): $(TERMUX_API_OBJ) $(TERMUX_API_LIBDIR)
	$(AR) -rcs $@ $(TERMUX_API_OBJ)
	rm -rf $(TERMUX_API_OBJ)
	make $(TERMUX_API) TERMUX_TEST_SHOW=1
endif

$(TERMUX_API_OBJDIR)/%.o:$(TERMUX_API_SRCDIR)/%.c $(TERMUX_API_OBJDIR)
	$(CC) -o $@ -c $< $(TERMUX_API_DEF) $(TERMUX_API_FLAG) $(TERMUX_API_INC)

$(TERMUX_API_OBJDIR):
	@-mkdir $@
$(TERMUX_API_LIBDIR):
	@-mkdir $@

#app
APP_OBJDIR := $(OBJDIR)/$(APP)
APP_SRCDIR := $(SRCDIR)/$(APP)
APP_BIN := $(BINDIR)/$(APP)

APP_FLAG := $(FLAG)
APP_LINK := $(LINK)
APP_LINK += -fstack-protector-all

APP_SRC += $(wildcard $(APP_SRCDIR)/*.c)
APP_OBJ += $(addprefix $(APP_OBJDIR)/,$(notdir $(APP_SRC:.c=.o)))
APP_INC += $(INC)
APP_DEF += 
APP_LIB += $(LIB) $(CJSON_OBJ)

$(APP):$(APP_BIN)
ifdef TERMUX
	-termux-elf-cleaner $^
endif

$(APP_BIN):$(APP_OBJ) $(PD_STATIC)
	$(CC) -o $@  $^ $(APP_LIB) $(APP_LINK) $(APP_INC)

$(APP_OBJDIR)/%.o:$(APP_SRCDIR)/%.c $(APP_OBJDIR)
	$(CC) -o $@ -c $< $(APP_DEF) $(APP_FLAG) $(APP_INC)

$(APP_OBJDIR):
	@-mkdir $@

#termux-test
TERMUX_TEST_OBJDIR := $(OBJDIR)/$(TERMUX_TEST)
TERMUX_TEST_SRCDIR := $(SRCDIR)/$(TERMUX_TEST)
TERMUX_TEST_BIN := $(BINDIR)/$(TERMUX_TEST)

TERMUX_TEST_FLAG := $(FLAG)
TERMUX_TEST_LINK := $(LINK)
TERMUX_TEST_LINK += -fstack-protector-all
TERMUX_TEST_SRC += $(wildcard $(TERMUX_TEST_SRCDIR)/*.c)
TERMUX_TEST_OBJ += $(addprefix $(TERMUX_TEST_OBJDIR)/,$(notdir $(TERMUX_TEST_SRC:.c=.o)))
TERMUX_TEST_INC += $(INC)
TERMUX_TEST_DEF += 
TERMUX_TEST_LIB += $(LIB)

$(TERMUX_TEST):$(TERMUX_TEST_BIN)
ifdef TERMUX
	-termux-elf-cleaner $^
endif

$(TERMUX_TEST_BIN): $(TERMUX_TEST_OBJ) $(TERMUX_API_OBJ)
	$(CC) -o $@  $^ $(TERMUX_TEST_LIB) $(TERMUX_TEST_LINK) $(TERMUX_TEST_INC)

$(TERMUX_TEST_OBJDIR)/%.o:$(TERMUX_TEST_SRCDIR)/%.c $(TERMUX_TEST_OBJDIR)
	$(CC) -o $@ -c $< $(TERMUX_TEST_FLAG) $(TERMUX_TEST_INC)

$(TERMUX_TEST_OBJDIR):
	@-mkdir $@

#termux_pd
TERMUX_PD_OBJDIR := $(OBJDIR)/$(TERMUX_PD)
TERMUX_PD_SRCDIR := $(SRCDIR)/$(TERMUX_PD)
TERMUX_PD_BIN := $(BINDIR)/$(TERMUX_PD)

TERMUX_PD_FLAG := $(FLAG)
TERMUX_PD_LINK := $(LINK)
TERMUX_PD_LINK += -fstack-protector-all

TERMUX_PD_SRC += $(wildcard $(TERMUX_PD_SRCDIR)/*.c)
TERMUX_PD_OBJ += $(addprefix $(TERMUX_PD_OBJDIR)/,$(notdir $(TERMUX_PD_SRC:.c=.o)))
TERMUX_PD_INC += $(INC)
TERMUX_PD_DEF += 
TERMUX_PD_LIB += $(LIB) $(CJSON_OBJ)

$(TERMUX_PD):$(TERMUX_PD_BIN)
ifdef TERMUX
	-termux-elf-cleaner $^
endif

$(TERMUX_PD_BIN): $(PD_OBJ) $(TERMUX_PD_OBJ) $(TERMUX_API_STATIC)
	$(CC) -o $@  $^ $(TERMUX_PD_LIB) $(TERMUX_PD_LINK) $(TERMUX_PD_INC)

$(TERMUX_PD_OBJDIR)/%.o:$(TERMUX_PD_SRCDIR)/%.c $(TERMUX_PD_OBJDIR)
	$(CC) -o $@ -c $< $(TERMUX_PD_DEF) $(TERMUX_PD_FLAG) $(TERMUX_PD_INC)

$(TERMUX_PD_OBJDIR):
	@-mkdir $@

#--------------------------------------------------------------------

#mkdir 1 dir
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
	tar -czf $(TARTAG) makefile $(SRCDIR) $(INCDIR) data 

$(TARDIR):
	mkdir $@
x:$(TARTAG)
	tar -xzf $(TARTAG)
clean:
	rm -rf $(OBJDIR) $(BINDIR) $(TARDIR)