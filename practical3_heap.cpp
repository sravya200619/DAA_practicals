#include <iostream>
using namespace std;
void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}
void heapSort(int a[], int n) {
    // Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);
    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}
int main() {
    int a[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    heapSort(a, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}