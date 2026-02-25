# CS 300 – Data Structures and Algorithms  
Southern New Hampshire University  

## Project Overview

This repository contains two major artifacts from CS 300 focused on evaluating and implementing efficient data structures for an academic advising system.

The objective was to design a scalable solution capable of:

- Loading course data from a CSV file  
- Printing courses in alphanumeric order  
- Searching for a specific course  
- Displaying prerequisite relationships  

The project emphasized algorithm analysis, runtime complexity, memory efficiency, and maintainable C++ design.

---

# Project One – Data Structure Analysis

## Engineering Objective

Determine which data structure provides the best balance of:

- Efficient search performance  
- Sorted output capability  
- Memory efficiency  
- Scalability  

Three data structures were evaluated:

- Vector  
- Hash Table  
- Binary Search Tree (BST)  

---

## Performance Comparison

| Data Structure | Insert (Avg) | Search (Avg) | Sorted Output | Memory |
|---------------|-------------|--------------|--------------|--------|
| Vector | O(1) | O(n) | O(n log n) | O(n) |
| Hash Table | O(1) | O(1) | O(n log n) | O(n) + bucket overhead |
| BST | O(log n) | O(log n) | O(n) | O(n) + pointer overhead |

---

## Analysis Summary

### Vector
- Simple structure with contiguous memory.  
- Requires sorting before ordered output.  
- Linear-time searching.  

### Hash Table
- Fastest average lookup time.  
- Does not maintain order.  
- Additional memory overhead for bucket structure.  

### Binary Search Tree
- Naturally maintains sorted order via in-order traversal.  
- Efficient average-case searching.  
- Meets both lookup and ordering requirements without additional sorting.  

---

## Final Decision

The Binary Search Tree was selected for implementation because it:

- Maintains natural alphanumeric ordering  
- Provides efficient average-case search performance  
- Eliminates the need for repeated sorting  

The decision was guided by runtime and memory analysis rather than convenience.

---

# Project Two – Advising Assistance Program

## Implementation Summary

A C++ command-line application was developed using a custom Binary Search Tree implementation.

The program:

- Loads course data into a BST  
- Prints courses in sorted order  
- Searches for specific course details  
- Displays prerequisite relationships  

## Technical Highlights

- Custom BST with recursive insertion and traversal  
- CSV parsing without external libraries  
- Input validation and error handling  
- Modular function design  
- Clean separation of logic and user interface  

---

# Reflection and Growth

## Problem Solved

Built a scalable advising system capable of storing and retrieving structured academic data efficiently.

## Technical Growth

This project strengthened my ability to:

- Analyze algorithm complexity before implementation  
- Compare data structures based on performance characteristics  
- Implement recursive tree structures  
- Write modular, maintainable C++ code  
- Design programs with scalability in mind  

## Key Takeaway

Data structure selection directly impacts runtime efficiency, memory usage, and overall system performance. Understanding these trade-offs is essential for building scalable software solutions.

