/*
 NAME: Harish Palani
 CRN: 41600
 ASSIGNMENT: Lab 7
 SOURCES: stackoverflow.com
 */
 
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    double A, B, a0, a1, a2, a3, a4, a5;
    string in;
    
    /* Accept decimal input */
    cout << "Enter value for A below." 
         << endl;
    cin >> in;
    
    try { // Check if x is numeric
        A = stoll(in);
    } catch (exception &e) {
        cout << "\n"
             << "Make sure you're entering a real number!"
             << endl;
        cin >> A;
    }
    
    cout << "Enter value for B below." 
         << endl;
    cin >> in;
    
    try { // Check if x is numeric
        B = stoll(in);
    } catch (exception &e) {
        cout << "\n"
             << "Make sure you're entering a real number!"
             << endl;
        cin >> B;
    }
    
    cout << "Enter value for a0 below." 
         << endl;
    cin >> in;
    
    try { // Check if x is numeric
        a0 = stoll(in);
    } catch (exception &e) {
        cout << "\n"
             << "Make sure you're entering a real number!"
             << endl;
        cin >> a0;
    }
    
    cout << "Enter value for a1 below." 
         << endl;
    cin >> in;
    
    try { // Check if x is numeric
        a1 = stoll(in);
    } catch (exception &e) {
        cout << "\n"
             << "Make sure you're entering a real number!"
             << endl;
        cin >> a1;
    }
    
    // Report info
    cout << "\nRECURRENCE RELATION: "
         << "A(k) = "
         << A
         << "A(k-1) + "
         << B
         << "A(k-2)"
         << endl;
    
    cout << "INITIAL CONDITIONS: "
         << "a0 = "
         << a0
         << ", a1 = "
         << a1
         << endl;
         
    cout << "CHARACTERISTIC EQUATION: "
         << "t^2 — "
         << A
         << "t — "
         << B
         << " = 0"
         << endl;
    
    // Solve characteristic equation
    double r, s;
    double discriminant = A*A + 4*B;
    double sequence[6];
    
    if (discriminant > 0) {
        r = (A + sqrt(discriminant)) / 2;
        s = (A - sqrt(discriminant)) / 2;
        
        double c, d;
        
        if (s < 0) {
            c = (a0 * -s)/(r+s); // this is (r+s)c
        }
        
        if (r < 0) {
            d = (a0 * -r)/(r+s);
        }
        
        // Determine formula
        cout << "FORMULA: A(n) = "
             << c // a0 = c + d
             << "("
             << r
             << ")^n + "
             << d // a1 = rc + sd
             << "("
             << s
             << ")^n"
             << endl;
        
        // Print sequence
        for(int n = 0; n < 6; n++) {
            sequence[n] = (c * pow(r, n)) + (d * pow(s, n));
            cout << "a"
                 << n
                 << " = "
                 << sequence[n]
                 << endl;
        }
             
    } else if (discriminant == 0) {
        r = (A + sqrt(discriminant)) / 2;
        
        // Determine formula
        cout << "FORMULA: A(n) = "
             << a0
             << "("
             << r
             << ")^n + "
             << (a1 - a0*r) / r
             << "n("
             << r
             << ")^n"
             << endl;
        
        
        // Print sequence
        for(int n = 0; n < 6; n++) {
            sequence[n] = (a0 * pow(r, n)) + (((a1 - a0*r) / r) * n * pow(r, n));
            cout << "a"
                 << n
                 << " = "
                 << sequence[n]
                 << endl;
        }     
    } else {
        cout << "The roots are complex! Moving on..."
             << endl;
    }
}