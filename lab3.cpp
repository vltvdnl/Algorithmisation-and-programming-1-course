#include <iostream>
#include <windows.h>
#include "arraylib.h"
#include <malloc.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int *a = ArrInput(n);
    ArrOutput(a,n);
    int Maxx = MAX(a,n);
    int Minn = MIN(a,n);
    SORT(a,n);
    ArrOutput(a,_msize(a)/sizeof(a[0])); // _msize офицально не должен работать, но почему верно отображает результат
    // cout <<endl;
    cout <<Maxx<<" "<< Minn <<endl;
    int value = 4;
    MoreThenValue(a,n,value);
    NegativeRemoval(a,n);
    ArrOutput(a,n);
    cout <<SUM(a,n)<<endl;
    cout <<MULT(a,n)<<endl;
    cout <<CountOfPrimals(a,n)<<endl;




}