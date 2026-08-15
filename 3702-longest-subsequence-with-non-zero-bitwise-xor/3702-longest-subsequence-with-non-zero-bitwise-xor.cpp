class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)count++;
            xr=xr^nums[i];
        }
        if(count == nums.size()) return 0;
        if(xr==0)return nums.size()-1;
        return nums.size();
    }
};