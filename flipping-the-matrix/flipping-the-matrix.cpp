#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  int q, n;
  std::cin >> q;

  for (int i; i < q; ++i) {
    int n;
    std::cin >> n;
    int width = n*2;
    int count = width*width;
      
    // Allocate the Matrix
    std::vector < std::vector<int> > matrix(width, std::vector<int>(width));
      
    // Fill in the Matrix from input
    for(int j; j < width; ++j) {
      for (int k; k < width; ++k) {
        std::cin >> matrix[j][k];
      }
    }
      
    // Solve the Matrix
    int result = 0;
    for (int j; j < n; ++j) {
      for (int k; k < n; ++k) {
        result += std::max(
          std::max(
            matrix[j][k],
            matrix[width - 1 - j][k]
          ),
          std::max(
            matrix[j][width - 1 - k],
            matrix[width - 1 - j][width - 1 - k]
          )
        );
      }
    }

    // Print the solution
    std::cout << result << std::endl;
  }
}