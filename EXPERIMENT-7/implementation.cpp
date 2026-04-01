

#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> cost(n, INT_MAX);
    cost[src] = 0;
    for(int i = 0; i <= k; i++)
    {
        vector<int> tmp(cost);
        for(auto edge : flights)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if(cost[u] != INT_MAX && tmp[v] > cost[u] + w)
            {
                tmp[v] = cost[u] + w;
            }
        }
        cost = tmp;
    }
    if(cost[dst] != INT_MAX) return cost[dst];
    return -1;
}

int main()
{
    int n = 4;
    int src = 0, dst = 3, k = 1; 
    vector<vector<int>> flights = {
        {0, 3, 500}, // Direct
        {0, 1, 100}, {1, 3, 100}, // 1 stop (Total 200)
        {1, 2, 20}, {2, 3, 30}    // These would make it 2 stops (Total 150)
    };
    
    int result = findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price (Scenario 1): " << result << endl; 
    // Output should be 200
    
    return 0;
}
