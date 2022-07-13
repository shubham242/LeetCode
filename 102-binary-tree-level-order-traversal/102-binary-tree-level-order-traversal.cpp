class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ans;
        if (!root)
            return ans;

        while (q.size())
        {
            int s = q.size();
            vector<int> temp;

            for (int i = 0; i < s; i++)
            {
                temp.push_back(q.front()->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};