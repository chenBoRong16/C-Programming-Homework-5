#include <stdio.h>
#include <time.h>
#include <stdlib.h> // 亂數相關函數
#define MIN(a, b) (((a) < (b))? (a): (b))
#define digitCount 4 // 答案和猜測的位數
#define guessLimit 2 // 猜測的次數限制
typedef struct{
    int A; // 位置正確且數字正確的個數
    int B; // 位置錯誤但數字正確的個數
}ABresult;

int digitArr[10] = {0,1,2,3,4,5,6,7,8,9}; // 可用的數字範圍 0-9

// 函式宣告:
ABresult compare_array(int *input, int *target);
void randomize(int *target);
void reset_digitArr();
void swap(int *input, int index, int index1);
void print_int_array(int *input);

int main(){
    srand(time(NULL)); // 初始化隨機數種子

    int guess_time = guessLimit; // 初始化猜測次數
    int answer[digitCount];
    randomize(answer); // 隨機生成答案

    while (guess_time > 0){
        guess_time--;
        int guess[digitCount];
        randomize(guess); // 隨機生成猜測數字（或用戶輸入）
        printf("input four different number:(例如2178)");
        print_int_array(guess); // 打印當前猜測的數字
        printf("\n");

        ABresult result = compare_array(guess, answer); // 比較猜測和答案
        printf("結果:%dA%dB，還有%d次機會...\n", result.A, result.B, guess_time);
        if (result.A == digitCount){ // 如果所有位數和位置都正確
            printf("你猜對了!\n");
            return 0;
        }
    }

    printf("失敗，猜超過%d次，答案是", guessLimit);
    print_int_array(answer); // 顯示正確答案
    printf("\n");
    return 0;
}

// 比較猜測和答案，返回AB值
ABresult compare_array(int *guess, int *target){
    int guess_show_count[10] = {0}; // 記錄猜測中各數字出現次數
    int target_show_count[10] = {0}; // 記錄答案中各數字出現次數
    int i;
    ABresult result = {0, 0};
    for (i = 0; i < digitCount; i++){
        if (guess[i] == target[i]){
            result.A ++; // 位置和數字都正確
        }
        else{
            guess_show_count[guess[i]]++; // 記錄出現次數
            target_show_count[target[i]]++;
        }
    }

    // 計算位置錯誤但數字正確的B值
    for (i = 0; i < 10; i++){
        result.B += MIN(guess_show_count[i], target_show_count[i]);
    }
    return result;
}

// 隨機生成答案
void randomize(int *target){
    int leftDigitCount = 10; // 可用的數字還剩多少
    int changeIndex = 0;

    for (; changeIndex < digitCount; changeIndex++, leftDigitCount--){
        int picked_num = rand() % leftDigitCount; // 隨機挑選一個數字
        int picked_index = changeIndex + picked_num;
        target[changeIndex] = digitArr[picked_index]; // 從digitArr中挑選數字
        swap(digitArr, changeIndex, picked_index); // 更新digitArr，使已選的數字不再被選擇
    }

    reset_digitArr(); // 重置 digitArr
}

// 重置 digitArr 為初始狀態
void reset_digitArr() {
    for (int i = 0; i < 10; i++) {
        digitArr[i] = i;
    }
}

// 交換數組中的兩個元素
void swap(int *input, int index, int index1){
    int temp = input[index]; 
    input[index] = input[index1];
    input[index1] = temp;
}

// 打印整數數組
void print_int_array(int *input){
    int i;
    for (i = 0; i < digitCount; i++){
        printf("%d", input[i]);
    }
}
