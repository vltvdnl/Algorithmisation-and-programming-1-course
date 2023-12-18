#include <iostream>
#include <string.h>
#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "arraylib.h"
using namespace std;
void ToReg(){
    cout <<"Введите строку: ";
    char* str = new char [256];
    cin.getline(str, 256);
    cout << "Введите регистр, в который перевести строку (0 - нижний, 1 - верхний): ";
    int registor;
    cin >> registor;
    for (int i =0; i<strlen(str); i++){
        if (registor==1){
            str[i] = toupper(str[i]);
        }
        else if (registor==0){
            str[i] = tolower(str[i]);
        }
        else{
            cout <<"Неправильно введен регистр";
            break;
        }
    }
    cout <<"Строка в нужном регистре: "<<str;

}
void StrRev(){
    cout <<"Введите строку: ";
    char *str = new char[256];
    cin.getline(str, 256);
    char tmp;
    for(int i =0; i<strlen(str)/2; i++){
        tmp = str[i];
        str[i] = str[strlen(str)-1-i];
        str[strlen(str)-1-i] = tmp;
    }
    cout << "Реверсированная строка: "<< str;
}
void RevWords(){
    cout <<"Введите строку: ";
    char *str = new char[256];
    cin.getline(str, 256);
    char tmp;
    char *ans = (char*)calloc(256, sizeof(char));
    char *word = strtok(str, " ");
    while (word != NULL){
        strcat(ans, " ");
        for (int i =0; i<strlen(word)/2; i++){
            tmp = word[i];
            word[i] = word[strlen(word)-1-i];
            word[strlen(word)-1-i]=tmp; 
        }
        strcat(ans, word);
        word = strtok(NULL, " ");
    }
    cout << "Строка, с реверсированными словами:"<<ans;

}
void Menu(){
    bool flags[]{true, false, false, false, false, false, false, true};
    while (true){
        cout << endl;
        cout <<"1. Создать массив"<<endl;
        cout <<"2. Ввести массив"<<endl;
        cout <<"3. Найти максимум"<<endl;
        cout <<"4. Найти сумму"<<endl;
        cout <<"5. Отсортировать"<<endl;
        cout <<"6. Вывести массив"<<endl;
        cout <<"7. Удалить массив"<<endl;
        cout <<"8. Выход из программы\n\n";
        cout <<"Ваш выбор: ";
        int n;
        int *arr;
        int size_of_arr;
        cin >> n;
        switch (n){
            case 1:
                cout <<"Введите размер массива: ";
                cin >> size_of_arr;
                flags[n] = true;
                flags[6] = true;
                arr = new int[n];
                cout << endl;
                break;
            case 2:
                if (flags[n-1] == false){
                    cout <<"Массив еще не был создан"<<endl;
                    break;
                }
                cout << "Введите значения массива: ";
                ArrInput(arr, size_of_arr);
                for (int i = 2; i<6; i++){
                    flags[i]=true;
                }
                cout << endl;
                break;
            case 3:
                if (flags[n-1] == false){
                    cout <<"Массив еще не введен/создан"<<endl;
                    break;
                }
                cout << "Максимум массива: "<<MAX(arr, size_of_arr)<<endl;
                break;
            case 4:
                if (flags[n-1] == false){
                    cout <<"Массив еще не введен/создан"<<endl;
                    break;
                }
                cout << "Сумма массива: " << SUM(arr, size_of_arr)<<endl;
                break;
            case 5:
                if (flags[n-1] == false){
                    cout <<"Массив еще не введен/создан"<<endl;
                    break;
                }
                SORT(arr, size_of_arr);
                cout <<"Массив отсортирован по возрастанию"<<endl;
                break;
            case 6:
                if (flags[n-1] == false){
                    cout <<"Массив еще не введен/создан"<<endl;
                    break;
                }
                cout <<"Вывод массива: ";
                ArrOutput(arr, size_of_arr);
                break;
            case 7:
                if (flags[n-1] == false){
                    cout <<"Массив еще не введен/создан"<<endl;
                    break;
                } 
                delete[](arr);
                cout <<"Массив очищен"<<endl;
                for (int i =1; i<7; i++){
                    flags[i] = false;
                }
                break;
            case 8:
                cout << "Доброго дня!";
                exit(0);
            default:
                cout <<"Введен неверный пункт меню"<<endl;
                break;


        }
}
}
int main(){
    // ToReg();
    // StrRev();
    RevWords();
    Menu();
}