class Solution {
public:
    int bst(vector<int>& ans,int target){
        int left=0;
        int right=ans.size()-1;
        int a=-1;

        while(left<=right){
            int mid = (left+right)/2;

            if(ans[mid]>=target){
                a = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return a;
    }
    int lis(vector<int>& nums){
        if(nums.size()==0)return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(ans.back()<nums[i])ans.push_back(nums[i]);
            else{
                int idx = bst(ans,nums[i]);
                ans[idx]= nums[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int largest = 0;
        for(int i=0;i<32;i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++){
                if((nums[j] >> i & 1)==1){
                temp.push_back(nums[j]);
                }
            }
            largest = max(largest,lis(temp));
        }
        return largest;
    }
};