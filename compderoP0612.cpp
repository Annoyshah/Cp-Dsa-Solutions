#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int findShortestPath(int input1, int input2, vector<vector<int>>& input3) {
    int rows = input1, cols = input2;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (input3[i][j] == 1) {
                q.push(make_pair(make_pair(i, j), 1)); 
                visited[i][j] = true;
                break;
            }
        }
    }

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first.first;
        int y = current.first.second;
        int dist = current.second;

        if (input3[x][y] == 2) {
            return dist;
        }

        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && input3[newX][newY] != -1 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push(make_pair(make_pair(newX, newY), dist + 1));
            }
        }
    }

    return -1;
}

int main() {
    int input1, input2;
    cin >> input1 >> input2;
    vector<vector<int>> input3(input1, vector<int>(input2));
    
    for (int i = 0; i < input1; ++i) {
        for (int j = 0; j < input2; ++j) {
            cin >> input3[i][j];
        }
    }

    cout << findShortestPath(input1, input2, input3) << endl;

    return 0;
}
