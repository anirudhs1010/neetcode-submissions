class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int mins = nums[0];
        
        while (l <= r) {
            if (nums[l] < nums[r]) {
                mins = min(nums[l], mins);
                return mins;
            }
            int mid = (l+r)/2;
            mins = min(nums[mid], mins);
            if (nums[mid] >= nums[l])
                l = mid+1;
            
            else
                r = mid-1;
        }
        return mins;
    }
};
