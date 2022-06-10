/*
Given an array of integers, find the closest (not considering the distance, but value) greater or the same value on the left of every element. 
If an element has no greater or same value on the left side, print -1.

Examples:  

Input : arr[] = {10, 5, 11, 6, 20, 12} 
Output : -1, 10, -1, 10, -1, 20 

The first element has nothing on the left side, so the answer for first is -1. 
Second, element 5 has 10 on the left, so the answer is 10. 
Third element 11 has nothing greater or the same, so the answer is -1. 
Fourth element 6 has 10 as value wise closes, so the answer is 10 
Similarly, we get values for the fifth and sixth elements.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> printPrevGreater(int arr[], int n){
    vector<int> ans;
    stack<int> s;
    for(int i=0; i<n; i++){
        if(s.empty()) ans.push_back(-1);
        else if(s.top() > arr[i]) ans.push_back(s.top());
        else{
            while(!s.empty() && s.top() < arr[i]) s.pop();
            if(s.empty()) ans.push_back(-1);
            else if(s.top() > arr[i]) ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> ans = printPrevGreater(arr, n);
        for(int i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
 
