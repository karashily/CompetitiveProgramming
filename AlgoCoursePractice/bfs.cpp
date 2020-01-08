#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> graph, int* lvls, int source) {
    int n = graph.size();
    
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    
    queue<int> q;
    q.push(source);
    visited[source] = true;
    lvls[source] = 0;
    while(!q.empty()) {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(auto i = graph[curr].begin(); i != graph[curr].end(); i++) {
            if(!visited[*i]){
                visited[*i] = true;
                lvls[*i] = lvls[curr] + 1;
                q.push(*i);
            }
        }
    }
    cout << endl;
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
    int lvls[V];
    bfs(graph, lvls, 2);
    for(int i = 0; i < V; i++) {
        cout << i << " " << lvls[i] << endl;
    }
}