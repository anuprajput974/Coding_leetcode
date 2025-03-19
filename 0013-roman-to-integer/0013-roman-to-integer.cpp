class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100}
            ,{'D',500},{'M',1000}
        };
        int result=0;
        int preval=0;
        for(int i=s.size()-1;i>=0;i--){
            int currval=roman[s[i]];
            if(currval<preval){
                result-=currval;
            }else {
                result+=currval;
            }
            preval=currval;
        }
        return result;
        
    }
};