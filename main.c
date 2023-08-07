#include "header.h"

int main(int argc, char *argv[]){
    // check that at least 2 files are passed
    if (argc < 3){
	printf("Pass two file names\n");
	return 0;
    }

    // local variables
    struct courseStruct courseInfo[NUMBER_COURSES];
    struct profStruct profInfo [NUMBER_PROFS];
    int task2 = 0, task3 = 0, choice = 0, n = 0, courseID = 0;
    char profsNCourses [NUMBER_PROFS][MAX_STR];
    char courseName[MAX_STR];

    /***		TASK 2			***/
    // courses.txt is first line command
    task2 = readCourse(argv[1], courseInfo);
    if (task2 == 1){
	printf("Course information has been successfully saved using %s\n", argv[1]);
    }

    /***		TASK 3			***/
    // data.txt is second line command
    task3 = readProfAndCoursesTaught(argv[2], profInfo, courseInfo);
    if (task3 == 1){
	printf("Professor information has been successfully saved using %s\n", argv[2]);
    }

    /***		TASKS 4 - 8		***/
    // display menu
    printf("\n1. Populate an array with names of all professors who teach n or more courses");
    printf("\n2. Search for the course name with the course number");
    printf("\n3. Search for the course number with the course name");
    printf("\n4. Search what professors teach a specific course ID");
    printf("\n5. Get the average number of courses taught by a professor");

    // ask user for choice
    printf("\nChoose from the above choices: ");
    scanf("%d", &choice);

    while (choice >= 1 && choice <= 5) {
        switch (choice) {
	    /***		TASK 4		***/
            case 1:
		// ask user for n
                printf("Enter the minimum number of courses: ");
                scanf("%d", &n);
                printf("Number of professors teaching %d or more courses: %d", n, nCourses(n, profInfo, profsNCourses));
                break;
	    /***		TASK 5		***/
	    case 2:
		printf("Enter the course number of the course you want to know the name for: ");
		scanf("%d", &courseID);
		char cNameFound[MAX_STR];
		if (getCourseName(courseID, cNameFound, courseInfo) == 1){
		    printf("%s is the course with the course ID %d", cNameFound, courseID);
		}
		else{
		    printf("There is no course corresponding to %d", courseID);
		}
		break;
	    case 3:
		printf("Enter the name course of the course you want to know the ID for: ");
		// gets input until \n character is read
		scanf(" %[^\n]s", courseName);
		int cNumFound;
		if (getCourseNum(courseName, &cNumFound, courseInfo) == 1){
		    printf("%d is the course ID with the course name %s", cNumFound, courseName);
		}
		else{
		    printf("There is no course corresponding to %s", courseName);
		}
		break;
	    case 4:
		printf("Enter the course number you want to search for: ");
		scanf("%d", &courseID);
		char taughtBy[NUMBER_PROFS][MAX_STR];
		int totalProfsTeaching = profsTeachingCourse(courseID, profInfo, taughtBy);
		if (totalProfsTeaching != 0){
		    printf("%d professors are teaching %d", totalProfsTeaching, courseID);
		    printf("\nThe following professors are teaching %d:", courseID);
		    for (int i = 0; i < totalProfsTeaching; i++){
			printf("\n%s", taughtBy[i]);
		    }
		}
		break;
	    case 5:
		printf("The average number of courses taught by a professor is %.1f", avgNumCourses(profInfo));
		break;
    }
        // display menu again
        printf("\n\n\n1. Populate an array with names of all professors who teach n or more courses");
        printf("\n2. Search for the course name with the course number");
        printf("\n3. Search for the course number with the course name");
        printf("\n4. Search what professors teach a specific course ID");
        printf("\n5. Get the average number of courses taught by a professor");

        printf("\nIf you want to continue, choose from the above choices again, else enter another number: ");
        scanf("%d", &choice);
    }


    return 0;
}
