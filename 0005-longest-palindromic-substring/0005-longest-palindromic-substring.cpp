class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return"";
        int start=0,maxLength=1;

        auto expandAroundCentre=[&](int left ,int right){
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
            }
            return right-left-1;
        };
        for(int i=0;i<s.length();i++){
            int length1=expandAroundCentre(i,i);
            int length2=expandAroundCentre(i,i+1);
            int len=max(length1,length2);
            if(len>maxLength){
            maxLength=len;
             start=i-(len-1)/2;
        }
       
        }
    
        return s.substr(start,maxLength);
    }
};
