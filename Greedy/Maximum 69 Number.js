/*
Maximum Number 69

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Example 1:
Input: num = 9669
Output: 9969

Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

Example 2:
Input: num = 9996
Output: 9999

Explanation: Changing the last digit 6 to 9 results in the maximum number.

Example 3:
Input: num = 9999
Output: 9999

Explanation: It is better not to apply any change.
 
Constraints:
1 <= num <= 104
num consists of only 6 and 9 digits.
*/

// Time - O(size of number) | Space - Constant
var maximum69Number  = function(num) {
    let sixPos = -1;
    let size = 0;
    let temp = num;
    while(temp != 0){
        let lastDigit = temp % 10;
        if(lastDigit == 6){
            sixPos = size;
        }
        temp = Math.floor(temp / 10);
        size++;
    }
    
    return sixPos == -1 ? num : num + 3 * Math.pow(10, sixPos);
};

// Time - O(size of number) | Space - O(size of number)
var maximum69Number  = function(num) {
    let arr = [];
    while(num !== 0){
        arr.push(num % 10);
        num = Math.floor(num / 10);
    }
    
    let ans = 0, n = arr.length-1;
    let check = false;
    for(let i=arr.length-1; i>=0; i--){
        if(!check && arr[i] === 6){
            check = true;
            arr[i] = 9;
        }
        ans += arr[i] * Math.pow(10, i);
    }
    
    return ans;
};
