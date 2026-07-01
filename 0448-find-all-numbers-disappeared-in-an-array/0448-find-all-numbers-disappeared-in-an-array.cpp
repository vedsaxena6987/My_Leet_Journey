class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n+1,0);
        vector<int> res;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(freq[i]==0){
                res.push_back(i);
            }
        }
        return res;

    }
};