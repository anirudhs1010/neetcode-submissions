class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;
        int mins = nums[0];
        while (l <= r) {
            int mid = (l+r)/2;
            mins = min(mins, nums[mid]);
            if (nums[l] < nums[mid]) {
                mins = min(mins, nums[l]);
                l = mid+1;
                
            }
            else {
                mins = min(mins, nums[r]);
                r = mid-1;
            }

        }
        return mins;
    }
};
