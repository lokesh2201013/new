
class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> remainderCount;
        int totalSubarrays = 0;
        int cumulativeSum = 0;
        int remainder = 0;
        
        remainderCount[remainder]++;
        
        for(int i = 0; i < nums.size(); i++) {
            cumulativeSum += nums[i];
            remainder = cumulativeSum % k;
            
            if (remainder < 0) {
                remainder += k;
            }
            
            if (remainderCount.find(remainder) != remainderCount.end()) {
                totalSubarrays += remainderCount[remainder];
            }
            
            remainderCount[remainder]++;
        }
        
        return totalSubarrays;
    }
};