class Solution
{
public:
    int depth(TreeNode *r, bool &is)
    {
        if (!r)
            return 0;
        int maxl = depth(r->left, is);
        int maxr = depth(r->right, is);

        if (is)
            is = (abs(maxr - maxl) <= 1) ? true : false;
        return 1 + max(maxl, maxr);
    }
    bool isBalanced(TreeNode *root)
    {
        bool ans=true;
        depth(root, ans);
        return ans;
    }
};