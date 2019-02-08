//
//  main.cpp
//  8.1vector
// david harden
//  Created by mian wei  on 11/16/17.
//  Copyright © 2017 mian wei. All rights reserved.
// this is a program that will sort the array that user enter

#include <iostream>
#include <vector>
using namespace std;

struct highscore{
public:
    int score;
    char name[24];
};

void initializeData(vector<highscore>& scores);
void sortData(vector<highscore>& scores);
void displayData(const vector<highscore>& scores);
vector<highscore>::iterator Smallest(const vector<highscore> scores
                                     , vector<highscore>::iterator start);



int main(){
    vector<highscore> scores;
    initializeData(scores);
    sortData(scores);
    displayData(scores);
    
}


void initializeData(vector<highscore>& scores){
    
    vector<highscore>::size_type currentSize;
    cout << "how many scores you want to enter? ";
    cin >> currentSize;
    scores = vector<highscore>(currentSize);
    for (vector<highscore>::iterator i = scores.begin(); i != scores.end(); i++)
    
    {
        cout << "enter the score: ";
        cin >> (*i).score;
        cout << "enter the name: ";
        cin >> (*i).name;
    }
}






vector<highscore>::iterator Smallest(const vector<highscore>& scores
                                     , vector<highscore>::iterator start)
{
    
    vector<highscore>::iterator target = start;
    // start = keep track of the start value
    for (vector<highscore>::iterator i = start; i != scores.end(); i++)
    {
        
        if ((*i).score < (*target).score){
            target = i;
        }
    }
    return target;
}







void sortData(vector<highscore>& scores){
//    int upperBound = size - 1;
//    for (int i = 0; i < upperBound-1; i ++){
//        int index_of_smallest = indexOfSmallest(scores, i, upperBound+1);
//        cout<<index_of_smallest;
//        highscore temp = scores[i];
//        scores[i] = scores[index_of_smallest];
//        scores[index_of_smallest] = temp;
//
//    }
    
    for (vector<highscore>::iterator i = scores.begin(); i != scores.end()
         ; i++)
    {
        
        vector<highscore>::iterator smallest = Smallest(scores,i);
        swap(i -> score, smallest -> score);
        swap(i -> name, smallest -> name);
    }
}






void displayData(const vector<highscore>& scores){
    //    for (int i = 0; i < size; i ++){
    //        cout << scores[i].score << endl;
    //        cout << scores[i].name  << endl;
    //    }
    for (vector<highscore>::const_iterator i = scores.begin(); i != scores.end(); i++)
    {
        cout << (*i).score ;
        cout << (*i).name << endl;
    }
}

/*
 how many scores you want to enter? 3
 enter the score: 3
 enter the name: e
 enter the score: 4
 enter the name: r
 enter the score: 2
 enter the name: w
 2w
 3e
 4r
 */
