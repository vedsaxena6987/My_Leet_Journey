class Solution {
public:
    vector<vector<int>>grid;
    int n;
    // mid=safenessFactor
    vector<vector<int>>dist;
    

    bool isvalid(int mid){
        if(dist[0][0]<mid || dist[n-1][n-1]<mid){
            return false;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(r==n-1 && c==n-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && dist[nrow][ncol]>=mid && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        this->grid=grid;
        n=grid.size();
        dist.resize(n,vector<int>(n,INT_MAX));
        // dist[0][0]=0;
        // dist[n-1][n-1]=0;
        queue<pair<int,int>>q;//{row,col}
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && dist[nrow][ncol]==INT_MAX){
                    dist[nrow][ncol]=dist[r][c]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        int low=0;
        int high=2*n;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(mid)){
                ans=max(ans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};