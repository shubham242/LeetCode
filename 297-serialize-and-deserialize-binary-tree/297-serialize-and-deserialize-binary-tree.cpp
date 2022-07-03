class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        queue<TreeNode *> q;
        string s;

        q.push(root);
        while (!q.empty())
        {
            int l = q.size();
            for (int i = 0; i < l; i++)
            {
                TreeNode *n = q.front();
                q.pop();
                if (n == NULL)
                    s += "#,";
                else
                {
                    s += to_string(n->val) + ',';
                    q.push(n->left);
                    q.push(n->right);
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        int l = data.size();
        if (l == 0)
            return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        queue<TreeNode *> q;
        TreeNode *n = new TreeNode(stoi(str));
        q.push(n);

        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
                cur->left = NULL;
            else
            {
                TreeNode *temp = new TreeNode(stoi(str));
                cur->left = temp;
                q.push(cur->left);
            }

            getline(s, str, ',');
            if (str == "#")
                cur->right = NULL;
            else
            {
                TreeNode *temp = new TreeNode(stoi(str));
                cur->right = temp;
                q.push(cur->right);
            }
        }
        return n;
    }
};