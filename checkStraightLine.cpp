//Time Complexity O(n)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cord) {
        int x1=cord[0][0],y1=cord[0][1];
        double m=(cord[1][1]-y1)/(double)(cord[1][0]-x1);
        int flag=0;
        for(int i=2;i<cord.size();i++){
            int x2=cord[i][0];
            int y2=cord[i][1];
            double m1=(y2-y1)/(double)(x2-x1);
            if(m1!=m) return false;
        }
        return true;
    }
};