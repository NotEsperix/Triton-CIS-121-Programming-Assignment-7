/******************************************
* Edgardo Richard Ventura                 *
* Week 7                                  *
* Assignment 5                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    /************************************
    * ln = last name                    *
    * ch = credit hours                 *
    * dc = district code                *
    * tu = tuition owed                 *
    * ttu = total tuition               *
    * tch = total credit hours          *
    * sc = student count                *
    *************************************/

    string ln, dc;
    int ch;
    double tu;
    double ttu = 0;
    int tch = 0, sc = 0;

    cout << fixed << setprecision(2);

    while (true) {
        cout << "(Press Ctrl+Z to tally the total at anytime)\n" << endl; 
        cout << "District Codes: (I = In State) (O = Out of State)" << endl;
        cout << "\nEnter student's last name: "; 
        if (!(cin >> ln)) {
            break; // Stop loop if input is invalid (Ctrl+Z)
        }

        cout << "       Enter credit hours: ";
        cin >> ch;
        cout << "      Enter district code: ";
        cin >> dc;

        /* Process phase */
        // Tuition is calculated based on district code: "I" for in-district at $250 per credit hour, "O" for out-of-district at $550 per credit hour.
        if (dc == "I"|| "i") tu = ch * 250;
        else if (dc == "O" || "o") tu = ch * 550;
        else {
            cout << "Invalid district code. Please try again.\n" << endl;
            continue; // Skip this iteration for invalid district code
        }

        ttu += tu; // Total tuition accumulated
        tch += ch; // Total credit hours accumulated
        sc++; // Student count incremented

        // Output phase
        cout << "\n      Student's Last Name: " << ln << endl;
        cout << "             Credit Hours: " << ch << endl;
        cout << "                 District: " << dc << endl;
        cout << "             Tuition Owed: $" << tu << "\n" << endl;
    }

    // Display total tuition, total credit hours, and student count
    cout << "\nTotal Tuition Owed: $" << ttu << endl;
    cout << "Total Credit Hours: " << tch << endl;
    cout << "Number of Students: " << sc << endl;

    return 0;
}
