#include <iostream>
#include "Fraction.h"

#include <string>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;
namespace cs2b_fraction {
    
        Fraction::Fraction(int inNumerator,int inDenominator){
            assert(inDenominator != 0);
            Numerator = inNumerator;
            Denominator = inDenominator;
            simplify();
        }

    
    
    
    
    
    ostream& operator<<(ostream& out, const Fraction& right){
    
            if (right.Numerator == 0){
                out << "0";
            }else if(right.Denominator == 1)
            {
                out << right.Numerator;
        
            //}else if(abs(right.Numerator)!= right.Numerator){
                                
            }else if (abs(right.Numerator) < right.Denominator){
        
                out << right.Numerator <<'/'<< right.Denominator;
        
            }else if (abs(right.Numerator) > right.Denominator){
                int number = right.Numerator / right.Denominator;
                int remainder = abs(right.Numerator % right.Denominator);
                out << number << '+' << remainder <<'/'<< right.Denominator;
            }
            return out;
        }
    
    
    
    
    
    
        istream& operator>>(istream& in, Fraction& right){
            int  temp1;
            in >>temp1;
            
            if(in.peek() == '+')
            {
                int temp2,denominator;
                
                
                in.ignore();
                in >> temp2;
                
                in.ignore();
                in >> denominator;
        
                if (temp1 < 0){
                    temp1 = abs(temp1);
                    right.Numerator = -(temp1 * denominator + temp2);
                    right.Denominator = denominator;
                }else {
                    right.Numerator = temp1 * denominator + temp2;
                    right.Denominator = denominator;
                }
            }else if(in.peek() == '/')
            {
                int denominator;
                
                in.ignore();
                in >> denominator;
                right.Numerator = temp1;
                right.Denominator = denominator;
        
            } else
            {
                right.Numerator = temp1;
                right.Denominator = 1;
            }
            right.simplify();
            return in;
    
        }
    
    
    
    
    
    
        bool operator<(const Fraction& left,
               const Fraction& right){
            int leftnum, rightnum;
    
            leftnum = left.Numerator * right.Denominator;
            rightnum = right.Numerator * left.Denominator;
            
            return leftnum < rightnum;
    
        }
    
    
    
    
    
    
        bool operator==(const Fraction& left,
                        const Fraction& right){
            int leftnum, rightnum;
            
            leftnum = left.Numerator * right.Denominator;
            rightnum = right.Numerator * left.Denominator;
            
            return leftnum == rightnum;
        }
    
    
    
    
    
    
        bool operator>(const Fraction& left,
                       const Fraction& right){
            int leftnum, rightnum;
            
            leftnum = left.Numerator * right.Denominator;
            rightnum = right.Numerator * left.Denominator;
            
            
            return leftnum > rightnum;
        }
    
    
    
    
    
    
        bool operator<=(const Fraction&left, const Fraction&right){
            int leftnum, rightnum;
            
            leftnum = left.Numerator * right.Denominator;
            rightnum = right.Numerator * left.Denominator;
            
            return leftnum <= rightnum;
        }
    
    
    
    
    
    
        bool operator>=(const Fraction&left, const Fraction&right){
            int leftnum, rightnum;
            
            leftnum = left.Numerator * right.Denominator;
            rightnum = right.Numerator * left.Denominator;
            
            return leftnum >= rightnum;
        }
    
    
    
    
    
    
        bool operator!=(const Fraction&left, const Fraction&right){
            int leftnum, rightnum;
            
            leftnum = left.Numerator * right.Denominator;
            rightnum = right.Numerator * left.Denominator;
            
            return leftnum != rightnum;
        }
    
    
    
    
    
    
        void Fraction:: simplify(){
            
            if (Numerator != Denominator)
            {
                int m = 0;
                for(m = max(abs(Numerator),abs(Denominator)); m>1; m--)
                {
                    if (Numerator % m == 0 && Denominator % m ==0)
                    {
                        Numerator = Numerator / m;
                        Denominator = Denominator / m;
                        m++;
                    }
                }
            }
            
            if (Numerator == Denominator)
            {
                Numerator = Denominator = 1;
            }
            
            if (Denominator < 0)
            {
                Denominator = (-1) * Denominator;
                Numerator = (-1) * Numerator;
            }
            
        }
    
    
    
    
    
    
        Fraction operator+(const Fraction&left, const Fraction&right){
            Fraction answer;
            int leftnum, rightnum;
            leftnum = (left.Numerator * right.Denominator);
            rightnum = right.Numerator * left.Denominator;
            answer.Numerator = leftnum + rightnum;
            answer.Denominator = left.Denominator * right.Denominator;
            answer.simplify();
            return answer;
        }
    
    
    
    
    
    
        Fraction operator-(const Fraction&left, const Fraction&right){
            Fraction answer;
            int leftnum, rightnum;
            leftnum = (left.Numerator * right.Denominator);
            rightnum = right.Numerator * left.Denominator;
            answer.Numerator = leftnum - rightnum;
            answer.Denominator = left.Denominator * right.Denominator;
            answer.simplify();
            return answer;
        }
    
    
    
    
    
    
        Fraction operator*(const Fraction&left, const Fraction&right){
            Fraction answer;
            answer.Numerator = left.Numerator * right.Numerator;
            answer.Denominator = left.Denominator * right.Denominator;
            answer.simplify();
            return answer;
        }
    
    
    
    
    
    
        Fraction operator/(const Fraction&left, const Fraction&right){
            Fraction answer;
            int leftnum, rightnum;
            leftnum = (left.Numerator * right.Denominator);
            rightnum = right.Numerator * left.Denominator;
            answer.Numerator = leftnum ;
            answer.Denominator = rightnum;
            answer.simplify();
            return answer;
        }
    
    
    
    
    
    
        Fraction Fraction::operator+=(const Fraction&right){
    
            *this = *this + right;
            return *this;
        }






        Fraction Fraction::operator-=(const Fraction&right){
            *this = *this - right;
            return *this;
        }
    
    
    
    
    
    
        Fraction Fraction::operator*=( const Fraction&right){
            *this = *this * right;
            return *this;
        }
    
    
    
    
    
    
        Fraction Fraction::operator/=(const Fraction&right){
            *this = *this / right;
            return *this;
        }
    
    
    
    
    
    
        Fraction Fraction::operator++( ){
            Numerator = Numerator + Denominator;
            return *this;
        }
    
    
    
    
    
    
        Fraction Fraction::operator++(int){
            Fraction g(Numerator,Denominator);
            Numerator += Denominator;
        return g;
        }
    
    
    
    
    
    
        Fraction Fraction::operator--(){
            Numerator = Numerator - Denominator;
            return *this;
        }
    
    
    
    
    
    
        Fraction Fraction::operator--(int){
            Fraction g(Numerator,Denominator);
            Numerator -= Denominator;
            return g;
        }
}
