#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <iostream>
#include <cstdint>
#include <cstring>
#include <chrono>

template <typename T, T* sort_algorithm(T*, int)>
double calculate_single_execution_run_time(T* vector, int n){

    size_t size = n * sizeof(T);

    T* copy_vector = new T[n];
    std::memcpy(copy_vector, vector, size);

    auto start = std::chrono::steady_clock::now();
    
    sort_algorithm(copy_vector, n);
 
    auto end = std::chrono::steady_clock::now();

    delete[] copy_vector;
 
    // Calculating total time taken by the program.
    std::chrono::duration<double> time_taken = end - start;
 
    return time_taken.count();
}

template <typename T, T* sort_algorithm(T*, int)>
double run_instances(T* instance, int instance_size, int amount_of_instances){
    double total_run_time{0};
    double current_rt;
    
    for (int i = 0; i < amount_of_instances; i++){
        current_rt = calculate_single_execution_run_time<T, sort_algorithm>(instance, instance_size);
        total_run_time = total_run_time + current_rt;
    }

    return total_run_time;
}


#endif