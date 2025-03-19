class Solution {
public:
    int countHomogenous(string s) {

        long long result=0;
        long long count=1;
        const int MOD=1e9+7;
          
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                result=(result+(count*(count+1)/2))%MOD;
                count=1;
            }
            
        }
        result=(result+(count*(count+1)/2))%MOD;
        return result;

    }
};