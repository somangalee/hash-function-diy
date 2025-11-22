# Hash Function DIY Contest
**Author:** Somang Lee  
**Course:** CSE 310 - Data Structures and Algorithms  
**Instructor:** Yiran "Lawrence" Luo  
**Score:** 20/20  
**Average Hidden Case StdDev:** 2.993  
**Ranking:** 10/114 Students  

## Overview

### Programming Language
- **C++**

This project implements a custom chaining-based hash table in C++, designed for uniform string hashing.
The goal was to engineer a consistent, deterministic, and well-balanced hash function that minimizes slot variance — reflected by a low standard deviation across multiple test inputs.

The project was graded through the Gradescope autograder in an Ubuntu 22.04 (GCC 11) environment, achieving a perfect score and ranking in the top 10 benchmark performers among 114 students.


## Hash Function Design

### Concept

- **Implements a linked-list chaining hash table.** 
- **The hash function blends division and multiplication techniques.** 

### For each input word:
1. Program reads all words from input file.
2. Converts all letters to lowercase.
3. For each character, its ASCII value is added into a running sum.
4. Incorporates a rolling calculation by using the formula 
```cpp
   tracker = tracker * 31 + (unsigned char)c;
   return tracker % k;
```
per character.
We use unsigned characters to avoid dealing with possible negatives or overflows and choose the number 31 as our multiplier as its a prime odd number often used in Java hash functions. 
5. The last step is to return the value 'tracker % k' (where k is the amount of words in the file) that will determine its slot spot in the hash table. 

## Implementation Details

- **Language: C++11** 
- **Build System: Makefile (make → builds executable encoder)** 
- **Structure:**
main.cpp
hash.cpp and hash.h (implementation of the hash table class)
Makefile 
inputs/sample_input.txt

### Run Instructions
<pre> ```bash make ./encoder < inputs/sample_input.txt ``` </pre>

## References
- **GeeksforGeeks – Hash Functions and List Types of Hash Functions** 

- **CSE 310 Course Materials, Fall 2025 (Arizona State University)** 
