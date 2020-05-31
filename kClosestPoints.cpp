//Time Complexity O(nlogn)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,pair<int,int>>>ans;
        for(int i=0;i<points.size();i++)
            ans.push_back(make_pair((points[i][0]*points[i][0])+(points[i][1]*points[i][1]),make_pair(points[i][0],points[i][1])));
        sort(ans.begin(),ans.end());
        vector<vector<int>>a;
        for(int i=0;i<K;i++){
            vector<int>temp;
            temp.push_back(ans[i].second.first);
            temp.push_back(ans[i].second.second);
            a.push_back(temp);
        }
        return a;
    }
};