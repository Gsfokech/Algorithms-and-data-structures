#include <iostream>
using namespace std;

// Example
// array:   6, 5, 3, 2, 1, 4
// step 1:  1, 5, 3, 2, 6, 4
// step 2:  1, 2, 3, 5, 6, 4
// step 3:  1, 2, 3, 5, 6, 4
// step 4:  1, 2, 3, 4, 6, 5
// step 5:  1, 2, 3, 4, 5, 6

void selection_sort(int a[], int length);

int main () {
    int array[] = {6, 5, 3, 2, 1, 4};
    int length = 6;

    selection_sort(array, length);

    for(int i = 0; i < length; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

void selection_sort(int a[], int length){
    for(int i = 0; i < length - 1 ; i++){
        int min_pos = i;
        for (int j = i + 1; j < length; j++){
            if(a[j] < a[min_pos]){
                min_pos = j;
            }
        }
        if (min_pos != i){
            int t = a[i];
            a[i] = a[min_pos];
            a[min_pos] = t;
        }
    }
}