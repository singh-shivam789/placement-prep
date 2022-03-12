/*
Given the root of a binary tree, invert the tree, and return its root.
https://leetcode.com/problems/invert-binary-tree/
*/

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */

class Solution
{
    public:
        TreeNode* invertTree(TreeNode *root)
        {
            if (root)
            {
                if (!root->left && !root->right)
                {
                    return root;
                }
                else
                {
                    swap(root->left, root->right);
                    root->left = invertTree(root->left);
                    root->right = invertTree(root->right);
                    return root;
                }
            }
            else return nullptr;
        }
};
