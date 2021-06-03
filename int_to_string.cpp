/*
 * int_to_string.cpp
 * Purpose: Program to test the int_to_string function, whose contract appears 
 * below
 * Essential idea:  Given an integer, like 87, return the string
 * consisting of the same digits, i. e., "87".
 *
 * By: Kevin Nguyen
 */

#include <iostream>

using namespace std;

string int_to_string(int num);

char convert(int num);
string reverse(string input, bool negative);
void test(int input, string solution);

/*
 * main function tests the int_to_string function
 */
int main()
{
    test(-42069, "-42069");
    test(420, "420");
    test(-69, "-69");
    test(0, "0");
    return 0;
}

/* int_to_string
 * Parameters: Any integer
 * Purpose: Turns a type integer into a string with the same digits
 * Returns: A string with the same digits as the original integer input
 */
string int_to_string(int num)
{
    string output;
    bool negative = false;
    
    if (num == 0)
    {
        return "0";
    }
    if (num < 0)
    {
        negative = true;
        num *= -1;
    }
    
    // Core of function. Concatenates all the chars from convert into a string
    while (num > 0)
    {
        output += convert(num);
        num = (num - (num % 10)) / 10;
    }
    
    return reverse(output, negative);
}

/* convert
 * Parameters: Any integer
 * Purpose: Turns the last digit in an integer into a char
 * Returns: The last digit of an int as type char
 */
char convert(int num) // use modulus
{
    int digit = num % 10;
    char output = digit + 48;
    return output;
}

/* reverse
 * Parameters: A string of numbers and a boolean value
 * Purpose: Reverses the order of a string with all numbers
 * Returns: A string with the same digits as the input, but in reverse order
 * Note: Adds a negative sign at beginning of string if the original input from 
 int_to_string is negative
 */
string reverse(string input, bool negative)
{
    string output;
    
    if (negative)
    {
        output += "-";
    }
    
    for (size_t i = input.length(); i > 0; i--)
    {
        output += input[i-1];
    }
    
    return output;
}

/* test
 * Parameters: String that may or may not contain digit characters ('0' -- '9')
 and what the solution output should be
 * Purpose: Tests to see if string_to_int is working correctly
 * Returns: Whether string_to_int succeeded or failed and string_to_int output
 * Note: Also prints out TESTING: followed by the input
 */
void test(int input, string solution)
{
    cout << "TESTING: " << input << endl;
    
    if (int_to_string(input) == solution)
    {
        cout << "SUCCESS: " << int_to_string(input) << endl;
    }
    else
    {
        cout << "FAILURE: " << int_to_string(input) << endl;
    }
}