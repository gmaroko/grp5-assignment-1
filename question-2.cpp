#include <iostream>
using namespace std;
int main()
{
    // Declare a loop counter variable.
    int i;
    // loop for the number of rows
    for (i = 10; i >= 1; i--){
        // Declares a loop counter variable.
        int j;
        // loop for printing stars in each row
        for (j = 1; j <= i; j++) {
            cout << "*";
        }
        // Move to the next line after each row
        cout << endl;
    }
}