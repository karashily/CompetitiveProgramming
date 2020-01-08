#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void dfs_aux(vector<vector<int>>& graph, int curr, bool* visited, queue<int>& topologicalSort) {
    cout << curr << " ";
    visited[curr] = true;
    for(auto i = graph[curr].begin(); i != graph[curr].end(); i++) {
        if(!visited[*i])
            dfs_aux(graph, *i, visited, topologicalSort);
    }
    topologicalSort.push(curr);
}

void dfs (vector<vector<int>> graph) {
    int n = graph.size();
    
    bool visited[n];
    for(int i = 0; i<n; i++) visited[i] = false;
    
    queue<int> toplogicalSort;

    cout << "\nDepth first search of the graph: \n";
    dfs_aux(graph, 2, visited, toplogicalSort);

    cout << "\ntopological sort of the graph: \n";
    while(!toplogicalSort.empty()) {
        cout << toplogicalSort.front() << " ";
        toplogicalSort.pop();
    }

}

int main() {
    int V = 4;
    vector<vector<int>> graph (V);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);
    dfs(graph);
    return 0;
}