#include <iostream>
#include <vector>
#include <algorithm> // Not strictly required, but good practice for vector operations

using namespace std;

class Solution {
public:
    /**
     * @brief Searches for a target value in a rotated sorted array.
     * @param nums The input vector (rotated and sorted).
     * @param target The value to search for.
     * @return int The index of the target if found, otherwise -1.
     */
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            // Calculate mid index safely
            int mid = st + (end - st) / 2;

            // Case 1: Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Determine which side of the array is correctly sorted
            
            // Case 2: Left half (from st to mid) is sorted
            if (nums[st] <= nums[mid]) { 
                // Check if target is within the sorted left half
                if (nums[st] <= target && target <= nums[mid]) {
                    // Target is in the left half, so eliminate the right half
                    end = mid - 1;
                } else {
                    // Target must be in the right (unsorted) half
                    st = mid + 1;
                }
            } 
            // Case 3: Right half (from mid to end) is sorted
            else { 
                // Check if target is within the sorted right half
                if (nums[mid] <= target && target <= nums[end]) {
                    // Target is in the right half, so eliminate the left half
                    st = mid + 1;
                } else {
                    // Target must be in the left (unsorted) half
                    end = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};

// Helper function to print execution results
void testSearch(Solution& sol, vector<int> nums, int target) {
    int index = sol.search(nums, target);
    cout << "Array: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "], Target: " << target << " -> Index: " << index << endl;
}

int main() {
    Solution sol;

    // Example 1: Target is in the first half
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    testSearch(sol, nums1, 0); // Expected: 4

    // Example 2: Target is in the second half
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    testSearch(sol, nums2, 5); // Expected: 1

    // Example 3: Target not found
    vector<int> nums3 = {10, 1, 2, 3, 4, 5, 6};
    testSearch(sol, nums3, 11); // Expected: -1
    
    // Example 4: Edge case (smallest array)
    vector<int> nums4 = {1, 3};
    testSearch(sol, nums4, 3); // Expected: 1

    return 0;
}