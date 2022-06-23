class Solution
{
public:
    static bool comp(const vector<int> &c1, const vector<int> &c2)
    {
        return c1[1] < c2[1];
    }
    int scheduleCourse(vector<vector<int>> &courses)
    {
        int n = courses.size();
        sort(courses.begin(), courses.end(), comp);

        int startTime = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (startTime + courses[i][0] <= courses[i][1])
            {
                courses[count++] = courses[i];
                startTime += courses[i][0];
            }
            else
            {
                int maxi = i;
                for (int j = 0; j < count; j++)
                {
                    if (courses[j][0] > courses[maxi][0])
                        maxi = j;
                }
                if (courses[i][0] < courses[maxi][0])
                {
                    startTime += courses[i][0] - courses[maxi][0];
                    courses[maxi] = courses[i];
                }
            }
        }
        return count;
    }
};