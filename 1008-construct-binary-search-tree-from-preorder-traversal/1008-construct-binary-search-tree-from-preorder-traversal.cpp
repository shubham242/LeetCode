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
public:TreeNode *build(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd, int preStart, int preEnd, unordered_map<int, int> &mp)
    {
        if (preEnd < preStart || inEnd < inStart)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int rootPos = mp[root->val];
        int numsLeft = rootPos - inStart;

        root->left = build(preorder, inorder, inStart, rootPos - 1, preStart + 1, preStart + numsLeft, mp);
        root->right = build(preorder, inorder, rootPos + 1, inEnd, preStart + numsLeft + 1, preEnd, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        TreeNode *root = build(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1, mp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
};