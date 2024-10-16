#include <stdio.h>

int main()
{
    char input[200] = "";
    int count_alpha[26] = {0}; // 알파벳 카운트
    int count_digit[10] = {0}; // 숫자 카운트
    int count_symbol[32] = {0}; // 기호 카운트 (예: !, @, #, $, ...)
    
    int ch;
    int i = 0;
    
    while((ch = getchar()) != EOF){
        input[i++] = ch;
    }
    i = 0;

    // 문자열에서 각 문자 출현 횟수 카운트
    while(input[i] != '\0'){
        if(input[i] >= 'a' && input[i] <= 'z'){
            count_alpha[input[i] - 'a']++;
        }
        else if(input[i] >= '0' && input[i] <= '9'){
            count_digit[input[i] - '0']++;
        }
        else if((input[i] >= 33 && input[i] <= 47) || (input[i] >= 58 && input[i] <= 64) || 
                (input[i] >= 91 && input[i] <= 96) || (input[i] >= 123 && input[i] <= 126)){
            count_symbol[input[i] - 33]++;
        }
        i++;
    }

    // 입력된 문자열 출력
    printf("입력문자열 : %s\n", input);

    // 알파벳 출현 횟수 출력
    for(int i = 0; i < 26; i++)  
        printf("%c 출현횟수 : %d\n", 'a' + i, count_alpha[i]);

    // 숫자 출현 횟수 출력
    for(int i = 0; i < 10; i++)  
        printf("%c 출현횟수 : %d\n", '0' + i, count_digit[i]);

    // 기호 출현 횟수 출력
    for(int i = 0; i < 32; i++)  
        printf("%c 출현횟수 : %d\n", 33 + i, count_symbol[i]);

    return 0;
}
