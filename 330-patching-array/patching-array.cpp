class Solution {
public:
int minPatches(vector<int>& nums, int n) {
long maxNumber = 0;
int minNumberOfPatches = 0, idx = 0, sz = nums.size();
while(maxNumber < n){
if(idx >= sz || nums[idx] > maxNumber + 1){
maxNumber += maxNumber + 1;
minNumberOfPatches++;
} else {
maxNumber += nums[idx++];
}
}
return minNumberOfPatches;
}
};