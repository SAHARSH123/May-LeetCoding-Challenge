class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int>m1;
        for(int i=0;i<J.size();i++) m1[J[i]]++;
        int count=0;
        for(int i=0;i<S.size();i++){
            if(m1[S[i]]!=0) count++;
        }
        return count;
    }
};
