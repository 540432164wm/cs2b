#include <iostream>
#include <cassert>
#include <cstring>
#include "MyString.h"
using namespace std;
namespace cs_mystring {

    
    MyString::MyString(){
        letter = new char[1];
        strcpy(letter, "");
    }

    MyString::MyString(const char *inLetter){
        letter = new char[strlen(inLetter) + 1];
        strcpy(letter, inLetter);
    }

    MyString::MyString(const MyString& right)
    {
       
        letter = new char[strlen(right.letter) + 1];
        strcpy(letter, right.letter);
    }

    MyString::~MyString()
    {
        delete [] letter;
    }

    int MyString::length()const{
        return (int) strlen(letter);
    }

    MyString MyString::operator=(const MyString& right)
    {
        if (this != &right){
           
            delete [] letter;
            letter = new char[strlen(right.letter) + 1];
            strcpy(letter, right.letter);
        }
        return *this;
    }
    void MyString::setInfo(const char *inLetter, int inSize)
    {
    
        delete [] letter;
        letter = new char[strlen(inLetter) + 1];
        strcpy(letter, inLetter);
    }


    ostream& operator<<(ostream& out, const MyString& source)
    {
        out << source.letter;
        return out;
    }

    istream& operator>>(istream& in, MyString& target)
    {
        in.getline(target.letter, 127);
        return in;
    }

    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(letter));
        return letter[index];
    }

    char& MyString::operator[](int index)
    {
        assert(index >= 0 && index < strlen(letter));
        return letter[index];
    }

    bool operator==(const MyString &left, const MyString &right){
        return strcmp(left.letter,right.letter) == 0;
    }



    bool operator<(const MyString &left, const MyString &right){
        return strcmp(left.letter,right.letter) < 0;
    }


    bool operator<=(const MyString &left, const MyString &right){
        return strcmp(left.letter,right.letter) <= 0;
    }



    bool operator>(const MyString &left, const MyString &right){
        return strcmp(left.letter,right.letter) > 0;
    }



    bool operator>=(const MyString &left, const MyString &right){
        return strcmp(left.letter,right.letter) >= 0;
                      
    }
    bool operator!=(const MyString &left, const MyString &right){
       return strcmp(left.letter,right.letter) != 0;
    }
}
