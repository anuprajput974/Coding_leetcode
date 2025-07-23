class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
        unordered_map<int, int> ngeMap;  
        stack<int> st;  

       
        for (int i = 0; i < nums2.size(); i++) {
            int num = nums2[i];
            
            while (!st.empty() && num > st.top()) {
                ngeMap[st.top()] = num;  
                st.pop();
            }
            st.push(num); 
        }

       
        while (!st.empty()) {
            ngeMap[st.top()] = -1;
            st.pop();
        }

        
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            result.push_back(ngeMap[num]);
        }

        return result;
        
    }
};