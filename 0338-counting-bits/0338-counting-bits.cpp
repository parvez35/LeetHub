class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector <int> ans(n+1);
        for (int i = 1; i <= n; i++)
        {
            int c = 0, t = i;
            while(t) {
                if (t % 2) c++;
                t /= 2;
            }
            ans[i] = c;
        }
        return ans;
    }
};
