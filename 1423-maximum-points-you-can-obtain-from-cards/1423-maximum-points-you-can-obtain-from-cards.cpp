class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int size = n-k;

        int left=0;
        int sum =0;
        int minsum = INT_MAX;
        for(int right=0;right<n;right++){
            sum+=cardPoints[right];

            if(right-left+1 > size){
                sum-=cardPoints[left];
                left++;
            }
            if(right-left+1 == size)minsum = min(minsum,sum);
        }
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum += cardPoints[i];
        }
        return totalsum-minsum;
    }
};