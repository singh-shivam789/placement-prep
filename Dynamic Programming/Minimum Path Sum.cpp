// Link - https://leetcode.com/problems/minimum-path-sum/

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Solution {
public:
    int helper(vector<vector<int>>&grid, vector<vector<int>>& dp, int m, int n){
        for(int i=m-1; i >= 0; i--){
            for(int j=n-1; j >= 0; j--){
                if(i+1 == m && j+1 == n) dp[i][j] = grid[i][j];
                else if(i+1 == m && j+1 != n) dp[i][j] = grid[i][j] + dp[i][j+1];
                else if(i+1 != m && j+1 == n) dp[i][j] = grid[i][j] + dp[i+1][j];
                else dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }} return dp[0][0]; }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        return helper(grid, dp, m, n);
    }
};
