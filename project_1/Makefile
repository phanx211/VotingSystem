# CSCI5801 Project1 makefile

CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall
BUILDDIR = build
SRCDIR = src
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj/src
EXEFILE = elect.out
CXXTEST = ./cxxtest/bin/cxxtestgen --error-printer -o
CXXCOMPILE = g++ -I./cxxtest -o
TESTDIR = tests

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
	@rm -rf *.out
	@rm -rf $(TESTDIR)/*.cpp

$(OBJDIR) $(BINDIR):
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@echo "==== Compiling $< into $@. ===="
	$(CC) $(CFLAGS) -o  $@ $<

# Copy these two commands and change all the "Ballot_tests" to the test filename
Ballot_tests: $(TESTDIR)/Ballot_tests.cpp
	$(CXXCOMPILE) Ballot_tests.out $(TESTDIR)/Ballot_tests.cpp $(OBJDIR)/Ballot.o

$(TESTDIR)/Ballot_tests.cpp:
	$(CXXTEST) $(TESTDIR)/Ballot_tests.cpp $(TESTDIR)/Ballot_tests.h

BallotList_tests: $(TESTDIR)/BallotList_tests.cpp
	$(CXXCOMPILE) BallotList_tests.out $(TESTDIR)/BallotList_tests.cpp $(OBJDIR)/Ballot.o $(OBJDIR)/BallotList.o

$(TESTDIR)/BallotList_tests.cpp:
	$(CXXTEST) $(TESTDIR)/BallotList_tests.cpp $(TESTDIR)/BallotList_tests.h

Candidate_tests: $(TESTDIR)/Candidate_tests.cpp
	$(CXXCOMPILE) Candidate_tests.out $(TESTDIR)/Candidate_tests.cpp $(OBJDIR)/Candidate.o

$(TESTDIR)/Candidate_tests.cpp:
	$(CXXTEST) $(TESTDIR)/Candidate_tests.cpp $(TESTDIR)/Candidate_tests.h


$(EXEFILE): $(addprefix $(OBJDIR)/, $(OBJFILES)) | $(BINDIR)
	$(CXX) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) -o $@
