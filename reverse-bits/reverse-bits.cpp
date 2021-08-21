class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int binaryNum[32] = {0};

        int i = 0;
        uint32_t res = 0;
        while (n > 0)
        {

            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        long int base = 1;
        for (int j = 31; j >= 0; j--)
        {
            res += base * binaryNum[j];
            base = base * 2;
        }
        return res;
    }
};