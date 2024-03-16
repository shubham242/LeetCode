class Solution {
   public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += encrypt(num);
        }
        return sum;
    }

   private:
    int encrypt(int x) {
        int max_digit = 0;
        int num = x;

        while (num > 0) {
            int digit = num % 10;
            max_digit = max(max_digit, digit);
            num /= 10;
        }
        int encrypted_num = 0;
        int multiplier = 1;
        while (x > 0) {
            encrypted_num += max_digit * multiplier;
            multiplier *= 10;
            x /= 10;
        }

        return encrypted_num;
    }
};