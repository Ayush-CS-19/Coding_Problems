class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        if(positions.size()==1)return {healths[0]};
        vector<pair<int,int>>pos(positions.size());
        vector<int>collison;
        stack<int>kt;
        for(int i=0;i<positions.size();i++)pos[i]={positions[i], i};
        sort(pos.begin(),pos.end());
        reverse(pos.begin(),pos.end());
    for(auto& [pos, i]: pos){
        if(directions[i]=='L'){
            kt.push(i);
        }
        else{
        while(!kt.empty() && healths[i]>0){
            int j=kt.top();
            int x=healths[j]-healths[i];
            if(x>0){
                healths[j]=healths[j]-1;
                healths[i]=0;
                }
            else if(x<0){
                healths[i]=healths[i]-1;
                healths[j]=0;
                kt.pop();
            }
            else{
                healths[i]=0;
                healths[j]=0;
                kt.pop();
            }
     }
    }
}
    for(auto i:healths){
        if(i>0){
            collison.push_back(i);
        }
    }
    return collison;
    }
};