# CSCI5801 Project1 makefile

CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
BUILDDIR = build
SRCDIR = src
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj/src
EXEFILE = elect.out

# The list of files to compile for this project.  Defaults to all
# of the .cpp and .cc files in the source directory.  (We use both .cpp
# and .cc in order to support two different popular naming conventions.)
SRCFILES = $(wildcard $(SRCDIR)/*.cc)

# For each of the source files found above, replace .cpp (or .cc) with
# .o in order to generate the list of .o files make should create.
OBJFILES = $(notdir $(patsubst %.cc,%.o,$(SRCFILES)))

all: $(EXEFILE)

clean:
	@rm -rf $(BUILDDIR)/obj/src/*.o
	@rm -rf $(EXEFILE)

$(OBJDIR) $(BINDIR):
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@echo "==== Compiling $< into $@. ===="
	$(CC) $(CFLAGS) -o  $@ $<

Ballot_tests: tests/Ballot_tests.cpp
	g++ -I./cxxtest -o Ballot_tests tests/Ballot_tests.cpp build/obj/src/Ballot.o

tests/Ballot_tests.cpp:
	./cxxtest/bin/cxxtestgen --error-printer -o tests/Ballot_tests.cpp tests/Ballot_tests.h





$(EXEFILE): $(addprefix $(OBJDIR)/, $(OBJFILES)) | $(BINDIR)
	$(CXX) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) -o $@
