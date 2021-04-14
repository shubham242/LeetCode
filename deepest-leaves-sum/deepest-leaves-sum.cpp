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
    int sum=0;
    int lvl(TreeNode* root,int l){
        if(root->left!=NULL&&root->right!=NULL)
            return max(lvl(root->left,l+1),lvl(root->right,l+1));
        else if(root->left!=NULL)
            return lvl(root->left,l+1);
        else if(root->right!=NULL)
            return lvl(root->right,l+1);
        else
            return l; 
    }
    
    int deepSum(TreeNode* root,int l,int deep){
        if(l==deep)
            sum+=root->val;
        if(root->left!=NULL)
            deepSum(root->left,l+1,deep); 
        if(root->right!=NULL)
            deepSum(root->right,l+1,deep);
        return sum;
    }
        
    int deepestLeavesSum(TreeNode* root) {
        
        int deep = lvl(root,1);
        return deepSum(root,1,deep);
        
    }
};