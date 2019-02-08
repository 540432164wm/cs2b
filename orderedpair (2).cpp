//
//  orderedpair.cpp
//  a8.2
//
//  Created by mian wei  on 11/18/17.
//  Copyright © 2017 mian wei. All rights reserved.
//

//#include "orderedpair.hpp"

#include <cassert>
#include <iostream>
//using namespace std;

namespace cs_pairs {
    template <class T>
    orderedPair<T>::orderedPair(T newFirst, T newSecond) {
        setFirst(newFirst);
        setSecond(newSecond);
    }
    
    
    
    
    
    
    template <class T>
    void orderedPair<T>::setFirst(T newFirst) {
        // if statement to throw an exception if precondition not met goes here.
        if((newFirst == second)&&(newFirst != DEFAULT_VALUE)){
            throw DuplicateMemberError();
        }else {
             first = newFirst;
        }
    }
    
    
    
    
    
    
    template <class T>
    void orderedPair<T>::setSecond(T newSecond) {
        // if statement to throw an exception if precondition not met goes here.
        if((newSecond == first)&&(newSecond != DEFAULT_VALUE)){
            throw DuplicateMemberError();
        }else {
            second = newSecond;
        }
    }
    
    
    
    
    
    
    template <class T>
    T orderedPair<T>::getFirst() {
        return first;
    }
    
    
    
    
    
    
    template <class T>
    T orderedPair<T>::getSecond() {
        return second;
    }
    
    
    
    
    
    
    template <class T>
    orderedPair<T> orderedPair<T>::operator+(const orderedPair<T>& right) {
        return orderedPair<T>(first + right.first, second + right.second);
    }
    
    
    
    
    
    
    template <class T>
    bool orderedPair<T>::operator<(const orderedPair<T>& right) {
        return first + second < right.first + right.second;
    }
    
    
    
    
    
    
    
    template <class T>
    void orderedPair<T>::print() {
            std::cout << "(" << first << ", " << second << ")";
    }
}
