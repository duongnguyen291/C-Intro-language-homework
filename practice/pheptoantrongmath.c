#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
printf("\n%.4lf",sqrt(9));/*square root: căn bậc 2 của c*/
printf("\n%.3lf",cbrt(8));/*cuberoot : căn bậc 3 của c*/
printf("\n%.3lf",exp(3));/*e mũ 3 */
printf("\n%.3lf",log(2.718282));/*log cơ số e của x*/
printf("\n%.3lf",log10(100));/*log cơ số 10 của x*/
printf("\n%.3lf",fabs(-200));/*giá trị tuyệt đối khuyên dùng*/
printf("\n%.3lf",ceil(5.1)); /*Làm tròn lên số nguyên*/
printf("\n%.3lf",round(4.4999999));
printf("\n%.3lf",round(5.5));/*Làm tròn lên hoặc xuống */
printf("\n%.3lf",floor(9.9));/*làm tròn xuống*/
printf("\n%.3lf",pow(4,6));/*4 mũ 6*/
printf("\n%.3lf",fmod(12.69,4));/*phần dư của 12,69 chia 4*/
printf("\n%.3lf",sin(70));/*tính sin của 70*/
printf("\n%.3lf",cos(70));
printf("\n%.3lf",tan(70));
printf("\n%.3lf",asin(0.2));/*arcsin của 0.2*/
printf("\n%.3lf",acos(0.3));
printf("\n%.3lf",atan(0.3));

}