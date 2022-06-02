 #ifndef _CONTAINERS_H
 #define _CONTAINERS_H 

#include<alloca.h>
#include<iostream>
#include"iterator.hpp"

namespace ft{

    template <typename T, class Alloc = std::allocator<T> >
    class vector{
        public:
        typedef Alloc allocator_type;
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef size_t size_type;
        
        explicit 
        vector (const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _capacity(0)
        {}
        
        explicit 
        vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _capacity(n), _size(n)
        {
            _vector = _alloc.allocate(_capacity);
            for(size_t i = 0; i < _size; i++){
                _alloc.construct(&_vector[i], val);
               // _vector[i] = val;
            }
        }

      template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _size(0)
        {
            InputIterator tmp(first);
            while (tmp != last){
                _size++;
                tmp++;
            }
            _capacity = _size;
            _vector = _alloc.allocate(_capacity); 
            first++;
            for(size_t i = 0; i < _size; i++){
                _alloc.construct(&_vector[i], *first); //?????
                first++;
             }
        }



        size_type size() { return _size;} //const?????

        
        private:
        allocator_type _alloc;
        pointer _vector;
        size_t _capacity;
        size_t _size;
    };




}
#endif