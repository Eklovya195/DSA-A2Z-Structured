#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void funGenerate(int idx,vector<int>& candidates, int target,int n,vector<int> &subset,vector<vector<int>> &ans,int &sum){
        if(idx == n || sum >= target){
            if(sum == target){
                ans.push_back(subset);
            }
            return;
        }
        subset.push_back(candidates[idx]);
        sum += candidates[idx];
        funGenerate(idx,candidates,target,n,subset,ans,sum);
        sum -= candidates[idx];
        subset.pop_back();
        funGenerate(idx+1,candidates,target,n,subset,ans,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        int idx = 0;
        vector<vector<int>> ans;
        vector<int> subset;
        funGenerate(idx,candidates,target,n,subset,ans,sum);
        return ans;
    }
};
int main(){
    vector<int> nums = {2,3,6,7};
    int target = 7;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum(nums,target);
    for(int i=0;i<ans.size();i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
    return 0;
}
