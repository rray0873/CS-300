# CS 300 -- Project One

## Run-Time and Memory Analysis of Data Structures

### Overview

The purpose of Project One was to evaluate multiple data structures to
determine the most efficient approach for building an advising
assistance program. The system needed to:

-   Load course data from a CSV file\
-   Print courses in alphanumeric order\
-   Search for and display a specific course including prerequisites

The data structures evaluated were:

-   Vector\
-   Hash Table\
-   Binary Search Tree (BST)

------------------------------------------------------------------------

## Vector

### Run-Time Complexity

-   Insert (push_back): O(1) amortized\
-   Search: O(n)\
-   Sort for ordered output: O(n log n)\
-   Print after sort: O(n)

Total time to print sorted list: O(n log n)

### Memory Usage

-   O(n) memory for n elements\
-   Contiguous memory layout\
-   May temporarily allocate extra memory during resizing

### Evaluation

Vectors are simple and efficient for iteration, but searching requires
linear time. Sorting is required to print courses in order.

------------------------------------------------------------------------

## Hash Table

### Run-Time Complexity (Average Case)

-   Insert: O(1)\
-   Search: O(1)\
-   Print sorted list:
    -   Gather elements: O(n)\
    -   Sort: O(n log n)\
    -   Print: O(n)

Total time to print sorted list: O(n log n)

### Run-Time Complexity (Worst Case)

-   Insert/Search: O(n) due to collisions

### Memory Usage

-   O(n) for stored elements\
-   Additional overhead for buckets and collision handling\
-   Typically uses more memory than vector or BST

### Evaluation

Hash tables provide the fastest average search time but do not maintain
order. Additional sorting is required for ordered output.

------------------------------------------------------------------------

## Binary Search Tree (BST)

### Run-Time Complexity (Average Case)

-   Insert: O(log n)\
-   Search: O(log n)\
-   In-order traversal (sorted print): O(n)

### Run-Time Complexity (Worst Case)

-   Insert/Search: O(n) if tree becomes unbalanced

### Memory Usage

-   O(n) for n nodes\
-   Each node stores data plus two pointers\
-   Slightly more memory overhead than vector

### Evaluation

The BST naturally maintains sorted order through in-order traversal
while providing efficient average search performance.

------------------------------------------------------------------------

## Final Recommendation

The Binary Search Tree (BST) was selected for Project Two implementation
because:

-   It supports sorted output directly through in-order traversal\
-   It provides efficient average-case search performance\
-   It satisfies both lookup and ordering requirements without
    additional sorting

This analysis demonstrates how data structure selection directly impacts
runtime efficiency, memory usage, and overall software performance.
