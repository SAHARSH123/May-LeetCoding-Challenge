#define ll long long
class Solution {
public:
    
    bool isPerfectSquare(int num) {
        ll Num=num/2;
        ll start=0,end=num;
        while(start<=end){
            ll mid=start+(end-start)/2;
            if(mid*mid==(ll)num) return true;
            if(mid*mid>(ll)num) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
};