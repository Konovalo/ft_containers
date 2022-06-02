 #ifndef _ITERATR_H
 #define _ITERATR_H 

 #include<alloca.h>
 #include<iostream>

namespace ft{
    //base class
     template <class Category,             
          class T,                     
          class Distance = ptrdiff_t,  
          class Pointer = T*,          
          class Reference = T&        
          > 
    class iterator {
        public:
            typedef T         value_type;
            typedef Distance  difference_type;
            typedef Pointer   pointer;
            typedef Reference reference;
            typedef Category  iterator_category;
    
    class MyIterator: 
        public std::iterator<std::input_iterator_tag, int>
    {
        value_type* val;
    }
        iterator (pointer val): _val(val){}
        iterator(const iterator& mit) : _val(mit._val) {}

        iterator& operator++() {++_val;return *this;}
        
        iterator operator++(value_type) {
           iterator tmp(*this);
           operator++();
           return tmp;
           }

        bool operator==(const iterator& rhs) const {return _val==rhs._val;}
        bool operator!=(const iterator& rhs) const {return _val!=rhs._val;}   
        reference operator*() {return *_val;}

        private:
            pointer _val;
    };
}

#endif