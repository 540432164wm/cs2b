
//
//  sequence.hpp
//  a9
//
//  Created by mian wei  on 11/22/17.
//  Copyright © 2017 mian wei. All rights reserved.
//

#ifndef sequence_hpp
#define sequence_hpp
namespace cs_sequence{

    class sequence{
    public:
        typedef std::size_t size_type;
        typedef int value_type;
        sequence();
        sequence(const sequence& copyMe);

        ~sequence();

        sequence operator=(const sequence& right);
        void start();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        size_type size() const;
        bool is_item() const;
        value_type current() const;

    private:
        struct node {
            value_type data;
            node* next;
        };
        node* headptr, *tailptr, *cursor, *precursor;
        int numitems;
        void copyList(const sequence& copyMe);
        void deleteList();
    };
}
#endif /* sequence_hpp */

