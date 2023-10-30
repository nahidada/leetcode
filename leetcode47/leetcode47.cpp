#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> vis;
public:

    void backtrace(vector<int> & nums, vector<vector<int> > & ans, int idx, vector<int> & perm){
        
        if(idx == nums.size()){
            // ans.emplace_back(perm);
            ans.push_back(perm);

            return;
        }

        for(int i=0; i<(int)nums.size(); ++i){

            if(vis[i]==1){
                continue;
            }

            if(i>0 && vis[i-1] == 1 && nums[i-1] == nums[i]){

                continue;
            }

            // perm.emplace_back(nums[i]);
            perm.push_back(nums[i]);
            vis[i] = 1;

            backtrace(nums, ans, idx+1, perm);

            vis[i] = 0;
            perm.pop_back();
        }

    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> perm;

        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrace(nums, ans, 0, perm);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(2);

    vector<vector<int> > out = s.permuteUnique(input);

    for(int i=0; i<out.size(); i++){
        for(int j=0; j<out[i].size(); j++){
            cout<< out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}