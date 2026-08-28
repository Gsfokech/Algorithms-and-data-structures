#include <iostream>

using namespace std;

int binary_search(int a[], int n, int x);

int recursiveBS(int a[], int p, int r, int x);

int main() {
    int sorted[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int size = 13;

    int res1 = binary_search(sorted,size, 8);
    cout << res1 << endl;

    int res2 = recursiveBS(sorted, 0, 12, 9);
    cout << res2 << endl;

    return 0;
}

int binary_search(int a[], int n, int x){
    int p = 0, r = n;
    int q;
    while (p <= r){
        q = (p+r)/2;
        if(a[q] == x){
            return q;
        }
        else if (a[q]>x){
            r = q - 1;
        }
        else {
            p = q + 1;
        }
    }
    return -1;
}

int recursiveBS(int a[], int p, int r, int x){
    int mid = (p + r) / 2;
    if(p > r){
        return -1;  // Ключ не найден
    }
    if (a[mid] == x){
        return mid;
    }
    else if(a[mid] > x){
        return recursiveBS(a, p, mid - 1, x);
    } else{
        return recursiveBS(a, mid+1, r, x);
    }
}