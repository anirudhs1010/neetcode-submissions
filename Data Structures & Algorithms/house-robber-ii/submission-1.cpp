class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size()-1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size()-1; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        int m = dp[dp.size()-1];
        if (nums.size() == 2)
            return dp[1];
        vector<int> dpa(nums.size()-1, 0);
        dpa[0] = nums[1];
        dpa[1] = max(nums[1], nums[2]);
        for (int i = 2; i < nums.size()-1; i++) {
            dpa[i] = max(dpa[i-1], dpa[i-2]+nums[i+1]);
            cout << dpa[i] << " " << nums[i] << endl;
        }
        cout << dpa[dpa.size()-1] << endl;
        return max(m, dpa[dpa.size()-1]);
    }
};
