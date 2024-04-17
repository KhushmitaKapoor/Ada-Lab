#include <iostream>
#include <vector>
using namespace std;

void sum_of_subsets(int s, int k, int r, vector<int>& wt, int m, vector<int>& x) {
    if (k == wt.size()) {
        if (s == m) {
            for (int i = 0; i < x.size(); i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    x[k] = 1;
    if (s + wt[k] <= m) {
        sum_of_subsets(s + wt[k], k + 1, r - wt[k], wt, m, x);
    }
    x[k] = 0;
    if (s + r - wt[k] >= m && s + wt[k + 1] <= m) {
        sum_of_subsets(s, k + 1, r - wt[k], wt, m, x);
    }
}

int main() {
    vector<int> wt;
    wt.push_back(5);
    wt.push_back(10);
    wt.push_back(12);
    wt.push_back(13);
    wt.push_back(15);
    wt.push_back(18);

    int m = 30;
    vector<int> x(wt.size(), 0);
    int sum = 0;
    for (int weight : wt) {
        sum += weight;
    }
    sum_of_subsets(0, 0, sum, wt, m, x);
    return 0;
}

