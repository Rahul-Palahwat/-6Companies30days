class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
    set<int> s;
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[0].size(); ++j)
            for (int sz = 0; i + sz < g.size() && i - sz >= 0 && j + 2 * sz < g[0].size(); ++sz) {
                int x = i, y = j, r_sum = 0;
                do r_sum += g[x++][y++]; while (x < i + sz);
                if (sz > 0) {
                    do r_sum += g[x--][y++]; while (y < j + 2 * sz);
                    do r_sum += g[x--][y--]; while (x > i - sz);
                    do r_sum += g[x++][y--]; while (x < i);
                }
                s.insert(r_sum);
                if (s.size() > 3)
                    s.erase(begin(s));                
            }
    return vector<int>(rbegin(s), rend(s));
}
};