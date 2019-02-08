/*
 this is a program that can do some calculation for mystring or mystring and c-string. For "+=" only MyStrings can be on the left-hand side, but either MyStrings or C-strings may appear on the right side.  FoR "+" The operator are able to handle either MyString objects or C-strings on either side of the operator. It also has a readfile function, a extraction operator.
void read(ifstream &in, char stop);
 pre: the file is opened successfully.
 post: get the line of char which has limit of 127.
 
 MyString();
 post: constructor
 
 
 
 
 MyString(const char *inLetter);
 post: constructor
 
 
 
 
 MyString(const MyString& right);
 post: constructor
 
 
 
 
 ~MyString();
 post: delete array in stack
 
 
 
 
 int length() const;
 post: track the length of the string
 
 
 
 
 MyString operator=(const MyString& right);
 post: true return *this,false otherwise.
 
 
 
 
 void setInfo(const char *inLetter);
 post:copy contructor
 
 
 
 
 friend std::ostream& operator<<(std::ostream& out, const MyString& source);
 post: Returns out, false otherwise.
 
 
 
 
 friend std::istream& operator>>(std::istream& in, const MyString& target);
 post: post: Returns in, false otherwise.
 
 
 
 
 friend bool operator==(const MyString&left, const MyString&right);
 post: return strcmp(left.letter,right.letter) == 0, false otherwise
 
 
 
 
 friend bool operator<=(const MyString&left, const MyString&right);
 post: return strcmp(left.letter,right.letter) <= 0, false otherwise
 
 
 
 
 friend bool operator<(const MyString&left, const MyString&right);
 post: return strcmp(left.letter,right.letter) < 0, false otherwise
 
 
 
 
 friend bool operator>=(const MyString&left, const MyString&right);
 post: return strcmp(left.letter,right.letter) >= 0, false otherwise
 
 
 
 
 friend bool operator>(const MyString&left, const MyString&right);
 post: return strcmp(left.letter,right.letter) > 0, false otherwise
 
 
 
 
 friend bool operator!=(const MyString&left, const MyString&right);
 post: return strcmp(left.letter,right.letter) != 0, false otherwise
 
 
 
 
 friend bool operator+(const MyString&left, const MyString&right);
 post: return temp, false otherwise
 
 
 
 
 friend bool operator+=(const MyString&left, const MyString&right);
 post: return left, false otherwise
 
 
 
 
 friend bool operator+=(const MyString&left, const char *inLetter);
 post: return left, false otherwise
 */


#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;
namespace cs_mystring {
  
    class MyString{
    private:
        char *letter;
        
    public:
        void read(ifstream &in, char stop);
        MyString();
        MyString(const char *inLetter);
        MyString(const MyString& right);
        ~MyString();
        int length() const;
        MyString operator=(const MyString& right);
        void setInfo(const char *inLetter);
        friend std::ostream& operator<<(std::ostream& out, const MyString& source);
        friend std::istream& operator>>(std::istream& in, MyString& target);
        char operator[](int index) const;
        char& operator[](int index);
        
        friend bool operator==(const MyString&left, const MyString&right);
        friend bool operator<(const MyString&left, const MyString&right);
        friend bool operator<=(const MyString&left, const MyString&right);
        friend bool operator>(const MyString&left, const MyString&right);
        friend bool operator>=(const MyString&left, const MyString&right);
        friend bool operator!=(const MyString&left, const MyString&right);
        friend MyString operator+(const MyString&left, const MyString&right);
        friend MyString& operator+=( MyString&left, const MyString&right);
        friend MyString& operator+=( MyString&left, const char *inLetter);
        
    };
}
#endif /* Header_h */

