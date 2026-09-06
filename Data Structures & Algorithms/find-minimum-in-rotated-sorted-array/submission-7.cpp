class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int mins = nums[0];
        cout << mins << endl;
        while (l <= r) {
            int mid = l +((r-l)/2);
            if (nums[l] <= nums[mid] && l < nums.size()-1) {
                l = mid+1;
                mins = min(nums[l], mins);
            }
            else
                r = mid-1;
            cout << mins << " " << l << endl;

        }
        return mins;
    }
};
