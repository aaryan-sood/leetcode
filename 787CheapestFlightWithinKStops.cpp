// probelem link
// https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        // making the adjajency list
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        // a vector for n nodes with distance[i] containing the cheapest fare from src with at most k stops
        vector<int> distance(n,INT_MAX);
        distance[src]=0;

        // a queue containing elements in the order {stops,{node,fare}} because as with {fare,{node,stops}} it does not take into consideration the number of stops and it might reach a node with the lowest cost but since stops are not considered it might be possible that the number of stops are exausted in minimising the distance and the now the journey further cannot be continued and such node is of no use so we need to maintain a queue with increasing number of stops so if a node is reached with stops < k even if has a some more cost 
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(!q.empty())
        {
            pair<int,pair<int,int>> p=q.front();
            q.pop();

            int stops=p.first;
            int node=p.second.first;
            int rootDistance=p.second.second;

            if(stops > k)
            {
                continue;
            }

            for(int i=0;i<adj[node].size();i++)
            {
                int temp=adj[node][i].first;
                int tempDistance=adj[node][i].second;

                if(rootDistance + tempDistance < distance[temp] && stops <= k)
                {
                    distance[temp]=tempDistance + rootDistance;
                    q.push(pair<int,pair<int,int>>(stops+1,pair<int,int>(temp,distance[temp])));
                }
            }
        }
        if(distance[dst] == INT_MAX)
        {
            return -1;
        }
        return distance[dst];
    }
};