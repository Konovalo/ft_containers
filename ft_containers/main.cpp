#include <iostream>
#include <vector>
#include "container.hpp"

int main() {
    std::vector <int> a1;
    std::vector <int> a11(5, 10);
    ft::vector <int> a2;
    ft::vector <int> a22(5, 10);

    std::cout << a11.size() << std::endl;
    std::cout << a22.size();

    int numbers[]={10,20,30,40,50};
  ft::InputIterator <int> from(numbers);
  ft::InputIterator <int> until(numbers+5);
  for (ft::InputIterator <int> it=from; it!=until; it++)
    std::cout << *it << ' ';
  std::cout << '\n';

    return 0;
}
