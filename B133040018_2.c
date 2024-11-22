#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �p���ӼƦr���̤j���]�ơ]GCD�^
long long int getGcd(long long a, long long b) {
    if (a == 0) {
        return b; // �p�G a �� 0�A�h b �� GCD
    }
    return getGcd(b % a, a); // �ϥλ��j�p�� GCD
}

// ����r�Ŧ�
void reverse(char *input, char *output){
    int length = strlen(input); // �����J�r�Ŧꪺ����
    int i = 0, j = length - 1;
    while (i < length){
        output[i] = input[j]; // �N�r�űq�᩹�e�ƻs���X��
        j--; 
        i++;
    }
    output[length] = '\0'; // ����X�r�Ŧ�K�[������
    return;
}

int main(){
    char input[10000], reversed[10000]; // �w�q��J�M����᪺�r�Ŧ�
    printf("Enter an integer: ");
    scanf("%9999s", input); // Ū���Τ��J�]�̦h 9999 �Ӧr�š^
    reverse(input, reversed); // �����J���r�Ŧ�

    long long int a, b;
    a = strtoll(input, NULL, 10); // �N�r�Ŧ��ഫ�������
    b = strtoll(reversed, NULL, 10); // �N����᪺�r�Ŧ��ഫ�������

    // ���L����᪺�Ʀr�M��̪� GCD
    printf("Reversed integer: %lld\n", b);
    printf("GCD of %lld and %lld is %lld\n", a, b, getGcd(a, b));

    return 0;
}
