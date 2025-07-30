class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> hashset;
        for(int i=0;i<n;i++){
            if(hashset.contains(nums[i])){
                return true;
            }
            else{
                hashset.insert(nums[i]);
            }
        }
        return false;
       
    }
};