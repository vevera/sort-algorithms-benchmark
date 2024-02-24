#ifndef INSTANCES_HPP
#define INSTANCES_HPP

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

#include "pivot.hpp"
#include "utils.hpp"
#include "myrandomgen.hpp"

template <typename T>
void print_instance(T*& instance, int instance_size){

  auto* iterator = instance;

  for (T* end = iterator + instance_size; iterator != end; ++iterator){
    std::cout << *iterator << "|";
  }

  std::cout << std::endl;
}

template <typename T>
bool random_instance(T* vector, int n){
  std::cout << "Random Instance\n\n";
  
  MyRandomGen * mygen = MyRandomGen::instance();

  for (T *end = vector + n; vector != end; ++vector) {
    *vector = mygen->generate();
  }
  return true;
}

template <typename T>
bool worst_case_instance(T* vector, int n){
  std::cout << "WorstCase Instance\n\n";
  int pivot_{0};
  T next_value{1};

  T** v_ptr2 = new T*[n];
  T** v_ptr2_c = v_ptr2;

  for (T** end_ptr = v_ptr2_c + n; v_ptr2_c != end_ptr; ++v_ptr2_c) {
    *v_ptr2_c = vector++;
  }

  for (int start = 0; start <= n-1; start++) {
    pivot_ = pivot(start, n-1);
    *v_ptr2[pivot_] = next_value++;
    swap<T*>(v_ptr2[start], v_ptr2[pivot_]);
  }

  delete[] v_ptr2;

  return true;
}

template <typename T>
bool ascending_instance(T* vector, int n){
  std::cout << "Ascending Instance\n\n";
  T acc{1};
  for (T *end = vector + n; vector != end; ++vector) {
    *vector = acc++;
  }
  return true;
}

template <typename T>
bool descending_instance(T* vector, int n){
  std::cout << "Descending Instance\n\n";
  T inc{n};
  for (T *end = vector + n; vector != end; ++vector) {
    *vector = inc--;
  }
  return true;
}

template <typename T>
T* get_instance(std::string instance_type, int n){

  std::map<std::string, bool (*) (T*, int)> instances_map = {
          {"A", random_instance<T>},
          {"C", ascending_instance<T>},
          {"D", descending_instance<T>},
          {"P", worst_case_instance<T>},};

  T* allocated_instance = new T[n];
  instances_map.find(instance_type)->second(allocated_instance, n);

  return allocated_instance;
}

#endif