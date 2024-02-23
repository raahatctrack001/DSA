class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // converting graph into adjList;
        unordered_map<int, list<pair<int, int>>> adjList;
        vector<int> price(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        // queue<stopsCovered, pair<node, price>>>

        q.push({0, {src, 0}});
        price[src] = 0;
        for(auto &row : flights)
            adjList[row[0]].push_back({row[1], row[2]});

        while(!q.empty()){
            pair<int, pair<int, int>> frontNode = q.front();
            q.pop();

            int stopsCovered = frontNode.first;            
            if(stopsCovered > k)
                continue;
            
            int node = frontNode.second.first;
            int cost = frontNode.second.second;
            for(auto &nbr : adjList[node]){
                int nbrNode = nbr.first;
                int nbrPrice = nbr.second;
                if(cost + nbrPrice < price[nbrNode]){
                    price[nbrNode] = cost+nbrPrice;
                    q.push({stopsCovered+1, {nbrNode, price[nbrNode]}});
                }  
            }

        }
        return price[dst] == 1e9 ? -1 : price[dst];
        
    }
};