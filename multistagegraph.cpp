#include <iostream>
#include <climits>
using namespace std;

struct Result
{
    int path[4];
    int length;
};

Result fcost(int cost[4][4], int number_vertices, int k)
{
    int fcost[number_vertices];
    fcost[number_vertices - 1] = 0;
    int d[number_vertices];
    int path[k];
    int r;
    for (int j = number_vertices - 2; j >= 0; j--)
    {
        int min = INT_MAX;
        for (int h = j + 1; h < number_vertices; h++)
        {
            if (cost[j][h] != 0 && cost[j][h] != INT_MAX)
            {
                if (cost[j][h] + fcost[h] < min)
                {
                    r = h;
                    min = cost[j][h] + fcost[h];
                }
            }
        }
        fcost[j] = cost[j][r] + fcost[r];
        d[j] = r;
    }
    Result result;
    result.length = fcost[0];
    result.path[0] = 1;
    result.path[k - 1] = number_vertices;

    for (int n = 1; n < k - 1; n++)
    {
        result.path[n] = d[result.path[n - 1] - 1] + 1;
    }
    return result;
}
int calculateNumStages(int cost[4][4], int number_vertices)
{
    int maxStage = 0;
    for (int i = 0; i < number_vertices; ++i)
    {
        for (int j = 0; j < number_vertices; ++j)
        {
            if (cost[i][j] != 0 && cost[i][j] != INT_MAX && j > maxStage)
            {
                maxStage = j;
            }
        }
    }
    return maxStage + 1; 
}
int main()
{
    int cost[4][4] = {
        {1, 2, 3, 4},
        {INT_MAX, 1, 2, 3},
        {INT_MAX, INT_MAX, 1, 2},
        {INT_MAX, INT_MAX, INT_MAX, 1}};
    int number_vertices = 4;
    int path_length = 4;
    Result result = fcost(cost, number_vertices, path_length);
    cout << "Minimum cost path length: " << result.length << endl;
    cout << "Path: ";
    for (int i = 0; i < path_length; i++)
    {
        cout << result.path[i] << " ";
    }
    cout << endl;
    int numStages = calculateNumStages(cost, number_vertices);
    cout << "Number of stages in the graph: " << numStages << endl;
    return 0;
}

