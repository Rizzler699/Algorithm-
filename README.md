# Algorithm-

1. Power of xⁿ using Binary Exponentiation (Iterative)
Aim
To efficiently compute the value of x^n using Binary Exponentiation (Iterative Method) with reduced time complexity.
Algorithm
int pow(int x, int n)
{
    if (n == 0)
        return 1;
    int m = n;
    int z = x;
    int pow_result = 1;
    while (m > 1)
    {
        if (m % 2 == 0)
        {
            z = z * z;
            m = m / 2;
        }
        else
        {
            pow_result = pow_result * z;
            m = m - 1;
        }
    }
    return pow_result;
}

Time Complexity:
O(logn)
(Exponent is reduced by half in each step)

Space Complexity:
O(1)
(Iterative method uses constant extra space)

Use Cases
Fast computation of large powers
Cryptographic algorithms such as RSA and Diffie–Hellman

------------------------------------------------------------------------------------------------------------------------------------------------------------------

 2. Permutation Generation using Recursion
Aim
To generate all possible permutations of a given set of characters using recursion and analyze the execution time for different input sizes.

Algorithm
void permute(char a[], int l, int r)
{
    if (l == r)
        return;

    for (int i = l; i <= r; i++)
    {
        swap(a[l], a[i]);
        permute(a, l + 1, r);
        swap(a[l], a[i]);   // backtracking
    }
}

Steps:
Fix one character at position l.
Swap it with every character from index l to r.
Recursively generate permutations for the remaining characters.
Restore the original order using backtracking.
Repeat until all permutations are generated.

Time Complexity
Number of permutations of n elements = n!
Each permutation takes constant time to generate.
Time Complexity:
O(n!)
Space Complexity:
O(n)
(due to recursion stack)

Use Cases
Generating all possible arrangements of characters or numbers
Solving combinatorial problems

------------------------------------------------------------------------------------------------------------------------------------------------------------------

 3. Polynomial Evaluation using Horner’s Rule

Aim
To evaluate the value of a polynomial at a given value of x using Horner’s Rule efficiently.

Algorithm
1. Read degree n of the polynomial.
2. Read coefficients from highest degree to constant term.
3. Read the value of x.
4. Set result = first coefficient (highest degree coefficient).
5. For i = 1 to n:
       result = result * x + coeff[i]
6. Print result.

 Time Complexity
* Time: O(n)
* Space: O(1) iterative, O(n) recursive

 Use Cases

Fast evaluation of polynomials in mathematics and engineering
Used in numerical methods and scientific computing.
Competitive programming problems involving polynomial calculations

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 4. Tower of Hanoi using Recursion

Aim
To solve the Tower of Hanoi problem using recursion and analyze the execution time for different numbers of disks.

Algorithm
void Toh(int n, char F, char U, char T)
{
    if (n == 0)
        return;

    Toh(n - 1, F, T, U);   // Move n−1 disks from source to auxiliary
    Toh(n - 1, U, F, T);   // Move n−1 disks from auxiliary to destination
}

Steps:
If the number of disks is 0, stop the recursion.
Recursively move n−1 disks from the source peg to the auxiliary peg.
Recursively move n−1 disks from the auxiliary peg to the destination peg.
Repeat the process until all disks are moved.

Time Complexity
For each disk, the function makes two recursive calls.
Total number of moves required for n disks = 2^n-1

Time Complexity:
O(2^n)
Space Complexity:
O(n)
(due to recursion stack)

Use Cases

Understanding recursion and divide-and-conquer strategy
Teaching and learning recursion concepts

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 5. Bubble Sort (Time Complexity Analysis)

Aim
To sort a list of numbers using Bubble Sort and analyze its execution time for different input sizes.

Algorithm
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


Steps:
Start from the first element of the array.
Compare adjacent elements.
Swap them if they are in the wrong order.
After each pass, the largest element moves to its correct position.
Repeat until the array is completely sorted.

