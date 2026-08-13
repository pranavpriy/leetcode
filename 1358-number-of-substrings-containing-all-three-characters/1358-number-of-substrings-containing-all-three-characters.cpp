class Solution {
public:
    int numberOfSubstrings(string s) {
        int alastseen=-1;int blastseen=-1;int clastseen=-1;
        int  ans=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='a')alastseen=i;
            if(s[i]=='b')blastseen=i;
            if(s[i]=='c')clastseen=i;
            if(alastseen!=-1 && blastseen!=-1 && clastseen!=-1){
                int firstoccurence=min(min(alastseen,blastseen),clastseen);
                ans=ans+firstoccurence+1;
            }
            i++;
        }
        return ans;
    }
};