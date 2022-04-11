#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define ARRAY_SIZE(_array) \
    (sizeof((_array)) / sizeof((_array)[0]))


template<class T>
void print_vector(const vector<T> &array, const string name = "") {
    cout << (name.length() > 0 ? name : "Unknown");
    cout << " with " << array.size() << " elements:" << endl;
    for (auto n : array) {
        cout << n << " ";
    }
    cout << endl;
}

void merge(vector<int> &data, int begin, int mid, int end) {
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    vector<int> left;
    vector<int> right;
    int i, j, k;

    for (i = 0; i < n1; ++i) left.push_back(data[begin + i]);
    for (j = 0; j < n2; ++j) right.push_back(data[mid + 1 + j]);
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);

    i = j = 0;
    for (k = begin; k <= end; ++k) {
        if (left[i] <= right[j]) {
            data[k] = left[i++];
        } else {
            data[k] = right[j++];
        }
    }
}

void merge_sort(vector<int> &data, int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        merge_sort(data, begin, mid);
        merge_sort(data, mid + 1, end);
        merge(data, begin, mid, end);
    }
}

int main(void) {
    int raw0[] = {8, 3, 4, 6, 5, -1, -1, 0};
    vector<int> data0(raw0, raw0 + ARRAY_SIZE(raw0));
    int raw1[] = {9, 13, 2, 4, 5, 1, 11};
    vector<int> data1(raw1, raw1 + ARRAY_SIZE(raw1));
    int raw2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> data2(raw2, raw2 + ARRAY_SIZE(raw2));
    int raw3[] = {7, 6, 5, 4, 3, 2, 1};
    vector<int> data3(raw3, raw3 + ARRAY_SIZE(raw3));

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
