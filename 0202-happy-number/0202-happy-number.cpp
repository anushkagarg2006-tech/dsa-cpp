class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long> s;
        
        while(!s.count(n)){
            long long m=n;
            long long sum=0;
            while(m>0){
                int digit=m%10;
                sum+=pow(digit,2);
                m=m/10;
            }
            if(sum==1){
                return true;
            }
            s.insert(n);
            n=sum;
        }return false;
    }
};