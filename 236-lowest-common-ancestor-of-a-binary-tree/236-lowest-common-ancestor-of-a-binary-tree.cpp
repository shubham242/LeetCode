class Solution
{
public:
    bool traverse(TreeNode *A, TreeNode *B, vector<TreeNode *> &ans)
    {
        if (A == NULL)
            return false;
        if (A == B)
        {
            ans.push_back(A);
            return true;
        }

        if (traverse(A->left, B, ans))
        {
            ans.push_back(A);
            return true;
        }

        if (traverse(A->right, B, ans))
        {
            ans.push_back(A);
            return true;
        }

        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> P;
        traverse(root, p, P);
        vector<TreeNode *> Q;
        traverse(root, q, Q);
        reverse(P.begin(), P.end());
        reverse(Q.begin(), Q.end());
        int i = 0;
        while (i < P.size() && i < Q.size() && P[i] == Q[i])
            i++;
        return P[i - 1];
    }
};