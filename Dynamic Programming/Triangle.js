// Link - https://leetcode.com/problems/triangle/

// Recursive (Brute Force)
// Time Complexity - O(2^n) 
// Space Complexity - Recursive Stack
const helper = function(i, j, n, arr){
    if(i > n || j > n){
       return 0;
    }
    else if(i == n){
        return arr[i][j];
    }
    else{
        let ans = Math.min(helper(i+1, j, n, arr), helper(i+1, j+1, n, arr));
        return ans + arr[i][j];
    }
};

var minimumTotal = function(arr) {
    return helper(0, 0, arr.length-1, arr);    
};

// Top Down
// Time Complexity - O(n^2) 
// Space Complexity - O(n^2)
const helper = function(i, j, n, arr, dp){
    if(i > n || j > n) return 0;
    else if(i == n) return arr[i][j];
    else if(dp[i][j] != -1) return dp[i][j];
    else{
        let ans = Math.min(helper(i+1, j, n, arr, dp), helper(i+1, j+1, n, arr, dp)) + arr[i][j];
        dp[i][j] = ans;
        return ans;
    }
};

var minimumTotal = function(arr) {
    var dp = [];
    for(let i=0; i<arr.length; i++){
        dp.push(new Array(i+1).fill(-1));
    }
    return helper(0, 0, arr.length-1, arr, dp);    
};

// Bottom Up
// Time Complexity - O(n^2) 
// Space Complexity - O(n)
const iter = function(n, arr){
    var dp = [], r = n;
    for(let i=0; i<arr.length; i++){
        dp.push(arr[n][i]);
    }
    for(let i=n-1; i>=0; i--){
        for(let j=0; j<=r; j++){
            dp[j] = arr[i][j] + Math.min(dp[j], dp[j+1]);
        } r--;
    } 
    return dp[0];
}

var minimumTotal = function(arr) {
    var dp = [];
    for(let i=0; i<arr.length; i++){
        dp.push(new Array(i+1).fill(-1));
    }
    return iter(arr.length-1, arr);
};
