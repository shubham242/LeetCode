class Solution {
   public:
    static bool comparator(const vector<int>& p1, const vector<int>& p2) {
        return (((p1[0] * p1[0]) + (p1[1] * p1[1])) <= ((p2[0] * p2[0]) + (p2[1] * p2[1])));
    }

    int partition(vector<vector<int>>& nums, int low, int high) {
        int i = low;
        for (int j = low; j < high; j++)
            if (comparator(nums[j], nums[high]))
                swap(nums[i], nums[j]), i++;

        swap(nums[high], nums[i]);
        return i;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int low = 0, high = points.size() - 1;
        while (low < high) {
            int pivot = partition(points, low, high);
            if (pivot + 1 == K)
                return vector<vector<int>>(points.begin(), points.begin() + K);
            else if (pivot + 1 < K)
                low = pivot + 1;
            else
                high = pivot - 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};