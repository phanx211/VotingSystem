## Team 13 Voting System Project Agile Functionality

This repo contains the Voting System Project done by Team 13 as well as functionality added by Agile Scrum methods.

### Compiling and Running System

To compile the file open a terminal and make sure that you are inside the project folder
```
umn-csci-5801-S18/repo-Team13/Project2
```
Then, you can simply type the following in a Terminal:
```
make all
```
This will create all files which include an executable file **elect.out** and all the test files.

**NOTE:**
We decided to put the makefile in the project folder instead of the src folder as it makes it simpler to link both testing and source compilation from a single command.

To launch the Voting System, type in:
```
./elect.out
```
You will then be prompted to type in the path and name of the CSV file which will be processed. Alternatively, you can type in:
```
./elect.out path/to/filename.csv
```
This will run the election automatically, with output being written to logFile.txt as well as Audit.txt in accordance with the PBI described in product_backlogs/InitialProductBacklog.docx.

The algorithm will then run through the respective voting algorithm and display all the results in **log.txt** inside the project file.

**NOTE:**
The number of winners may not be the same of the number of seats if Droop is too high and candidates never reach it. This is documented more in the bug report.

## Shuffling of Ballots

STV works by first shuffling the initial ballots. To turn this off, simply comment out
```
get_ballots().ShuffleBallots();
```
which should be in line 128 of STV.cc in `src`.

### Running Unit Tests

Typing `make all` created both **elect.out** and also all the Unit Tests executable. To run all these unit tests simultaneously, type in:
```
make run-tests
```
This will run all the tests and output the results on Terminal.
**NOTE:** In addition to the unit tests written for Project 1, additional tests were included in BallotList_tests.h, Ballot_tests.h, and Election_tests.h in `testing` to cover new functionality needed for the Scrum PBI's.

### Doxygen

All Doxygen related files are inside the `docs` directory. This includes the **doxyfile** and **index.html** which is in `docs/html`

**ALL FILES SHOULD ALREADY EXIST IN THE DOCS FILE, BUT JUST IN CASE SOMETHING HAPPENS:**

From the project file, typing in `doxygen docs/doxyfile` will create all the html files for the project and opening **index.html** will direct you to the mainpage of the Doxygen documentation.
