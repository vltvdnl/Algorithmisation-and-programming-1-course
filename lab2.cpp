#include <iostream>
#include <windows.h>
#include <math.h>
#include <set>
using namespace std;
int** MatrixInput(int m, int n){
    cout <<"Введите значения матрицы по строкам: ";
    int **a = new int*[m];
    for (int i =0; i<m; i++){
        a[i] = new int [n];
    }
    for (int i=0; i <m; i++){
        for (int j =0; j<n; j++){
            cin >> a[i][j];
        }
    }
    return a;
}
void MatrixOutput(int **a, int m, int n){
    for (int i = 0; i<m; i++){
        for (int j =0; j<n; j++){
            cout << a[i][j] << " ";
        }

    }
    cout <<"\n";
}
void ArrInput(int *a, int n){
    for (int i =0; i <n; i++){
        cin >> a[i];
    }
}
void ArrOutput(int *a, int n){
    for (int i =0; i <n; i++){
        cout <<a[i]<<" ";
    }
}
void FirstTask(){
    cout <<"Введите размер вектора: ";
    int n;
    cin >> n;
    int *a;
    a = new int [n];
    cout <<"Введите значения элементов вектора: "<<endl;
    ArrInput(a, n);

    int min_el[2]{0,0};
    int max_el[2]{0,0};

    for (int i =0; i<n; i++){
        if (min_el[1]>a[i]){
            min_el[0]=i;
            min_el[1]=a[i];
        }
        if (max_el[1]<a[i]){
            max_el[0]=i;
            max_el[1]=a[i];
        }
    }
    int temp = a[max_el[0]];
    a[max_el[0]]=a[min_el[0]];
    a[min_el[0]]=temp;
    ArrOutput(a, n);

}
void SecondTask(){
    cout <<"Введите размер вектора: ";
    int n;
    cin >> n;
    int *a;
    a = new int [n];
    cout <<"Введите значения элементов вектора: "<<endl;
    ArrInput(a, n);
    cout <<"Введите заданное значение: ";
    int r;
    cin >> r;
    int j =0;
    int indices [n];
    int values [n];
    for (int i=0; i<n; i++ ){
        if (a[i]<r){
            indices[j]=i;
            values[j]=a[i];
            j++;
        }
    }
    ArrOutput(indices, j);
    cout <<"\n";
    ArrOutput(values, j);

    
}
void ThirdTask(){
    cout <<"Введите размер вектора: ";
    int n;
    cin >> n;
    int *a;
    a = new int [n];
    cout <<"Введите значения элементов вектора: "<<endl;
    ArrInput(a, n);
    cout <<"Введите размер вектора разрешенных значений: ";
    int m;
    cin >>m;
    cout <<"Введите вектор разрешенных значений: ";
    int *b= new int [m];
    ArrInput(b, m);
    int count=0;
    for (int i =0; i <n; i++){
        for (int j =0; j<m; j++){
            if (a[i]==b[j]){
                count++;
                break;
            }
        }
    }
    cout <<"Количество элементов из разрешенных значений: "<<count;

    
}
void FourthTask(){
   cout <<"Введите размер вектора: ";
    int n;
    cin >> n;
    int *a;
    a = new int [n];
    cout <<"Введите значения элементов вектора: "<<endl;
    ArrInput(a, n);
    int *ans = new int [n];
    int k=0;
    for (int i=0; i<n; i++){
        bool fl = true;
        for (int j =0;j<n; j++){
            if (a[i]==a[j] && i!=j){
                fl = false;
                break;
            }
        }
        if (fl == true){
            ans[k]=a[i];
            k++;
        }
    }
    ArrOutput(ans, k);

}
void FifthTask(){
    cout <<"Введите размер вектора: ";
    int n;
    cin >> n;
    int *a;
    a = new int [n];
    cout <<"Введите значения элементов вектора: "<<endl;
    ArrInput(a, n);
    int k=0;
    int *frequency = new int [n];
    int *value = new int [n];
    set <int> prev;
    for (int i =0; i <n; i++){
        int count = 1;
        if (prev.count(a[i])==0){
            prev.insert(a[i]);
            // cout <<"sada"<<endl;
            for (int j =0; j<n; j++){
                if (a[i]==a[j] && j!=i){
                    count++;
                }
            }
            frequency[k]=count;
            value[k]=a[i];
            k++;


        }
        else{
            continue;
        }
    }
    ArrOutput(value, k);
    cout <<"\n";
    ArrOutput(frequency, k);


}
void TwoFirstTask(){
    cout <<"Введите количество строк матрицы: ";
    int m;
    cin>>m;
    cout <<"Введите количество столбцов матрицы: ";
    int n;
    cin >>n;
    int **a = MatrixInput(m,n);
    int *b = new int [m];
    for (int i =0; i <m; i++){
        int count=0;
        for (int j =0; j<n; j++){
            if (a[i][j]>=0){
                count++;
            }
        }
        b[i]=count;
    }
    ArrOutput(b, m);
}
void TwoSecondTask(){
    cout <<"Введите количество строк матрицы: ";
    int m;
    cin>>m;
    cout <<"Введите количество столбцов матрицы: ";
    int n;
    cin >>n;
    int **a = MatrixInput(m,n);
    int *b = new int [n];
    for (int j=0; j<n; j++){
        int count =0;
        int sum =0;
        for (int i =0; i<m; i++){
            if (a[i][j] >0){
                count++;
                sum+=a[i][j];
            }
        }
        b[j] = sum/count;
    }
    ArrOutput(b, n);
}
void TwoThirdTask(){
    cout <<"Введите количество строк матрицы: ";
    int m;
    cin>>m;
    cout <<"Введите количество столбцов матрицы: ";
    int n;
    cin >>n;
    int **a = MatrixInput(m,n);
    int *b = new int [m];
    for (int i =0; i<m; i++){
        int min=a[i][0];
        for (int j=1; j<n; j++){
            if (a[i][j]<min){
                min = a[i][j];
            }
        }
        b[i]=min;
    }
    ArrOutput(b,m);
}
void TwoFourthTask(){
    cout <<"Введите количество строк матрицы: ";
    int m;
    cin>>m;
    cout <<"Введите количество столбцов матрицы: ";
    int n;
    cin >>n;
    int **a = MatrixInput(m,n);
    int *b = new int [m];
    for (int i =0; i<m; i++){
        int adress =0;
        int max = a[i][0];
        for (int j =1; j<n; j++){
            if (a[i][j]>max){
                max=a[i][j];
                adress = j;
            }
        }
        b[i] = adress+1;
    }
    ArrOutput(b, m);
}
void TwoFifthTask(){
    cout <<"Введите количество строк матрицы: ";
    int m;
    cin>>m;
    cout <<"Введите количество столбцов матрицы: ";
    int n;
    cin >>n;
    int **a = MatrixInput(m,n);
    int *b = new int [m];
    for (int i =0; i<m; i++){
        int count =0;
        for (int j =0; j<n; j++){
            if (a[i][j]==1){
                continue;
            }
            int number = a[i][j];
            bool fl = true;
            for (int p = 2; p < int(sqrt(number))+1; p++){
                if (number % p ==0){
                    fl = false;
                    break;
                }
            }
            if (fl==true){
                count++;
            }
        }
        b[i]=count;
    }
    ArrOutput(b, m);
}
int main(){
    setlocale(LC_ALL, "utf-8");
    // FirstTask();
    // SecondTask();
    // ThridTask();
    // FourthTask();
    // FifthTask();
    // TwoFirstTask();
    // TwoSecondTask();
    // TwoThirdTask();
    // TwoFourthTask();
    // TwoFifthTask();
;


}