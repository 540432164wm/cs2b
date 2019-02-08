/*
 Assignment 3.2
 Mian Wei
 10/15
 this is a program that get in the name and score, then sort it and print them in order.
 How many scores will you enter?: 4
 Enter the name for score #1: Suzy
 Enter the score for score #1: 600
 Enter the name for score #2: Kim
 Enter the score for score #2: 9900
 Enter the name for score #3: Armando
 Enter the score for score #3: 8000
 Enter the name for score #4: Tim
 Enter the score for score #4: 514
 
 Top Scorers:
 Kim: 9900
 Armando: 8000
 Suzy: 600
 Tim: 514
 
 */
#include <iostream>
#include <string>
using namespace std;

void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void swap(string names[], int scores[], int index1, int index2);
int indexOfSmallest( const int scores[], int startingIndex, int size);
void displayData(const string names[], const int scores[], int size);

int main(){
    
    int size;
    cout << "How many scores will you enter?: ";
    cin >> size;
    string* names = new string[size];
    int* scores = new int[size];
    
    
    initializeArrays( names, scores, size);
    sortData( names, scores, size);
    displayData( names, scores, size);
    
    delete [] names;
    delete [] scores;
}





//cin the names and score into program
void initializeArrays(string names[], int scores[], int size){
    cout << "Enter the name for score #1: ";
    cin >> names[0];
    cout << "Enter the score for score #1: ";
    cin >> scores[0];
    cout << "Enter the name for score #2: ";
    cin >> names[1];
    cout << "Enter the score for score #2: ";
    cin >> scores[1];
    cout << "Enter the name for score #3: ";
    cin >> names[2];
    cout << "Enter the score for score #3: ";
    cin >> scores[2];
    cout << "Enter the name for score #4: ";
    cin >> names[3];
    cout << "Enter the score for score #4: ";
    cin >> scores[3];
    
}





//it switch the index of names and scores
void swap(string names[], int scores[], int index1, int index2){
    int temp1;
    string temp2;
    temp1 = scores[index1];
    scores[index1] = scores[index2];
    scores[index2] = temp1;
    
    temp2 = names[index1];
    names[index1] = names[index2];
    names[index2] = temp2;
    
}





//it swap the result and count
void sortData(string names[], int scores[], int size){
    
    for (int count = 0; count < size - 1; count++){
        int result = indexOfSmallest(scores,count,size);
        swap(names,scores,result,count);
    }
}





//it find the smallest of the score[] and sort it
int indexOfSmallest( const int scores[], int startingIndex, int size){
    int targetIndex = startingIndex;
    
    for (int count = startingIndex + 1; count < size; count++){
        if (scores[count] > scores[targetIndex]){
            targetIndex = count;
        }
    }
    
    return targetIndex;
}





//it print results
void displayData(const string names[], const int scores[], int size){
    
    cout <<"Top Scorers: "<<endl;
    for (int count = 0; count < size; count++){
        
        
        cout << names[count] << ": " << scores[count] << endl;
        
    }
}

