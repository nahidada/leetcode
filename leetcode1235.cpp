#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            int n = startTime.size();
            vector<vector<int>> jobs(n);

            for(int i=0; i<n; i++){
                jobs[i] = {startTime[i], endTime[i], profit[i]};
            }

            sort(jobs.begin(), jobs.end(), [](const vector<int>&job1, const vector<int>&job2){return job1[1] < job2[1]; });

            for (const auto& job : jobs) {
                cout << job[0] <<","<<job[1] <<","<<job[2] << endl;
            }
            
            return 0;
        }
};

int main(){
    Solution s;
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    s.jobScheduling(startTime, endTime, profit);

    return 0;
}