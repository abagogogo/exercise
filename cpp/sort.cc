#include <array>
#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& arr) {
    // assume arr[0 to i-1] are sorted, insert arr[i].
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

void bubble_sort(vector<int>& arr) {
    // bubble max of arr[0 to i] to arr[i].
    for (size_t i = arr.size() -1; i > 0; --i) {
        for (size_t j = 0; j < i; ++j) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j+1]);
        }
    }
}

void select_sort(vector<int>& arr) {
    // select min of arr[i to n-1] to arr[i].
    for (size_t i = 0; i < arr.size() -1; ++i) {
        int min_val = arr[i];
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < min_val) {
                min_val = arr[j];
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void dump(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << "  arr[" << i << "] = " << arr[i] << endl;
    }
}

int main() {
    array<int, 5> input{4, 3, 1, 5, 2};

    cout << "insertion sort" << endl;
    vector<int> sort1(input.begin(), input.end());
    insertion_sort(sort1);
    dump(sort1);

    cout << "bubble sort" << endl;
    vector<int> sort2(input.begin(), input.end());
    bubble_sort(sort2);
    dump(sort2);

    cout << "selection sort" << endl;
    vector<int> sort3(input.begin(), input.end());
    select_sort(sort3);
    dump(sort3);

    return 0;
}
