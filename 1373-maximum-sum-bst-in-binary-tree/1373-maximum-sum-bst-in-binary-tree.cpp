class Solution
{
public:
    struct container
    {
        int sum;
        int largest;
        int smallest;
        container(int s, int l, int sm) : sum(s), largest(l), smallest(sm){};
    };
    container isBST(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return container(0, INT_MIN, INT_MAX);
        container l = isBST(root->left, ans);
        container r = isBST(root->right, ans);

        if (root->val > l.largest && root->val < r.smallest)
        {
            ans = max(ans, root->val + l.sum + r.sum);
            return container(root->val + l.sum + r.sum, max(root->val, r.largest), min(root->val, l.smallest));
        }
        return container(0, INT_MAX, INT_MIN);
    }
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        isBST(root, ans);
        return ans;
    }
};