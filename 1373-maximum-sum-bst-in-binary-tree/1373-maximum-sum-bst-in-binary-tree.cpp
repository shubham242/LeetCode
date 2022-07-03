class Solution
{
public:
    struct container
    {
        bool isValid;
        int sum;
        int largest;
        int smallest;
        container(bool v, int s, int l, int sm) : isValid(v), sum(s), largest(l), smallest(sm){};
    };
    container isBST(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return container(true, 0, INT_MIN, INT_MAX);
        container l = isBST(root->left, ans);
        container r = isBST(root->right, ans);

        if (l.isValid && r.isValid && root->val > l.largest && root->val < r.smallest)
        {
            ans = max(ans, root->val + l.sum + r.sum);
            return container(true, root->val + l.sum + r.sum, max(root->val, r.largest), min(root->val, l.smallest));
        }
        return container(false, 0, INT_MIN, INT_MAX);
    }
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        isBST(root, ans);
        return ans;
    }
};