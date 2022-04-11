#include <iostream>
#include <vector>

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

int qs_partition(vector<int> &data, int begin, int end) {
#if 0
    int head = begin + 1; // 1st one bigger than pivot.
    int tail = end; // lst one smaller than pivot.
    int pivot = data[begin];

    do {
        while (head <= end && data[head] < pivot) ++head;
        while (tail > begin && data[tail] > pivot) --tail;
        if (head < tail) swap(data[head], data[tail]);
    } while (head < tail);
    data[begin] = data[tail];
    data[tail] = pivot;
    return tail;
#else
    int i = begin -1;
    int j;
    int pivot = data[end];

    for (j = begin; j < end; ++j) {
        if (data[j] <= pivot) {
            i++;
            if (data[i] > pivot) {
                swap(data[i], data[j]);
            }
        }
    }
    if (i + 1 != end) {
        data[end] = data[i + 1];
        data[i + 1] = pivot;
    }
    return i + 1;
#endif
}

void quick_sort(vector<int> &data, int begin, int end) {
    if (begin < end) {
        int mid = qs_partition(data, begin, end);
        quick_sort(data, begin, mid - 1);
        quick_sort(data, mid + 1, end);
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

    print_vector(data0, "original data0");
    quick_sort(data0, 0, data0.size() - 1);
    print_vector(data0, "sorted data0");

    print_vector(data1, "original data1");
    quick_sort(data1, 0, data1.size() - 1);
    print_vector(data1, "sorted data1");

    print_vector(data2, "original data2");
    quick_sort(data2, 0, data2.size() - 1);
    print_vector(data2, "sorted data2");

    print_vector(data3, "original data3");
    quick_sort(data3, 0, data3.size() - 1);
    print_vector(data3, "sorted data3");

    vector<int> data4;
    data4.push_back(0);
    print_vector(data4, "original data4");
    quick_sort(data4, 0, data4.size() - 1);
    print_vector(data4, "sorted data4");

    return 0;
}
