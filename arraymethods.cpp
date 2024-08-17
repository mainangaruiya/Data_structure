#include <iostream>
#include <algorithm>  // For std::reverse

using namespace std;

int main() {
    const int SIZE = 5;
    int arr1[SIZE] = {1, 3, 5, 7, 9};
    int arr2[SIZE] = {2, 4, 6, 8, 10};
    int mergedArray[SIZE * 2];

    // Merging the two arrays
    for(int i = 0; i < SIZE; i++) {
        mergedArray[i] = arr1[i];
        mergedArray[i + SIZE] = arr2[i];
    }

    // Displaying the merged array
    cout << "Merged Array: ";
    for(int i = 0; i < SIZE * 2; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    // 1. Adding the elements of the merged array
    int sum = 0;
    for(int i = 0; i < SIZE * 2; i++) {
        sum += mergedArray[i];
    }
    cout << "Sum of elements: " << sum << endl;

    // 2. Reversing the merged array
    reverse(mergedArray, mergedArray + SIZE * 2);
    cout << "Reversed Array: ";
    for(int i = 0; i < SIZE * 2; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    // 3. Finding the largest and smallest elements in the merged array
    int largest = mergedArray[0];
    int smallest = mergedArray[0];
    
    for(int i = 1; i < SIZE * 2; i++) {
        if(mergedArray[i] > largest) {
            largest = mergedArray[i];
        }
        if(mergedArray[i] < smallest) {
            smallest = mergedArray[i];
        }
    }
    cout << "Largest element: " << largest << endl;
    cout << "Smallest element: " << smallest << endl;

    return 0;
}
