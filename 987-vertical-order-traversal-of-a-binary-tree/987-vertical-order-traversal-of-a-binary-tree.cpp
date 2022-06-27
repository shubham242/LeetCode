/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, int *l, int *r, unordered_map<int, vector<pair<int, int>>> &mp, int curr, int h)
    {
        if (root == NULL)
            return;
        *l = min(*l, curr);
        *r = max(*r, curr);
        mp[curr].push_back({h, root->val});
        solve(root->left, l, r, mp, curr - 1, h + 1);
        solve(root->right, l, r, mp, curr + 1, h + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int l=0,r=0;
        unordered_map<int,vector<pair<int,int>>> mp;
        solve(root,&l,&r,mp,0,0);
        
        vector<vector<int>> ans;
        
        for(int i=l;i<=r;i++)
        {
            sort(mp[i].begin(),mp[i].end());
            vector<int> temp;
            for(int j=0;j<mp[i].size();j++)
                temp.push_back(mp[i][j].second);
            ans.push_back(temp);
        }
        return ans;
    }
};