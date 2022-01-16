#include <cstdlib>
#include <iostream>

using namespace std;

int binarySearchIterative(const int arr[], long long size, int target) {
    int low = 0;
    int high = (int) size - 1;
    int count = 0;
    while (low <= high) {
        count++;
        int mid = (int) (high + low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            cout << "Found number " << target << " at index " << mid << " in " << count << " iterations" << endl;
            return mid;
        }
    }
    cout << "The number " << target << " does not exist in the array" << endl;
    return -1;
}

int binarySearchRecursive(const int arr[], long long size, int low, long long high, int target) {
    if (low > high) {
        cout << "The number " << target << " does not exist in the array" << endl;
        return -1;
    }
    int mid = (int) (low + high) / 2;
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, size, mid + 1, high, target);
    } else if (arr[mid] > target) {
        return binarySearchRecursive(arr, size, low, mid - 1, target);
    } else {
        cout << "Found number " << target << " at index " << mid << endl;
        return mid;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i : arr) {
        if (i < arr[*(&arr + 1) - arr - 1]) {
            cout << i << ", ";
        } else {
            cout << i;
        }
    }
    cout << "\n" << endl;
    string userInput{};
    cout << "Enter the number to search: ";
    cin >> userInput;
    cout << endl;
    cout << "Iterative binary search: " << endl;
    binarySearchIterative(arr, *(&arr + 1) - arr, stoi(userInput));
    cout << endl;
    cout << "Recursive binary search: " << endl;
    binarySearchRecursive(arr, *(&arr + 1) - arr, 0, *(&arr + 1) - arr - 1, stoi(userInput));
    return EXIT_SUCCESS;
}
