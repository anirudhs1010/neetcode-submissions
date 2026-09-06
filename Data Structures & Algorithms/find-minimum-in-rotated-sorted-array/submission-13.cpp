class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int mins = nums[0]; //account for sorted case
        while (l <= r) {
            int mid = l + ((r-l)/2);
            if (nums[mid] <= nums[r]) {
                r = mid - 1;
                mins = min(nums[mid], mins);
            }
            else
                l = mid+1;
        }
        return mins;

    }
};
