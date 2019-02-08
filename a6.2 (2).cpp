//
//  main.cpp
//  a6.2
//
//  Created by mian wei  on 11/2/17.
//  Copyright © 2017 mian wei. All rights reserved.
//

/*
 Mian Wei
 David Harden
 Assignment 6.3
 11/02
 this is a program that reads in any number of MyStrings of characters from the
 user and determines if each MyString is a palindrome. The user will terminate
 each MyString by pressing the return (or enter) button. The user will indicate
 that there are no more MyStrings by entering "quit".
 */

#include <iostream>
#include "mystring.h"
#include <cctype>

using namespace cs_mystring;

bool isAPalindrome(MyString str, int upperBound, int lowerBound);

int main() {
    MyString str;
    string str1;
    while ( true){
    cout << "Enter a string: ";
    getline (cin,str1);
        str = str1.c_str();
        if (str == "quit"){
            break;
        }
        if (isAPalindrome(str,str.length()-1,0)){
            cout << str << "is a palindrome.\n";
        }else {
            cout << str << "is not a palindrome.\n";
        }
    }
}
//    MyString str = "Able was I, ere I saw Elba";
//    MyString str1 = "aBCBA";
    
// peanut butter






/*
 str is a MyString, upperBound is the bigger bound of the array and the
 lowerBound is the smaller bound. This fuction recursively call itself until
 upperBound <= lowerBound and is will ignore space, punctuation and it is not
 case sensitive. When upperBound is a space or punctuation it return upperBound
 -1 and When lowerBound is a space or punctuation it return lowerBound
 +1. in other case it return upperBound -1, lowerBound +1 until it complete
 check.
 */
bool isAPalindrome(MyString str, int upperBound, int lowerBound){
    if (upperBound <= lowerBound){
        return true;
    } else if (ispunct(str[upperBound])||isspace(str[upperBound])){
        return isAPalindrome(str, upperBound -1, lowerBound);
    } else if (ispunct(str[lowerBound])||isspace(str[lowerBound])){
        return isAPalindrome(str, upperBound, lowerBound +1);
    }

    if (toupper(str[upperBound]) == toupper(str[lowerBound])){
        return isAPalindrome(str, upperBound -1, lowerBound +1);
    }else {
        return false;
    }
}

/*
 Enter a string: Able was I, ere I saw Elba
 Able was I, ere I saw Elbais a palindrome.
 Enter a string: peanut butter
 peanut butteris not a palindrome.
 Enter a string: quit
 */
