# CSCI5801 Project2 makefile

CC = g++
CFLAGS = -c -w
LFLAGS =
BUILDDIR = build
SRCDIR = src
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj/src
EXEFILE = elect.out
CXXTEST = ./cxxtest/bin/cxxtestgen --error-printer -o
CXXCOMPILE = g++ -I./cxxtest -o
TESTDIR = testing

# The list of files to compile for this project.  Defaults to all
# of the .cpp and .cc files in the source directory.  (We use both .cpp
# and .cc in order to support two different popular naming conventions.)
SRCFILES = $(wildcard $(SRCDIR)/*.cc)

# For each of the source files found above, replace .cpp (or .cc) with
# .o in order to generate the list of .o files make should create.
OBJFILES = $(notdir $(patsubst %.cc,%.o,$(SRCFILES)))

all: $(EXEFILE)
	make Ballot_tests
	make BallotList_tests
	make Candidate_tests
	make CandidateList_tests
	make Election_tests
	make Plurality_tests
	make STV_tests

run-tests: Ballot_tests BallotList_tests Candidate_tests CandidateList_tests Election_tests Plurality_tests STV_tests
	./Ballot_tests.out
	./BallotList_tests.out
	./Candidate_tests.out
	./CandidateList_tests.out
	./Election_tests.out
	./Plurality_tests.out
	./STV_tests.out

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
	$(CXXCOMPILE) Candidate_tests.out $(TESTDIR)/Candidate_tests.cpp $(OBJDIR)/Candidate.o $(OBJDIR)/BallotList.o $(OBJDIR)/Ballot.o

$(TESTDIR)/Candidate_tests.cpp:
	$(CXXTEST) $(TESTDIR)/Candidate_tests.cpp $(TESTDIR)/Candidate_tests.h

CandidateList_tests: $(TESTDIR)/CandidateList_tests.cpp
	$(CXXCOMPILE) CandidateList_tests.out $(TESTDIR)/CandidateList_tests.cpp $(OBJDIR)/Candidate.o $(OBJDIR)/CandidateList.o $(OBJDIR)/BallotList.o $(OBJDIR)/Ballot.o

$(TESTDIR)/CandidateList_tests.cpp:
	$(CXXTEST) $(TESTDIR)/CandidateList_tests.cpp $(TESTDIR)/CandidateList_tests.h

Election_tests: $(TESTDIR)/Election_tests.cpp
	$(CXXCOMPILE) Election_tests.out $(TESTDIR)/Election_tests.cpp $(OBJDIR)/Candidate.o $(OBJDIR)/CandidateList.o $(OBJDIR)/BallotList.o $(OBJDIR)/Ballot.o $(OBJDIR)/Election.o

$(TESTDIR)/Election_tests.cpp:
	$(CXXTEST) $(TESTDIR)/Election_tests.cpp $(TESTDIR)/Election_tests.h

Plurality_tests: $(TESTDIR)/Plurality_tests.cpp
	$(CXXCOMPILE) Plurality_tests.out $(TESTDIR)/Plurality_tests.cpp $(OBJDIR)/Candidate.o $(OBJDIR)/CandidateList.o $(OBJDIR)/BallotList.o $(OBJDIR)/Ballot.o $(OBJDIR)/Election.o $(OBJDIR)/Plurality.o

$(TESTDIR)/Plurality_tests.cpp:
	$(CXXTEST) $(TESTDIR)/Plurality_tests.cpp $(TESTDIR)/Plurality_tests.h

STV_tests: $(TESTDIR)/STV_tests.cpp
	$(CXXCOMPILE) STV_tests.out $(TESTDIR)/STV_tests.cpp $(OBJDIR)/Candidate.o $(OBJDIR)/CandidateList.o $(OBJDIR)/BallotList.o $(OBJDIR)/Ballot.o $(OBJDIR)/Election.o $(OBJDIR)/STV.o

$(TESTDIR)/STV_tests.cpp:
	$(CXXTEST) $(TESTDIR)/STV_tests.cpp $(TESTDIR)/STV_tests.h

$(EXEFILE): $(addprefix $(OBJDIR)/, $(OBJFILES)) | $(BINDIR)
	$(CXX) $(LDFLAGS) $(addprefix $(OBJDIR)/, $(OBJFILES)) -o $@
