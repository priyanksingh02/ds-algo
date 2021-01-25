#ifndef PRINT_H
#define PRINT_H
#include <iostream>

void print() {
    std::cout << std::endl;
}

template <typename T,typename... TAIL>
void print(T item,TAIL... tail) {
    std::cout << item << " ";
    print(tail...);
}
#endif //print_h
