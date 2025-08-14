class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mp;
        int n=nums.size();
        int size=n/3;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;

        }
        for(auto it:mp){
            if(it.second>size){
                ans.push_back(it.first);
            }
        }
       return ans; 
    }
};