#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true; // duplicate found
            }
            seen.insert(num); // add to set
        }
        return false; // no duplicates
    }
};
