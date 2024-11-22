#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 計算兩個數字的最大公因數（GCD）
long long int getGcd(long long a, long long b) {
    if (a == 0) {
        return b; // 如果 a 為 0，則 b 為 GCD
    }
    return getGcd(b % a, a); // 使用遞迴計算 GCD
}

// 反轉字符串
void reverse(char *input, char *output){
    int length = strlen(input); // 獲取輸入字符串的長度
    int i = 0, j = length - 1;
    while (i < length){
        output[i] = input[j]; // 將字符從後往前複製到輸出中
        j--; 
        i++;
    }
    output[length] = '\0'; // 為輸出字符串添加結束符
    return;
}

int main(){
    char input[10000], reversed[10000]; // 定義輸入和反轉後的字符串
    printf("Enter an integer: ");
    scanf("%9999s", input); // 讀取用戶輸入（最多 9999 個字符）
    reverse(input, reversed); // 反轉輸入的字符串

    long long int a, b;
    a = strtoll(input, NULL, 10); // 將字符串轉換為長整數
    b = strtoll(reversed, NULL, 10); // 將反轉後的字符串轉換為長整數

    // 打印反轉後的數字和兩者的 GCD
    printf("Reversed integer: %lld\n", b);
    printf("GCD of %lld and %lld is %lld\n", a, b, getGcd(a, b));

    return 0;
}
