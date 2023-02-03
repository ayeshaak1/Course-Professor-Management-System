#include "givenA1.h"

/* Task 1
 *
 * Take fileName as a string
 * Open file to read contents
 */
FILE *openFileForReading(char fileName [MAX_STR]){
    // open file for reading
    FILE *fptr = fopen(fileName, "r");

    // check if file exists
    if (fptr == NULL){
        return NULL;
    }
    else{
	return fptr;
    }
}

/* Task 2
 *
 * Takes fileName as a string, array of struct courseInfo
 * Populates the array with the correspending course ids from courses.txt
 */
int readCourse (char filename [MAX_STR],
                struct courseStruct courseInfo [NUMBER_COURSES]
                ){
    // local variables
    int numLines = 0, id = 0;
    FILE *fptr = openFileForReading(filename);
    char temp[MAX_STR];

    if (fptr == NULL){
	printf("Null file pointer\n");
        return -1;
    }

    //count number of lines in the file
    while (fgets(temp, MAX_STR, fptr) != NULL){
        numLines++;
    }

    // numLines < 2x NUMBER_COURSES
    if (numLines < (2 * NUMBER_COURSES)) {
        printf("File passed has less lines than two times NUMBER_COURSES\n");
        return -1;
    }
    // numLines > 2x NUMBER_COURSES
    else if (numLines > (2 * NUMBER_COURSES)) {
        printf("File passed has more lines than two times NUMBER_COURSES\n");
        return -1;
    }
    // populate array
    else{
	// reset the variable to read each fptr line
        numLines = 0;

        // go back to the beginning of the file
        rewind(fptr);

        while (fgets(temp, MAX_STR, fptr) != NULL) {
            int len = strlen(temp);

            // remove newline character
            if (temp[len - 1] == '\n') {
                temp[len - 1] = '\0';
            }

            // copy courseName
            if (numLines < NUMBER_COURSES) {
                strcpy(courseInfo[numLines].courseName, temp);
            }
            else {
		// convert char to int for courseID
                sscanf(temp, "%d", &id);
		// store courseID
                courseInfo[numLines - NUMBER_COURSES].courseID = id;
            }
	    // increment numLines
            numLines++;
        }

        fclose(fptr);
        return 1;
    }
}

/* Task 3
 *
 * Take profInfo and courseInfo as struct arrays
 * Populate profInfo using the file and courseInfo provided
 */
int readProfAndCoursesTaught (char filename [MAX_STR],
                               struct profStruct profInfo [NUMBER_PROFS],
                              struct courseStruct courseInfo [NUMBER_COURSES]
                               ){
    FILE *fptr = openFileForReading(filename);
    char temp;

    // check for !null file
    if (fptr == NULL) {
        printf("Null file pointer\n");
	fclose(fptr);
	return -1;
    }
    // scan profs' names from file
    for (int i = 0; i < NUMBER_PROFS; i++) {
      fscanf(fptr, "%s", profInfo[i].profName);
    }

    // check course info
    for (int i = 0; i < NUMBER_PROFS; i++) {
        for (int j = 0; j < NUMBER_COURSES; j++) {
	    fscanf(fptr, " %c", &temp);
 	    if (tolower(temp) == 'y') {
		profInfo[i].coursesTaught[j] = courseInfo[j].courseID;
            }
	    else{
		profInfo[i].coursesTaught[j] = 0;
	    }
        }
    }

    fclose(fptr);
    return 1;
}


/* Task 4
 *
 * Populate profsNCourses with professors' names who teach n or more courses
 * Return the total number of professors who teach n or more courses
 */
int nCourses (int n,
              struct profStruct profInfo [NUMBER_PROFS],
              char profsNCourses [NUMBER_PROFS][MAX_STR]
              ){
    // local variables
    int numProfs = 0, numCourses = 0;

    // calculate how many courses a professor teaches
    for (int i = 0; i < NUMBER_PROFS; i++) {
	// reset numCourses for each prof
	numCourses = 0;
        for (int j = 0; j < NUMBER_COURSES; j++) {
	    // increment coursesTaught for each prof if coursesTaught[] element isn't NULL
            if (profInfo[i].coursesTaught[j] != 0) {
                numCourses = numCourses + 1;
            }
        }

	// increment numProfs if the coursesTaught variable >= n and add profs name to array
        if (numCourses >= n) {
            strcpy(profsNCourses[i], profInfo[i].profName);
            numProfs = numProfs + 1;
        }
    }

    // return the number of professors who teach n or more courses
    return numProfs;
}

