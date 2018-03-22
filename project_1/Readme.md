## Team 13 Voting System Project

This repo contains the Voting System Project done by Team 13.

### Compiling and Running System

To compile the file open a terminal and make sure that you are inside the project folder
```
umn-csci-5801-S18/repo-Team13/project_1
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
You will then be prompted to type in the number of candidates in the election, the number of seats, ballots, the voting type to run the election on and the name of the CSV file that contains all the ballots.

The algorithm will then run through the respective voting algorithm and display all the results in **log.txt** inside the project file.

**NOTE:**
The number of winners may not be the same of the number of seats if Droop is too high and candidates never reach it. This is documented more in the bug report.

## Shuffling of Ballots

STV works by first shuffling the initial ballots. To turn this off, simply comment out
```
get_ballots().ShuffleBallots();
```
which should be in line 85 of STV.cc in `src`.

### Running Unit Tests

Typing `make all` created both **elect.out** and also all the Unit Tests executable. To run all these unit tests simultaneously, type in:
```
make run-tests
```
This will run all the tests and output the results on Terminal

### Doxygen

All Doxygen related files are inside the `docs` directory. This includes the **doxyfile** and **index.html** which is in `docs/html`

**ALL FILES SHOULD ALREADY EXIST IN THE DOCS FILE, BUT JUST IN CASE SOMETHING HAPPENS:**

From the project file, typing in `doxygen docs/doxyfile` will create all the html files for the project and opening **index.html** will direct you to the mainpage of the Doxygen documentation.
