class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string target = sortedDigits(n);
        
        for (int i = 0; i < 31; i++) { // 2^0 to 2^30 covers range
            int power = 1 << i;
            if (sortedDigits(power) == target) {
                return true;
            }
        }
        return false;
    }
    
    string sortedDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};