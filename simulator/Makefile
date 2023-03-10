.SUFFIXES:
.SUFFIXES: .cc .cpp .o .x

CC := g++
OPT =
DEBUG = 
OTHER := -Wall -O3

# Use this CFLAGS definition if you need to see debug output
# CFLAGS = -c -g -Wno-deprecated -Wall -D_DEBUG
CFLAGS := -c -g -Wno-deprecated 

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR := src
INCDIR := inc
BUILDDIR := obj
TARGETDIR := bin
SRCEXT := cpp
OBJEXT := o

MODULE := run

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(SOURCES:$(SRCDIR)/%.$(SRCEXT)=$(BUILDDIR)/%.$(OBJEXT))

# include Makefile.defs
INCDIR = -I./inc -I./src \
		 -I$(AMS_HOME)/src \
		 -I$(SYSTEMC_HOME)/include \
		 -I$(SYSTEMC_HOME)/src/sysc/libs \
		 -I$(SYSTEMC_HOME)/src/sysc/kernel

EXE := $(MODULE).x

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@echo "Compiling source $< into object $@"
	@mkdir -p '$(@D)'
	$(GCC_PATH)$(CC) $(CFLAGS) $(INCDIR) $< -o $@

$(TARGETDIR)/$(EXE): $(OBJECTS)
	@echo "Building $@ from $<"
	@mkdir -p '$(@D)'
	$(GCC_PATH)$(CC) -g $(INCDIR) -o $@ $(OBJECTS) \
	$(AMS_HOME)/lib-linux64/libsystemc-ams.a \
	$(SYSTEMC_HOME)/lib-linux64/libsystemc.a -lpthread 2>&1 | c++filt 

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(TARGETDIR)
	rm -rf codegen/__pycache__

ultraclean: clean
	rm -f Makefile.deps

Makefile.deps:
	$(GCC_PATH)$(CC) $(CFLAGS) $(INCDIR) -M $(SOURCES) $(SRCS_BUS) >> Makefile.deps

# include Makefile.deps
