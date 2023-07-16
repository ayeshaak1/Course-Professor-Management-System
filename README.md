# Course Professor Management System

This repository contains a C program that implements a Course Professor Management System. The program allows users to manage and query data related to courses and professors. It provides functionalities to read course information from one file and professor information from another file, store the data in appropriate data structures, and perform various operations on the data.

## Getting Started

### Prerequisites

To compile and run the program, you need to have the following installed on your system:

- C Compiler (e.g., GCC)

### Compilation

Use the following command to compile the program:

```bash
gcc -o course_prof_management main.c givenA1.c -lm

*Running the Program*
To run the program, execute the compiled binary with the filenames of the course and professor data files as command-line arguments:
./course_prof_management courses.txt data.txt

Replace courses.txt and data.txt with the appropriate filenames containing course and professor information, respectively.


**FEATURES**
The Course Professor Management System provides the following features:

Populating an array with names of all professors who teach n or more courses.
Searching for the course name using the course number.
Searching for the course number using the course name.
Searching for professors who teach a specific course ID.
Getting the average number of courses taught by a professor.


**USAGE**
Upon running the program, you will be presented with a menu displaying the available options. Enter the corresponding number to select the desired operation.

To find professors who teach n or more courses, choose option 1 and input the minimum number of courses.
To search for a course name using its course number, choose option 2 and input the course number.
To search for a course number using its name, choose option 3 and input the course name.
To find professors teaching a specific course ID, choose option 4 and input the course number.
To get the average number of courses taught by a professor, choose option 5.
The program will continue displaying the menu after each operation, allowing you to perform multiple queries.

**DATA FILE FORMAT**
The program reads course and professor information from text files in a specific format:

*Courses File (courses.txt)*
The courses file should contain one course per line, with the following format:
CourseID CourseName
Example:
1001 Introduction to Computer Science
1002 Data Structures and Algorithms
Professor Data File (data.txt)
The professor data file should contain one professor's information per line, with the following format:
ProfessorID ProfessorName CourseID1 CourseID2 ... CourseIDN
Example:
1 John Smith 1001 1002
2 Jane Doe 1001 1003
