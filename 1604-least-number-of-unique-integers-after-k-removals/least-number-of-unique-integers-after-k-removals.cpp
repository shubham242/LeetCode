class Solution {
   public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> hashMap;
        vector<int> frequencies;

        for (int& num : arr)
            hashMap[num]++;

        for (auto& [key, value] : hashMap)
            frequencies.push_back(value);

        sort(frequencies.begin(), frequencies.end());

        for (int i = 0; i < frequencies.size(); i++) {
            k -= frequencies[i];
            if (k < 0) return frequencies.size() - i;
        }

        return 0;
    }
};