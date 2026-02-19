class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                int left = mid;
                int right = mid;

                
                while (left - 1 >= 0 && nums[left - 1] == target) {
                    left--;
                }
                while (right + 1 < nums.size() && nums[right + 1] == target) {
                    right++;
                }

                ans.push_back(left);
                ans.push_back(right);
                return ans;
            }

            if (target < nums[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return {-1, -1};
    }
};
