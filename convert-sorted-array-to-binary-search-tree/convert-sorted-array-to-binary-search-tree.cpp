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
class Solution
{
public:
    TreeNode *fill(vector<int> &n, int s, int e)
    {
        if (s <= e)
        {
            int mid = (s + e) / 2;
            TreeNode *root = new TreeNode();
            root->val = n[mid];
            root->left = fill(n, s, mid - 1);
            root->right = fill(n, mid + 1, e);
            return root;
        }
        else
            return NULL;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return fill(nums, 0, nums.size() - 1);
    }
};