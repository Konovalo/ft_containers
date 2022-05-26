 #ifndef _CONTAINERS_H
 #define _CONTAINERS_H 

#include<alloca.h>
#include<iostream>

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
            for(int i = 0; i < _size; i++){
                _vector[i] = val;
            }
        }

        template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
        : _alloc(alloc), _size(last-first), _capacity(last-first)
        {
             _vector = _alloc.allocate(_capacity);
             
        }

        
        private:
        allocator_type _alloc;
        pointer _vector;
        size_t _capacity;
        size_t _size;
    };




}
#endif