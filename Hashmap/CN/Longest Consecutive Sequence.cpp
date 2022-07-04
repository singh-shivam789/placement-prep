/*
Longest Consecutive Sequence (Medium)
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

//O(n^3)
class Solution {
    bool arrayContains(vector<int> &nums, int num) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                return true;
            }
        }
        return false;
    }
  
    public int longestConsecutive(vector<int> &nums) {
        int longestStreak = 0;
        for (auto num : nums) {
            int currentNum = num;
            int currentStreak = 1;
            while (arrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
        return longestStreak;
    }
}

//O(n*log(n))
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size() == 0) return 0;
        sort(arr.begin(), arr.end());
        int count = 1, maxCount = -1;
        for(int i=0, j=i+1; j<arr.size(); i++,j++){
            if(arr[j] - arr[i] == 1) count++;
            else if(arr[j] - arr[i] == 0) continue;
            else{
                maxCount = max(count, maxCount);
                count = 1;
            } }   
        maxCount = max(count, maxCount);
        return maxCount;
    }
};

//O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]] = 1;
        }
        
        int longestStreak = 0;
        for(auto i : map){
            int currentElement = i.first;
            if(map.count(currentElement - 1) != 1){
                int currentStreak = 1;
                while(map.count(currentElement + 1)){
                    currentStreak += 1;
                    currentElement += 1;
                }
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};
