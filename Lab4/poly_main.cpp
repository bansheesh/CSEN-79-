/* Lab 3, poly_main.cpp
   Lydia Martin
   Febuary 8, 2024
*/

#include "poly.h"
#include <iostream>
using namespace std;
using namespace coen79_lab4;

void printTest() {
  // Initialize polynomial p1 &p2. Print p1.
  polynomial p1, p2;
  cout << p1 << endl;
  // p1 := 5x^2. Print p1.
  p1.assign_coef(5, 2);
  cout << p1 << endl;
  // p1 := 3 - 4x + 5x^2. Print p1.
  p1.assign_coef(-4, 1);
  p1.assign_coef(3, 0);
  cout << p1 << endl;
  // p1 := p1 + 8x. Print p1.
  p1.add_to_coef(8, 1);
  cout << p1 << endl;
  // p1 := 3 + 4x + 5x^2 - 2.5x^3. Print p1.
  p1.assign_coef(-2.5, 3);
  cout << p1 << endl;
  // p2 := -7.2. Print p2.
  p2.assign_coef(-7.2, 0);
  cout << p2 << endl;
  // p2 := -7.2 -3x^5. Print p2.
  p2.assign_coef(-3, 5);
  cout << p2 << endl;
}

int main() {
  cout << "Testing Printing Function" << endl;
  // Initialization
  printTest();

  cout << "Constructor Tests" << endl;
  polynomial p1, p2(5.2, 0), p3(3.7, 29), p4(4.6, 13);
  // Print all of them
  cout << p1 << endl;
  cout << p2 << endl;
  cout << p3 << endl;
  cout << p4 << endl;

  cout << "Assignment Tests" << endl;
  // Clear() p1 and p2
  p1.clear();
  p2.clear();
  // p1 = 9 + 8x + 7x^17 + 6x^28 + 5x^29. Print p1.
  p1.assign_coef(9, 0);
  p1.assign_coef(8, 1);
  p1.assign_coef(7, 17);
  p1.assign_coef(6, 28);
  p1.assign_coef(5, 29);
  cout << p1 << endl;
  // Print p1’s degree
  cout << "Degree: " << p1.degree() << endl;
  // p2 = -4 - 3.5x - 3x^17 - 2.5x^28 - 2x^29. Print p2.
  p2.assign_coef(-4, 0);
  p2.assign_coef(-3.5, 1);
  p2.assign_coef(-3, 17);
  p2.assign_coef(-2.5, 28);
  p2.assign_coef(-2, 29);
  cout << p2 << endl;

  cout << "Add To Tests" << endl;
  // p1 := p1 - 12
  p1.add_to_coef(-12, 0);
  // p2 := p2 + 4x^29
  p2.add_to_coef(4, 29);
  // Print p1 & p2
  cout << p1 << endl;
  cout << p2 << endl;

  cout << "Next Term Tests" << endl;
  //  Use Expected output to infer the code needed. Call next_term() and
  //  previous_term()
  cout << "Next term after " << p1.degree() << " is "
       << p1.next_term(p1.degree()) << endl;
  cout << "Next term after 20 is " << p1.next_term(20) << endl;
  cout << "Term before 20 is " << p1.previous_term(20) << endl;
  cout << "Next term after 5 is " << p1.next_term(5) << endl;
  cout << "Term before 5 is " << p1.previous_term(5) << endl;
  cout << "Term before 0 is " << p1.previous_term(0) << endl;

  cout << "Is Zero Test" << endl;
  //  Use ternary operator to determine whether p1 is_zero() or not. Check
  //  expected output format.
  if (p1.is_zero())
    cout << p1 << " is zero." << endl;
  else
    cout << p1 << " is not zero." << endl;
  p1.clear();
  //  Use ternary operator again to determine whether p1 is_zero() or not. Check
  //  expected output format.
  cout << p1 << " is zero." << endl;

  cout << "Math Tests" << endl;
  p1.clear();
  // p1 := 3 + 4x + 5x^2. Print p1.
  p1.assign_coef(3, 0);
  p1.assign_coef(4, 1);
  p1.assign_coef(5, 2);
  cout << p1 << endl;
  // Use Expected output to infer the code needed.
  cout << "If x=4, f(x)=" << p1.eval(4) << endl;
  cout << "If x=2.5, f(x)=" << p1.eval(2.5) << endl;
  cout << "If x=-3.7, f(x)=" << p1.eval(-3.7) << endl;
  polynomial ptemp = p1.derivative();
  cout << "Derivate: " << ptemp << endl;
  ptemp = p1.antiderivative();
  cout << "Antiderivative: " << ptemp << endl;
  cout << "DefInt(f) from 0 to 5.7: " << p1.definite_integral(0, 5.7) << endl;

  cout << "Math Operator Tests" << endl;
  p2.clear();
  // p2 = -11.3x + 7.2x^2
  p2.assign_coef(-11.3, 1);
  p2.assign_coef(7.2, 2);
  // Test p1 + p2
  cout << "(" << p1 << ") + (" << p2 << ") = " << p1 + p2 << endl;
  // Test p1 - p2
  cout << "(" << p1 << ") - (" << p2 << ") = " << p1 - p2 << endl;
  // Test p1 * p2
  cout << "(" << p1 << ") * (" << p2 << ") = " << p1 * p2 << endl;
}