Time Complexity
Bubble sort repeatedly compares adjacent elements.
Best Case (Already Sorted):
O(n)
Average Case:
O(n^2)
Worst Case (Reverse Sorted):
O(n^2)
Space Complexity:
O(1)
(in-place sorting algorithm)

Use Cases
Sorting small datasets
Educational purposes to understand sorting algorithms

------------------------------------------------------------------------------------------------------------------------------------------------------------------

6. Selection Sort (Time Complexity Analysis)

Aim
To sort a list of numbers using Selection Sort and analyze its execution time for different input sizes.

Algorithm
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

Steps:
Assume the first element is the minimum.
Compare it with all remaining elements in the array.
Find the smallest element in the unsorted part.
Swap it with the first unsorted element.
Repeat until the entire array is sorted.

Time Complexity
Selection sort always performs the same number of comparisons.
Best Case:
O(n^2)
Average Case:
O(n^2)
Worst Case:
O(n^2)
Space Complexity:
O(1)
(in-place sorting algorithm)

Use Cases
Sorting small datasets
Situations where minimum number of swaps is required

------------------------------------------------------------------------------------------------------------------------------------------------------------------

 7. Finding the Missing Number in a Sequence

Aim
To find the missing number from a sequence of consecutive integers using the sum formula approach.

Algorithm
1. Read the value of n (number of elements).
2. Read n elements into an array.
3. Store the first element as a and the last element as b.
4. Calculate the sum of all numbers from a to b.
5. Calculate the sum of all elements present in the array.
6. Subtract the actual array sum from the expected sum.
7. The result is the missing number.

Explanation
The array contains consecutive numbers with exactly one number missing.
The sum of consecutive numbers from a to b is calculated.
The sum of the given array elements is calculated.
The difference between these two sums gives the missing number.

Time Complexity:
O(n)
(Single traversal of the array)
Space Complexity:
O(1)
(Only variables are used, no extra space)

Use Cases
Finding missing numbers in sorted sequences
Data validation and error detection

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 8.  Finding Number of Dips of a Ball using Recursion

Aim
To determine the number of dips a ball makes until its velocity becomes less than 1 using a recursive approach.

Algorithm
int NumDips(double v)
{
    if (v < 1.0)
        return 0;

    return 1 + NumDips(v - 0.425 * v);
}

Steps:
Take the initial velocity of the ball as input.
If the velocity becomes less than 1.0, stop recursion.
Reduce the velocity by 42.5% of its current value.
Call the function recursively with the reduced velocity.
Count each recursive call as one dip.
Continue until the stopping condition is met.

Time Complexity
The velocity is multiplied by a constant factor (0.575) in each step.
Hence, the number of recursive calls grows logarithmically.
Time Complexity:
O(logv)
Space Complexity:
O(logv)
(due to recursion stack)

Use Cases
Simulation of ball motion and velocity decay
Modeling exponential decay processes

------------------------------------------------------------------------------------------------------------------------------------------------------------------

 9. Truth Table Generation 
 Aim
To generate truth tables for n boolean variables and analyze exponential growth.

 Algorithm (BTT)
void BTT(int k, int n)
{
    if (k > n)
        return;

    a[k] = true;
    BTT(k + 1, n);

    a[k] = false;
    BTT(k + 1, n);
}

 Time Complexity
* Time: O(2^n)
* Space: O(n)

 Use Cases
Digital logic design, boolean algebra, and circuit analysis.
Backtracking and recursion practice
Exhaustive testing for small boolean input problems

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

10. Linear Search (Worst Case Time Complexity Analysis)
Aim
To search an element in an array using Linear Search and analyze its worst-case execution time for different input sizes.

Algorithm
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

Steps:
Start from the first element of the array.
Compare each element with the key.
If the key is found, return its index.
If the end of the array is reached, return -1.
Repeat the process for different input sizes.
Measure execution time and compute the average.

Worst Case Explanation

Worst case occurs when:
The element is at the last position, or
The element is not present in the array.
In this program, the key is chosen as arr[n-1], which forces the worst case.

