#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int minX, minY, maxX, maxY;

// Initialize bounds for the x and y coordinates
void initBounds(const vector<int>& x, const vector<int>& y) {
    minX = x[0];
    maxX = x[0];
    minY = y[0];
    maxY = y[0];
    for (int i = 1; i < x.size(); ++i) {
        if (x[i] > maxX) maxX = x[i];
        if (x[i] < minX) minX = x[i];
        if (y[i] > maxY) maxY = y[i];
        if (y[i] < minY) minY = y[i];
    }
}

// Count the number of points strictly inside the square defined by (sx1, sy1) and (sx2, sy2)
int countEnclosingPoints(const vector<int>& x, const vector<int>& y, int sx1, int sy1, int sx2, int sy2) {
    int count = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] > sx1 && x[i] < sx2 && y[i] > sy1 && y[i] < sy2) {
            count++;
        }
    }
    return count;
}

// Find the minimum area of a square that can enclose at least k points
long minArea(const vector<int>& x, const vector<int>& y, int k) {
    // Step 1: Initialize bounds
    initBounds(x, y);

    int xDiff = maxX - minX;
    int yDiff = maxY - minY;

    int sx1 = minX - 1;
    int sy1 = minY - 1;

    int sideDiff = std::abs(xDiff - yDiff) + 1;

    int sx2, sy2;
    if (xDiff > yDiff) {
        sx2 = maxX + 1;
        sy2 = maxY + sideDiff;
    } else {
        sx2 = maxX + sideDiff;
        sy2 = maxY + 1;
    }

    long area = (long)(sx2 - sx1) * (sx2 - sx1);

    // Step 2: Iterate over potential top-left corners of squares
    int minSize = (int) std::sqrt(k) + 1;
    for (int p = sx1; p < sx2 - minSize; ++p) {
        for (int q = sy1; q < sy2 - minSize; ++q) {
            int xd = sx2 - p;
            int yd = sy2 - q;
            int sd = (xd < yd) ? xd : yd;

            for (int i = sd; i >= minSize; --i) {
                int count = countEnclosingPoints(x, y, p, q, p + i, q + i);
                if (count >= k) {
                    long currArea = (long) i * i;
                    if (currArea < area) area = currArea;
                } else {
                    break;
                }
            }
        }
    }

    return area;
}

int main() {
    // Test case 1
    vector<int> x1 = {0, 2, 2};
    vector<int> y1 = {0, 4, 2};
    int k1 = 2;
    long min_area1 = minArea(x1, y1, k1);
    cout << "Minimum area of a square enclosing at least " << k1 << " points for the first set: " << min_area1 << endl;  // Expected: 36

    // Test case 2
    vector<int> x2 = {0, 3, 2};
    vector<int> y2 = {0, 7, 2};
    int k2 = 2;
    long min_area2 = minArea(x2, y2, k2);
    cout << "Minimum area of a square enclosing at least " << k2 << " points for the second set: " << min_area2 << endl;  // Expected: 81

    return 0;
}
