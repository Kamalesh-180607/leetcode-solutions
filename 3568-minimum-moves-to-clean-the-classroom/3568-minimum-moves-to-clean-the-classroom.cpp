class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int si = -1, sj = -1;
        int litterCount = 0;

        // Give every litter an ID
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    si = i;
                    sj = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        int allMask = (1 << litterCount) - 1;

        // visited[i][j][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        q.push({si, sj, energy, 0});
        visited[si][sj][energy][0] = true;

        vector<vector<int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [i, j, remEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == allMask)
                    return moves;

                // Cannot move
                if (remEnergy == 0)
                    continue;

                for (auto& d : dir) {

                    int ni = i + d[0];
                    int nj = j + d[1];

                    // Outside classroom
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;

                    // Wall
                    if (classroom[ni][nj] == 'X')
                        continue;

                    int newEnergy = remEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[ni][nj] == 'L') {
                        newMask |= (1 << id[ni][nj]);
                    }

                    // Recharge
                    if (classroom[ni][nj] == 'R') {
                        newEnergy = energy;
                    }

                    if (!visited[ni][nj][newEnergy][newMask]) {

                        visited[ni][nj][newEnergy][newMask] = true;

                        q.push({
                            ni,
                            nj,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};