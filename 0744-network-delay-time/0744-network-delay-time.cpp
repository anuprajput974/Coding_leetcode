#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       
        vector<vector<pair<int,int>>> graph(n+1);
        for (auto &t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }
        
      
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();
            if (time > dist[node]) continue; 
            
            for (auto &edge : graph[node]) {
                int next = edge.first, weight = edge.second;
                if (time + weight < dist[next]) {
                    dist[next] = time + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; 
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
