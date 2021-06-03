/*
 * string_converter.cpp
 * Program to test the string_to_int function, whose contract appears below
 * Essential idea:  extract digits from a string and return the integer that
 *                  results.  E. g., "a1b2c3" should produce the integer 123
 *
 * By: Kevin Nguyen
 * Date: 3/16/21
 */

#include <iostream>

using namespace std;

int string_to_int(string s);

// TODO:  Add any extra function prototypes you like here
string filter(string input); 
void test(string input, int solution);

/*
 * main function tests the string_to_int function
 */
int main()
{
    test("123ab6", 1236);
    test("comp11issoc00L", 1100);
    test("ericmetajisgr8", 8);
    test("cann0L15", 15);
    test("hi", 0);
    
    return 0;
}

/*
 * Purpose:   extract an integer from the digit characters in a string
 * Arg:       string that may or may not contain digit characters ('0' -- '9')
 * Returns:   the integer that result from extracting digits from string s
 * Notes:     only digit characters are considered.  
 *            Sign characters ('+', '-') are non-digits and are ignored
 * Examples:  "123abc56"   => 12356
 *            "   2times3" => 23
 *            "help me!"   => 0
 *            ""           => 0
 */
int string_to_int(string s)
{
    int place = 1;
    int sum = 0;
    string nums = filter(s);
    
    for (size_t i = nums.length(); i > 0; i--)
    {
        sum += (nums[i-1] - 48) * place;
        place *= 10;
    }
    
    return sum;
}

/* filter
 * Parameters: The user's raw input
 * Purpose: Concatenates all the ints from the input string into one output 
 string
 * Returns: A string with only the numbers from the input
 */
string filter(string input)
{
    string output;
    
    for (size_t i = 0; i < input.length(); i++)
    {
        if ((input[i] >= 48) && (input[i] <= 57))
        {
            output += input[i];
        }
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
void test(string input, int solution)
{
    cout << "TESTING: " << input << endl;
    
    if (string_to_int(input) == solution)
    {
        cout << "SUCCESS: " << string_to_int(input) << endl;
    }
    else
    {
        cout << "FAILURE: " << string_to_int(input) << endl;
    }
}