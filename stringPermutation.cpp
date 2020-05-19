//Time Complexity O(n*26)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        unordered_map<int,int>p_map,s_map;
        for(int i=0;i<s1.size();i++) {
            p_map[s1[i]-'a']++;
            s_map[s2[i]-'a']++;
        }
        
        int start=0,end=s1.size()-1;
        while(end<s2.size()){
            int flag=0;
            for(auto it=p_map.begin();it!=p_map.end();it++){
                if(s_map[it->first]==it->second) continue;
                else{
                    flag=1;
                    break;
                }
            }
           if(flag==0) return true;
            if(end+1<s2.size()){
                s_map[s2[start]-'a']--;
                start++;
                s_map[s2[end+1]-'a']++;
                end++;
            }
            else break;
        }
        return false;
    }
};