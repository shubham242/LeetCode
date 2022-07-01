class Solution
{
public:
    int solve(TreeNode *root, int &maxS)
    {
        if (!root)
            return 0;

        int pathL = max(solve(root->left, maxS), 0);
        int pathR = max(solve(root->right, maxS), 0);

        maxS = max(maxS, pathL + pathR + root->val);
        return root->val + max(pathL, pathR);
    }
    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};