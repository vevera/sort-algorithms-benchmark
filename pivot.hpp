#ifndef PIVOT_HPP
#define PIVOT_HPP

#include "myrandomgen.hpp"

int pivot(int start, int end){
  return start + (end - start)/2;
}

int pivot_r(int start, int end){

  auto mygen = MyRandomGen::instance();
  //mygen->change_interval(start, end);
  int n = end - start + 1;
  return start + mygen->generate() % n;
}

#endif