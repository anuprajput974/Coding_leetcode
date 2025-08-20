class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256,-1);
        int left=0;
        int right=0;
        int maxlength=0;
        int n=s.length();
        while(n>right){

           if(map[s[right]]!=-1){
            if(map[s[right]]>=left){
                left=map[s[right]]+1;
            }
           }
           int length=right-left+1;
           maxlength=max(maxlength,length);

            map[s[right]]=right;
            right++;
        }
       return maxlength; 
    }
};