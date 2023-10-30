### leetcode 47
```
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

            // if(i>0 && vis[i-1] == 1 && nums[i-1] == nums[i]){

            //     continue;
            // }

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
```
![没有去重复的输出](https://img-blog.csdnimg.cn/70ad98fa4699486ebcabca7b0630043c.png)
是递归，问题是出现重复元素，对全排列的结果会造成影响。


第一行和第二行是perm [1], vis[1,0,0] 之后递归的输出；
第三行和第四行是perm[1], vis[0,1,0] 之后递归的输出；

第五行是perm[2,1], vis[1,0,1]；
第六行是perm[2,1], vis[0,1,1];

所以这道题考查的是递归如何去重复；

```
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
```
![gdb调试leetcode47](https://img-blog.csdnimg.cn/4548e6c9664444f5921b27de6007bc36.png)
![gdb调试步骤](https://img-blog.csdnimg.cn/abbca212acdb4f84b7c9588674d7b581.png)

通过gdb, 第一个1和第二个1是重复的，第一个1的perm没有加入ans。
