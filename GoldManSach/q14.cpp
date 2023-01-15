
        int curr = 0;
        int res = 0;
        unordered_map<int, int> cnt;
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (cnt[nums[r]] > 0) {
                curr += cnt[nums[r]];
            }
            cnt[nums[r]]++;
            while (l <= r && curr >= k) {
                if (cnt[nums[l]] > 1) {
                    curr -= (cnt[nums[l]] - 1);
                }
                cnt[nums[l]]--;
                l++;
            }
            res += (r - l + 1);
        }
        return (n * (n + 1) / 2) - res;