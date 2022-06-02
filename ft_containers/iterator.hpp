 #ifndef _ITERATR_H
 #define _ITERATR_H 

 #include<alloca.h>
 #include<iostream>

namespace ft{
     template <class Category,              // iterator::iterator_category
          class T,                     // iterator::value_type
          class Distance = ptrdiff_t,  // iterator::difference_type
          class Pointer = T*,          // iterator::pointer
          class Reference = T&         // iterator::reference
          > 
    class iterator {
        public:
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;
       
       /* iterator (pointer val)
        : _val(val)
        {}*/
       reference operator*(pointer val) {return *_val;}

       iterator& operator++() {++_val;return *this;}
       
       iterator operator++(value_type) {
           iterator tmp(*this);
           operator++();
           return tmp;
           }
        bool operator!=(const iterator& rhs) const {return _val!=rhs._val;}
        reference operator*() {return *_val;}
        private:
            pointer _val;
    };
}

#endif