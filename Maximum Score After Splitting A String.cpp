class Solution {
public:
    int maxScore(string s) {
        int one=0,zero=0,n=s.size(),ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                zero++;
            }
            ans=max(ans,zero-one);
        }
        if(s[n-1]=='1'){
            one++;
        }
        return ans=ans+one;
    }
};