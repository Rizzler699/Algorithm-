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


Steps:

If the exponent is 0, return 1.

Initialize result as 1.

While exponent is greater than 1:

If exponent is even, square the base and halve the exponent.

If exponent is odd, multiply result with base and decrement exponent.

Return the final result.


Time Complexity:
O(logn)
(Exponent is reduced by half in each step)

Space Complexity:
O(1)
(Iterative method uses constant extra space)

Use Cases

Fast computation of large powers

Cryptographic algorithms such as RSA and Diffie–Hellman

Competitive programming problems

Numerical and scientific computations

Applications requiring efficient exponentiation

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

Used in problems like anagrams and string rearrangements

Backtracking-based problem solving

Educational purposes to understand recursion and backtracking

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

Analyzing exponential time complexity

Used as a classic problem in algorithm design courses

Helps in understanding stack-based function calls


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

Situations where simplicity is preferred over efficiency

Demonstrating quadratic time complexity

Useful when memory usage must be minimal

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

Educational purposes to understand sorting algorithms

Useful when memory usage must be minimal

Demonstrating quadratic time complexity




------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

Competitive programming problems

Detecting missing roll numbers or IDs

Simple numerical analysis problems

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

Understanding recursion with real-valued inputs

Demonstrating logarithmic time complexity

Educational applications in physics-based algorithms

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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


