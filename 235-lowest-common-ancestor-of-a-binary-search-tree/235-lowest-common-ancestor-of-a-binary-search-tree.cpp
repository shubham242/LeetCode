static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root->val>p->val&&root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(root->val<p->val&&root->val<q->val)
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;
        
    }
};