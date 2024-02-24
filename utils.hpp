#ifndef UTILS_HPP
#define UTILS_HPP

template <typename T>
void swap(T& a, T& b){
    T aux = a;
    a = b;
    b = aux;
}

int log2(int x) {
    int result = 0;
    while (x >>= 1) result++; 
    return result;
}

#endif