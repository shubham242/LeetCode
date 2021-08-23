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
    bool search(TreeNode* root,int tar)
    {
        if(!root)
            return false;
        if(tar==root->val)
            return true;
        else if(tar>root->val)
            return search(root->right,tar);
        else
            return search(root->left,tar);
    }
    bool traversal(TreeNode* root,TreeNode* curr, int k)
    {
        if(!curr)
            return false;
        if(!(k%2==0&&k/2==curr->val))
            if(search(root,k-curr->val))
                return true;
        if(traversal(root,curr->left,k))
            return true;
        if(traversal(root,curr->right,k))
            return true;
        
            return false;
    }
    bool findTarget(TreeNode* root, int k) {
        return traversal(root,root,k);
    }
};