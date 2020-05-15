//Time Complexity O(n)

class Solution {
public:
    int findContigousSum(vector<int>A){
        int cur_max=A[0];
        int total_max=A[0];
        
        for(int i=1;i<A.size();i++){
            cur_max=max(A[i],cur_max+A[i]);
            total_max=max(total_max,cur_max);
        }
        
        return total_max;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int normal_sum=findContigousSum(A);
        int sum=0;
        int flag=0;
        for(int i=0;i<A.size();i++) {
            sum+=A[i];
            if(A[i]>0) flag=1;
            A[i]=-1*A[i];
        }
        if(flag==0) return normal_sum;
        int inverted_sum=findContigousSum(A);
        return max(normal_sum,(sum+inverted_sum));
        
    }
};