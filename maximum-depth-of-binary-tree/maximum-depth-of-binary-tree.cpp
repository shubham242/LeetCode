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
    int maxHeight=0;
    void maxH(TreeNode* root,int height){
        if(!root)
            return;
        maxHeight=max(height,maxHeight);
        if(root->left)
        maxH(root->left,height+1);
        if(root->right)
        maxH(root->right,height+1);
    }
    int maxDepth(TreeNode* root) {
        maxH(root,1);
        return maxHeight;
    }
};