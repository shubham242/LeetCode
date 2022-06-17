class Solution
{
    int ans;
    unordered_set<TreeNode *> covered;

public:
    int minCameraCover(TreeNode *root)
    {
        ans = 0;
        covered.insert(nullptr);
        dfs(root, nullptr);
        return ans;
    }

    void dfs(TreeNode *node, TreeNode *par)
    {
        if (node != nullptr)
        {
            dfs(node->left, node);
            dfs(node->right, node);

            if ((par == nullptr && (covered.find(node) == covered.end())) ||
                (covered.find(node->left) == covered.end()) ||
                (covered.find(node->right) == covered.end()))
            {
                ans++;
                covered.insert(node);
                covered.insert(par);
                covered.insert(node->left);
                covered.insert(node->right);
            }
        }
    }
};
