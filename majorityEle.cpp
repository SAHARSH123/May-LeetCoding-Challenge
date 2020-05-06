//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        n=n/2;
        unordered_map<int,int>m1;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
            if(m1[nums[i]]>n) return nums[i];
        }
        return 1;
    }
};