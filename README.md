This repository consists of C++ language programs under the subject of Analysis and Design of Algorithms.

The activity selection problem involves selecting the maximum number of non-overlapping activities from a set of activities, each characterized by a start time and finish time. The greedy approach efficiently solves it by sorting activities by finish times and selecting activities that do not overlap with previously selected ones. This problem has applications in scheduling tasks and job scheduling. The time complexity of the greedy algorithm is O(n log n), where n is the number of activities.

Binary search is a divide-and-conquer algorithm used to find a element within a sorted array . It works by repeatedly dividing the search interval in half until the target element is found or the interval is empty. It has a  time complexity of O(log n).

Truth tables are systematic representations of all possible combinations of truth values for logical variables in a logical expression. They help evaluate the truth value of the expression under each combination.

Dijkstra's algorithm finds the shortest path from a single source vertex to all other vertices in a weighted graph. It uses a greedy approach, iteratively selecting the vertex with the shortest distance from the source and updating distances to neighboring vertices. Dijkstra's algorithm is widely used in network routing, GPS navigation, and pathfinding algorithms. Dijkstra's algorithm has a time complexity of O(V^2) using an adjacency matrix or O((V + E) log V) using a binary heap implementation, where V is the number of vertices and E is the number of edges in the graph.

The graph coloring problem involves assigning colors to the vertices of a undirected graph so that no two adjacent vertices share the same color. It's used in various applications like register allocation and scheduling, it has been implemented using backtracking.

Horner's rule is a method for efficiently evaluating polynomials by reducing the number of multiplications and additions required. It evaluates the polynomial in a single loop, iteratively computing the value by multiplying the current result by x and adding the next coefficient. With a time complexity of O(n) where n is the degree of the polynomial.

Iterative Quicksort is a variation of Quicksort that avoids recursion by using an explicit stack. It sorts an array by repeatedly partitioning it into smaller subarrays, managing subproblems with a stack. With a time complexity of O(n log n) on average, it offers a space-efficient alternative to recursive Quicksort.

The Knapsack problem involves selecting items to maximize total value while staying within a limited weight capacity.

The 0-1 Knapsack problem involves selecting items to maximize total value while staying within a limited weight capacity, with each item either included entirely or excluded. It's typically solved using dynamic programming, with a time complexity of O(nW) where n s the number of items and W is the knapsack capacity.


Kruskal's algorithm finds the minimum spanning tree of a weighted graph by greedily selecting edges with the smallest weight, ensuring that no cycles are formed. It has a time complexity of O(ElogE) or O(ElogV).

Linear search is a straightforward searching algorithm that sequentially checks each element in a list until the target value is found or the end of the list is reached. It has a time complexity of O(n) and is suitable for small lists or unsorted data.

The Longest Common Subsequence (LCS) problem involves finding the longest sequence that is present in both given sequences (strings). It's typically solved using dynamic programming, with a time complexity of O(mn) where m and n are the lengths of the input sequences.LCS has applications in bioinformatics, text comparison, version control, and plagiarism detection.

A magic square is an n×n grid filled with distinct numbers from 1 to n^2, where the sum of each row, column, and diagonal is the same. It has various algorithms for generation, each with its complexity. 

Matrix multiplication is an operation that combines two matrices to produce a third matrix. It's a fundamental operation used in various fields like computer graphics, numerical computations, and machine learning.

The Max-Min problem involves finding the maximum and minimum elements in a set of numbers. It is solved by iterating through the elements once and keeping track of the maximum and minimum values encountered. The time complexity is O(n), where n is the number of elements. 

Merge sort is a divide-and-conquer sorting algorithm that recursively divides an array into halves until each half has only one element. Then, it merges the halves back together, sorting them in the process. It has a time complexity of O(nlogn).

A multistage graph is a directed graph where vertices are organized into stages, with edges only between consecutive stages. It's commonly used in optimization problems, like project scheduling and network optimization. The solutions often involve finding the optimal path or value through the graph.

The N-Queens problem involves placing chess queens on an N×N chessboard such that no two queens threaten each other. It's a classic combinatorial problem with applications in chessboard layout and constraint satisfaction. The solutions requires backtracking.

A permutation generator is a algorithm that generates all possible permutations of a given set of elements. It's commonly used in combinatorial problems, such as generating all possible orders of elements in a sequence or all possible arrangements of items.

Prim's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, weighted graph. It starts from an arbitrary vertex and grows the MST by iteratively adding the shortest edge that connects a vertex in the MST to a vertex outside the MST. Prim's algorithm maintains a set of vertices that are part of the MST and repeatedly selects the minimum-weight edge that connects a vertex in the MST to a vertex outside the MST. Time complexity of O(ElogV).

QuickSort is a divide-and-conquer sorting algorithm that recursively divides an array into smaller subarrays based on a chosen pivot element. It has an average-case time complexity of 
O(nlogn).

Selection Sort is a simple sorting algorithm with a time complexity of O(n^2).

The sum of subsets problem involves finding all possible subsets of a given set of numbers such that their sum equals a specific target value. It is solved using backtracking.

The Towers of Hanoi is a classic problem that involves moving a stack of disks from one peg to another, with the constraint that only one disk can be moved at a time, and a larger disk cannot be placed on top of a smaller disk.The time complexity of the Towers of Hanoi problem is O(2^n), as the number of moves required doubles with each additional disk.








