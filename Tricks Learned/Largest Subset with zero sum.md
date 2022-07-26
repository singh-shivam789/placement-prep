**Problem** : 
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

**Input Format**:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

**Output Format**
The first and only line of output contains length of the longest subarray whose sum is zero.

**Constraints**:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1:
10 
95 -97 -387 -435 -5 -70 897 127 23 284

Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 


**TRICK** 


![image](https://user-images.githubusercontent.com/52860981/181027065-359ae2db-cf76-4ae2-9d24-4e82d76915d0.png)


- IF sum till point A is x and sum till point B is also X, the then the sum of all the elements between A and B will be 0. 
- B - A = (x - x) = 0 
- Length will be difference in indices  -> B - A 

**Code** : 
```
#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> map;
    int sum = 0, maxLength = 0;
    map[0] = -1;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(map.find(sum) != map.end()){
            int frontIndex = i, backIndex = map[sum];
            int length = frontIndex - backIndex;
            maxLength = max(length, maxLength);
        } else {
            map[sum] = i;
        }
    }
    return maxLength;
}
```
