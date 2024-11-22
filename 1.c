#include <stdio.h>
#include <time.h>
#include <stdlib.h> // �üƬ������
#define MIN(a, b) (((a) < (b))? (a): (b))
#define digitCount 4 // ���שM�q�������
#define guessLimit 2 // �q�������ƭ���
typedef struct{
    int A; // ��m���T�B�Ʀr���T���Ӽ�
    int B; // ��m���~���Ʀr���T���Ӽ�
}ABresult;

int digitArr[10] = {0,1,2,3,4,5,6,7,8,9}; // �i�Ϊ��Ʀr�d�� 0-9

// �禡�ŧi:
ABresult compare_array(int *input, int *target);
void randomize(int *target);
void reset_digitArr();
void swap(int *input, int index, int index1);
void print_int_array(int *input);

int main(){
    srand(time(NULL)); // ��l���H���ƺؤl

    int guess_time = guessLimit; // ��l�Ʋq������
    int answer[digitCount];
    randomize(answer); // �H���ͦ�����

    while (guess_time > 0){
        guess_time--;
        int guess[digitCount];
        randomize(guess); // �H���ͦ��q���Ʀr�]�ΥΤ��J�^
        printf("input four different number:(�Ҧp2178)");
        print_int_array(guess); // ���L��e�q�����Ʀr
        printf("\n");

        ABresult result = compare_array(guess, answer); // ����q���M����
        printf("���G:%dA%dB�A�٦�%d�����|...\n", result.A, result.B, guess_time);
        if (result.A == digitCount){ // �p�G�Ҧ���ƩM��m�����T
            printf("�A�q��F!\n");
            return 0;
        }
    }

    printf("���ѡA�q�W�L%d���A���׬O", guessLimit);
    print_int_array(answer); // ��ܥ��T����
    printf("\n");
    return 0;
}

// ����q���M���סA��^AB��
ABresult compare_array(int *guess, int *target){
    int guess_show_count[10] = {0}; // �O���q�����U�Ʀr�X�{����
    int target_show_count[10] = {0}; // �O�����פ��U�Ʀr�X�{����
    int i;
    ABresult result = {0, 0};
    for (i = 0; i < digitCount; i++){
        if (guess[i] == target[i]){
            result.A ++; // ��m�M�Ʀr�����T
        }
        else{
            guess_show_count[guess[i]]++; // �O���X�{����
            target_show_count[target[i]]++;
        }
    }

    // �p���m���~���Ʀr���T��B��
    for (i = 0; i < 10; i++){
        result.B += MIN(guess_show_count[i], target_show_count[i]);
    }
    return result;
}

// �H���ͦ�����
void randomize(int *target){
    int leftDigitCount = 10; // �i�Ϊ��Ʀr�ٳѦh��
    int changeIndex = 0;

    for (; changeIndex < digitCount; changeIndex++, leftDigitCount--){
        int picked_num = rand() % leftDigitCount; // �H���D��@�ӼƦr
        int picked_index = changeIndex + picked_num;
        target[changeIndex] = digitArr[picked_index]; // �qdigitArr���D��Ʀr
        swap(digitArr, changeIndex, picked_index); // ��sdigitArr�A�Ϥw�諸�Ʀr���A�Q���
    }

    reset_digitArr(); // ���m digitArr
}

// ���m digitArr ����l���A
void reset_digitArr() {
    for (int i = 0; i < 10; i++) {
        digitArr[i] = i;
    }
}

// �洫�Ʋդ�����Ӥ���
void swap(int *input, int index, int index1){
    int temp = input[index]; 
    input[index] = input[index1];
    input[index1] = temp;
}

// ���L��ƼƲ�
void print_int_array(int *input){
    int i;
    for (i = 0; i < digitCount; i++){
        printf("%d", input[i]);
    }
}
