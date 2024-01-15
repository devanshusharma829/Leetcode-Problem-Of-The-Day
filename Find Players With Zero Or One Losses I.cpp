class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>lostCount;
        for(auto match:matches){
            int pWin=match[0],pLost=match[1];
            if(lostCount.find(pWin)==lostCount.end()){
                lostCount[pWin]=0;
            }
            lostCount[pLost]++;
        }
        vector<int>zeroLost,oneLost;
        for(auto p:lostCount){
            if(p.second==0){
                zeroLost.push_back(p.first);
            }
            if(p.second==1){
                oneLost.push_back(p.first);
            }
        }
        return {zeroLost,oneLost};
    }
};