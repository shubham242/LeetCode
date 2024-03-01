class Solution {
   public:
    string maximumOddBinaryNumber(string s) {
        int one = 0, zero = 0;
        for (auto &c : s)
            if (c == '1')
                one++;
            else
                zero++;

        string ans = string(one - 1, '1') + string(zero, '0') + "1";
        return ans;
    }
};