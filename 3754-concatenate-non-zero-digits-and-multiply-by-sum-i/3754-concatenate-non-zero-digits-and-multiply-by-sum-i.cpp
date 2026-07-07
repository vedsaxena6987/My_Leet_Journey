class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x= 0, jod=0 ,lambai =1;
        while (n!= 0){
            x=(n%10)*lambai+x;
            if(n%10 != 0) lambai = lambai *10;
            jod+= n%10;
            n=n/10;
        }
        return jod * x;
    }
};