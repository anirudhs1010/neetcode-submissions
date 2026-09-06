class Solution {
public:
    vector<int> v;
    vector<vector<int>> ans;
    void backtrack(vector<int> nums, int ind, int a) {
        if (a == 0) {
            ans.push_back(v);
            return;
        }
        if (ind >= nums.size() || a < 0)
            return;
        v.push_back(nums[ind]);
        backtrack(nums, ind, a-nums[ind]);
        v.pop_back();
        backtrack(nums, ind+1, a);
        

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, 0, target);
        return ans;
    }
};
