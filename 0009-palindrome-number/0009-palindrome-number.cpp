
class Solution {
public:
     
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        } 

        int original_num=x;
        int reverse_number=0;
        
       while(x>0){
        int remainder=x%10;
        if (reverse_number > (INT_MAX - remainder) / 10) {
                return false; // Overflow detected
            }
        reverse_number=(reverse_number*10)+remainder;
        x=x/10;
    }
    
    return reverse_number==original_num;
    }
        
   
        
    
};
