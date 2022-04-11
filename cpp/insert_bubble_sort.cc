#include <iostream>
#include <algorithm>

using namespace std;

void insertion_sort(int *array, int count) {
    for (int i = 0; i < count; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void bubble_sort(int *array, int count) {
#if 0
    for (int i = 0; i < count; i++) {
        // bubble min to array[i]
        for (int j = count - 1; j > i; --j) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
        }
    }
#else
    for (int i = count - 1; i >= 1; --i) {
        // bubble max to array [i]
        for (int j = 0; j < i; ++j) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
#endif
}

void selection_sort(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        // select min to a[i]
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
