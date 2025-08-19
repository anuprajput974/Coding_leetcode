class Solution {
public:
    bool isAlphanum(char ch){
     if((ch>='0' && ch<='9') ||
     (tolower(ch)>='a' && tolower(ch)<='z')){
        return true;
     }
     return false;
    }
    bool isPalindrome(string s) {
        
        int end=s.length()-1;
        int start=0;
         
        while(end>start){
            if(!isAlphanum(s[start])){ start++;continue;}
            if(!isAlphanum(s[end])){end--;continue;}
            
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
        
    }
};