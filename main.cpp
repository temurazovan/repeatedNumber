#include <iostream>

void heapify(int arr[], int heapSize, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex;
    int rightChild = 2 * rootIndex + 1;

    if (leftChild < heapSize && arr[leftChild] >= arr[largest]) {
        largest = leftChild;
    }
    if (rightChild < heapSize && arr[rightChild] >= arr[largest]) {
        largest = rightChild;
    }
    if (largest > rootIndex) {
        std::swap(arr[rootIndex], arr[largest]);
        heapify(arr, heapSize, largest);
    }
}

void heapSort(int arr[], int childIndex) {
    for (int i = childIndex / 2; i >= 0; i--) {
        heapify(arr, childIndex, i);
    }
    for (int i = childIndex - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    heapSort(numbers, size);
    printArray(numbers, size);

    for (int i = 0; i < size; i++) {
        if (numbers[i] == numbers[i + 1] && i + 1 <= size) {
            std::cout << numbers[i];
        }
    }
}
