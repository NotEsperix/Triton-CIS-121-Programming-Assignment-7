/******************************************
* Edgardo Richard Ventura                 *
* Week 7                                  *
* Assignment 4                            *
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
    * jc = job code                     *
    * hw = hours worked                 *
    * pay = calculated pay              *
    * tp = total pay                    *
    * ec = entry count                  *
    *************************************/
    string ln, jc;
    double hw, pay;
    double tp = 0;
    int ec = 0;

    cout << fixed << setprecision(2);

    while (true) {
        cout << "(Press Ctrl+Z to tally the total at anytime)" << endl;

        cout << "\n       (Job Codes:)" << endl;
        cout << "     L = Llama Tamer" << endl;
        cout << " A = Appalachian Mt.Sherpa" << endl;
        cout << "J = Queen Elizabeth's Jester" << endl;

        cout << "\nEnter employee's last name: ";
        if (!(cin >> ln)) {
            break; // Stop loop if input is invalid (Ctrl+Z)
        }

        cout << "            Enter job code: ";
        cin >> jc;
        cout << "        Enter hours worked: ";
        cin >> hw;

        /* Process phase */
        double hourlyRate = 0;
        if (jc == "L" || "l") hourlyRate = 25.00;
        else if (jc == "A" || "a") hourlyRate = 30.00;
        else if (jc == "J" || "j") hourlyRate = 50.00;
        else {
            cout << "Invalid job code. Please try again.\n" << endl;
            continue; // Skip this iteration and prompt for new input
        }

        /* Calculate pay */
        if (hw <= 40) {
            pay = hw * hourlyRate;
        }
        else {
            pay = 40 * hourlyRate + (hw - 40) * hourlyRate * 1.5; // Includes overtime
        }

        tp += pay;
        ec++;

        // Output phase
        cout << "Employee's Last Name: " << ln << endl;
        cout << "            Job Code: " << jc << endl;
        cout << "        Hours Worked: " << hw << endl;
        cout << "                 Pay: $" << pay << "\n\n";
    }

    // Display total pay and number of entries
    cout << "        Total Pay: $" << tp << endl;
    cout << "Number of Entries: " << ec << endl;

    return 0;
}