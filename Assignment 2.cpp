/******************************************
* Edgardo Richard Ventura                 *
* Week 7                                  *
* Assignment 2                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    /***********************************************************
    * ln = Last Name                                           *
    * hits = hits                                              *
    * ab = at bat                                              *
    * htotal = total hits                                      *
    * pc = player count                                        *
    * ba = batting average                                     *
    * zha = total hits combined, 3 hits to defeat a zelda boss *
    ************************************************************/
    string ln;
    int hits, ab;
    int htotal = 0;
    int pc = 0;
    double ba;
    double zha = 0;
    cout << fixed << setprecision(3);

    while (true) {
        cout << "(Press Ctrl+Z to stop at anytime)\nEnter player's last name: ";
        if (!(cin >> ln)) {
            break; // Stop loop if input is invalid (Ctrl+Z)
        }

        while (true) {
            cout << " Enter number of at bats: ";
            cin >> ab;
            cout << "    Enter number of hits: ";
            cin >> hits;

            if (hits > ab) {
                cout << "Invalid input: hits cannot be more than at bats. Please try again." << endl;
            }
            else {
                htotal += hits; // Add to total hits if valid
                break; // Proceed if the input is valid
            }
        }

        ba = static_cast<double>(hits) / ab;
        zha += ba;
        pc++;

        cout << "\n        Player's Last Name: " << ln << endl;
        cout << "          Batting Average: " << ba << "\n" << endl;
    }

    if (pc > 0) {
        cout << "\nTotal Number of Players: " << pc << endl;
        cout << "Average Batting Average: " << (zha / pc) << endl;

        // Joke about defeating Zelda bosses based on total hits
        cout << "\nTotal Calculated Hits: " << htotal << endl;
        cout << "That means you would've defeated " << static_cast<double>(htotal) / 3 << " Zelda bosses." << endl;
    }
    else {
        cout << "\nNo player data was entered." << endl;
    }

    return 0;
}
