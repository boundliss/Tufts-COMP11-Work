/*
 * flights.cpp
 * Purpose: 
 
 * Author: Kevin Nguyen
 * Credits: n/a
 * Note: If you input anything other than a int, the program will malfunction,
 skip all the lines of the code, and end. The program also expects integers
 that would belong to a 24-hour time period. Any other inputs might cause the
 code to glitch.
 * Date: 2/23/21
 */

#include <iostream>

using namespace std;

int hrsmin(int hrs, int mins);
int elapsed(int post, int pre);
void print(int elapsed);

/*
 * Initializes functions used in main
 */
int main()
{
    // Initializes variables
    int dTimeH, dTimeM, aTimeH, aTimeM, dTimeH1, dTimeM1, aTimeH1, aTimeM1;

    // Asks user for flight times
    cout << "Flight 1: "; 
    cin >> dTimeH >> dTimeM >> aTimeH >> aTimeM;
    cout << "Flight 2: "; 
    cin >> dTimeH1 >> dTimeM1 >> aTimeH1 >> aTimeM1;
    
    // Prints out layover time and total time of flight
    cout << "Layover: ";
    print(elapsed(hrsmin(dTimeH1, dTimeM1), hrsmin(aTimeH,aTimeM)));
    
    cout << "Total: ";
    print(elapsed(hrsmin(aTimeH, aTimeM), hrsmin(dTimeH, dTimeM)) + 
    elapsed(hrsmin(aTimeH1, aTimeM1), hrsmin(dTimeH1, dTimeM1)) + 
    elapsed(hrsmin(dTimeH1, dTimeM1), hrsmin(aTimeH,aTimeM)));
    
    return 0;
}

/* hrsmin
 * Parameters: Two integers
 * Purpose: Converts hours and minutes to just minutes
 * Returns: The time in minutes
 */
int hrsmin(int hrs, int mins)
{
    int totMins = 0;
    totMins = hrs * 60 + mins;
    
    return totMins;
}

/* elapsed
 * Parameters: Two integers, in minute time
 * Purpose: Figures out how many minutes elapsed between begining and end of 
 * event
 * Returns: How long the flight is in minutes (int)
 */
int elapsed(int post, int pre)
{
    int elapsed = 0;
    
    // Deals with cases where flights span mutliple days
    if (post < pre)
    {
        post += 1440;
    }
    
    // Finds the time elapsed between before and after an event
    elapsed = post - pre;
    
    return elapsed;
}

/* elapsed
 * Parameters: Minutes elapsed. Integer
 * Purpose: Converts 24-hour time to normal time and then prints it
 * Returns: Nothing
 */
void print(int elapsed)
{
    int hrs = 0;
    
    // Converts minutes back to hours
    while ((elapsed >= 60) || (elapsed < 0))
    {
        if (elapsed >= 60)
        {
            elapsed -= 60;
            hrs++;
        }
        else
        {
            elapsed += 60;
            hrs --;
        }
    }
    
    // Prints out time elapsed in hour/min format
    cout << hrs << " hr " << elapsed << " min " << endl;
}