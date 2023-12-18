#include <iostream>
#include <string.h>
#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "arraylib.h"
#include <map>
using namespace std;
void first(){
    int count = 0;
    char *s = new char[256];
    cin.getline(s, 256);
    // map<char, int> symbols;
    char *word = strtok(s, " ");
    // cout <<word;
    while (word!=NULL){
        if (word[0] == word[strlen(word)-1]){
            // symbols[word[0]]+=1; 
            count++;
        }
        // cout <<word<<endl;
        word = strtok(NULL, " ");
        
    }
    // for (const auto& [symb, freq]: symbols){
    //     count += freq;
    // }
    cout <<"Количество слов на одну букву: "<<count;
}
void second(){
    char *s = new char [256];
    cout <<"Введите строку:";
    cin.getline(s, 256);
    int value;
    cout <<"Введите количество символов ";
    cin >> value;
    int l =0;
    int start = 0;
    int i =0;
    while (i < strlen(s)){
        if (s[i] != ' '){
            l+=1;
            start ==0 ? start = i : start = start;
        }else{
            if (l == value){
                memmove(&s[start], &s[start+value+1], strlen(s)-i);
                cout <<s<<endl;
                l = 0;
                start =0;
                i =0;
            }else{
                l=0;
                start = 0;
            }
        }
        i++;
    }
    if (l == value){
                memmove(&s[start-1], &s[start+l], value);
            }

    cout << s;   
}
void third(){
    char *s = new char [256];
    cout <<"Введите строку:";
    cin.getline(s, 256);
    char *ans = (char*)calloc(256, sizeof(char));
    
    char *word = strtok(s, " ");
    while (word != NULL){
        map <char, int> symb;
        bool fl = true;
        cout <<word<<endl;
        for (int i =0; i < strlen(word); i++){
            for (int j = i+1; j <strlen(word); j++){
                if (word[i] == word[j]){
                    fl = false;
                    break;
                }
            }
        }
        if (fl == true){
            strncat(ans, word, strlen(word));
            strncat(ans, " ", 1);
            word = strtok(NULL, " ");
        }else{
            word = strtok(NULL, " ");
        }
    }
    cout << ans;
}
void fourth(){
        char *s = new char [256];
    cout <<"Введите строку:";
    cin.getline(s, 256);
    int *ans = new int [100];
    char *word = strtok(s, " ");
    int counter =0;
    int k =0;
    while (word != NULL){
        bool fl = true;
        for (int i =0; i < strlen(word); i++){
            for (int j = i+1; j <strlen(word); j++){
                if (word[i] == word[j]){
                    fl = false;
                    break;
                }
            }
        }
        if (fl == false){
            ans[k] = counter;
            counter++;
            k++;
            word = strtok(NULL, " ");
        }else{
            counter++;
            word = strtok(NULL, " ");
        }
    }
    for(int i =0; i<k; i++){
        cout<< ans[i]<<" ";
    } 

}
void fifth(){
    // char *s = new char [256];
    // cout <<"Введите строку:";
    // cin.getline(s, 256);
    // int i;
    // int j;
    // cout <<"Введите номера слов: ";
    // cin >>i;
    // cin >> j;

    // int l =0;
    // int i =0;
    // while (k < strlen(s)){
    //     if 
}
void swapWords(char *str, int i, int j) {
    int word_count = 0;
    char *current_word = strtok(str, " ");

    // Подсчитываем количество слов
    while (current_word != NULL) {
        word_count++;
        current_word = strtok(NULL, " ");
    }

    // Проверяем корректность введенных позиций
    if (i < 1 || j < 1 || i > word_count || j > word_count || i == j) {
        fprintf(stderr, "Некорректные позиции слов для обмена\n");
        exit(EXIT_FAILURE);
    }

    // Сбрасываем указатель strtok для повторного использования
    strtok(str, " ");

    char *temp_i = NULL;
    char *temp_j = NULL;
    current_word = strtok(NULL, " ");

    // Находим i-е и j-е слово
    for (int k = 2; k <= word_count; k++) {
        if (k == i) {
            temp_i = current_word;
        } else if (k == j) {
            temp_j = current_word;
        }
        current_word = strtok(NULL, " ");
    }

    // Обмениваем i-е и j-е слова
    strcpy(temp_i, strtok(NULL, " "));
    strcpy(temp_j, strtok(NULL, " "));
}

int main() {
    const int MAX_LENGTH = 1000;
    char inputString[MAX_LENGTH];

    printf("Введите строку: ");
    fgets(inputString, MAX_LENGTH, stdin);

    int i, j;
    printf("Введите позиции i и j (через пробел): ");
    scanf("%d %d", &i, &j);

    swapWords(inputString, i, j);

    printf("Результат: %s\n", inputString);

    return EXIT_SUCCESS;
}