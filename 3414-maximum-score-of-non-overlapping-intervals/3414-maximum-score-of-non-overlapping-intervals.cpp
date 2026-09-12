class Solution {
public:
    int n;
    vector<vector<int>> a;

    // dp[i][cnt] = {maximum score, corresponding indices}
    vector<vector<pair<long long, vector<int>>>> dp;
    vector<vector<bool>> vis;

    int getNext(int i) {

        int lo = i + 1;
        int hi = n - 1;
        int ans = n;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (a[mid][0] > a[i][1]) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return ans;
    }

    pair<long long, vector<int>> solve(int i, int cnt) {

        if (i == n || cnt == 4)
            return {0, {}};

        if (vis[i][cnt])
            return dp[i][cnt];

        vis[i][cnt] = true;

        // Don't pick
        auto notPick = solve(i + 1, cnt);

        // Pick
        int next = getNext(i);

        auto pick = solve(next, cnt + 1);

        pick.first += a[i][2];
        pick.second.push_back(a[i][3]);

        // We need indices in sorted order for lexicographical comparison
        sort(pick.second.begin(), pick.second.end());

        // Choose better score
        if (pick.first > notPick.first) {
            return dp[i][cnt] = pick;
        }

        if (pick.first < notPick.first) {
            return dp[i][cnt] = notPick;
        }

        // Same score -> lexicographically smaller indices
        if (pick.second < notPick.second) {
            return dp[i][cnt] = pick;
        }

        return dp[i][cnt] = notPick;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // {start, end, weight, original_index}
        for (int i = 0; i < n; i++) {

            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start time
        sort(a.begin(), a.end(),
             [](const vector<int>& x, const vector<int>& y) {

                 if (x[0] != y[0])
                     return x[0] < y[0];

                 if (x[1] != y[1])
                     return x[1] < y[1];

                 return x[2] < y[2];
             });

        dp.resize(n, vector<pair<long long, vector<int>>>(5));
        vis.assign(n, vector<bool>(5, false));

        return solve(0, 0).second;
    }
};