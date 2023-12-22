#include <iostream>
#include <vector>

using namespace std;

size_t qs_partition(vector<int> &data, size_t begin, size_t end) {
#if 1
    size_t head = begin + 1; // 1st one bigger than pivot from the left.
    size_t tail = end; // 1st one smaller than pivot from the right.
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
    int pivot = data[end];
    size_t i = begin;

    for (size_t j = begin; j < end; ++j) {
        if (data[j] <= pivot) {
            std::swap(data[i], data[j]);
            ++i;
        }
    }
    std::swap(data[i], data[end]);
    return i;
#endif
}

void quick_sort(vector<int> &data, size_t begin, size_t end) {
    if (begin < end) {
        size_t mid = qs_partition(data, begin, end);
        if (mid > 0) quick_sort(data, begin, mid - 1);
        quick_sort(data, mid + 1, end);
    }
}

void dump(const vector<int>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        cout << "  [" << i << "] = " << data[i] << endl;
    }
}

int main() {
    vector<int>data0 = {8, 3, 4, 6, 5, -1, -1, 0};
    vector<int>data1 = {9, 13, 2, 4, 5, 1, 11};
    vector<int>data2 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int>data3 = {7, 6, 5, 4, 3, 2, 1};
    
    cout << "sorting data0.." << endl;
    quick_sort(data0, 0, static_cast<int>(data0.size())-1);
    dump(data0);

    cout << "sorting data1.." << endl;
    quick_sort(data1, 0, static_cast<int>(data1.size())-1);
    dump(data1);

    cout << "sorting data2.." << endl;
    quick_sort(data2, 0, static_cast<int>(data2.size())-1);
    dump(data2);

    cout << "sorting data3.." << endl;
    quick_sort(data3, 0, static_cast<int>(data3.size())-1);
    dump(data3);

    return 0;
}
