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
    int result[10000]={0};
    void maxSum(TreeNode* root, int level)
    {
        if(root==NULL)
            return;
        result[level]+=root->val;
        if(root->left!=NULL)
        maxSum(root->left,level+1);
        if(root->right!=NULL)
        maxSum(root->right,level+1);

    }
    int maxDepth(TreeNode* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);

            if (lDepth > rDepth)
                return(lDepth + 1);
            else return(rDepth + 1);
        }
    }
    int maxLevelSum(TreeNode* root) {
        maxSum(root,1);
        int height = maxDepth(root);
        for(int i=1;i<=height;i++)
            if(result[i]==*max_element(result+1, result + height+1))
                return i;
        
        return 0;
    }
};