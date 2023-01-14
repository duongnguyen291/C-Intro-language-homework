#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLAYERS 5

int main(void) {
int shirt_numbers[NUM_PLAYERS];
float ratings[NUM_PLAYERS];

// Nhập số áo và điểm của các cầu thủ
for (int i = 0; i < NUM_PLAYERS; i++) {
printf("\nEnter the jersey of player number %d: ", i + 1);
scanf("%d", &shirt_numbers[i]);
printf("\nEnter the point of player %d: ", i + 1);
scanf("%f", &ratings[i]);
}

// Làm tròn điểm theo yêu cầu
for (int i = 0; i < NUM_PLAYERS; i++) {
ratings[i] = round(ratings[i] * 2) / 2;
}

// In ra kết quả
for (int i = 0; i < NUM_PLAYERS; i++) {
printf("Number %d: point %.1f\n", shirt_numbers[i], ratings[i]);
}

return 0;
}

/*
Hướng dẫn:

Sử dụng mảng shirt_numbers để lưu trữ số áo của các cầu thủ.
Sử dụng mảng ratings để lưu trữ điểm của các cầu thủ.
Sử dụng vòng lặp for để nhập số áo và điểm của các cầu thủ từ người dùng.
Sử dụng hàm round() để làm tròn điểm của các cầu thủ theo yêu cầu.
Sử dụng vòng lặp for để in ra số áo và điểm của các cầu thủ.*/