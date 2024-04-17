#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int weight;
    int profit;
    double ratio;
    Item(int w, int p) : weight(w), profit(p), ratio(0.0) {}
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    int remainingWeight = W;

    for (int i = 0; i < items.size(); ++i) {
        if (remainingWeight >= items[i].weight) {
            totalProfit += items[i].profit;
            remainingWeight -= items[i].weight;
        } else {
            totalProfit += items[i].ratio * remainingWeight;
            break;
        }
    }

    return totalProfit;
}
int main() {
    vector<Item> items;
    items.push_back(Item(10, 60));  
    items.push_back(Item(20, 100)); 
    items.push_back(Item(30, 120)); 

    int knapsackCapacity = 50;

    cout << "Maximum profit that can be obtained: " << fractionalKnapsack(knapsackCapacity, items) << endl;
    
    return 0;
}


