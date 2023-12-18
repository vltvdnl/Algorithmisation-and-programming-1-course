#ifndef _arraylib_H_
#define _arraylib_H_
#include <iostream>
#include <cmath>
#pragma once
using namespace std;
void ArrInput (int*arr, int size_of_array){
    for (int i =0; i < size_of_array; i++){
        cin >> arr[i];
    }
}
void ArrOutput(int *arr,int size_of_array){
    for (int i =0; i < size_of_array; i++){
        cout <<arr[i]<<" ";
    }
    cout << endl;
}
int MIN(int *arr, int size_of_array){
    int m = arr[0];
    for (int i =1; i<size_of_array; i++){
        if (m>arr[i]){
            m=arr[i];
        }
    }
    return m;
}
int MAX(int *arr, int size_of_array){
    int m = arr[0];
    for (int i =1; i<size_of_array; i++){
        if (m<arr[i]){
            m=arr[i];
        }
    }
    return m;
}
void SORT(int *arr, int size_of_array){
    for (int i =0; i<size_of_array; i++){
        for (int j=i+1; j<size_of_array; j++){
            if (arr[i]>arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void MoreThenValue(int *arr, int size_of_array, int value){
    for (int i =0; i<size_of_array; i++){
        if (arr[i] >value){
            cout << arr[i] <<" ";
        }
    }
    cout <<endl;
}
void NegativeRemoval(int* arr, int size_of_array){
    for(int i =0; i<size_of_array; i++){
        if (arr[i]<0){
            arr[i]=0;
        }
    }
}
int SUM(int* arr, int size_of_array){
    int sum =0;
    for (int i =0; i<size_of_array; i++){
        sum+=arr[i];
    }
    return sum;
}
int MULT(int *arr, int size_of_array){
    int mult =1;
    for (int i =0; i<size_of_array; i++){
        mult*=arr[i];
    }
    return mult;
}
int CountOfPrimals(int* arr, int size_of_array){
    int count =0;
    for (int i =0; i<size_of_array; i++){
        bool fl = true;
        for (int j=2; j<sqrt(arr[i])+1; j++){
            if (arr[i]%j==0){
                fl=false;
                break;
            }
        }
        if (fl == true && arr[i]!=1 && arr[i]!=0){
            count++;
        }
    }
    return count;
}


#endif