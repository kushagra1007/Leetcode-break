class Solution {
public:
    set<vector<int>> s;
    void getAllCombinations(vector<int>& arr, int idx,int tar,vector<vector<int>>&ans,vector<int>& combin){
        if(idx == arr.size() || tar<0){
            return;
        }
        if(tar == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }

            return;
        }
        combin.push_back(arr[idx]);
        // single
        getAllCombinations(arr,idx+1,tar-arr[idx],ans,combin);
        // multiple
        getAllCombinations(arr,idx,tar-arr[idx],ans,combin);

        // backtracking
        combin.pop_back();
        getAllCombinations(arr,idx+1,tar,ans,combin);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;

        getAllCombinations(candidates,0,target,ans,combine);
        return ans;
    }
};