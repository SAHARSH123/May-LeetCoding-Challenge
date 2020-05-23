//Time Complexity O(n)
//Simple merge
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>>ans;
        if(A.size()==0 || B.size()==0) return ans;
        int first_ptr=0,second_ptr=0;
        while(first_ptr<A.size() && second_ptr<B.size()){
            int max_start=max(A[first_ptr][0],B[second_ptr][0]);
            int min_end=min(A[first_ptr][1],B[second_ptr][1]);
            if(max_start<=min_end){
                vector<int>temp;
                temp.push_back(max_start);
                temp.push_back(min_end);
                ans.push_back(temp);
            }
            if(A[first_ptr][1]>B[second_ptr][1]) second_ptr++;
            else first_ptr++;
        }
        return ans;
        
    }
};