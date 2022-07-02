class Solution
{
public:
    TreeNode *build(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return NULL;
        TreeNode *root = new TreeNode(nums[(start + end) / 2]);
        root->left = build(nums, start, (start + end) / 2 - 1);
        root->right = build(nums, (start + end) / 2 + 1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
};