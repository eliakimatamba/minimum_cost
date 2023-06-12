#include <vector>
#include <iostream>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int getMinCost(vector<int>& crew_id, vector<int>& job_id) {
    int n = crew_id.size();
    int m = job_id.size();

    // Create and initialize the cost matrix
    vector<vector<int>> cost(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Calculate the cost as the absolute difference between crew_id and job_id
            cost[i][j] = abs(crew_id[i] - job_id[j]);
        }
    }

    vector<int> u(n + 1), v(m + 1);
    vector<int> p(m + 1), way(m + 1);
    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(m + 1, INF);
        vector<bool> used(m + 1, false);

        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    return -v[0];  // The minimum cost is the negation of the dual solution
}

int main() {
    vector<int> crew_id = {1, 2, 3};
    vector<int> job_id = {4, 5, 6};
    int minCost = getMinCost(crew_id, job_id);
    cout << "Minimum cost: " << minCost << endl;
    return 0;
}
