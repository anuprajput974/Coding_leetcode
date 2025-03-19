class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' ')
            i++;
        
        
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            char firstSign = s[i];  
            i++;

           
            if (i < n && (s[i] == '+' || s[i] == '-')) 
                return 0;
            
            
            if (firstSign == '-') 
                sign = -1;
        }


        long result=0;
        while(i<n && isdigit(s[i])){
        result=result*10+(s[i]-'0');
        if(result>INT_MAX) break;
        i++;
        }

        result=result*sign;

        if(result>INT_MAX) return INT_MAX;
        if(result<INT_MIN) return INT_MIN;


        return result;


        
    }
};