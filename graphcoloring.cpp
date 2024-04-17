#include <iostream>
#include <vector>
using namespace std;

void next_value(int k, int n, vector<int>& x, const vector<vector<int> >& cost) {
    do {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0) {
            return;
        }
        int j;
        for (j = 0; j < cost[k].size(); j++) {
            if (cost[k][j] == 1 && x[k] == x[j]) {
                break;
            }
        }
        if (j == cost[k].size()) {
            return;
        }
    } while (true);
}

void mcoloring(int k, int m, vector<int>& x, const vector<vector<int> >& cost) {
    if (k == cost.size()) {
        for (int i = 0; i < cost.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }
    do {
        next_value(k, m, x, cost);
        if (x[k] == 0) {
            return;
        } else {
            mcoloring(k + 1, m, x, cost);
        }
    } while (true);
}

int main() {
    int m = 3;
    vector<vector<int> > cost;
    cost.push_back(vector<int>());
    cost[0].push_back(0);
    cost[0].push_back(1);
    cost[0].push_back(0);
    cost[0].push_back(1);

    cost.push_back(vector<int>());
    cost[1].push_back(1);
    cost[1].push_back(0);
    cost[1].push_back(1);
    cost[1].push_back(0);

    cost.push_back(vector<int>());
    cost[2].push_back(0);
    cost[2].push_back(1);
    cost[2].push_back(0);
    cost[2].push_back(1);

    cost.push_back(vector<int>());
    cost[3].push_back(1);
    cost[3].push_back(0);
    cost[3].push_back(1);
    cost[3].push_back(0);

    int n = cost.size();
    vector<int> color(n, 0);
   
    mcoloring(0, m, color, cost);
    return 0;
}
