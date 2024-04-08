class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), k = 0, count[] = { 0 , 0 };
		
        for(int stu : students)
            count[stu]++;
        
        for(k = 0; k < n && count[sandwiches[k]] > 0; ++k)
            count[sandwiches[k]]--;

        return n-k;
    }
};