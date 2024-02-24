#ifndef SORT_ALGORITHMS_HPP
#define SORT_ALGORITHMS_HPP

#include <iostream>
#include "pivot.hpp"
#include "utils.hpp"
#include "instances.hpp"
#include "runtime.hpp"

template <typename T>
T* heap_sort(T* vector, int n){
  auto heapify = [&vector](int i, int v_size) {

    bool heapified = false;
    int largest;
    int left;
    int right;

    while(!heapified) {
      largest = i;
      left = 2 * i + 1;
      right = 2 * i + 2;

      if (left < v_size && vector[left] > vector[largest])
        largest = left;

      if (right < v_size && vector[right] > vector[largest])
        largest = right;

      if (largest != i) {
        swap<T>(vector[i], vector[largest]);
        i = largest;
      }
      else
        heapified = true;     
    }
  };

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(i, n);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap<T>(vector[0], vector[i]);
    heapify(0, i);
  }
  return vector;
}

template <typename T, int pivot_fun(int, int)>
int partition(T* vector, int low, int high) {

  int r = pivot_fun(low, high);
  swap<T>(vector[r], vector[high]);

  T pivot = vector[high];
  int i = (low - 1);

  for (int j = low; j <= high- 1; j++) {
    if (vector[j] <= pivot) {
      i++;
      swap<T>(vector[i], vector[j]);
    }
  }
  swap<T>(vector[i + 1], vector[high]);
  return (i + 1);
}

template<typename T, int pivot_fuc(int, int)>
void internal_quick_s(T* vector, int low, int high) {
  if (low < high) {
    int p_point = partition<T, pivot_fuc>(vector, low, high);

    internal_quick_s<T, pivot_fuc>(vector, low, p_point - 1);
    internal_quick_s<T, pivot_fuc>(vector, p_point + 1, high);
  }
}

template <typename T>
T* quick_sort(T* vector, int n) {
  internal_quick_s<T, pivot>(vector, 0, n-1);
  return vector;
}

template <typename T>
T* random_quick_sort(T* vector, int n) {
  internal_quick_s<T, pivot_r>(vector, 0, n-1);
  return vector;  
}

template <typename T>
T* insertion_sort(T* vector, int begin, int end) {
  int i, j;
  for (i = begin + 1; i < end; i++) {
    j = i;
    while (j > begin && vector[j - 1] > vector[j]) {
        swap<T>(vector[j], vector[j-1]);
        j = j - 1;
    }
  }
  return vector;
}

template <typename T, T* insertion_sort(T*, int, int) = nullptr>
T* internal_introsort(T* vector, int low, int high, int depth_limit) {
  
  int n = high - low;

  if (insertion_sort != nullptr && n < 18) {
    insertion_sort(vector, low, high);
    return vector;
  }

  if (depth_limit == 0) { 
    heap_sort<T>(vector, n);
    return vector;
  }

  if (low >= high) 
    return vector;

  int p_point = partition<T, pivot_r>(vector, low, high-1);
  internal_introsort<T, insertion_sort>(vector, low, p_point, depth_limit - 1);
  internal_introsort<T, insertion_sort>(vector, p_point+1, high, depth_limit - 1);

  return vector;  
}

template <typename T>
T* intro_sort(T* vector, int n) {
  int depth_limit = 2 * log2(n);
  internal_introsort<T>(vector, 0, n, depth_limit);
  return vector;  
}

template <typename T>
T* intro_sort_with_insertion(T* vector, int n) {
  int depth_limit = 2 * log2(n);
  internal_introsort<T, insertion_sort<T>>(vector, 0, n, depth_limit);
  return vector;  
}

template <typename T>
std::map<std::string, double (*) (T*, int, int)> get_run_sort_algorithms(){

  std::map<std::string, double (*) (T*, int, int)> run_algorithms_map = {
    {"HeapSort", run_instances<T, heap_sort<T>>},
    {"QuickSort", run_instances<T, quick_sort<T>>},
    {"RandomQuickSort", run_instances<T, random_quick_sort<T>>},
    {"IntroSort", run_instances<T, intro_sort<T>>},
    {"IntroSort with Insertion", run_instances<T, intro_sort_with_insertion<T>>}
  };

  return run_algorithms_map;
}

#endif