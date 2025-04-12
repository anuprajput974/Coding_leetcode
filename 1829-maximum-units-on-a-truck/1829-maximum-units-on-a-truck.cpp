class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort boxTypes by the second element (units per box) in descending order
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];  // Sort by units per box (descending)
        });

        int totalUnits = 0;

        // Iterate through the sorted boxTypes and pick boxes for the truck
        for (const auto& box : boxTypes) {
            if (truckSize == 0) break;  // If the truck is full, exit the loop
            
            // Take as many boxes as possible (either all or the remaining capacity)
            int boxesToTake = min(box[0], truckSize);
            
            // Add the corresponding units
            totalUnits += boxesToTake * box[1];
            
            // Decrease the truck size by the number of boxes taken
            truckSize -= boxesToTake;
        }

        return totalUnits;
    }
};