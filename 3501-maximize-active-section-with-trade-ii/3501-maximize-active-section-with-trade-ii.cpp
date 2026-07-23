class Solution {
public:
    vector<int> seg;
    int n;

    void build(int ind, int low, int high, vector<int>& arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        int mid = low+(high-low)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }
    int query(int ind, int low, int high, int left, int right){
        if(left<=low && right>=high) return seg[ind];
        if(right<low || left>high) return INT_MIN;
        int mid = low+(high-low)/2;
        int l = query(2*ind+1, low, mid, left, right);
        int r = query(2*ind+2, mid+1, high, left, right);
        return max(l,r);
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int len = s.size();
        int ones = 0;

        for(auto i : s) if(i == '1') ones++;

        vector<int> gstart, glen;
        vector<int> gidx(len);

        for(int i=0;i<len;i++){
            if(s[i]=='0'){
                if(i>0 && s[i-1]=='0') glen.back()++;
                else{
                    gstart.push_back(i);
                    glen.push_back(1);
                }
            }
            gidx[i] = gstart.size()-1;
        }

        if(gstart.empty()) return vector<int>(queries.size(), ones);

        vector<int> mergelen;
        for(int i=0;i+1<(int)gstart.size();i++)
            mergelen.push_back(glen[i]+glen[i+1]);

        n = mergelen.size();
        if(n>0){
            seg.assign(4*n, INT_MIN);
            build(0,0,n-1,mergelen);
        }

        vector<int> ans;
        for(auto q : queries){
            int l = q[0], r = q[1];

            int left;
            if(gidx[l]==-1) left = -1;
            else left = glen[gidx[l]] - (l - gstart[gidx[l]]);

            int right;
            if(gidx[r]==-1) right = -1;
            else right = r - gstart[gidx[r]] + 1;

            int fullStart = gidx[l]+1;

            int fullEnd;
            if(s[r]=='1') fullEnd = gidx[r];
            else fullEnd = gidx[r]-1;

            int best = ones;

            if(fullStart > fullEnd){
                if(s[l]=='0' && s[r]=='0' && gidx[r]==fullStart)
                    best = max(best, ones+left+right);
            }else{
                if(s[l]=='0') best = max(best, ones+left+glen[fullStart]);
                if(s[r]=='0') best = max(best, ones+right+glen[fullEnd]);
                if(fullEnd>fullStart) best = max(best, ones+query(0,0,n-1,fullStart,fullEnd-1));
            }
            ans.push_back(best);
        }
        return ans;
    }
};