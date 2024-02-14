class Solution {
   public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res, pos, neg;
        for (auto i : nums)
            if (i < 0)
                neg.push_back(i);
            else
                pos.push_back(i);

        for (int i = 0; i < neg.size(); i++) {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }

        return res;
    }
};
