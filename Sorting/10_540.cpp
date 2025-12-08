#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the single element that appears only once in a sorted array.
     * @param nums The input array where every element appears twice except for one.
     * @return int The single non-duplicate element.
     */
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // 1. Handle Edge Cases
        if (n == 1) return nums[0];
        // Check first element
        if (nums[0] != nums[1]) return nums[0];
        // Check last element
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        // 2. Binary Search Core Logic
        // We only need to search the middle section, as boundaries are handled.
        int st = 1;
        int end = n - 2;
    
        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Found the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            
            // Core Logic based on index parity and where the pair is located:
            // The single element is on the side where the paired elements are "misaligned" 
            // relative to their index parity.

            if (mid % 2 == 0) { // Current index is Even
                // Case 1: The pair is on the left (e.g., [x, x, ?, y, y])
                // nums[mid] == nums[mid - 1] -> Misalignment is on the left side of the pair.
                if (nums[mid] == nums[mid + 1]) {
                    st = mid + 2; // Move past the pair (mid and mid+1)
                } else { // nums[mid] == nums[mid-1]
                    end = mid - 2; // Single element is before the pair (mid-1 and mid)
                }
            } else { // Current index is Odd
                // Case 2: The pair is on the left (e.g., [x, x, y, y, ?])
                // nums[mid] == nums[mid - 1] -> Correctly aligned pair means the single element is to the right.
                if (nums[mid] == nums[mid - 1]) {
                    st = mid + 1; // Move past the current pair (mid-1 and mid)
                } else { // nums[mid] == nums[mid+1]
                    end = mid - 1; // Single element is before the pair (mid and mid+1)
                }
            }
        }
        
        return -1; // Should not be reached in a valid array
    }
};

// Helper function to print execution results
void testSingleNonDuplicate(Solution& sol, vector<int> nums) {
    int result = sol.singleNonDuplicate(nums);
    cout << "Array: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "], Single Element: " << result << endl;
}

int main() {
    Solution sol;

    // Example 1: Single element in the middle
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    testSingleNonDuplicate(sol, nums1); // Expected: 2

    // Example 2: Single element at the start (handled by edge case)
    vector<int> nums2 = {3, 3, 7, 7, 10, 10, 11, 11, 12};
    testSingleNonDuplicate(sol, nums2); // Expected: 12
    
    // Example 3: Larger example
    vector<int> nums3 = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6};
    testSingleNonDuplicate(sol, nums3); // Expected: 5
    
    // Example 4: Small array
    vector<int> nums4 = {1, 2, 2};
    testSingleNonDuplicate(sol, nums4); // Expected: 1

    return 0;
}