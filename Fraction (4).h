/*
 This Fraction class can be used to represent numbers
 like fractions,integer and mix number.  This code include 
 many operators, like stream extraction, stream
 insertion, relational operators, and arithmetic operators.
 
 
 
 
 
 
 Fraction(int inNumerator,int inDenominator);
 pre: num = 0, deno = 1
 post: A fraction with numerator equal to inNum and denominator
 equal to inDen that in this function
 
 
 
 
 friend ostream& operator<<(std::ostream& out,
 const Fraction& right);
 
 pre: The object out can be printed.
 
 post: there are 3 kinds of situation:+, / and no character
 
 
 
 friend istream& operator>>(istream &in, fraction &target);
 
 pre: The istream object in can be read.
 
 post: The fraction in the istream in has been read and assigned correctly.
 
 
 
 
 friend bool operator<(const fraction &left, const fraction &right);
 
 post: Returns true if left < right, false otherwise.
 
 
 
 
 friend bool operator<=(const fraction &left, const fraction &right);
 
 post: Returns true if left <= right, false otherwise.
 
 
 
 
 friend bool operator==(const fraction &left, const fraction &right);
 
 post: Returns true if left == right, false otherwise.
 
 
 
 
 friend bool operator>(const fraction &left, const fraction &right);
 
 post: Returns true if left > right, false otherwise.
 
 
 
 
 friend bool operator>=(const fraction &left, const fraction &right);
 
 post: Returns true if left >= right, false otherwise.
 
 
 
 
 friend bool operator!=(const fraction &left, const fraction &right);
 
 post: Returns true if left != right, false otherwise.
 
 
 
 
 friend fraction operator+(const fraction &left, const fraction &right);
 
 post: Returns the answer.
 
 
 
 
 friend fraction operator-(const fraction &left, const fraction &right);
 
 post: Returns the answer.
 
 
 
 
 friend fraction operator*(const fraction &left, const fraction &right);
 
 post: Returns the answer.
 
 
 
 
 friend fraction operator/(const fraction &left, const fraction &right);
 
 post: Returns the answer.
 
 
 
 
 fraction operator+=(const fraction &right);
 
 post: Calculates the sum of the calling object and right. 
 Return *this = *this + right;
 
 
 
 fraction operator-=(const fraction &right);
 
 post: Calculates the difference of the calling object and right. 
 Return *this = *this - right;
 
 
 
 
 fraction operator*=(const fraction &right);
 
 post: Calculates the product of the calling object and right. 
 Return *this = *this * right;

 
 
 
 
 fraction operator/=(const fraction &right);
 
 post: Calculates the quotient of the calling object and right.  
 Return *this = *this / right;.
 
 
 
 
 fraction operator++();
 
 post: Adds one to the calling object.  Returns *this;
 
 
 
 
 fraction operator++(int);
 
 post: Adds one to the calling object. Returns *this;
 
 
 
 fraction operator--();
 
 post: Subtracts one from the calling object. Returns *this;
 
 
 fraction operator--(int);
 
 post: Subtracts one from the calling object. Returns *this; 
 */

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;
namespace cs2b_fraction {
  
    class Fraction{
    private:
        int Numerator,Denominator;
        void simplify();
    public:
        Fraction(int inNumerator = 0,int inDenominator = 1);
        friend ostream& operator<<(std::ostream& out,
                                   const Fraction& right);
        friend istream& operator>>(istream& in, Fraction& right);
        friend bool operator<(const Fraction& left,
                              const Fraction& right);
        friend bool operator==(const Fraction& left,
                               const Fraction& right);
        friend bool operator>(const Fraction& left,
                              const Fraction& right);
        friend bool operator<=(const Fraction&left,
                               const Fraction&right);
        friend bool operator>=(const Fraction&left,
                               const Fraction&right);
        friend bool operator!=(const Fraction&left,
                               const Fraction&right);
        friend Fraction operator+(const Fraction&left,
                                  const Fraction&right);
        friend Fraction operator-(const Fraction&left,
                                  const Fraction&right);
        friend Fraction operator*(const Fraction&left,
                                  const Fraction&right);
        friend Fraction operator/(const Fraction&left,
                                  const Fraction&right);
        Fraction operator+=(const Fraction&right);
        Fraction operator-=( const Fraction&right);
        Fraction operator*=(const Fraction&right);
        Fraction operator/=(const Fraction&right);
        Fraction operator++( );
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);
        
    };
}
#endif
