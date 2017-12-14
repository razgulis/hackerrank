#include <set>
#include <list>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  int q;
  std::cin>>q;

  for (int i; i < q; ++i) {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector<std::set<int>> connections(n+1);

    // Build the connection list
    for (int j; j < m; ++j) {
      int node1, node2;
      std::cin >> node1;
      std::cin >> node2;
      connections[node1].insert(node2);
      connections[node2].insert(node1);
    }

    bool visited[n+1] = {false};
    int distance[n+1] = {0};
    std::list<int> queue;

    int start;
    std::cin >> start;

    queue.push_back(start);
    visited[start] = true;

    // Traverse
    while (!queue.empty()) {
      int current = queue.front();

      std::set<int>::const_iterator it;
      for (it=connections[current].begin(); it != connections[current].end(); ++it) {
        if(!visited[*it]) {
          queue.push_back(*it);
          distance[*it] += (distance[current] + 6);
          visited[*it] = true;
        }
      }
      queue.pop_front();
    }

    for (int j=1; j <= n; ++j) {
      if (j != start) {
        if (distance[j] == 0) {
          std::cout << "-1";
        }
        else {
          std::cout << distance[j] << " ";
        }
      }
    }

    std::cout << std::endl; 
  }
}