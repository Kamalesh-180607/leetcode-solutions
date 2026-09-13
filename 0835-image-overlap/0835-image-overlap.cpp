class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        
        int n = img1.size();
        
        vector<pair<int,int>> a, b;
        
        // Store positions of 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    a.push_back({i, j});
                
                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }
        
        map<pair<int,int>, int> freq;
        int ans = 0;
        
        for (auto [x1, y1] : a) {
            for (auto [x2, y2] : b) {
                
                int dx = x2 - x1;
                int dy = y2 - y1;
                
                freq[{dx, dy}]++;
                ans = max(ans, freq[{dx, dy}]);
            }
        }
        
        return ans;
    }
};