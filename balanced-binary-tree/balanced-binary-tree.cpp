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
    bool isBal(TreeNode* root, int* height)
{
    int lh = 0, rh = 0;
 
    int l = 0, r = 0;
 
    if (root == NULL) {
        *height = 0;
        return 1;
    }
 
    l = isBal(root->left, &lh);
    r = isBal(root->right, &rh);
 
    *height = (lh > rh ? lh : rh) + 1;
 
    if (abs(lh - rh) >= 2)
        return 0;
    else
        return l && r;
}
    bool isBalanced(TreeNode* root) {
        int h=0;
        return isBal(root,&h);
    }
};