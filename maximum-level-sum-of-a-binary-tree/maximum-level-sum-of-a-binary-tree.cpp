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
static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int result[10000]={0};
    int maxSum(TreeNode* root, int level)
    {
        if(root==NULL)
            return 0;
        result[level]+=root->val;
        
        int l = maxSum(root->left,level+1);
        int r= maxSum(root->right,level+1);
        if(l>r)
            return l+1;
        else
            return r+1;

    }
    int maxLevelSum(TreeNode* root) {
        int height = maxSum(root,1);
        for(int i=1;i<=height;i++)
            if(result[i]==*max_element(result+1, result + height+1))
                return i;
        
        return 0;
    }
};