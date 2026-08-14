class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0;
        int maxlen =0;
        unordered_map<char,int>mpp;

        for(int right =0;right < s.size();right++){
            mpp[s[right]]++;

            while(mpp[s[right]] > 2){
                mpp[s[left]]--;
                left++;
            }

            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};