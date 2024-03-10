/******************************************
* Edgardo Richard Ventura                 *
* Week 7                                  *
* Assignment 3                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    /************************************
    * dc = destination city             *
    * mt = miles traveled               *
    * gu = gallons used                 *
    * mpg = miles per gallon            *
    * tmt = total miles traveled        *
    * tc = trip count                   *
    *************************************/
    string dc;
    double mt, gu, mpg;
    double tmt = 0;
    int tc = 0;

    cout << fixed << setprecision(2);

    while (true) {
        cout << "(Press Ctrl+Z to tally the total at anytime)\nEnter destination city: ";
        // Use getline to allow spaces in destination city input
        if (!getline(cin, dc)) {
            break; // Stop loop if input is invalid (Ctrl+Z)
        }

        // Convert destination city to lowercase for case-insensitive comparison
        transform(dc.begin(), dc.end(), dc.begin(), ::tolower);

        if (dc == "hawaii") {
            cout << "  Yea, no. I'm cancelling this right away.\n";
            return 0; // Terminates the program immediately
        }

        cout << "  Enter miles traveled: ";
        cin >> mt;
        cout << "    Enter gallons used: ";
        cin >> gu;
        // Clear the newline character after the numeric input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Process phase
        mpg = mt / gu;
        tmt += mt;
        tc++;

        // Output phase, each section separated for ease of reading
        cout << "\n      Destination City: " << dc << endl;

        // Easter egg messages based on the destination city
        if (dc == "chicago" || dc == "illinois") {
            cout << "  Jeeze buddy, just try not to get shot." << endl;
        }
        else if (dc == "ohio") {
            cout << "  Let me fix that for you, I think you meant the backrooms." << endl;
        }
        else if (dc == "florida" || dc == "seattle") {
            cout << "  Oh how I envy you" << endl;
        }
        else if (dc == "new york") {
            cout << "  HA! DRIVING THROUGH THERE!? GOOD LUCK!" << endl;
        }

        cout << "        Miles Traveled: " << mt << endl;
        cout << "          Gallons Used: " << gu << endl;
        cout << "      Miles per Gallon: " << mpg << "\n" << endl;
    }

    // Display total miles traveled and trip count
    cout << "\nTotal Miles Traveled: " << tmt << endl;
    cout << "     Number of Trips: " << tc << endl;

    return 0;
}