Time Complexity
Best Case:
O(1) (element found at first position)
Average Case:
O(n)
Worst Case:
O(n)
Space Complexity:
O(1)

Use Cases
Searching in unsorted arrays
Small datasets where simplicity is preferred
Educational demonstration of searching algorithms
Situations where data changes frequently
Linear scans in system utilities and logs

------------------------------------------------------------------------------------------------------------------------------------------------------------------

11. Binary Search
Aim
To efficiently search an element in a sorted array using Binary Search and analyze its worst-case time complexity.

Algorithm
void binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
}

Explanation:
Initialize start and end.
Find the middle element.
If the key matches the middle element, search ends.
If the key is smaller, search the left half.
If the key is larger, search the right half.
Repeat until the element is found or the search space becomes empty.

Time Complexity
At each step, the search space is reduced to half.
Best Case:
O(1)
Average Case:
O(logn)
Worst Case:
O(logn)
(when the element is not present in the array)
Space Complexity:
O(1)
(iterative implementation)

Use Cases

Searching elements in sorted arrays
Database indexing and fast lookups
Searching in dictionaries and phone directories
Efficient searching in large datasets
Used in competitive programming and system software

------------------------------------------------------------------------------------------------------------------------------------------------------------------

12. Insertion Sort
Aim
To sort a list of numbers using Insertion Sort and analyze its average execution time for different input sizes.

Algorithm
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

Explanation:
Start from the second element of the array.
Store the current element as key.
Compare key with elements to its left.
Shift all larger elements one position to the right.
Insert key at its correct position.
Repeat until the entire array is sorted.

Time Complexity
Insertion sort compares each element with the elements before it.
Best Case (Already Sorted):
O(n)
Average Case:
O(n^2)
Worst Case (Reverse Sorted):
O(n^2)
Space Complexity:
O(1)
(in-place sorting algorithm)

Use Cases
Sorting small datasets
Efficient when the array is nearly sorted
Used in online sorting (data received one by one)
Used as a subroutine in advanced algorithms like Tim Sort
Simple and easy to implement for educational purposes

------------------------------------------------------------------------------------------------------------------------------------------------------------------

13. Merge Sort
Aim: To sort an array in ascending order using the Merge Sort algorithm and analyze its execution time.

Algorithm
Read the number of elements n.
Read n elements into an array.
If l < r:
Find mid = (l + r) / 2
Apply Merge Sort on left part (l to mid)
Apply Merge Sort on right part (mid+1 to r)
Merge both sorted parts into one sorted array.
Repeat until the entire array is sorted.
Print the sorted array.

Time Complexity
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)
Space Complexity
Space: O(n)

Use Cases
Used for sorting large datasets.
Suitable for external sorting (file sorting).
Useful when stable sorting is required.
Used in linked list sorting.
Applied in divide and conquer based applications

------------------------------------------------------------------------------------------------------------------------------------------------------------------

14. Quick Sort
Aim: To sort an array in ascending order using the Quick Sort algorithm and analyze its execution time.

Algorithm
Read the number of elements n.
Read n elements into an array.
Select the first element as the pivot.
Rearrange the array so that:
Elements greater than pivot go to the right side.
Elements smaller than pivot go to the left side.
Place the pivot in its correct position.
Apply Quick Sort on left and right subarrays.
Repeat until the entire array is sorted.
Print the sorted array.

Time Complexity
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n²)
Space Complexity
Space: O(log n) (Recursive stack)

Use Cases
Used for fast in-memory sorting.
Suitable for large datasets.
Commonly used in system libraries.
Useful in competitive programming.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

15. Finding kth smallest element using partition algorithm.
Aim: To implement a C++ program to find the kth smallest element in an array using the Quick Sort algorithm and analyze its efficiency.

Algorithm
Step 1: Read the size of the array n.
Step 2: Input n elements into the array.
Step 3: Read the value of k (position of the smallest element to find).
Step 4: Use the partition() function to place the pivot element at its correct position.
Step 5: Compare the pivot position with k:
If pivot position + 1 == k, return that element.
If pivot position + 1 < k, search in the right sub-array.
If pivot position + 1 > k, search in the left sub-array.
Step 6: Repeat the process recursively until the kth smallest element is found.
Step 7: Display the result.

