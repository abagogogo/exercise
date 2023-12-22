#include <climits>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void print_vector(const vector<T> &array, const string name = "") {
  cout << (!name.empty() ? name : "Unknown");
  cout << " with " << array.size() << " elements:" << endl;
  for (const auto &n : array) {
    cout << n << " ";
  }
  cout << endl;
}

// Heap definition: an array object that can be viewed as a nearly complete tree.
// Max-heap property: A[parent(i)] >= A[i] -> root is the max.
// Heap application: priority queue (union/insert/extract-min), k-way merge.
int parent(int i) { return (i - 1) / 2; }

int left(int i) { return (i * 2 + 1); }

int right(int i) { return (i * 2 + 2); }

void max_heapify_down(vector<int> &array, int curr, int heap_size) {
  int left_child = left(curr);
  int right_child = right(curr);
  int max_idx;

  max_idx = curr;
  for (int i = left_child; i < heap_size && i <= right_child; ++i) {
    if (array[i] > array[max_idx]) max_idx = i;
  }
  if (max_idx != curr) {
    swap(array[max_idx], array[curr]);
    max_heapify_down(array, max_idx, heap_size);
  }
}

void max_heapify_up(vector<int> &array, int curr) {
  while (curr > 0 && parent(curr) >= 0 && array[parent(curr)] < array[curr]) {
    swap(array[parent(curr)], array[curr]);
    curr = parent(curr);
  }
}

bool remove_heap(vector<int> &array, int *heap_size) {
  if (!heap_size || *heap_size <= 0) return false;

  swap(array[0], array[*heap_size - 1]);
  (*heap_size)--;
  array.pop_back();
  max_heapify_down(array, 0, *heap_size);
  return true;
}

void insert_heap(vector<int> &array, int val, int *heap_size) {
  array.push_back(val);
  (*heap_size)++;
  max_heapify_up(array, *heap_size - 1);
}

int build_max_heap(vector<int> &array) {
  int heap_size = array.size();
  for (int i = parent(heap_size - 1); i >= 0; --i) {
    max_heapify_down(array, i, heap_size);
  }
  return heap_size;
}

void heap_sort(vector<int> &array) {
  int heap_size = build_max_heap(array);

  for (int i = heap_size - 1; i >= 1; --i) {
    swap(array[0], array[i]);
    heap_size--;
    max_heapify_down(array, 0, heap_size);
  }
}

int main(void) {
    vector<int> data0 = {8, 3, 4, 6, 5, -1, -1, 0};
    vector<int> data1 = {9, 13, 2, 4, 5, 1, 11};
    vector<int> data2 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> data3 = {7, 6, 5, 4, 3, 2, 1};

    print_vector(data0, "original data0");
    heap_sort(data0);
    print_vector(data0, "sorted data0");

    print_vector(data1, "original data1");
    heap_sort(data1);
    print_vector(data1, "sorted data1");

    print_vector(data2, "original data2");
    heap_sort(data2);
    print_vector(data2, "sorted data2");

    print_vector(data3, "original data3");
    heap_sort(data3);
    print_vector(data3, "sorted data3");

    vector<int> data4;
    data4.push_back(0);
    print_vector(data4, "original data4");
    heap_sort(data4);
    print_vector(data4, "sorted data4");

    return 0;
}
