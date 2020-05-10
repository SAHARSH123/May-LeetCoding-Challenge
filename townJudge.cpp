//Time Complexity O(n)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int arr[N][N];
        memset(arr,0,sizeof(int)*N*N);
        for(int i=0;i<trust.size();i++){
            int a=trust[i][0]-1;
            int b=trust[i][1]-1;
            arr[a][b]=1;
        }
        
        int start=0;
        int end=N-1;
        
        while(start<end){
            if(arr[start][end]==1)start++;
            else end--;
        }
        
        int flag=0;
        for(int i=0;i<N;i++) 
            if(arr[start][i]==1) flag=1;
        if(flag==1) return -1;
        
        for(int i=0;i<N;i++){
            if(i==start) continue;
            if(arr[i][start]==0) flag=1;
        }
        
        if(flag==1) return -1;
        return start+1;
    }
};