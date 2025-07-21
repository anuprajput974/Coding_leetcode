class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i]==s[i-1]){
                count++;
            }else{

                count=1;
            }
            if(count<3){
                ans+=s[i];
            }
        }
        return ans;
    }
};