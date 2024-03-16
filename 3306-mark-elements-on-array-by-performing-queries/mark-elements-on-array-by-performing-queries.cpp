class Solution {
   public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<long long> answer;
        long long sum = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> marked(n, false);

        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
            sum += nums[i];
        }

        for (int i = 0; i < m; ++i) {
            int index = queries[i][0];
            int k = queries[i][1];

            if (!marked[index]) {
                marked[index] = true;
                sum -= nums[index];
            }
            while (k > 0 && !pq.empty()) {
                auto [value, idx] = pq.top();
                pq.pop();
                if (!marked[idx]) {
                    marked[idx] = true;
                    sum -= value;
                    k--;
                }
            }

            answer.push_back(sum);
        }

        return answer;
    }
};