Time Complexity
Case	        Time Complexity
Best Case	        O(n)
Average Case       	O(n)
Worst Case          O(n²)

Explanation:
In most cases, the array is divided into two parts, so it runs in linear time.
In the worst case (already sorted array), the pivot is always smallest/largest, leading to O(n²).

Space Complexity
O(1) (In-place algorithm, no extra array is used)

Use Cases
Finding the kth smallest/largest score in a class.
Selecting the median of a dataset.

------------------------------------------------------------------------------------------------------------------------------------------------------

16. Convex Hull
Aim:To implement a C++ program to find the Convex Hull of a set of points using a brute force approach.

Algorithm
Step 1: Read the number of points n.
Step 2: Input all coordinate points.
Step 3: Assume all points are part of the convex hull.
Step 4: For each point P, form triangles using every combination of three other points (A, B, C).
Step 5: Check if P lies inside triangle (A, B, C) using orientation.
Step 6: If inside any triangle, mark P as not part of the hull.
Step 7: Repeat for all points.
Step 8: Print points that remain marked as convex hull.

Time Complexity
Best Case: O(n⁴)
Average Case: O(n⁴)
Worst Case: O(n⁴)

Space Complexity
O(n)

Use Cases
Finding boundary points in computer graphics
Used in geographical mapping (GIS)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------


17. Knapsack problem
Aim:To implement a C++ program to solve the 0/1 Knapsack problem using recursion and find the maximum profit.

Algorithm:
Step 1: Read the number of items n.
Step 2: Input weights and values of all items.
Step 3: Read the knapsack capacity W.
Step 4: Define recursive function knapsack(wt, val, n, W):
        - If n == 0 or W == 0, return 0.
        - If wt[n-1] > W, skip the item and call knapsack(wt, val, n-1, W).
        - Else:
            Include = val[n-1] + knapsack(wt, val, n-1, W - wt[n-1])
            Exclude = knapsack(wt, val, n-1, W)
            Return max(Include, Exclude)
Step 5: Call the function and store the result.
Step 6: Display the maximum profit.

Time Complexity:
Best Case: O(2^n)
Average Case: O(2^n)
Worst Case: O(2^n)

Space Complexity:
O(n) (due to recursion stack)

Use Cases:
- Resource allocation problems
- Budget optimization under constraints

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

18. Activity Selection Problem
 Aim:
To implement a C++ program to select the maximum number of non-overlapping activities using a greedy approach.

Algorithm:
Step 1: Read the number of activities n.
Step 2: Input start and finish times of all activities.
Step 3: Sort all activities in increasing order of their finish time.
Step 4: Select the first activity (earliest finishing).
Step 5: For remaining activities:
        - If start time of current activity >= finish time of last selected activity:
            Select the activity
Step 6: Repeat until all activities are checked.
Step 7: Display the selected activities.

Time Complexity:
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)

Space Complexity:
O(1) (in-place sorting, no extra space used apart from variables)

Use Cases:
- Scheduling meetings in a room
- CPU process scheduling

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

19. Dijkstra's Algorithm
Aim:To implement a C++ program to find the shortest path from a source vertex to all other vertices using Dijkstra’s algorithm.

Algorithm:
Step 1: Read the number of vertices n.
Step 2: Input the adjacency matrix of the graph.
Step 3: Read the source vertex.
Step 4: Initialize distance array dist[] with infinity and visited[] as false.
Step 5: Set dist[source] = 0.
Step 6: Repeat n-1 times:
        - Find the unvisited vertex with minimum distance (u).
        - Mark u as visited.
        - For all adjacent vertices v of u:
            If v is not visited and there is an edge (graph[u][v] != 0)
            and dist[u] + graph[u][v] < dist[v]:
                Update dist[v].
Step 7: Display shortest distances from source to all vertices.

Time Complexity:
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(n) (for distance and visited arrays)

