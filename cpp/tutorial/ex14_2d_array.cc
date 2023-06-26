#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

template <typename T, typename TIter = decltype(std::begin(std::declval<T>()))>
constexpr auto enumerate(T&& iterable) {
  struct iterator {
    size_t i;
    TIter iter;
    bool operator!=(const iterator& other) const { return iter != other.iter; }
    void operator++() {
      ++i;
      ++iter;
    }
    auto operator*() const { return std::tie(i, *iter); }
  };
  struct iterable_wrapper {
    T iterable;
    auto begin() { return iterator{0, std::begin(iterable)}; }
    auto end() { return iterator{0, std::end(iterable)}; }
  };
  return iterable_wrapper{std::forward<T>(iterable)};
}

int main() {
  int row_cnt = 3;
  int col_cnt = 4;
  int i, j;

  // v1
  int** matrix = new int*[row_cnt];
  for (i = 0; i < row_cnt; i++) {
    matrix[i] = new int[col_cnt];
  }
  for (i = 0; i < row_cnt; i++) {
    for (j = 0; j < col_cnt; j++) {
      matrix[i][j] = (i * col_cnt) + j;
    }
  }

  // v2
  vector<vector<int>> matrix_i(row_cnt, vector<int>(col_cnt, -1));
  for (i = 0; i < row_cnt; i++) {
    for (j = 0; j < col_cnt; j++) {
      cout << "matrix[" << i << "]";
      cout << "[" << j << "]";
      cout << " = " << matrix[i][j] << endl;
      matrix_i[i][j] = matrix[i][j];
    }
  }

  for (i = 0; i < row_cnt; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;

  for (i = 0; i < row_cnt; i++) {
    for (j = 0; j < col_cnt; j++) {
      cout << "matrix_i[" << i << "]";
      cout << "[" << j << "]";
      cout << " = " << matrix_i[i][j] << endl;
    }
  }
  for (const auto& row : matrix_i) {
    for (const auto& element : row) {
      cout << element << ", ";
    }
  }
  cout << endl;

  // v3. C__17 structured bindings to access matrix elements.
  vector<vector<int>> matrix_ii = matrix_i;
  for (const auto& [row_idx, row] : enumerate(matrix_ii)) {
    for (const auto& [col_idx, element] : enumerate(row)) {
      cout << "matrix_ii[" << row_idx << "]";
      cout << "[" << col_idx << "]";
      cout << " = " << element << endl;
    }
  }

  return 0;
}
