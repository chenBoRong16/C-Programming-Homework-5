#include <stdio.h>
#include <time.h>
#include <stdlib.h> // 睹计闽ㄧ计
#define MIN(a, b) (((a) < (b))? (a): (b))
#define digitCount 4 // 氮㎝瞦代计
#define guessLimit 2 // 瞦代Ω计
typedef struct{
    int A; // 竚タ絋计タ絋计
    int B; // 竚岿粇计タ絋计
}ABresult;

int digitArr[10] = {0,1,2,3,4,5,6,7,8,9}; // ノ计絛瞅 0-9

// ㄧΑ:
ABresult compare_array(int *input, int *target);
void randomize(int *target);
void reset_digitArr();
void swap(int *input, int index, int index1);
void print_int_array(int *input);

int main(){
    srand(time(NULL)); // ﹍て繦诀计贺

    int guess_time = guessLimit; // ﹍て瞦代Ω计
    int answer[digitCount];
    randomize(answer); // 繦诀ネΘ氮

    while (guess_time > 0){
        guess_time--;
        int guess[digitCount];
        randomize(guess); // 繦诀ネΘ瞦代计┪ノめ块
        printf("input four different number:(ㄒ2178)");
        print_int_array(guess); // ゴ讽玡瞦代计
        printf("\n");

        ABresult result = compare_array(guess, answer); // ゑ耕瞦代㎝氮
        printf("挡狦:%dA%dB临Τ%dΩ诀穦...\n", result.A, result.B, guess_time);
        if (result.A == digitCount){ // 狦┮Τ计㎝竚常タ絋
            printf("瞦癸!\n");
            return 0;
        }
    }

    printf("ア毖瞦禬筁%dΩ氮琌", guessLimit);
    print_int_array(answer); // 陪ボタ絋氮
    printf("\n");
    return 0;
}

// ゑ耕瞦代㎝氮AB
ABresult compare_array(int *guess, int *target){
    int guess_show_count[10] = {0}; // 癘魁瞦代い计瞷Ω计
    int target_show_count[10] = {0}; // 癘魁氮い计瞷Ω计
    int i;
    ABresult result = {0, 0};
    for (i = 0; i < digitCount; i++){
        if (guess[i] == target[i]){
            result.A ++; // 竚㎝计常タ絋
        }
        else{
            guess_show_count[guess[i]]++; // 癘魁瞷Ω计
            target_show_count[target[i]]++;
        }
    }

    // 璸衡竚岿粇计タ絋B
    for (i = 0; i < 10; i++){
        result.B += MIN(guess_show_count[i], target_show_count[i]);
    }
    return result;
}

// 繦诀ネΘ氮
void randomize(int *target){
    int leftDigitCount = 10; // ノ计临逞ぶ
    int changeIndex = 0;

    for (; changeIndex < digitCount; changeIndex++, leftDigitCount--){
        int picked_num = rand() % leftDigitCount; // 繦诀珼匡计
        int picked_index = changeIndex + picked_num;
        target[changeIndex] = digitArr[picked_index]; // 眖digitArrい珼匡计
        swap(digitArr, changeIndex, picked_index); // 穝digitArrㄏ匡计ぃ砆匡拒
    }

    reset_digitArr(); // 竚 digitArr
}

// 竚 digitArr ﹍篈
void reset_digitArr() {
    for (int i = 0; i < 10; i++) {
        digitArr[i] = i;
    }
}

// ユ传计舱いㄢじ
void swap(int *input, int index, int index1){
    int temp = input[index]; 
    input[index] = input[index1];
    input[index1] = temp;
}

// ゴ俱计计舱
void print_int_array(int *input){
    int i;
    for (i = 0; i < digitCount; i++){
        printf("%d", input[i]);
    }
}
