#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max and std::min

// The class you provided
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Handle the edge case of an empty or single-element array
        if (prices.size() < 2) {
            return 0;
        }

        int mp = 0; // mp stands for max profit
        int bestbuy = prices[0]; // Initialize the best buy price to the first day's price

        for (size_t i = 1; i < prices.size(); i++) {
            // If the current price is higher than our best buy price,
            // calculate the potential profit and update max profit if it's a new high.
            if (prices[i] > bestbuy) {
                mp = std::max(mp, prices[i] - bestbuy);
            }
            // Update the best buy price to be the minimum price seen so far.
            bestbuy = std::min(bestbuy, prices[i]);
        }
        return mp;
    }
};

// Main function to run the code
int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Create a sample vector of stock prices
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call the maxProfit method and store the result
    int max_profit = sol.maxProfit(prices);

    // Print the result to the console
    std::cout << "The maximum profit is: " << max_profit << std::endl; // Expected output: 5

    // Another test case
    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    int max_profit2 = sol.maxProfit(prices2);
    std::cout << "The maximum profit is: " << max_profit2 << std::endl; // Expected output: 0

    return 0; // Indicate successful execution
}