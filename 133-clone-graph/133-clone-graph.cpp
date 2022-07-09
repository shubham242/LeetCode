
class Solution
{
public:
    unordered_map<int, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        Node *n;
        if (mp.find(node->val) != mp.end())
            n = mp[node->val];
        else
        {
            n = new Node(node->val);
            mp[node->val] = n;
            for (int i = 0; i < node->neighbors.size(); i++)
                n->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return n;
    }
};