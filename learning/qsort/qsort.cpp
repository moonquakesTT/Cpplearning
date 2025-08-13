#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

// 随机选择 pivot，并放到最右边
int randomPartition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1); // 随机选择
    cout << "Pivot index: " << pivotIndex << endl;
    swap(arr[pivotIndex], arr[high]); // 把它换到末尾
    int pivot = arr[high];

    int i = low - 1; // i 指向小于 pivot 的最后一个元素
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序主函数
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL)); // 初始化随机数种子

    int arr[] = {3, 5, 2, 9, 1, 4, 8, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    randomizedQuickSort(arr, 5, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
