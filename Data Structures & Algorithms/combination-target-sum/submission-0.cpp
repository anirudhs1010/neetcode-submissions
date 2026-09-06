class Solution {
public:
    vector<vector<int>> v;
    vector<int> ans;
    void dfs(vector<int> nums, int index, int target) {
        if (index >= nums.size() || target <0)
            return;
        if (target == 0) {
            v.push_back(ans);
            return;
        }
        ans.push_back(nums[index]);
        dfs(nums, index, target-nums[index]);
        ans.pop_back();
        dfs(nums, index+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0, target);
        return v;
    }

};
