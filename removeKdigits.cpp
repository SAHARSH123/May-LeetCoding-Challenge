//Time Complexity O(n)
//Space complexity O(n)


class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==0) return num;
        if(num.size()==k) return "0";
        stack<int>s1;
        int i=0;
        
        while(i<num.size()){
            while(k>0 && s1.size()>0 && s1.top()>(num[i]-'0')){
                s1.pop();
                k--;
            }
            s1.push(num[i]-'0');
            i++;
         }
        
        string ans;
        while(s1.size()>0){
            ans.push_back(s1.top()+'0');
            s1.pop();
        }
        while(ans.size()>0 && ans[ans.size()-1]=='0') ans.pop_back();
        if(ans.size()!=0) reverse(ans.begin(),ans.end());
        while(k>0){
            ans.pop_back();
            k--;
        }
        if(ans.size()==0) return "0";
        return ans;
        
        
    }
};