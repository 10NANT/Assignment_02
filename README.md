# Assignment_02 for 25FAL-CIS-17C-28094
## Overview
This project implements a template-based **DynamicArray** class in C++. It works similarly to a simplified version of `std::vector`. The array can automatically grow when new elements are added, supports bounds checking, and demonstrates copy and move semantics as required for the assignment.
---

## Problem 1: Generic Container Implementation

### Requirements
Implement a generic `DynamicArray` class with the following features:

- Template-based implementation  
- Dynamic resizing  
- Bounds checking  
- Copy and move semantics  
- Iterator support  

---

### Implementation Tasks

1. Create the `DynamicArray` class template  
2. Implement constructor, destructor, copy constructor, and assignment operator  
3. Add methods: `push_back`, `pop_back`, `at`, `size`, `capacity`  
4. Implement bounds checking with exceptions  
5. Add basic iterator functionality

## Features
- **Template-based implementation**  
- **Dynamic resizing:**  
  Automatically doubles its capacity when full inside `push_back()`.
- **Bounds checking:**  
  The `at()` method throws an exception if you try to access an index that doesn’t exist.
- **Copy and move semantics:**  
  Correctly handles copying and moving arrays without memory leaks.
- **Iterator support:**  
  The `begin()` and `end()` functions allow the class to be used with range-based for loops.

---
| Method                      | Description                                             |
| --------------------------- | ------------------------------------------------------- |
| `push_back(const T& value)` | Adds an element to the end, resizing if full            |
| `pop_back()`                | Removes the last element (throws if empty)              |
| `at(std::size_t index)`     | Returns the element at a given index, throws if invalid |
| `getSize()`                 | Returns number of elements stored                       |
| `getCapacity()`             | Returns current capacity (allocated space)              |
| `begin()` / `end()`         | Allow use in range-based for loops                      |

## Testing (main.cpp)

The `main.cpp` file tests all required features:

- Creating, copying, and moving arrays  
- Adding and removing elements  
- Checking size and capacity 
- (Optional) Testing bounds checking and exception handling

## Video
https://youtu.be/_hV0XYgFZgs
