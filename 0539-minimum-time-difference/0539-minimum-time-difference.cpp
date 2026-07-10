class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mint;
        for( int i=0;i<timePoints.size();i++){
            int hour=stoi(timePoints[i].substr(0,2));
            
            int minu=stoi(timePoints[i].substr(3,5));
            int minti=hour*60+minu;
            mint.push_back(minti);
        }
        sort(mint.begin(),mint.end());
        int mindif=INT_MAX;
        for(int i=1;i<mint.size();i++){
            mindif=min(mindif,mint[i]-mint[i-1]);
        }
        int n=mint.size();
        mindif=min(mindif,1440+mint[0]-mint[n-1]);
        return mindif;}
};