/* Task 5
 *
 * Takes course ID
 * Finds and saves corresponding course name
 */
int getCourseName (int courseNum,
                   char cNameFound [50],
                   struct courseStruct courseInfo [NUMBER_COURSES]
                   ){

    // check through the entire array
    for (int i = 0; i < NUMBER_COURSES; i++) {
        if (courseInfo[i].courseID == courseNum) {
            // if course number matches what user input, set cNameFound to the course name
            strcpy(cNameFound, courseInfo[i].courseName);
            return 1;
        }
    }
    // if unable to find courseNum
    return 0;

}

/* Task 6
 *
 * Takes course name
 * Finds and saves corresponding course ID
 */
int getCourseNum (char cName [50],
                  int * cNumFound,
                  struct courseStruct courseInfo [NUMBER_COURSES]
                  ){
    cName = removeSpaces(cName);

    for (int i = 0; i < NUMBER_COURSES; i++){
	strcpy(courseInfo[i].courseName, removeSpaces(courseInfo[i].courseName));
    }
/*    // repeat removing spaces for the array
    for (int i = 0; i < NUMBER_COURSES; i++){
	for (int j = 0; j < MAX_STR; j++){
	    if(courseInfo[i].courseName[j] == ' '){
	        strcpy(courseInfo[i].courseName[j], '\0');
	    }
	}
    }
*/
    for (int i = 0; i < NUMBER_COURSES; i++) {
//        printf("\ncName: %s, courseName: %s", cName, courseInfo[i].courseName);
	if (strcmp(cName, courseInfo[i].courseName) == 0) {
	    // save the course ID to the address of cNumFound
            *cNumFound = courseInfo[i].courseID;
            return 1;
        }
    }
    // if no corresponding course ID is found
    return 0;
}

/* Task 7
 *
 *
 */
int profsTeachingCourse (int courseNum,
                         struct profStruct profInfo [NUMBER_PROFS],
                         char taughtBy [NUMBER_PROFS][MAX_STR]
                         ){
    // local var
    int numProfs = 0;

    // check each course for every prof
    for (int i = 0; i < NUMBER_PROFS; i++) {
	for (int j = 0; j < NUMBER_COURSES; j++){
	    // if prof teaches courseNum, add prof to taughtBy and increment numProfs
            if (profInfo[i].coursesTaught[j] == courseNum) {
                strcpy(taughtBy[numProfs], profInfo[i].profName);
                numProfs++;
	    }
        }
    }

    // return the total number of profs who teach courseNum
    return numProfs;
}
/* Task 8
 *
 *
 */
float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]){

    // local var
    int totalCoursesTaught = 0, numProfs = 0, numCoursesTaught = 0;
    float average = 0;

    for (int i = 0; i < NUMBER_PROFS; i++){
	// reset var for each prof
	numCoursesTaught = 0;
	for (int j = 0; j < NUMBER_COURSES; j++){
	    // if coursesTaught[j] is not 0, professor teaches that course so, increment var
	    if (profInfo[i].coursesTaught[j] != 0){
		numCoursesTaught++;
	    }
	}

	// add the number of courses current prof teaches to totalCourses
	totalCoursesTaught += numCoursesTaught;
	numProfs++;
    }

    // calculate average as a float
    average = (float)totalCoursesTaught/numProfs;

    // round up and return average
    average = roundUp(average);
    return average;
}


/* Helper Function
 *
 * Takes a string
 * Removes any spaces in the string
 */
char *removeSpaces(char *str) {
  int j = 0;
  char *stringWithNoSpaces = (char*)malloc((strlen(str)) + 1);

    for (int i = 0; i < strlen(str); i++) {
	// if there is a space, don't add it
        if (str[i] != ' ') {
            stringWithNoSpaces[j++] = str[i];
        }
    }

    // avoid \n
    stringWithNoSpaces[j] = '\0';

    return stringWithNoSpaces;
}

/* Helper Function
 *
 * Take a float number as input
 * Return a float number that has been rounded up
 */
float roundUp(float number){
    // add 0.5 so that the number >= 0.5 then convert to int and conert it back to float
    return (float)((int)(number + 0.5));
}
