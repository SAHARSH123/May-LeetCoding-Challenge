//Time complexity O(nlogn)
class Solution {
public:
    
    string frequencySort(string s) {
        if(s.size()==0) return s;
        string temp;
        unordered_map<char,int>m1;
        for(int i=0;i<s.size();i++){
            m1[s[i]]=m1[s[i]]+1;
            if(m1[s[i]]==1) temp.push_back(s[i]);
        }
        vector<pair<int,char>>v1;
        for(int i=0;i<temp.size();i++) v1.push_back(make_pair(m1[temp[i]],temp[i]));
        sort(v1.begin(),v1.end(),greater<pair<int,char>>());
        string ans;
        for(int i=0;i<v1.size();i++){
            char c=v1[i].second;
            for(int j=0;j<v1[i].first;j++) ans.push_back(c);
        }
        return ans;
    }
};