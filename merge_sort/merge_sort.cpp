//3->2,5->2,9->4
#include <iostream>
#include<vector>
#include<test_if_sorted.hpp>
using namespace std;
void merge(int* a, int* aux, int lo, int mid, int hi) {
    int k;
    for (k = 0; k <= hi; k++) {
        aux[k] = a[k];
    }
    int i = lo, j = mid + 1;
    for (k = lo; k <= hi; k++) {
        if (i > mid) {
            a[k] = aux[j];
            j = j + 1;
        }
        else {
            if (j > hi) {
                a[k] = aux[i];
                i = i + 1;
            }
            else {
                if (aux[j] < aux[i]) {
                    a[k] = aux[j];
                    j = j + 1;
                }
                else {
                    a[k] = aux[i];
                    i = i + 1;
                }
            }
        }

    }
}

void sort(int* a) {
    int lo, N = 10;
    int aux[10];
    int sz;
    for (sz = 1; sz < N; sz = sz + 1) {
        for (lo = 0; lo < N - sz; lo = lo + sz + sz) {
            merge(a, aux, lo, lo + sz - 1, min(lo + sz + sz - 1, N - 1));
        }
    }
}

int main()
{
    int i;
    int a[10] = { 4, 3, 0, 2, 1, 2, 3, 4, 9, 1 };
    int aux[10];

    sort(a);
    for (i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

