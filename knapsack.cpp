#include <iostream>
using namespace std;

struct Item {
    int profit;
    int weight;
};

double Knapsack(int Capacity, Item arr[], int n) {
    vector<pair<double, int> > v(n);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        v[i].first = arr[i].profit / double(arr[i].weight);
        v[i].second = i;
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n && Capacity > 0; i++) {
        if (arr[v[i].second].weight >= Capacity) {
            ans += Capacity * v[i].first;
            break;
        } else {
            ans += arr[v[i].second].profit;
            Capacity -= arr[v[i].second].weight;
        }
    }
    return ans;
}

int main() {
    int numberItems, Capacity;
    cout << "Enter the number of items & total capacity: ";
    cin >> numberItems >> Capacity;
    Item arritems[numberItems];
    cout << "Enter profits: ";
    for (int i = 0; i < numberItems; i++)
        cin >> arritems[i].profit;
    cout << "Enter weights: ";
    for (int i = 0; i < numberItems; i++)
        cin >> arritems[i].weight;
    cout << "Maximum Profit: " << Knapsack(Capacity, arritems, numberItems);
    return 0;
}