//Time Complexity O(v+e)
//Detect Cycle in directed graph using coloring method
class Solution {
public:
    
    bool isCycle(int src,vector<int> adj[],int visit[]){
        visit[src]=1;
        for(int i=0;i<adj[src].size();i++){
            if(visit[adj[src][i]]==1) return true;
            if(visit[adj[src][i]]==0 && isCycle(adj[src][i],adj,visit)==true) return true;
        }
        visit[src]=2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        
        int visit[n];
        memset(visit,0,sizeof(visit));
        
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                if(isCycle(i,adj,visit)==true) return false;
            }
        }
        
        return true;
    }
};