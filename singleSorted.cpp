
//Time Complexity O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans=nums[0];
        for(int i=1;i<nums.size();i++) ans=ans^nums[i];
        return ans;
    }
};

//Time Complexity O(logn) Binary Search
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        if(arr.size()==0) return 0;
        int start=0;
        int end=arr.size()-1;
        int ans;
        while(start<=end){
            if(start==end) return arr[start];
            int mid=start+(end-start)/2;
            if(mid%2==0){ //before the single element occur every element first occurence will be on even 
                          // index the nat odd index
                if(arr[mid]==arr[mid+1]) start=mid+2;
                else end=mid;
            }
            else{
                if(arr[mid-1]==arr[mid]) start=mid+1;
                else end=mid-1;
            }
        }
        
        return 0;
    }
};