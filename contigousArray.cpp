// Time Comlexity O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0) return 0;
        
        for(int i=0;i<n;i++)
            if(nums[i]==0) nums[i]=-1;
        int cum_sum[n];
        cum_sum[0]=nums[0];
        for(int i=1;i<n;i++) cum_sum[i]=nums[i]+cum_sum[i-1];
        int max_ans=0;
        for(int i=0;i<n;i++)
            if(cum_sum[i]==0) max_ans=i+1;
        unordered_map<int,int>m1;
        m1[0]=0;
        for(int i=0;i<n;i++){
            if(m1.find(cum_sum[i])==m1.end())
                m1[cum_sum[i]]=i;
            else max_ans=max(max_ans,i-m1[cum_sum[i]]);
        }
        
        return max_ans;
        
        
    }
};