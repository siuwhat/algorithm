//3->2,5->2,9->4
#include <iostream>
#include<vector>
#include<test_if_sorted.hpp>
#include<random>
using namespace std;
random_device r;
void traverse(vector<int>& a) { for (auto i : a)cout << i << ends; cout << endl; }
void merge(vector<int>&a, vector<int>& aux, int lo, int mid, int hi) {
    int k;
    for (k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }cout << "回合内:";
    traverse(aux);
    traverse(a);
    cout << "回合结束" << endl;
    int i = lo, j = mid + 1;
    for (k = lo; k <= hi; k++) {
        cout << endl;
        cout << "k: "<<k << ends;
        cout << endl;
        if (i > mid) 
            a[k] = aux[j++];
        else if(j>hi)  
            a[k] = aux[i++];
        else if (aux[j] < aux[i]) 
            a[k] = aux[j++];
        else 
            a[k] = aux[i++];
    }
}

void sort(vector<int>&a) {
    const int N = a.size();
    vector<int> aux(N, 0);
    for (int sz = 1; sz < N; sz+=sz) {
        for (int lo = 0; lo < N-sz ; lo += 2*sz ) {
            cout << "lo: " << lo << " mid: " << lo + sz - 1 << " end: " << min(lo + 2 * sz - 1, N - 1)<<endl;
            merge(a, aux, lo, lo + sz - 1, min(lo + 2*sz - 1, N - 1));
            traverse(a);
        }
    }
}

int main()
{
    vector<int> a;
    for (auto i = 0; i < 14; ++i) { 
        //a.emplace_back(r() % 100); 
        a.emplace_back(14 - i);
    };

    traverse(a);
    sort(a);
    traverse(a);
}

