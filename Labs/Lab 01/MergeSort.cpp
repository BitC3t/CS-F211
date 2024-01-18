#include <vector>
#include <iostream>

using namespace std;

vector<int> merge(vector<int> arr, int l, int r) {
    // Assumption that left and right are both sorted.
    vector<int> left(arr.begin() + l, arr.begin() + r);
    vector<int> right(arr.begin() + r, arr.end());


    for (int i = 0; i < right.size(); i++) {
        int key = right[i];
        for(int j = 0; j < left.size(); j++) {
            if(left[j] > key) {
                left.insert(left.begin() + j, key);
                break;
            }
        }
    }

    return left;
}

void merge(int * arr, int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    int temp[low + high + 1];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int * arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 3, 5, 7};

    int length = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, length - 1);

    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

