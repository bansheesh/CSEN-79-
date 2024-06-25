/* Lab 3, poly.cpp
   Lydia Martin
   Febuary 8, 2024
*/
#include "poly.h"
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4 {
// HELPER FUNCTION
// the current degree is set to the highest exponent with a non-zero coeficient
void polynomial::update_current_degree() { current_degree = degree(); }
// CONSTRUCTOR
polynomial::polynomial(double c, unsigned int exponent) {
  for (int i = 0; i <= MAXIMUM_DEGREE; i++) {
    coef[i] = 0.0;
  }
  coef[exponent] = c;
  current_degree = exponent;
}

// MODIFICATION MEMBER FUNCTIONS

// sets the coefficient for the specified exponent
void polynomial::assign_coef(double coefficient, unsigned int exponent) {
  assert(exponent <= MAXIMUM_DEGREE);
  coef[exponent] = coefficient;
}

// Adds the given amount to the coefficient of the specified exponent.
void polynomial::add_to_coef(double amount, unsigned int exponent) {
  assert(exponent <= MAXIMUM_DEGREE);
  coef[exponent] += amount;
}

// all coefficients of this polynomial are set to zero
void polynomial::clear() {
  for (int i = 0; i <= MAXIMUM_DEGREE; i++) {
    coef[i] = 0;
  }
}

// CONSTANT MEMBER FUNCTIONS

// The return value is the antiderivative (indefinite integral) of this
// polynomial. NOTE: The return polynomial always has a constant term of zero.
polynomial polynomial::antiderivative() const {
  assert(degree() < MAXIMUM_DEGREE);
  polynomial value;
  for (int i = MAXIMUM_DEGREE - 1; i >= 0; i--) {
    value.assign_coef(coef[i] / (i + 1), i + 1);
  }
  return value;
}

// Returns coefficient at specified exponent of this polynomial.
double polynomial::coefficient(unsigned int exponent) const {
  if (exponent > MAXIMUM_DEGREE) {
    return 0;
  }
  return (coef[exponent]);
}

// Returns the value of definite integral computed from x0 to x1. The answer is
// computed analytically.
double polynomial::definite_integral(double x0, double x1) const {
  polynomial antideriv = antiderivative();

  return antideriv.eval(x1) - antideriv.eval(x0);
}

// The function returns the value of the largest exponent with a non-zero
// coefficient. If all coefficients are zero, then the function returns zero
// (even though, technically, this polynomial does not have a degree).
unsigned int polynomial::degree() const {
  for (int i = MAXIMUM_DEGREE; i >= 0; i--) {
    if (coef[i] != 0) {
      return i;
    }
  }
  return 0; // means that "i" got to the end of the array and all coefficients
            // were 0
}

// The return value is first the derivative of this polynomial.
polynomial polynomial::derivative() const {
  polynomial value;
  for (int i = 1; i <= MAXIMUM_DEGREE; i++) {
    value.assign_coef(coef[i] * i, i - 1);
  }
  return value;
}

// The return value is the value of this polynomial with the given value for the
// variable x.
double polynomial::eval(double x) const {
  double value = coef[0];
  for (int i = 1; i <= degree(); i++) {
    value += coef[i] * pow(x, i);
  }
  return value;
}

// the return value is true if and only if the polynomial is the zero
// polynomial
bool polynomial::is_zero() const {
  for (int i = 0; i <= MAXIMUM_DEGREE; i++) {
    if (coef[i] != 0) {
      return false;
    }
  }
  return true;
}

unsigned int polynomial::next_term(unsigned int e) const {
  if (degree() > e) {
    //check the next biggest exponent with a nonzero coeffienctient and return
    for (int i = e + 1; i <= degree(); i++) {
      if (coef[i] != 0) {
        return i;
      }
    }
  }
  return 0;
}

unsigned int polynomial::previous_term(unsigned int e) const {
  //check the next lowest exponent with a nonzero coefficient and return 
  for (int i = e - 1; i >= 0; i--) {
    if (coef[i] != 0) {
      return i;
    }
  }
  return UINT_MAX;
}

// CONSTANT OPERATORS
// same as eval number function
double polynomial::operator()(double x) const { return eval(x); }

// NON-MEMBER BINARY OPERATORS
polynomial operator+(const polynomial &p1, const polynomial &p2) {
  polynomial p3;
  //add p1 to p3
  for (int i = 0; i <= p1.degree(); i++) {
    p3.assign_coef(p1.coefficient(i), i);
  }
  //add p2 to p3
  for (int j = 0; j <= p2.degree(); j++) {
    p3.add_to_coef(p2.coefficient(j), j);
  }
  return p3;
}

polynomial operator-(const polynomial &p1, const polynomial &p2) {
  polynomial p3;
  //add p1 into p3
  for (int i = 0; i <= p1.degree(); i++) {
    p3.assign_coef(p1.coefficient(i), i);
  }
  //subtract p2 from p3
  for (int j = 0; j <= p2.degree(); j++) {
    p3.add_to_coef(-p2.coefficient(j), j);
  }
  return p3;
}

polynomial operator*(const polynomial &p1, const polynomial &p2) {
  polynomial p3;
  assert(p1.degree() + p2.degree() <= p3.MAXIMUM_DEGREE); //assert that it fits into p3
  //multiply each p2 term by each p1 term
  for (int i = 0; i <= p1.degree(); i++) {
    for (int j = 0; j <= p2.degree(); j++) {
      p3.add_to_coef(p1.coefficient(i) * p2.coefficient(j), i + j); 
    }
  }
  return p3;
}

// NON-MEMBER OUTPUT FUNCTIONS
std::ostream &operator<<(std::ostream &out, const polynomial &p) {
  cout << fixed;
  cout.precision(1);
  // if zero, print zero
  if (p.is_zero()) {
    return (out << "0.0");
  }
  // if polynomial & its not of degree 1, print polynomial
  if (p.degree() != 0 && p.degree() != 1) {
    out << p.coefficient(p.degree()) << "x^" << p.degree();
  }
  // if greatest degree is 1, print coef and x
  if (p.degree() == 1) {
    out << p.coefficient(p.degree()) << "x";
  }

  if (p.degree() == 0) {
    out << p.coefficient(p.degree());
  }

  // traverse through array backwards
  for (int i = p.degree() - 1; i >= 0; i--) {
    // if coefficient is zero, skip
    if (p.coefficient(i) == 0) {
      continue;
    }
    // if last element
    else if (i == 0) {
      if (p.coefficient(i) < 0) {
        out << " - "
            << abs(p.coefficient(
                   i)); // abs turns coef postive so it prints just one -
      } else {
        out << " + " << p.coefficient(i);
      }
    }
    // if degree 1
    else if (i == 1) {
      if (p.coefficient(i) < 0) {
        out << " - " << abs(p.coefficient(i)) << "x";
      } else {
        out << " + " << p.coefficient(i) << "x";
      }
    }
    // if first element
    else if (i == p.degree()) {
      if (p.coefficient(i) < 0)
        out << " - " << abs(p.coefficient(i)) << "x^";
      else {
        out << " + " << p.coefficient(i) << "x^";
      }
    } else if (p.coefficient(i) == 1 && i != 0) {
      out << " + x^" << i;
    } else if (p.coefficient(i) == -1 && i != 0) {
      out << " - x^" << i;
    } else if (p.coefficient(i) > 0) {
      out << " + " << p.coefficient(i) << "x^" << i;
    } else if (p.coefficient(i) < 0) {
      out << " - " << abs(p.coefficient(i)) << "x^" << i;
    }
  }
  std::cout.precision(0); // Reset to default
  return out;
}
} // namespace coen79_lab4