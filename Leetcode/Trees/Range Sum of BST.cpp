/*
Given the root node of a binary search tree and two integers low and high, 
return the sum of values of all nodes with a value in the inclusive range [low, high].
https://leetcode.com/problems/range-sum-of-bst/
*/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root){
            return 0;
        }
        else if(!root -> left && !root -> right){
            if(root -> val >= low && root -> val <= high){
                return root -> val;
            }
        }
        int leftAns = rangeSumBST(root -> left, low, high);
            int rightAns = rangeSumBST(root -> right, low, high);
            if(root -> val >= low && root -> val <= high){
                return (root -> val + rightAns + leftAns);
            }
            else 
                return leftAns + rightAns;
    }
};
