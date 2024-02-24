# sort-algorithms-benchmark

This project aims to benchmark various well-known sorting algorithms across different types of array instances.

## Algorithms Implemented

The following sorting algorithms are implemented in this project:

- HeapSort
- QuickSort
- Random QuickSort
- IntroSort
- IntroSort with Insertion

## Types of Array Instances

For the benchmark, you can specify the following types of instances to be tested:

- **Random Instance**: All elements of the array are random values between 1 and the size of the array.
- **Ascending Instance**: Elements of the array are in ascending order, from one to the size of the array.
- **Descending Instance**: Elements of the array are in descending order, from the size of the array to one.
- **Worst Case Instance**: Elements are shuffled in a way that algorithms using a pivot element in sorting always perform the maximum number of comparisons.

## Compilation

You can compile the project using any compiler. If you're using the MSVC compiler, follow these steps:

1. Create a build directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```

2. Run CMake to generate the build files:
   ```bash
   cmake ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

## Running the Program

To run the program, follow the syntax below:

```bash
sort_algorithms.exe <INSTANCE TYPE> <ARRAY SIZE> <NUMBER OF INSTANCES>
```

- **INSTANCE TYPE**: Specify the type of instance you want to benchmark. Possible values:
  - A for Random Instance
  - C for Ascending Instance
  - D for Descending Instance
  - P for Worst Case Instance

- **ARRAY SIZE**: The number of elements in the array.

- **NUMBER OF INSTANCES**: The number of times you want to benchmark the same instance of size ARRAY SIZE.