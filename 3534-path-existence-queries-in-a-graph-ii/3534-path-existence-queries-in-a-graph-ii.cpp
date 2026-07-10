class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>v1;
        for(int i=0;i<n;i++){
            v1.push_back({nums[i],i});
        }
        sort(v1.begin(),v1.end());

        vector<int>parent(n);

        for(int i=0;i<n;i++){
            int ind = v1[i].second;
            int val = v1[i].first;
           int itr = upper_bound(
                v1.begin(),
                v1.end(),
                make_pair(val + maxDiff, INT_MAX)
            ) - v1.begin();
            parent[ind] = v1[itr-1].second;
        }
        // for(auto &x:parent)cout<<x<<" "<<endl;
        vector<vector<int>>dp(n,vector<int>(19,-1));
        for(int j=0;j<19;j++){
             for(int i=0;i<n;i++){
                if(j==0)dp[i][j] = parent[i];
                else if(dp[i][j-1]!=-1) dp[i][j] = dp[dp[i][j-1]][j-1];
             }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<35;j++)cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        vector<int>ans;
        for(auto &x:queries){
            if(x[0]==x[1]){
                ans.push_back(0);
                continue;
            }
            int id1 = x[0];
            int id2 = x[1];
            if(nums[id2] < nums[id1])swap(id1,id2);

            long long s = 1;
            int e = 1e5 + 1;
            int res = -1;
           
            while(s<=e){
                int node1 = id1;
                int mid = (s+e)/2;
                for(int i=0;i<19;i++){
                    if((1LL<<i)&mid){
                        node1 = dp[node1][i];
                    }
                }
                if(nums[node1] >= nums[id2]){
                    res = mid;
                    e = mid - 1;
                }
                else s = mid + 1;
            }
            ans.push_back(res);

        
        }
        

        
        return ans;
    }
};