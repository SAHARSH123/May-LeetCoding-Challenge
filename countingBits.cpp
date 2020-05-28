//Time Complexity O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        
       vector<int>numOne;
        numOne.push_back(0);
        for(int i=1;i<=num;i++){
            if(i%2==1) numOne.push_back(numOne[i/2]+1);
            else numOne.push_back(numOne[i/2]);
        }
        return numOne;
    }
};