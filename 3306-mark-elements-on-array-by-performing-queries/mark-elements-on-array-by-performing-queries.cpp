class Solution {
   public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<long long> answer;
        long long sum = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
            sum += nums[i];
        }

        for (int i = 0; i < m; ++i) {
            int index = queries[i][0];
            int k = queries[i][1];
            sum -= nums[index];
            nums[index] = 0;

            while (k > 0 && !pq.empty()) {
                auto [value, idx] = pq.top();
                pq.pop();
                if (nums[idx]) {
                    sum -= nums[idx];
                    nums[idx] = 0;
                    k--;
                }
            }

            answer.push_back(sum);
        }

        return answer;
    }
};