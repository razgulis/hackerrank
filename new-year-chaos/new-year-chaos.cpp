#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  int t;
  std::cin >> t;

  for (int i; i < t; ++i) {
    int n;
    std::cin >> n;
    std::vector<int> queue(n);
    int count = 0;

    // Get the queue
    for (int j; j < n; ++j) {
      std::cin >> queue[j];
    }

    // Check the queue
    for (int j=n-1; j >= 0; --j) {
      if (queue[j] - (j+1) > 2) {
        count = -1;
        break;
      }
        
      int k = queue[j]-2 > 0 ? queue[j]-2 : 0;
      for (; k < j; ++k) {
        if (queue[k] > queue[j]) {
          count++;
        }
      }
    }

    // Print the result
    if (count >= 0) {
      std::cout << count << std::endl;
    }
    else {
      std::cout << "Too chaotic" << std::endl;
    }
  }
}