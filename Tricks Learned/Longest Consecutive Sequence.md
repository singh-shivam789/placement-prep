**Problem**

# **Longest Consecutive Sequence**

#### You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
#### You need to return the output array which contains starting and ending element. 
#### If the length of the longest possible sequence is one, then the output array must contain only single element.

## - Note:
### 1. Best solution takes O(n) time.
### 2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

## Input format:
 > The first line of input contains an integer, that denotes the value of the size of the array. 
 > Let us denote it with the symbol n. The following line contains n space separated integers, that denote the value of the elements of the array.

## Output format:
> The first and only line of output contains starting and ending element of the longest consecutive sequence. 
> If the length of longest consecutive sequence, then just print the starting element.

## Constraints :
> 0 <= n <= 10^6
> Time Limit: 1 sec

## Sample Input 1 :
> 13
> 
> 2 12 9 16 10 5 3 20 25 11 1 8 6 

## Sample Output 1 :
> 8 12 

## Sample Input 2 :
> 7
> 
> 3 7 2 1 9 8 41

## Sample Output 2 :
> 7 9
> Explanation: Sequence should be of consecutive numbers. 
> Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.

## Sample Input 3 :
> 7
> 
> 15 24 23 12 19 11 16

## Sample Output 3 :
> 15 16  

#  **Trick**  

# The trick is to optimize the bruteforce solution. 

## **Brute Force** O(N^3)

## For an element i: 
## Because a sequence could start at any number in nums, we can exhaust the entire search space by building as long a sequence as possible from every number.
### - check if its part of a sequence 
### - if not then start counting from it 
### - update the maximum and return
### The brute force algorithm does not do anything clever - it just considers each number in nums, attempting to count as high as possible from that number using only numbers in nums. After it counts too high (i.e. currentNum refers to a number that nums does not contain), it records the length of the sequence if it is larger than the current best. The algorithm is necessarily optimal because it explores every possibility.

## Sorting O(N*logN)
### If we can iterate over the numbers in ascending order, then it will be easy to find sequences of consecutive numbers. To do so, we can sort the array.

## Using Hashmap O(N) 
### This optimized algorithm contains only two changes from the brute force approach: the numbers are stored in a HashSet (or Set, in Python) to allow O(1)O(1) lookups, and we only attempt to build sequences from numbers that are not already part of a longer sequence. This is accomplished by first ensuring that the number that would immediately precede the current number in a sequence is not present, as that number would necessarily be part of a longer sequence.

# Time complexity : O(n).

## Although the time complexity appears to be quadratic due to the while loop nested within the for loop, closer inspection reveals it to be linear. Because the while loop is reached only when currentNum marks the beginning of a sequence (i.e. currentNum-1 is not present in nums), the while loop can only run for nn iterations throughout the entire runtime of the algorithm. This means that despite looking like O(n*n) complexity, the nested loops actually run in O(n + n) = O(n) time. All other computations occur in constant time, so the overall runtime is linear.
