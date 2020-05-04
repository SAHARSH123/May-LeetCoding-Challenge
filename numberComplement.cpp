//time complexity log(n)
class Solution {
public:
    int findComplement(int no) {
        vector<int>temp;
        while(no!=0){
            temp.push_back(no%2);
            no=no/2;
        }
        int ans=0;
        int count=0;
        for(int i=0;i<temp.size();i++){
            //cout<<temp[i]<<" ";
            ans+=(!temp[i])*pow(2,count);
            count++;
        }
        cout<<endl;
        return ans;
    }
};