#include <iostream>
using namespace std; 
double a, b, c, d, r1, r2;
void getValues(){
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
}
void computeRoots() {
    d = b * b - 4 * a * c;
    if (d >= 0){
        r1 = (-b + (d * d)) / 2 * a;
        r2 = (-b - (d * d)) / 2 * a;
    }
}
void display() {
    if (d < 0) {
        cout << "No real roots exist";
    } else {
        cout << "Root 1:" << r1 << "\n" << "Root 2:" << r2 << "\n";
    }
}
int main() {
    getValues();
    computeRoots();
    display();
}