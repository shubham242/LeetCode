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
    bool traverse(TreeNode* p, TreeNode* q)
    {
        if(!p&&!q)
            return true;
        if(!p&&q)
            return false;
        if(p&&!q)
            return false;
        
        if(traverse(p->left,q->right)&&traverse(p->right,q->left)&&p->val==q->val)
            return true;
        
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return traverse(root->left,root->right);
    }
};