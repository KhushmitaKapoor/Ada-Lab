include <iostream>
using namespace std;
const int MAXNODES = 10;
const int INF = 9999;
struct edge
{
int u, v, cost;
};
int FindParent(int v, int parent[]){
while (parent [v] != v)
v = parent[v];
return v;
}
void Union(int i, int j, int parent[]) {
if(i < j)
parent[j] = i;
else
}
parent[i] = j;
void InputGraph(int m, edge e[]){
int i, j, k, cost;
cout << "Enter edge and cost in the form u, v, w: \n";
for(k=0; k<m; k++) {
cin >> i >> j >> cost;
e[k].u= i;
e[k].v = j;
e[k].cost = cost;
}
}
int GetMinEdge (edge e[], int n){
int small = INF;
int pos = -1;
for(int i=0; i<n; i++) {
if(e[i].cost < small){
small e[i].cost;
pos = i;
}
}
return pos;
}
void kruskal(int n, edge e[], int m){
int i, j, count, k, sum, u, v, t[MAXNODES] [2],pos;
int parent [MAXNODES];
count = 0;
k = 0;
sum = 0;
for(i=0; i<n; i++){
}
parent[i] = i;
while(count != n-1){
    pos = GetMinEdge(e,m);
if (pos == -1){
break;
}
u = e[pos].u;
v = e[pos].v;
i = FindParent(u,parent);
j = FindParent(v,parent);
if(i!= j){
t[k][0] = u;
t[k][1] = v;
k++;
count++;
sum += e[pos].cost;
Union(i, j, parent);
}
e[pos].cost = INF;
}
if (count == n-1){
cout << "\nSpanning tree exists";
cout << "\nThe Spanning tree is shown below\n"; for(i=0; i<n-1; i++)
cout << t[i][0] << " " << t[i][1] << endl;
cout << "\nCost of the spanning tree : <<sum;
}
else
cout << "\nThe spanning tree does not exist";
}
int main()
{
int n 6, m = 10;
edge e [2*MAXNODES] = {{0,1,6},{1,4,3},{4,5,6},{5,3,2},{3,0,5},{0,2,1}, {1,2,5},{3,2,5},{4,2,6},{5,2,4}};
cout << "Enter the number of nodes: ";
cin >> n;
cout << "Enter the number of edges : ";
cin >> m;
InputGraph(m, e);
kruskal(n, e, m);
return 0
}