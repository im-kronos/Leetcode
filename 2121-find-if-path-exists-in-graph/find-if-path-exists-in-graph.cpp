class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        int s,d;
        unordered_map<int,list<int>>l;
        for(int i=0;i<edges.size();i++)
        {
            l[edges[i][0]].push_back(edges[i][1]);
            l[edges[i][1]].push_back(edges[i][0]);

        }
        //bfs
        //so how about we group sets
        queue<int>queue;    
       vector<bool>visited(n+1,false);  
        //from source to destination
        queue.push(source);
        visited[source]=true;
        while(!queue.empty())
        {
            int node=queue.front();
            queue.pop();

            if(node==destination)
            return true;

            for(int neighbour:l[node])
            {
                if(visited[neighbour]==false)
                {
                    queue.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return false;
    }
};