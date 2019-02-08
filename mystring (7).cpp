/*
 Mian Wei
 Assignment5
 10/27
 David Harden
 
 CLASS INVARIANT:
 there is one data member in this class. "char *letter" is a pointer array and it stores char. For "+=" only MyStrings can be on the left-hand side, but either MyStrings or C-strings may appear on the right side.  FoR "+" The operator are able to handle either MyString objects or C-strings on either side of the operator.
 
 correct ouput:
 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z
 
 ----- Now reading MyStrings from file
 
 ----- first, word by word
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 Read string =
 
 ----- now, line by line
 Read string = The  first  time  we  will
 Read string =     read individual words, next
 Read string = we read whole lines
 
 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ
 
 ----- Testing relational operators between MyStrings
 Comparing app to apple
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing apple to
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing  to Banana
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing Banana to Banana
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false
 
 ----- Testing relations between MyStrings and char *
 Comparing he to hello
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing why to wackity
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 
 ----- Testing concatentation on MyStrings
 outrageous + milk = outrageousmilk
 milk +  = milk
 + cow = cow
 cow + bell = cowbell
 
 ----- Testing concatentation between MyString and char *
 abcde + XYZ = abcdeXYZ
 XYZ + abcde = XYZabcde
 
 ----- Testing shorthand concat/assign on MyStrings
 who += what = whowhatandwhowhat
 what += WHEN = whatWHENandwhatWHEN
 WHEN += Where = WHENWhereandWHENWhere
 Where += why = WherewhyandWherewhy
 
 ----- Testing shorthand concat/assign using char *
 I love  += programming = I love programming
 
 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is BinkyBoo
 val is winky
 after assign,  val is BinkyBoo
 Program ended with exit code: 0
 */
#include <iostream>
#include <cassert>
#include <cstring>

#include <fstream>

#include "mystring.h"
using namespace std;
namespace cs_mystring {
 
    void MyString::read(ifstream &in, char stop){
        in.getline(letter, 127, stop);
       
    }
    
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
    void MyString::setInfo(const char *inLetter)
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
        char arr[127];
        char *temp = arr;
        in >> temp;
        strcpy(temp,target.letter);
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
    MyString operator+(const MyString&left, const MyString&right){
        char arr[127];
        char *temp = arr;
        strcpy(temp,left.letter);
        strcat(temp,right.letter);
        return temp;
    }
    
    MyString& operator+=( MyString&left, const MyString&right){
        strcat(left.letter,right.letter);
        return left;
    }
    
    MyString& operator+=( MyString&left, const char *inLetter ){
        strcat(left.letter,inLetter);
        return left;
    }
}
