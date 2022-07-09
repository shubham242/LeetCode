class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        if (arr[start] == 0)
            return true;
        int x = arr[start];
        arr[start] = -1;

        if (start - x >= 0 && arr[start - x] != -1 && canReach(arr, start - x))
            return true;

        if (start + x < arr.size() && arr[start + x] != -1 && canReach(arr, start + x))
            return true;

        return false;
    }
};