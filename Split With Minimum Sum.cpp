class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        
        sort(s.begin(), s.end());
        string n1 = "";
        string n2 = "";
        
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                n1 += s[i];
            }else{
                n2 += s[i];
            }
        }
        
        int in1 = stoi(n1);
        int in2 = stoi(n2);
        
        return (in1+in2);
    }
};