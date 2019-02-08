//
//  Header.h
//  a4
//
//  Created by mian wei  on 10/18/17.
//  Copyright © 2017 mian wei . All rights reserved.
//


#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
namespace cs_mystring {
  
    class MyString{
    private:
        char *letter;
    public:
        MyString();
        MyString(const char *inLetter);
        MyString(const MyString& right);
        ~MyString();
        int length() const;
        MyString operator=(const MyString& right);
        
        friend bool operator==(const MyString&left, const MyString&right);
        friend bool operator<(const MyString&left, const MyString&right);
        friend bool operator<=(const MyString&left, const MyString&right);
        friend bool operator>(const MyString&left, const MyString&right);
        friend bool operator>=(const MyString&left, const MyString&right);
        friend bool operator!=(const MyString&left, const MyString&right);
        void setInfo(const char *inLetter, int inSize);
        
        friend std::ostream& operator<<(std::ostream& out, const MyString& source);
        friend std::istream& operator>>(std::istream& in, MyString& target);
        char operator[](int index) const;
        char& operator[](int index);
    };
}

#endif /* Header_h */
