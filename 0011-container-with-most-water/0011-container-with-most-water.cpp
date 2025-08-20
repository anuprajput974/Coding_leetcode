class Solution {
public:
    int maxArea(vector<int>& height) {
        int totalwater=0;
        int water;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int width=right-left;
            int maxheight=min(height[left],height[right]);
            int water=width*maxheight;
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
            if(water>totalwater){
                totalwater=water;
            }
        }
        return totalwater;
    }
};