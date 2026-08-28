#include <iostream>

using namespace std;

void shellSort(int array[], int length);

int main() {
    int a[] = {4, 12, 6, 9, 1, 0, 45, 34, 3, 4, 6, 0};
    int length = 12;

    shellSort(a, length);

    for(int i = 0; i < length; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

    void shellSort(int array[], int length){
        int h = 1;
        while(h <= length/3){
            h = 3*h + 1;
        }

        for(h; h>0; h = (h-1)/3){
            for(int i = h; i < length; i++){
                int temp = array[i];
                int j;
                for(j = i; j >= h && array[j - h] > temp; j-=h){
                    array[j] = array[j - h];
                }
                array[j] = temp;
            }
        }
    }