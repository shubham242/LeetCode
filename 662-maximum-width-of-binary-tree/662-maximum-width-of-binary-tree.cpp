class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, long>> q;
        q.push({root, 0});
        int ans = 0;

        while (q.size())
        {
            int s = q.size();
            int mil = q.front().second;
            int l = INT_MAX, r = INT_MIN;
            for (int i = 0; i < s; i++)
            {
                auto curr = q.front();
                q.pop();
                if (i == 0)
                    l = curr.second - mil;
                if (i == s - 1)
                    r = curr.second - mil;
                if (curr.first->left)
                    q.push({curr.first->left, 2 * (curr.second - mil) + 1});
                if (curr.first->right)
                    q.push({curr.first->right, 2 * (curr.second - mil) + 2});
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};