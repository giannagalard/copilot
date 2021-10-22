// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// time complexity: O(n)
// space complexity: O(n)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = 0;
        if(root == NULL)
            return result;
        if(root->left != NULL)
            result = kthSmallest(root->left, k);
        if(result != 0)
            return result;
        count++;
        if(count == k)
            return root->val;
        if(root->right != NULL)
            result = kthSmallest(root->right, k);
        return result;
    }
};

