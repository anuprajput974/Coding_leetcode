class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int size=n/3;
        int count=1;
        for(int i=1;i<=n;i++){
            if(i<n && nums[i]==nums[i-1]){
                count++;

            }else{
                if(count>size){
                    ans.push_back(nums[i-1]);
                }
                count=1;

            }
        }
        
       return ans; 
    }
};