class Solution {
   public:
    int partition(vector<int>& nums, int low, int high) {
        int randIdx = rand() % (high - low + 1) + low;
        int pivot = nums[randIdx];
        swap(nums[randIdx], nums[high]);
        int partition_index = low;
        for (int j = low; j < high; j++)
            if (nums[j] < pivot)
                swap(nums[partition_index], nums[j]), partition_index++;
        swap(nums[partition_index], nums[high]);
        return partition_index;
    }
    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot - 1);
            quickSort(nums, pivot + 1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
