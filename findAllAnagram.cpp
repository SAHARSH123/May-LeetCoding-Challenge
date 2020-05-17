//Time Complexity O(n*26)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(s.size()<p.size()) return ans;
        unordered_map<int,int>p_map,s_map;
        for(int i=0;i<p.size();i++) {
            p_map[p[i]-'a']++;
            s_map[s[i]-'a']++;
        }
        
        int start=0,end=p.size()-1;
        while(end<s.size()){
            int flag=0;
            for(auto it=p_map.begin();it!=p_map.end();it++){
                if(s_map[it->first]==it->second) continue;
                else{
                    flag=1;
                    break;
                }
            }
           if(flag==0) ans.push_back(start);
            if(end+1<s.size()){
                s_map[s[start]-'a']--;
                start++;
                s_map[s[end+1]-'a']++;
                end++;
            }
            else break;
        }
        return ans;
        
    }
};