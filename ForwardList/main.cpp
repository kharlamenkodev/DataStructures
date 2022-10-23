#include <iostream>
#include "forward_list.h"
#include <cassert>


int main()
{
    forward_list <int> list;

    assert(list.empty() == true);

    for (size_t i = 0; i < 300; i++){
        list.push_front(i);
    }
    
    assert(list.size() == 300);

    for (size_t i = 0; i < 123; i++){
        list.pop_front();
    }

    auto it = list.begin();

    while (it != list.end()){
        std::cout << *it << std::endl;
        it++;
    }

    assert(list.size() == 177);
}