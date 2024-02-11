class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& s) 
    {
        vector <int> v, a;
        map <char,int> mp;
        for (int i = 0; i < s.size(); i++) {
            int p = s[i].size();
            v.push_back(p);
            for (int j = 0; j < s[i].size(); j++) mp[s[i][j]]++;
        }
        sort(begin(v), end(v));
        int ans = 0;
        for (auto i : mp) {
            //cout << i.first << " " << i.second << endl;
            a.push_back(i.second);
        }
        sort(rbegin(a), rend(a));
        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i];
                if (x % 2 == 1) {
                    for (int j = 0; j < a.size(); j++) {
                        if (a[j] % 2 == 1) {
                            x -= a[j];
                            a[j] = 0;
                            break;
                        }
                    }
                }
            sort(rbegin(a), rend(a));
            for (int j = 0; j < a.size(); j++)
            {
                int y = (a[j]/2)*2;
                if (y >= x) 
                {
                    a[j] -= x;
                    x = 0;
                    break;
                }
                else 
                {
                    a[j] -= y;
                    x -= y;
                }
            }
            if (x == 0) ans++;
        sort(rbegin(a), rend(a));
        }
        return ans;
    }
};