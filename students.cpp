/*
 * students.cpp
 * Purpose: Takes in a student ID and print outs the student's information.
 
 * Author: Kevin Nguyen
 * Credits: n/a
 * Note: Program gives segmentation fault if invalid ID is entered
 * Date: 3/16/21
 */

#include <iostream>
#include <string>

using namespace std;

// declare the Student struct
struct Student {
    int    id;
    string firstName;
    char   lastInitial;
    float  gpa; 
};

const int TOTAL_STUDENTS = 10;


// Function Prototypes
int  find_student(int id, Student students[], int num_students);
void print_student(int index, Student students[]);

/*
 * main function tests the string_to_int function
 */
int main() {

    // declare and initialize array of 
    // student structs of size TOTAL_STUDENTS
    Student students [TOTAL_STUDENTS] = 
    {
        {268, "Dana",     'J', 4.0},
        {123, "Rachel",   'G', 3.42},
        {126, "Sam",      'B', 3.8},
        {431, "Keisha",   'M', 3.9},
        {231, "Joe",      'W', 2.7},
        {272, "Isabella", 'U', 3.73},
        {112, "Sook-Hee", 'E', 3.54},
        {289, "Molly",    'C', 3.6},
        {345, "Talia",    'K', 3.63},
        {228, "Jackson",  'P', 3.33}
    };
    
    int input;
    cin >> input;
    
    print_student(find_student(input, students, TOTAL_STUDENTS), students);
    return 0;
}

/* find_student
 * Parameters: ID number of student to be found, array of Students to search,
 the length of that array
 * Purpose: Finds the student whose ID was passed into the function
 * Returns: Returns the array index of the found student. If student not found,
 returns -1.
 */
int  find_student(int id, Student students[], int num_students)
{
    int output = -1;
    
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].id == id)
        {
            return i;
        }
    }
    
    return output;
}

/* print_student
 * Parameters: Given index of a student and the array of students
 * Purpose: It prints student's name and GPA using given student index
 * Returns: Nothing. 
 * Note: Prints out student's name and last name initial and GPA.
 */
void print_student(int index, Student students[])
{
    cout << "Name: " << students[index].firstName << " " 
    << students[index].lastInitial << endl;
    
    cout << "GPA: " << students[index].gpa << endl;
}
