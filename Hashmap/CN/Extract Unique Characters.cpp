/*
Extract Unique characters
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. 
The respective order of characters should remain same, as in the input string.

Input format:
The first and only line of input contains a string, that denotes the value of S.

Output format :
The first and only line of output contains the updated string, as described in the task.

Constraints :
0 <= Length of S <= 10^8

Time Limit: 1 sec

Sample Input 1 :
ababacd
Sample Output 1 :
abcd

Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

/* Making changes in the same string */
#include<unordered_map>
string uniqueChar(string str) {
    unordered_map<char, int> map;
    int k = 0;
    for(int i=0; i<str.length(); i++){
        if(map.count(str[i]) != 1){
            map[str[i]] = k++;
        }
    }
    
    for(int i=0; i<str.length(); i++){
        int index = map[str[i]];
        swap(str[i], str[map[str[i]]]);
    }
	str.resize(k);
    return str;
}

/* Creating a new string */ 
#include<unordered_map>
string uniqueChar(string str) {
    unordered_map<char, int> map;
    int k = 0;
    string ans;
    for(int i=0; i<str.length(); i++){
        if(map.count(str[i]) != 1){
            map[str[i]] = 1;
            ans+=str[i];
        }
    }
	return ans;
}
