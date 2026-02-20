long long sumAndPairs(vector<int>& a) {
    long long ans = 0;
    int n = a.size();

    for(int b = 0; b < 32; b++){
        long long cnt = 0;
        for(int x : a){
            if(x & (1 << b)) cnt++;
        }
        ans += (cnt * (cnt + 1) / 2) * (1LL << b);
    }
    return ans;
}
\
