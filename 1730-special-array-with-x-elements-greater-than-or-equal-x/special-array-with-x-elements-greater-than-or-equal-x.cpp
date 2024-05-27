#include <vector>
#include <algorithm>

class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        // Get the size of the array
        int n = nums.size();
        
        // Iterate over possible values of x from 0 to n (since x cannot be greater than the size of the array)
        for (int x = 0; x <= n; ++x) {
            int count = 0;
            
            // Count the number of elements that are greater than or equal to x
            for (int num : nums) {
                if (num >= x) {
                    count++;
                }
            }
            
            // If the count equals x, we found our special number
            if (count == x) {
                return x;
            }
        }
        
        // If no such x is found, return -1
        return -1;
    }
};
