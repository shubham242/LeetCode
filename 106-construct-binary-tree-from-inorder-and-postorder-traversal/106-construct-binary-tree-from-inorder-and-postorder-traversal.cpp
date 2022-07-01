class Solution
{
public:
    TreeNode *build(vector<int> &postorder, vector<int> &inorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int> &mp)
    {
        if (postEnd < postStart || inEnd < inStart)
            return NULL;

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int rootPos = mp[root->val];
        int numsLeft = rootPos - inStart;

        root->left = build(postorder, inorder, inStart, rootPos - 1, postStart, postStart + numsLeft - 1, mp);
        root->right = build(postorder, inorder, rootPos + 1, inEnd, postStart + numsLeft, postEnd - 1, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        TreeNode *root = build(postorder, inorder, 0, inorder.size() - 1, 0, postorder.size() - 1, mp);
        return root;
    }
};