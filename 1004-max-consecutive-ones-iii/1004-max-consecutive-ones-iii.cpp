class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlength = 0;
        int l = 0;
        unordered_map<int,int> mpp;

        for (int r = 0; r < nums.size(); r++) {
            mpp[nums[r]]++;
            while(nums[r]==0 && mpp[nums[r]] > k){
                mpp[nums[l]]--;
                l++;
            }
            maxlength= max(maxlength,r-l+1);
        }
        return maxlength;
    }
};