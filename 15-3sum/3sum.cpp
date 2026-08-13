class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> result;

        // Sort the array
        sort(nums.begin(), nums.end());

        // Fix the first element
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Two pointers
            int left = i + 1;
            int right = n - 1;

            // Required sum of left and right
            int sum_target = -1 * nums[i];

            // Search using two pointers
            while (left < right) {

                int current_sum = nums[left] + nums[right];

                // Triplet found
                if (current_sum == sum_target) {

                    result.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    // Move both pointers
                    left++;
                    right--;

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicates
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                // Need a bigger sum
                else if (current_sum < sum_target) {
                    left++;
                }

                // Need a smaller sum
                else {
                    right--;
                }
            }
        }

        // Return all triplets
        return result;
    }
};