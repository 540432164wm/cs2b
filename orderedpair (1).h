//
//  orderedpair.hpp
//  a8.2
//
//  Created by mian wei  on 11/18/17.
//  Copyright © 2017 mian wei. All rights reserved.
//

#ifndef orderedpair_hpp
#define orderedpair_hpp

#include <iostream>
#include <cstdlib>

/* precondition for setFirst and setSecond: the values of first and second
 cannot be equal,
 except when they are both equal to DEFAULT_VALUE.
 */

namespace cs_pairs {
    template <class T>
    class orderedPair {
    public:
        
        static const T DEFAULT_VALUE;
        orderedPair(T newFirst = DEFAULT_VALUE
                    , T newSecond = DEFAULT_VALUE);
        void setFirst(T newFirst);
        void setSecond(T newSecond);
        T getFirst();
        T getSecond();
        orderedPair operator+(const orderedPair& right);
        bool operator<(const orderedPair& right);
        void print();
        class DuplicateMemberError{};
    private:
        T first;
        T second;
    };
    
    template <class T>
    // You will need a template prefix here above this declaration
    const T orderedPair<T>::DEFAULT_VALUE = T();
    
}
#include "orderedpair.cpp"
#endif /* orderedpair_hpp */
