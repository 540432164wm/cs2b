/*
 Mian Wei
 David Harden
 Assignment 6.1
 11/02
 this is a program that can reverse the order of the entries in the array whose
 indices are between the two bounds (including the bounds). 
 */
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

void reverseWithinBounds(char a[],int upperBound, int lowerBound);
void reverseCstring(char a[]);







int main()
{
    char temp[5];
    char* b = temp;
    b[0] = 'A';
    b[1] = 'B';
    b[2] ='C';
    b[3] ='D';
    b[4] ='E';

    reverseCstring(b);
    for (int i = 0; i < 5; i++){
        cout << b[i];
    }
}






/*
 * a is a character array, upperBound is the bigger bound of the array and the
 lowerBound is the smaller bound. And this function just switch the lowerBound
 and the upperBound. It recursively call itself until upperBound <= lowerBound.
 */
void reverseWithinBounds(char* a,int upperBound, int lowerBound){
    if (upperBound <= lowerBound){
        return;
    }
    
    char temp;
    temp = a[lowerBound];
    a[lowerBound] = a[upperBound];
    a[upperBound] = temp;

    reverseWithinBounds( a, upperBound -1,  lowerBound +1);
}






/*
 * a is a character array and this function set the value to the lowerBound
 and the upperBound.
 */
void reverseCstring(char* a){
    int upperBound = strlen(a) -1 ;
    int lowerBound = 0;
    reverseWithinBounds( a, upperBound,  lowerBound);
}







/*
 output:
 EDCBA
 */
