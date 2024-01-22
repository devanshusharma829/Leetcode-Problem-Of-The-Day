class Solution {
public:
    bool isVowel(string word){
        int n=word.size();
        int f=0;
        char s=word[0];
        char e=word[n-1];
        if((s=='a' || s=='e' || s=='i' || s=='o' || s=='u') && (e=='a' || e=='e' || e=='i' || e=='o' || e=='u')){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>v1(n+3,0);
        for(int i=0;i<n;i++){
            if(isVowel(words[i])){
                v1[i+1]=1;
            }
        }
        vector<int>dp(n+3,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+v1[i];  // prefix sum
        }
        vector<int>ans;
        for(auto query:queries){
            vector<int>p=query;
            int s=p[0]+1;  // li
            int e=p[1]+1;  // ri 
            ans.push_back(dp[e]-dp[s-1]);
        }
        return ans;
    }
};