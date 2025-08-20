class Solution {
public:
    string checkstring(string s,int left,int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {

        if(s.length()<=1) return s;
        string longest="";
        string curr;

        for(int i=0;i<s.length();i++){

           string odd=checkstring( s,i,i);
           string even=checkstring( s,i,i+1);

           if(odd.length()>even.length()){
          curr=odd;
           }else{
             curr=even;
           }

           if(longest.length()<curr.length()){
            longest=curr;
           }
        }
        return longest;
    }
};
