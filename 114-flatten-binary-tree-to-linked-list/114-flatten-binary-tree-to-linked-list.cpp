class Solution
{
public:
    TreeNode *righMost(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr->right != NULL)
            curr = curr->right;
        return curr;
    }
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        if (root->left != NULL)
        {
            TreeNode *r = root->right;
            TreeNode *rMost = righMost(root->left);
            root->right = root->left;
            root->left = NULL;
            rMost->right = r;
        }
    }
};