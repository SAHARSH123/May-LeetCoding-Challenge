//Time complexity O(n*n)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()==0 || image[0].size()==0) return image;
        vector<pair<int,int>>v1;
        queue<pair<int,int>>q1;
        q1.push(make_pair(sr,sc));
        int oldColor=image[sr][sc];
        image[sr][sc]=-1;
        v1.push_back(make_pair(sr,sc));
        while(q1.size()>0){
            pair<int,int>p1=q1.front();
            q1.pop();
            int x1=p1.first,y1=p1.second;
            if(x1+1>=0 && x1+1<image.size() && image[x1+1][y1]==oldColor){
                image[x1+1][y1]=-1;
                q1.push(make_pair(x1+1,y1));
                v1.push_back(make_pair(x1+1,y1));
            }
            
            if(x1-1>=0 && x1-1<image.size() && image[x1-1][y1]==oldColor){
                image[x1-1][y1]=-1;
                q1.push(make_pair(x1-1,y1));
                v1.push_back(make_pair(x1-1,y1));
            }
            
            if(y1+1>=0 && y1+1<image[0].size() && image[x1][y1+1]==oldColor){
                image[x1][y1+1]=-1;
                q1.push(make_pair(x1,y1+1));
                v1.push_back(make_pair(x1,y1+1));
            }
            
            if(y1-1>=0 && y1-1<image[0].size() && image[x1][y1-1]==oldColor){
                image[x1][y1-1]=-1;
                q1.push(make_pair(x1,y1-1));
                v1.push_back(make_pair(x1,y1-1));
            }
        }
        
        for(int i=0;i<v1.size();i++) image[v1[i].first][v1[i].second]=newColor;
        
        return image;
    }
};