class Solution
{
public:
    int kthSmallest(TreeNode *root, int &k)
    {
        if (root == NULL)
            return -1;
        int l = kthSmallest(root->left, k);
        if (l > -1)
            return l;
        k--;
        if (k == 0)
            return root->val;
        int r = kthSmallest(root->right, k);
        if (r > -1)
            return r;
        return -1;
    }
};