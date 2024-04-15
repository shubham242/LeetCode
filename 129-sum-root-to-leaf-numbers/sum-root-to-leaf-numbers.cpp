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
class Solution {
   public:
    void dfs(TreeNode *root, int prev, int &total) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            total += prev * 10 + root->val;
            return;
        }

        dfs(root->left, prev * 10 + root->val, total);
        dfs(root->right, prev * 10 + root->val, total);
    }
    int sumNumbers(TreeNode *root) {
        int total = 0;
        dfs(root, 0, total);
        return total;
    }
};