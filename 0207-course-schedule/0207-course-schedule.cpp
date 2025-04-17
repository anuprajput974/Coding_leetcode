class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Build graph
        for (auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        // Queue for all nodes with in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        int takenCourses = 0;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            takenCourses++;

            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If we could take all courses
        return takenCourses == numCourses;
    }
};