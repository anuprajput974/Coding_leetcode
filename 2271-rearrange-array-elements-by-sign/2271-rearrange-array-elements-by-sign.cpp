class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos_arr;
        vector<int> neg_arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                pos_arr.push_back(nums[i]);
            }
            else
            neg_arr.push_back(nums[i]);
        }
        for(int i=0;i<n/2;i++){
            nums[2*i]=pos_arr[i];
            nums[2*i+1]=neg_arr[i];
        }
        return nums;

        
    }
};