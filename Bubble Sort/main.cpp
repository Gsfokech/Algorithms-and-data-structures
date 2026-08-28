#include <iostream>
#include <utility>

using namespace std;

void bubbleSort(int array[], int length);

int main(){
    int a[] = {4, 8, 1, 5, 9, 0, 2, 7, 3, 6};
    int length = 10;

    bubbleSort(a, length);

    for (int i = 0; i<length; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

void bubbleSort(int array[], int length){
    for (int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            if(array[j] < array[j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}