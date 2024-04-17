#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<int> dp(W + 1, 0);

    for (int w = 1; w <= W; ++w) {
        for (int i = 0; i < n; ++i) {
            if (wt[i] <= w) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
    }
    return dp[W];
}

int main() {
    int val_arr[] = {60, 100, 120};
    int wt_arr[] = {10, 20, 30};

    vector<int> val(val_arr, val_arr + sizeof(val_arr) / sizeof(val_arr[0]));
    vector<int> wt(wt_arr, wt_arr + sizeof(wt_arr) / sizeof(wt_arr[0]));

    int W = 50;
    int n = sizeof(val_arr) / sizeof(val_arr[0]);

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;
    return 0;
}

