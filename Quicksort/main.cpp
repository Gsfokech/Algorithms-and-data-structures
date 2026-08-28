#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);    // Возвращает pivotInd после разделения

int main(){
    int a[] = {10,11,23,44,8,15,3,9,12,45,56,45,45};
    int length = 13;

    quicksort(a, length);

    for (int i = 0; i < length; i++){
        cout << a[i] << " ";
    }
    cout << endl << endl;

    return 0;
}

void quicksort(int array[], int length){
    srand(time(NULL));  // Задание сида для генерации случайных чисел
    quicksort_recursion(array, 0, length - 1);
}

void quicksort_recursion(int array[], int low, int high){
    if(low < high){
        int pivotInd = partition(array, low, high);
        quicksort_recursion(array, low, pivotInd-1);
        quicksort_recursion(array, pivotInd + 1, high);
    }
}

int partition(int array[], int low, int high){
    int pivotInd = rand() % (high - low + 1) + low;

    if(pivotInd != high){
        swap(array[pivotInd], array[high]);
    }

    int pivotValue = array[high];
    int i = low;
    for(int j = low; j < high; j++){
        if(array[j] <= pivotValue){     // Благодаря этому условию, сортируем массив в возрастающем порядке
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[high]);

    return i;
}

// 6 3 7 5 1 2 [4]
//              |
//       3 1[2] 4 6 7 [5]
//           |         |
//         1 2  3     5 7 [6]
//                         |
//                         6 7