class Solution
{
public:
    bool isValid(TreeNode *root, long uBound, long lBound)
    {
        if (root == NULL)
            return true;
        if (root->val >= uBound || root->val <= lBound)
            return false;
        else
            return isValid(root->left, root->val, lBound) && isValid(root->right, uBound, root->val);
    }
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, long(INT_MAX)+1,long(INT_MIN)-1);
    }
};