#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> arr) {
    for(int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 and arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return arr;
}

int main() {
    int n; 
    cin >> n;

    while(n-- > 0) {
        int m;
        cin >> m;

        vector<int> arr(m);
        for(int i = 0; i < m; i++) {
            cin >> arr[i];
        }

        arr = insertionSort(arr);

        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}