Use Cases:
- Finding shortest path in road networks
- Network routing protocols

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

20. Kruskal's Algorithm
Aim:To implement a C++ program to find the Minimum Spanning Tree (MST) of a graph using Kruskal’s algorithm.

Algorithm:
Step 1: Read the number of vertices n.
Step 2: Input the cost (adjacency) matrix of the graph.
Step 3: Initialize parent array such that each vertex is its own parent.
Step 4: Set edges = 0 and total cost = 0.
Step 5: While edges < n-1:
        - Find the minimum cost edge (u, v) in the matrix.
        - Find the parent of u and v using find().
        - If parents are different:
            Include the edge in MST
            Add its cost to total
            Perform union of the sets
            Increment edge count
        - Mark the edge as used (set cost to large value)
Step 6: Repeat until MST has n-1 edges.
Step 7: Display all selected edges and total cost.

Time Complexity:
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(n) (for parent array)

Use Cases:
- Designing network connections (like cables, roads)
- Minimum cost infrastructure planning

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

21. Prim's Algorithm
Aim:To implement a C++ program to find the Minimum Spanning Tree (MST) of a graph using Prim’s algorithm.

Algorithm:
Step 1: Read the number of vertices n.
Step 2: Input the cost (adjacency) matrix of the graph.
Step 3: Initialize a visited array and mark the starting vertex as visited.
Step 4: Set edges = 0 and total cost = 0.
Step 5: While edges < n-1:
        - Find the minimum cost edge (a, b) such that:
            a is visited and b is not visited.
        - Select this edge and add it to MST.
        - Add its cost to total.
        - Mark vertex b as visited.
        - Increment edge count.
Step 6: Repeat until MST has n-1 edges.
Step 7: Display all selected edges and total cost.

Time Complexity:
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(n) (for visited array)

Use Cases:
- Network design (minimum wiring or cabling)
- Road and bridge construction planning

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

22. Dijkstra’s Algorithm (with path tracing)
Aim:To implement a C++ program to find the shortest path from a source vertex to all other vertices and display the paths using Dijkstra’s algorithm.

Algorithm:
Step 1: Read the number of vertices n and edges e.
Step 2: Initialize adjacency matrix with INF (infinity).
Step 3: Input all edges (u, v, w) and store weights in the matrix.
Step 4: Read the source vertex.
Step 5: Initialize:
        - dist[] = INF for all vertices
        - visited[] = 0
        - parent[] = -1
Step 6: Set dist[source] = 0.
Step 7: Repeat n-1 times:
        - Find unvisited vertex u with minimum distance.
        - Mark u as visited.
        - For each adjacent vertex v:
            If not visited and edge exists:
                If dist[u] + weight(u,v) < dist[v]:
                    Update dist[v]
                    Set parent[v] = u
Step 8: Print shortest distances.
Step 9: For each vertex, reconstruct path using parent[] array and display it.

Time Complexity:
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(n²) (for adjacency matrix) + O(n) (for arrays)

Use Cases:
- Navigation systems (shortest route finding)
- Network routing and path optimization

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

23. Multistage Graph (Stage Identification)
Aim:To implement a C++ program to determine the number of stages in a multistage graph using adjacency matrix representation.

Algorithm:
Step 1: Read the number of vertices n.
Step 2: Input the adjacency matrix of the graph.
Step 3: Initialize first stage with source vertex (0).
Step 4: Store stages using a vector of sets.
Step 5: For each stage:
        - For every vertex in current stage:
            Check all adjacent vertices.
            If edge exists, add them to next stage.
Step 6: Continue until no new vertices are found.
Step 7: Count total number of stages.
Step 8: Display the number of stages.

Time Complexity:
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(n²) (adjacency matrix) + O(n) (for storing stages)

Use Cases:
- Used in multistage graph problems (like shortest path in stages)
- Useful in dynamic programming and decision-making processes

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

24. Matrix Chain Multiplication
Aim:To implement a C++ program to find the optimal order of matrix multiplication that minimizes the total number of scalar multiplications using dynamic programming.

