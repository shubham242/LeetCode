class Solution {
   public:
    string maximumOddBinaryNumber(string s) {
        int one = 0, zero = 0;
        string res = "";
        for (auto &c : s)
            if (c == '1')
                one++;
            else
                zero++;

        for (int i = 1; i < one; i++)
            res += "1";

        for (int i = 1; i <= zero; i++)
            res += "0";

        return res + "1";
    }
};