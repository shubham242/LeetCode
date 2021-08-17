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
    bool ans=true;
    int traverse(TreeNode* root){
        if(!root)
            return 0;
        return max(traverse(root->left),traverse(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        return abs(traverse(root->left)-traverse(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};