Algorithm:
Step 1: Read the number of matrices n.
Step 2: Input the dimensions array p[].
Step 3: Initialize two matrices:
        - m[][] to store minimum multiplication cost
        - s[][] to store split positions
Step 4: For chain length = 2 to n-1:
        For each i:
            j = i + length - 1
            Set m[i][j] = infinity
            For k = i to j-1:
                cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                If cost < m[i][j]:
                    Update m[i][j]
                    Store k in s[i][j]
Step 5: Minimum cost is m[1][n-1].
Step 6: Use recursive function to print optimal parenthesization using s[][].
Step 7: Display minimum cost and multiplication order.

Time Complexity:
Best Case: O(n³)
Average Case: O(n³)
Worst Case: O(n³)

Space Complexity:
O(n²) (for m and s matrices)

Use Cases:
- Optimizing matrix multiplication in computations
- Used in compiler optimization and scientific computing

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

25. Multistage Graph
Aim:To implement a C++ program to find the shortest path in a multistage graph using dynamic programming.

Algorithm:
Step 1: Read the number of vertices n.
Step 2: Input the adjacency matrix of the graph.
Step 3: Divide the graph into stages starting from source vertex (0).
Step 4: Initialize cost array with infinity and set cost[n-1] = 0 (destination).
Step 5: Traverse vertices from n-2 to 0:
        For each vertex i:
            For each vertex j:
                If edge exists from i to j:
                    If cost[i] > cost[j] + weight(i,j):
                        Update cost[i]
                        Store next vertex in d[i]
Step 6: Reconstruct path starting from source using d[] array.
Step 7: Display the stages and shortest path.

Time Complexity:
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)

Space Complexity:
O(n²) (adjacency matrix) + O(n) (cost and path arrays)

Use Cases:
- Multistage decision problems (like shortest path with stages)
- Network routing and optimization in layered systems

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

26. Bellman-Ford Algorithm
Aim:To implement a C++ program to find the shortest path from a source vertex to all other vertices using the Bellman-Ford algorithm.

Algorithm:
Step 1: Read the number of vertices V and edges E.
Step 2: Input all edges in the format (source, destination, weight).
Step 3: Read the source vertex.
Step 4: Initialize distance array dist[] with infinity for all vertices.
Step 5: Set dist[source] = 0.
Step 6: Repeat V-1 times:
        For each edge (u, v, w):
            If dist[u] is not infinity and dist[u] + w < dist[v]:
                Update dist[v]
Step 7: Check for negative weight cycle:
        For each edge (u, v, w):
            If dist[u] + w < dist[v]:
                Report negative cycle and exit.
Step 8: Display shortest distances from source to all vertices.

Time Complexity:
Best Case: O(VE)
Average Case: O(VE)
Worst Case: O(VE)

Space Complexity:
O(V) (for distance array)

Use Cases:
- Graphs with negative edge weights
- Network routing and financial calculations (currency arbitrage detection)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

27. Travelling Salesman Problem
Aim:To implement a C++ program to find the minimum travelling cost using the Travelling Salesman Problem (TSP) with backtracking.

Algorithm:
Step 1: Read the number of cities n.
Step 2: Input the cost matrix representing distances between cities.
Step 3: Initialize visited array to mark visited cities.
Step 4: Mark the starting city (0) as visited.
Step 5: Define recursive function tsp(city, count, cost):
        - If all cities are visited and return path exists:
            Return total cost including return to starting city.
        - Initialize minimum cost as infinity.
        - For each city i:
            If not visited and edge exists:
                Mark city i as visited.
                Recursively call tsp for next city.
                Update minimum cost.
                Backtrack (mark city i as unvisited).
Step 6: Call tsp from starting city.
Step 7: Display minimum travelling cost.

Time Complexity:
Best Case: O(n!)
Average Case: O(n!)
Worst Case: O(n!)

Space Complexity:
O(n) (for recursion stack and visited array)

Use Cases:
- Route optimization (delivery systems)
- Traveling and logistics planning
