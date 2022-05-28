
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (i == nums1.size())
            {
                res.push_back(nums2[j]);
                j++;
            }
            else if (j == nums2.size())
            {
                res.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] <= nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else
            {
                res.push_back(nums2[j]);
                j++;
            }
        }
        int l = res.size();
        if (l % 2 == 0)
        {
            double ans = ((double)res[l / 2] + (double)res[l / 2 - 1]) / 2;
            return ans;
        }
        else
        {
            return res[l / 2];
        }
    }
};