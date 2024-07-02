#include <bits/stdc++.h>
using namespace std;

// Directions for moving up, down, left, right
vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// Check if the given cell (x, y) is valid in the matrix
bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool isGreaterThanNeighbors(int x, int y, vector<vector<int>>& matrix) {
    for (auto& dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (isValid(newX, newY, matrix.size(), matrix[0].size()) && matrix[x][y] <= matrix[newX][newY]) {
            return false;
        }
    }
    return true;
}

void stabilizeMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    bool stabilized = false;
    
    while (!stabilized) {
        stabilized = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isGreaterThanNeighbors(i, j, matrix) && matrix[i][j] > 0) {
                    matrix[i][j]--;
                    stabilized = false;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        stabilizeMatrix(matrix);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
