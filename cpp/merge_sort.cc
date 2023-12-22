#include <climits>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void print_vector(const vector<T> &array, const string name = "") {
  cout << (name.length() > 0 ? name : "Unknown");
  cout << " with " << array.size() << " elements:" << endl;
  for (auto n : array) {
    cout << n << " ";
  }
  cout << endl;
}

void merge(vector<int> &data, size_t begin, size_t mid, size_t end) {
  vector<int> left(data.begin() + begin, data.begin() + mid + 1);
  vector<int> right(data.begin() + mid + 1, data.begin() + end + 1);
  size_t i, j, k;

  left.emplace_back(INT_MAX);
  right.emplace_back(INT_MAX);
  i = j = 0;
  for (k = begin; k <= end; ++k) {
    if (left[i] <= right[j]) {
      data[k] = left[i++];
    } else {
      data[k] = right[j++];
    }
  }
}

void merge_sort(vector<int> &data, size_t begin, size_t end) {
  if (begin < end) {
    size_t mid = (begin + end) / 2;
    merge_sort(data, begin, mid);
    merge_sort(data, mid + 1, end);
    merge(data, begin, mid, end);
  }
}

int main(void) {
  vector<int> data0 = {8, 3, 4, 6, 5, -1, -1, 0};
  vector<int> data1 = {9, 13, 2, 4, 5, 1, 11};
  vector<int> data2 = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> data3 = {7, 6, 5, 4, 3, 2, 1};

  cout << "INT_MAX = " << INT_MAX << endl;

  print_vector(data0, "original data0");
  merge_sort(data0, 0, data0.size() - 1);
  print_vector(data0, "sorted data0");

  print_vector(data1, "original data1");
  merge_sort(data1, 0, data1.size() - 1);
  print_vector(data1, "sorted data1");

  print_vector(data2, "original data2");
  merge_sort(data2, 0, data2.size() - 1);
  print_vector(data2, "sorted data2");

  print_vector(data3, "original data3");
  merge_sort(data3, 0, data3.size() - 1);
  print_vector(data3, "sorted data3");

  vector<int> data4;
  data4.push_back(0);
  print_vector(data4, "original data4");
  merge_sort(data4, 0, data4.size() - 1);
  print_vector(data4, "sorted data4");

  return 0;
}
