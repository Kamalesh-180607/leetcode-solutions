class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool inc = true, dec = true;
        for (int i = 0; i < n; i++) {
            int v = nums[(pos + i) % n];
            if (v != i)           inc = false;
            if (v != (n - i) % n) dec = false;
        }

        int ans = INT_MAX;
        if (inc) ans = min(pos, 2 + (n - pos) % n);
        if (dec) ans = min({ans, 1 + (n - 1 - pos), 1 + (pos + 1) % n});

        return ans == INT_MAX ? -1 : ans;
    }
};