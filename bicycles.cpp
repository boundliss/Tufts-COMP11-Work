/*
 * bicycles.cpp
 * Purpose: Asks the user how many bike parts they have and tells them how many
bikes they can make from those parts
 
 * Author: Kevin Nguyen
 * Credits: n/a
 * Note: No known bugs so far!
 * Date: 2/23/21
 */

#include <iostream>

using namespace std;

/*
 * Initializes functions used in main
 */
string grammar(int num, string word);
int checkInput(string question);

int main()
{
    // Initialize variables
    int wheels, frames, links;
    int bikes = 0;
    
    // Asks the user how many wheels, frames, links they have
    wheels = checkInput("Enter the number of wheels: ");
    frames = checkInput("Enter the number of frames: ");
    links = checkInput("Enter the number of links: ");
    
    // Checks to see if we can make one bike with our current materials
    while ((wheels >= 2) && (frames >= 1) && (links >= 50))
    {
        /* Subtracts the materials required to make a bike from the supply list
        and adds a new bike. */
        wheels -= 2;
        frames -= 1;
        links -= 50;
        bikes ++;
    }
    
    // Prints out the output
    cout << "You can make " << grammar(bikes,"bike") << ". There are " <<
    grammar(wheels, "wheel") << ", " << grammar(frames, "frame") << ", " <<
    grammar(links, "link") << " leftover." << endl;;
    
    return 0;
}


/* checkInput
 * Parameters: string
 * Purpose: Makes sure the user doesn't give an invalid input
 * Returns: An integer input by the user
 */
int checkInput(string question)
{
    int item;
    cout << question;
    cin >> item;
    if (item < 0)
    {
        return checkInput(question);
    }
    
    return item;    

}

/* grammar
 * Parameters: string
 * Purpose: Makes sure our output statement abides by plural/singular grammar 
 * rules
 * Returns: A string
 */
string grammar(int num, string word)
{
    if (num == 1)
    {
        return to_string(num) + " " + word;
    }
    else
    {
        return to_string(num) + " " + word + "s";
    }
}