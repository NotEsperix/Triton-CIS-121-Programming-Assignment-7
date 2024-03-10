/******************************************
* Edgardo Richard Ventura                 *
* Week 7                                  *
* Assignment 1                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    /************************************
    * qu = quantity                     *
    * pr = price                        *
    * expr = extended price             *
    * dcam = discounted amount          *
    * dcpr = discounted price           *
    * dctoatal = total discounted price *
    *************************************/
    double qu, pr, expr, dcam, dcpr;
    double dctotal = 0;
    cout << fixed << setprecision(2);

    // Input phase for quantity and price, separately
    while (true) {
        cout << "(Press Ctrl+Z to tally the total at anytime)\nEnter quantity: ";
        if (!(cin >> qu)) {
            break; // Stop loop if input is invalid (Ctrl+Z)
        }

        cout << "   Enter price: $";
        if (!(cin >> pr)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input for price. Please enter a valid number." << endl;
            continue; // Skip to next iteration
        }

        // Process phase
        expr = qu * pr;
        if (qu > 1000) {
            dcam = expr * 0.10; // 10% discount
            dcpr = expr - dcam;
        }
        else {
            dcam = 0;
            dcpr = expr;
        }
        dctotal += dcpr;

        // Output phase, each section seperated for ease of reading
        cout << "\n        Quantity: " << qu << endl;
        cout << "           Price: $" << pr << endl;
        cout << "  Extended Price: $" << expr << endl;
        cout << "        Discount: $" << dcam << endl;
        cout << "Discounted Price: $" << dcpr << "\n" << endl;
    }

    // Display total of discounted prices
    cout << "\nTotality Discounted Prices: $" << dctotal << endl;

    // Joke about buying V-Bucks with the total amount
    int vBucks = 0;
    if (dctotal >= 99.99) vBucks = static_cast<int>(dctotal / 99.99) * 13500;
    else if (dctotal >= 59.99) vBucks = static_cast<int>(dctotal / 59.99) * 7500;
    else if (dctotal >= 24.99) vBucks = static_cast<int>(dctotal / 24.99) * 2800;
    else if (dctotal >= 9.99) vBucks = static_cast<int>(dctotal / 9.99) * 1000;

    cout << "With $" << dctotal << ", you could buy approximately " << vBucks << " V-Bucks. That's a lot of in-game cosmetics!" << endl;

    return 0;
}
