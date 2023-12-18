#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
#include <vector>
using namespace std;
void set_cursor(int x, int y){
    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(hConsole, position);
}
void set_color(int attr){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, attr);
}
double enum_pi(double tcc){
double pi{};
    int sign = 1;
    int i = 1;
    while (4.0*1/i>=tcc){
        pi +=sign*4.0*1/i;
        sign*=-1;
        i+=2;
    }
    pi+= sign*(-1)*(double)1/i;
    return pi;
}
double exp_(double x,double tcc){
    double s=1;
    double n=1;
    double a=1;
    while (true){
        a=a*x/n;
        if (a <= tcc) break;
        s=s+a;
        n++;
    }
    return s;
}
void Merge(vector<int>& a, int p, int q , int r){
        int n1=q-p+1;
        int n2=r-q;
        vector <int> L (n1+1);
        vector <int> R (n2+1);
        for (int i=0; i<n1; i++){
            L[i]=a[p+i];
            // cout<<L[i]<<" ";
        }
        cout<<std::endl;
        for (int i=0; i<n2; i++){
            R[i]=a[q+i+1];
            // cout<<R[i]<<" ";
        }
        // cout<<std::endl;
        L[n1]=1000000000;
        R[n2]=1000000000;
        int i=0;
        int j=0;
        for (int k=p; k<=r; k++){
            if (L[i]<=R[j]){
                a[k]=L[i];
                i++;
            }
            else{
                a[k]=R[j];
                j++;
            }
            // cout<<a[k]<<" ";
        }
        cout<<std::endl;
    }
void MergeSort(vector<int>& a, int p, int r){
    if (p<r){
        int q=(p+r)/2;
        MergeSort(a, p, q);
        MergeSort(a, q+1,r);
        Merge(a, p, q, r);
    }
    }
void MultiplicationTable(){
    vector <int> numbers {1,2,3,4,5,6,7,8,9,10}; 
    system("cls");
    system("color 70");
    set_cursor(0,0);
    set_color(0x10);
    for (int i =0; i<numbers.size(); i++){
        set_cursor(6*i+6, 0);
        set_color(0xB0);
        cout.width(3);
        cout << numbers[i];
    }
    set_cursor(0,1);
    set_color(0x07);
    int k=2;
    for (int i = 1; i<11; i++){
        set_cursor(0, k);
        set_color(0xB0);
        cout.width(3);
        cout << i;
        for (int j = 0; j<numbers.size();j++){
            set_color(0x70);
            set_cursor(6*j+6, k);
            cout.width(3); 
            if ((numbers[j]==5||i==5)&&(numbers[j]<=5)&&(i<=5)){
                set_color(0x20);
            }
            if ((numbers[j]==8||i==8)&&(numbers[j]<=8)&&(i<=8)){
                set_color(0x60);
            }
            if (numbers[j]==i || numbers[j]==10 || i==10){
                set_color(0xD0);
            } 

            cout << numbers[j]*i;
        }
        cout <<"\n";
        k+=2;
    }
    set_color(0x70);
}
void Menu(char **menu, int n){
    for (int i =0; i<n; i++){
        cout << menu[i]<< endl;
    }
    int select;
    cin >>select;
    switch (select){
        case 1:
            cout << "Выбран пункт 1"<< endl;
            cout <<2;
            break;
        case 2:
            cout <<"Выбран пункт 2"<< endl;
            cout <<5;
            break;
        case 3:
            cout <<"Выбран пункт 3"<<endl;
            cout <<"???";
            break;
        default:
            cout <<"Неверный пункт меню"<<endl;
            break;
    }


}
int main()
{
    setlocale(LC_ALL, "ru_RU.UTF8");
    // // MultiplicationTable();
    // char *menu[]= {"1. Вывести 2", "2. Вывести 5", "3. Вывести ???"};
    // int n = size(menu);
    // Menu(menu, n);


}