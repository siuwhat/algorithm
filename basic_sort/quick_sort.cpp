


#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
static int nums = 0;

void quick_sort(vector<int>& ptr, int begin, int end) {
    if (begin < end) {
        int base = ptr[begin];
        int i = begin, j = end;
        while (i < j) {

            if (ptr[j] < base)
            {
                if (ptr[i] > base)
                    swap(ptr[i], ptr[j]);
                else i++;
            }
            else j--;
        }
        swap(ptr[begin], ptr[i]);
        for (auto a : ptr)
            cout << a << ends;
        cout << endl;
        nums++;
        quick_sort(ptr, begin, i - 1);
        quick_sort(ptr, i + 1, end);
    }
}

int main()
{
    /* vector<int>a{ 61,177,61,74,19,31,45,55,101,81 };*/
    vector<int>a{ 31,43,45,2,4,129,438,329,400,3232,1243,593,32,213,43,2,3443,5343 };
    for (auto i : a)cout << i << ends;
    cout << endl;
    quick_sort(a, 0, a.size() - 1);
    for (auto i : a)cout << i << ends;

}
