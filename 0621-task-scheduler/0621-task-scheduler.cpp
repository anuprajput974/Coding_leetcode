
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int f_max = freq[25]; // Highest frequency
        int maxCount = 1;

        // Count how many tasks have this max frequency
        for (int i = 24; i >= 0 && freq[i] == f_max; --i) {
            maxCount++;
        }

        // Apply formula
        int min_time = (f_max - 1) * (n + 1) + maxCount;

        // Result is the maximum between total tasks and calculated time
        return max((int)tasks.size(), min_time);
    }
};