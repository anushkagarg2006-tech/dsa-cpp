class Solution {
public:
    int maxDepth(string s) {
        int curr=0;
        int maxd=0;
        for(char ch: s){
            if(ch=='('){
                curr++;
                maxd=max(maxd,curr);
            }else if(ch==')'){
                curr--;
            }
        }return maxd;
    }
};