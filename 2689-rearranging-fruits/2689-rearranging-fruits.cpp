class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;

        for (int fruit : basket1) freq[fruit]++;
        for (int fruit : basket2) freq[fruit]--;

        vector<int> extra;
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1;  // not possible
            for (int i = 0; i < abs(count) / 2; ++i)
                extra.push_back(fruit);
        }

        sort(extra.begin(), extra.end());

        int n = extra.size();
        int minVal = min(*min_element(basket1.begin(), basket1.end()), 
                         *min_element(basket2.begin(), basket2.end()));
        long long cost = 0;

        for (int i = 0; i < n / 2; ++i) {
            cost += min(extra[i], 2 * minVal);
        }

        return cost;
    }
};
