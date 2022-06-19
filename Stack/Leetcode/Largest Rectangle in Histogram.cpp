/*
Leetcode (Hard) : https://leetcode.com/problems/largest-rectangle-in-histogram/
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Input: heights = [2,4]
Output: 4

Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

class Solution {
public:
    
vector<int> nsl(vector<int>& arr){
    stack<pair<int, int>*> s;
    vector<int> ans;
    int n = (int)arr.size();
    for(int i=0; i<n; i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(s.top() -> first < arr[i]){
            ans.push_back(s.top() -> second);
        }
        else{
            while(!s.empty() && s.top() -> first >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else if(s.top() -> first < arr[i]){
                ans.push_back(s.top() -> second);
            }
        }
        s.push(new pair<int, int>(arr[i], i));
    }
    return ans;
}
    
vector<int> nsr(vector<int>& arr){
    stack<pair<int, int>*> s;
    vector<int> ans;
    int n = (int)arr.size();
    for(int i=n-1; i>=0; i--){
        if(s.empty()){
            ans.push_back(n);
        }
        else if(s.top() -> first < arr[i]){
            ans.push_back(s.top() -> second);
        }
        else{
            while(!s.empty() && s.top() -> first >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(arr.size());
            }
            else if(s.top() -> first < arr[i]){
                ans.push_back(s.top() -> second);
            }
        }
        s.push(new pair<int, int>(arr[i], i));
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
    
    int largestRectangleArea(vector<int>& heights) {
        int n = (int)heights.size();
        vector<int> ans;
        vector<int> leftAns = nsl(heights);
        vector<int> rightAns = nsr(heights);
        for(int i=0; i<n; i++) ans.push_back((rightAns[i] - leftAns[i] - 1) * heights[i]);
        return *max_element(ans.begin(), ans.end());
    }
};
