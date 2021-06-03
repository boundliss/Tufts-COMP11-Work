/*
 * rps.cpp
 * Purpose: Plays Rock Paper Scissors against the user.
 
 * Author: Kevin Nguyen
 * Credits: n/a
 * Note: No known bugs so far!
 * Date: 2/23/21
 */

#include <iostream>

#include <cstdlib>
#include <ctime>

using namespace std;

// Initializes functions used in main
char checkInput(string question);
char convert(int compRaw);
string compChoice(char compMod, char input);
string result(char compMod, char input, char win);

/*
 * Initializes functions used in main
 */
int main()
{
        srand(time(nullptr));

        // Initializes and sets variables
        char input;
        int compRaw = rand() % 3;
        char compMod;
        
        compMod = convert(compRaw);
        input = checkInput("Enter rock (r), paper (p), or scissors (s): ");
        
        // Determines whether the user won/lost based off what item they chose
        if (input == 'r')
        {
            cout << result(compMod, input, 's');
        }
        if (input == 's')
        {
            cout << result(compMod, input, 'p');
        }
        if (input == 'p')
        {
            cout << result(compMod, input, 'r');
        }
        
        cout << compChoice(compMod, input) << endl;
        return 0;
}

/* checkInput
 * Parameters: A question (string)
 * Purpose: Makes sure the user doesn't give an invalid input
 * Returns: Either r, p, or s depending on what the user inputs
 */
char checkInput(string question)
{
    char input;
    cout << question;
    cin >> input;
    input = tolower(input);
    
    if ((input == 'r') || (input == 'p') || (input == 's'))
    {
        return input;
    }
    else
    {
        return checkInput(question);
    }
}

/* convert
 * Parameters: A random integer
 * Purpose: Converts random number from computer into a char
 * Returns: Either r, p, or s depending on what the computer generates
 */
char convert(int compRaw)
{
    if (compRaw == 0)
    {
        return 'r';
    }
    else if (compRaw == 1)
    {
        return 'p';
    }
    else
    {
        return 's';
    }
}

/* result
 * Parameters: Either r, p, or s, user input, and what the winning answer is 
 * Purpose: Figures out if the user wins, loses, or ties the game
 * Returns: The game result
 */
string result(char compMod, char input, char win)
{
    if (compMod == input)
    {
        return "It's a tie. ";
    }
    if (compMod == win)
    {
        return "You won! ";
    }
    else
    {
        return "You lost. ";
    }
}

/* compChoice
 * Parameters: User and machine-generated input
 * Purpose: Constructs a string saying what the players of the game chose
 * Returns: The game result
 */
string compChoice(char compMod, char input)
{
    string result = "The computer ";
    if (compMod == input)
    {
        result += "also "
    }
    else
    {
        if (compMod == 'r')
        {
            result += "chose rock.";
        }
        if (compMod == 'p')
        {
            result += "chose paper.";
        }
        else
        {
            result += "chose scissors.";
        }
    }
    
    return result;
}