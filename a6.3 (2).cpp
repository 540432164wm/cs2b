//
//  main.cpp
//  a6.3
//
//  Created by mian wei  on 11/2/17.
//  Copyright © 2017 mian wei. All rights reserved.
//
/*
 Mian Wei
 David Harden
 Assignment 6.3
 11/02
 this is a program that has a recursive function to sort an array of integers
 into ascending order using the following idea: place the smallest element in
 the first position, then sort the rest of the array by a recursive call. This
 is a recursive version of the selection sort.
 */
#include <iostream>
using namespace std;

int indexOfSmallest(const int list[], int startingIndex, int numItems);
void sortArray( int list[], int upperBound, int lowerBound);

int main() {
    int list[] = {5,3,8,6,1,7,2};
    sortArray( list, 6, 0);
    for (int i = 0; i < 7; i++){
        cout << list[i] << endl;
    }
    
}







/*
 list is a integer arrey, startingIndex is the first index that will be compare
 and numItems is how many numbers are in the array. This function compare each
 elements with startingIndex and the smaller one will be the number that compare
 next time.
 */
int indexOfSmallest(const int list[], int startingIndex, int numItems)
{
    int targetIndex = startingIndex;
    
    for (int count = startingIndex; count < startingIndex+numItems; count++){
        if (list[count] < list[targetIndex]){
            targetIndex = count;
        }
    }
    
    return targetIndex;
}







/*
 list is a integer arrey, upperBound is the bigger bound of the array and the
 lowerBound is the smaller bound. This function sort the numbers by switch the
 index between  smallestIndex and lowerBound and it recursively call itself
 until upperBound <= lowerBound.
*/
void sortArray( int list[], int upperBound, int lowerBound){
    if (upperBound <= lowerBound){
        return;
    }
    int temp;
    int smallestIndex = indexOfSmallest(list,
                                        lowerBound, upperBound - lowerBound+1);
    
    temp = list[smallestIndex];
    list[smallestIndex] = list[lowerBound];
    list[lowerBound] = temp;
    
    sortArray( list, upperBound, lowerBound +1);
    
}

/*
// 5 3 8 6 1 7 2
lower = 0 upper =7
// 1 3 8 6 5 7 2
lower = 1 upper = 7 left = 7-1
// 1 2 8 6 5 7 3

// 1 2 3 6 5 7 8
*/


/*
 output；
 1
 2
 3
 5
 6
 7
 8
*/

