# Sorting Algorithms in C++

This project contains implementations of common sorting algorithms in C++. Each algorithm is implemented as a separate function and demonstrated in a simple test program.

## Implemented Sorting Algorithms

- **Bubble Sort**: A simple comparison-based sorting algorithm.
- **Selection Sort**: Finds the minimum element and places it at the correct position.
- **Insertion Sort**: Builds the sorted array one item at a time.
- **Merge Sort**: A divide-and-conquer algorithm that splits the array into halves and merges them in sorted order.
- **Quick Sort**: Selects a pivot element and partitions the array around it.

## How to Run

1. Clone the repository:
   ```sh
   git clone https://github.com/cycloholic/c/sorting-algorithms.git
   cd sorting-algorithms
   ```

2. Compile the program using a C++ compiler (g++ recommended):
   ```sh
   g++ sorting_algorithms.cpp -o sorting
   ```

3. Run the executable:
   ```sh
   ./sorting
   ```

## Example Output
```
Original array: 64 25 12 22 11 
Bubble Sorted: 11 12 22 25 64 
Selection Sorted: 11 12 22 25 64 
Insertion Sorted: 11 12 22 25 64 
Merge Sorted: 11 12 22 25 64 
Quick Sorted: 11 12 22 25 64 
```

## Complexity Analysis

| Algorithm       | Best Case | Average Case | Worst Case |
|---------------|-----------|-------------|-------------|
| Bubble Sort   | O(n)      | O(n²)       | O(n²)       |
| Selection Sort| O(n²)     | O(n²)       | O(n²)       |
| Insertion Sort| O(n)      | O(n²)       | O(n²)       |
| Merge Sort    | O(n log n)| O(n log n)  | O(n log n)  |
| Quick Sort    | O(n log n)| O(n log n)  | O(n²)       |

## License

This project is open-source and available under the MIT License.

Screenshot
![Main Interface](https://github.com/cycloholic/c/blob/ce8ac084641f063e3efcc4db22d3dbf25f332200/ScreenshotSorting.png)
