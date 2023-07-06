#include <algorithm>
#include <iostream>

using namespace std;

void insertion_sort(int *a, int n) {
  // assume a[0 to i-1] are sorted, insert a[i].
  for (int i = 1; i < n; ++i) {
    int key = a[i];
    int j;
    for (j = i - 1; j >= 0; --j) {
      if (a[j] <= key) break;
      a[j + 1] = a[j];
    }
    a[j + 1] = key;
  }
}

void bubble_sort(int *a, int n) {
  // bublle max of a[0 to i] to a[i]
  for (int i = n - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }
  }
}

void selection_sort(int *a, int n) {
  // select min a[i to n-1] to a[i]
  for (int i = 0; i < n - 1; ++i) {
    int min_val = a[i];
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < min_val) {
        min_val = a[j];
        min_idx = j;
      }
    }
    swap(a[i], a[min_idx]);
  }
}

int main(void) {
  int input[] = {4, 3, 1, 5, 2};
  int count = sizeof(input) / sizeof(input[0]);
  int *sort1 = new int[count]();
  int *sort2 = new int[count]();
  int *sort3 = new int[count]();

  cout << "insertion sort" << endl;
  for (int i = 0; i < count; ++i) {
    sort1[i] = input[i];
  }
  insertion_sort(sort1, count);
  for (int i = 0; i < count; ++i) {
    cout << "sort1[" << i << "] = " << sort1[i] << endl;
  }

  cout << "bubble sort" << endl;
  for (int i = 0; i < count; ++i) {
    sort2[i] = input[i];
  }
  bubble_sort(sort2, count);
  for (int i = 0; i < count; ++i) {
    cout << "sort2[" << i << "] = " << sort2[i] << endl;
  }

  cout << "selection sort" << endl;
  for (int i = 0; i < count; ++i) {
    sort3[i] = input[i];
  }
  selection_sort(sort3, count);
  for (int i = 0; i < count; ++i) {
    cout << "sort3[" << i << "] = " << sort3[i] << endl;
  }
  return 0;
}
