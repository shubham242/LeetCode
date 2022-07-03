class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    void pushAll(TreeNode *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *res = st.top();
        st.pop();
        if (res->right != NULL)
            pushAll(res->right);
        return res->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};