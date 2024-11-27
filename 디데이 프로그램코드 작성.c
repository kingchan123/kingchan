#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    struct tm d_day = {0};   
    struct tm current_time = {0};  
    time_t d_day_time, current_time_t;
    double seconds_diff;
    
    
    time(&current_time_t);
    current_time = *localtime(&current_time_t);
    
    
    int year, month, day;
    printf("디데이 날짜를 입력하세요 (년 월 일): ");
    scanf("%d %d %d", &year, &month, &day);
    
 
    d_day.tm_year = year - 1900; 
    d_day.tm_mon = month - 1;    
    d_day.tm_mday = day;        
  
    
    
    d_day_time = mktime(&d_day);
    
   
    seconds_diff = difftime(d_day_time, current_time_t);
    
    if (seconds_diff > 0) {
        
        printf("디데이까지 %.0f일 남았습니다.\n", seconds_diff / (60 * 60 * 24));
    } else if (seconds_diff < 0) {
        
        printf("디데이가 %.0f일 지났습니다.\n", -seconds_diff / (60 * 60 * 24));
    } else {
        
        printf("오늘이 디데이입니다!\n");
    }

    return 0;
}
