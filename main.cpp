#include <exception>
#include <iostream>

#include "instances.hpp"
#include "myrandomgen.hpp"
#include "sort_algorithms.hpp"
#include "runtime.hpp"

#include <algorithm>

int main(int argc, char **argv) {

  int instances_size, amount_of_instances;
  double time{};
  std::string instance_type;

  if (argc != 4) {
    std::cout << "Invalid Argument Size!!!\n";
    return 0;
  }

  try{
    instance_type = argv[1];
    instances_size = std::stoi(argv[2]);
    amount_of_instances = std::stoi(argv[3]);
  }
  catch(std::exception &e){
    std::cout << "Invalid Arguments!!\n";
    std::cout << e.what() << std::endl;
    return 0;
  }

  MyRandomGen::instance()->change_interval(1, instances_size);

  auto * instance = get_instance<int>(instance_type, instances_size);
  auto run_sort_algorithms = get_run_sort_algorithms<int>();

  for (auto run_sort_algorithm : run_sort_algorithms){
    time = run_sort_algorithm.second(instance, instances_size, amount_of_instances);
    std::cout << run_sort_algorithm.first << " took " << time << "s to run " << amount_of_instances << " instances!\n";  
  }

  return 0;
}