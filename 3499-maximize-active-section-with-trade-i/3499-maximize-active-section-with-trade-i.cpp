class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> contarr;
        int n=s.length();
        int cnt=0;
        int maxsum=0; // store final max answer
        int possum=0; // store the count of all the 1's in the original string

        /**
        If we convert 0 to -1 in s, and add up the same contiguous parts:
        1000100 becomes [+1, -3, +1, -2] 
        */

        for(int i=0;i<n;i++)
        {
            if(i!=0 && s[i]!=s[i-1]) // when break in continious then change the counter;
            {
                contarr.push_back(cnt);
                cnt=0;
            }
            cnt= s[i]=='0'?cnt-1:cnt+1;
        }
        contarr.push_back(cnt);
        for(int i:contarr) // count the sum of all the active sessions i.e 1;
        {
            if(i>0)
            possum+=i;
        }
        // ------------------------------------------------------------------
        // note one trade means FIRST we have to chage continuous 1's to 0 then all continuous 0's to 1's
        // so our approach 
        // step 1 : find a positive which is in between negative
        // this is our +ve to -ve change 
        // now these 3 continous -ve will be converted to +ve
        // so here net we do is add these two bondary negatives to the prexisting sum of all positives and maximise this number by visiting various locations with [-ve,+ve,-ve]
        // and technically all the remaining POSITIVES will only be added
        // -------------------------------------------
        maxsum=possum; // if in case no trade occurs then the total no of 1's is the answer 
        int m = contarr.size();
        for(int i=1;i<m-1;i++)
        {
            if(i>0 && contarr[i-1]<0 && contarr[i+1]<0 && contarr[i]>0) // check [-ve,+ve,-ve]
            {
                maxsum=max(maxsum,(possum+abs(contarr[i-1]+contarr[i+1]))); // add count of 0's i.e -ve to the possum and maximise
            }
        }
        return maxsum;
    }
};