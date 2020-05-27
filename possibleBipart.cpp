//BFS Time complexity O(V+E)
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& d) {
        if(N==1) return true;
        if(d.size()==0) return true;
        vector<int> adj[N+1];
        int color[N+1],visit[N+1];
        
        for(int i=0;i<d.size();i++){
            adj[d[i][0]].push_back(d[i][1]);
            adj[d[i][1]].push_back(d[i][0]);
        }
        
        memset(visit,0,sizeof(visit));
        memset(color,-1,sizeof(visit));
        queue<int>q1;
        
        for(int i=1;i<=N;i++){
            if(color[i]==-1){
                q1.push(i);
                color[i]=0;
                visit[i]=1;
                while(q1.size()>0){
                    int cur=q1.front();
                    q1.pop();
                    for(int i=0;i<adj[cur].size();i++){
                        if(color[cur]==color[adj[cur][i]]) return false;
                        if(visit[adj[cur][i]]==0){
                            q1.push(adj[cur][i]);
                            visit[adj[cur][i]]=1;
                            color[adj[cur][i]]=color[cur]^1;
                        }
                    }
                }
            }
        }
        return true;
           
        
    }
};


//-------------------------------------------------------------------------------------------------//
//DFS Time Complexity O(V+E)

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& d) {
        if(N==1) return true;
        if(d.size()==0) return true;
        vector<int> adj[N+1];
        int color[N+1],visit[N+1];
        
        for(int i=0;i<d.size();i++){
            adj[d[i][0]].push_back(d[i][1]);
            adj[d[i][1]].push_back(d[i][0]);
        }
        
        memset(visit,0,sizeof(visit));
        memset(color,-1,sizeof(visit));
        queue<int>q1;
        
        for(int i=1;i<=N;i++){
            if(color[i]==-1){
                q1.push(i);
                color[i]=0;
                visit[i]=1;
                while(q1.size()>0){
                    int cur=q1.front();
                    q1.pop();
                    for(int i=0;i<adj[cur].size();i++){
                        if(color[cur]==color[adj[cur][i]]) return false;
                        if(visit[adj[cur][i]]==0){
                            q1.push(adj[cur][i]);
                            visit[adj[cur][i]]=1;
                            color[adj[cur][i]]=color[cur]^1;
                        }
                    }
                }
            }
        }
        return true;
           
        
    }
};