class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>lostCount(100001,-1);
        for(auto match:matches){
            int pWin=match[0],pLost=match[1];
            if(lostCount[pWin]==-1){
                lostCount[pWin]=0;
            }
            if(lostCount[pLost]==-1){
                lostCount[pLost]=1;
            }
            else{
                lostCount[pLost]++;
            }
        }
        vector<int>zeroLost,oneLost;
        for(int i=0;i<100001;i++){
            if(lostCount[i]==0){
                zeroLost.push_back(i);
            }
            else if(lostCount[i]==1){
                oneLost.push_back(i);
            }
        }
        return {zeroLost,oneLost};
    }
};