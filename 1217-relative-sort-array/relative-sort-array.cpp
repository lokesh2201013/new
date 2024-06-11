#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        vector<int> count(maxElement + 1, 0);
        
        // Count the frequency of each element in arr1
        for (int num : arr1) {
            count[num]++;
        }
        
        vector<int> result;
        
        // Add elements of arr2 in the order they appear
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        
        // Add remaining elements that were not in arr2
        for (int num = 0; num <= maxElement; num++) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        
        return result;
    }
};
