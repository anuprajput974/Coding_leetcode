class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater=0;
       
        int lp=0;
        int rp=height.size()-1;
        while(lp<rp){
            int minheight=min(height[lp],height[rp]);
            int width=rp-lp;
            int water=minheight*width;
            maxwater=max(maxwater,water);
            if(height[lp]<height[rp]){
                lp++;
            }else{
                rp--;
            }
        }

        return maxwater;
    }
};