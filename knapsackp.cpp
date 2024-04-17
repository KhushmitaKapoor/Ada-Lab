#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maximizeProfit(int W, const vector<int>& wt, const vector<int>& val, int n) {
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
    int profit[] = {30, 40, 50, 70}; 
    int weight[] = {5, 10, 15, 20};  

    vector<int> profits(profit, profit + sizeof(profit) / sizeof(profit[0]));
    vector<int> weights(weight, weight + sizeof(weight) / sizeof(weight[0]));
    int knapsackCapacity = 35; 
    int numItems = sizeof(profit) / sizeof(profit[0]);
    cout << "Maximum profit that can be obtained: " << maximizeProfit(knapsackCapacity, weights, profits, numItems) << endl;
    return 0;
}
