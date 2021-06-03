/*
 * most_common_int.cpp
 * Purpose: Picks out the most common integer out of an array of integers.
 
 * Author: Kevin Nguyen
 * Credits: n/a
 * Note: Inputting anything into the program that isn't an array will cause the
 program to malfunction
 * Date: 3/16/21
 */

#include <iostream>

using namespace std;

int most_common_int(int numbers[], int length);
void test(int numbers[], int length, int solution);

/*
 * main function tests the most_common_int function
 */
int main()
{
    int test1[9] = {2, 2, 2, 2, 4, 4, 4, 4, 4};
    test(test1, 9, 4);
    
    int test2[7] = {2, 2, 3, 1, 1, 2, 2};
    test(test2, 7, 2);
    
    int test3[7] = {-2,-2, 1, 1, 1, -2, -2};
    test(test3, 7, -2);
    
    int test4[4] = {4, 20, 69, 42069};
    test(test4, 4, 4);
    return 0;
}

/* most_common_int
 * Parameters: Any array of numbers and the length of that array
 * Purpose: Picks out the most common integer out of an array of integers.
 * Returns: The most common integer in the inputted array
 */
int most_common_int(int numbers[], int length)
{
    int best[2] = {numbers[0], 0};
    
    for (int i = 0; i < length; i++)
    {
        int times = 0;
        
        // Tells us how many times the numbers[i] appears in the array
        for (int y = 0; y < length; y++)
        {
            if (numbers[i] == numbers[y])
            {
                times++;
            }
        }
        
        // Checks to see if the current number has a higher count than the 
        // previous one
        if ((times >= best[1]) && (best[0] >= numbers[i]))
        {
            best[0] = numbers[i];
            best[1] = times;
        }
    }
    
    return best[0];
}

/* test
 * Parameters: Any array of numbers, the length of that array, and what 
 most_common_int should output
 * Purpose: Tests to see if most_common_int.cpp is working correctly
 * Returns: Whether most_common_int succeeded/failed and most_common_int output
 * Note: Also prints out TESTING: followed by the array of numbers
 */
void test(int numbers[], int length, int solution)
{
    cout << "TESTING: {";
    
    for (int i = 0; i < length; i++)
    {
        if (i == length-1)
        {
            cout << numbers[i] << "}" << endl;
        }
        else
        {
            cout << numbers[i] << ", ";
        }
    }
    
    if (most_common_int(numbers, length) == solution)
    {
        cout << "SUCCESS: " << most_common_int(numbers, length) << endl;
    }
    else
    {
        cout << "FAILURE: " << most_common_int(numbers, length) << endl;
    }
}