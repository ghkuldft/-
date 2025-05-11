#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> t(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> t[i][j];
        }
    }

    // Сортируем интервалы по времени окончания
    sort(t.begin(), t.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int res = 1;
    int last_end = t[0][1];
    for (int i = 1; i < n; ++i) {
        if (t[i][0] > last_end) {
            ++res;
            last_end = t[i][1];
        }
    }

    cout << res;
    return 0;
}
