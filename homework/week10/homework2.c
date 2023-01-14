#include <stdio.h>
void totalmoney(float dayhospital,float medical,float surgery,float insurance, float total_money,float total_pay);
void totalreport(int number_patient,int gold, int silver, int citizen, float total_medical_all,float total_surgery_all,float total_money_all,float total_pay_all,float the_most_profit);

int main(){
    //khai báo biến
    int check0 = 1,check1 = 2,check2, home = 0,number_patient = 0;
    float dayhospital = 0,medical = 0,surgery = 0,insurance = 0;
    float total_money = 0, total_pay = 0;
    float total_money_storage[100],total_pay_storage[100],total_medical_storage[100],total_surgery_storage[100],total_insurance_storage[100] ;
    float total_money_all = 0, total_pay_all = 0, total_medical_all = 0, total_surgery_all = 0;
    float patient_name[100];
    float the_most_profit,insurance_profit;
    int gold = 0,silver = 0 ,citizen = 0;
    //menu
    do{
        printf("\n--------------------------");
        printf("\n HOSPITAL FEE PROGRAM! ");
        printf("\n1.Patient information\n2.Hospital fee bill\n3.Total report\n4.Exit;");
            do{
                printf("\nYour choice is: ");
                scanf("%d", &home);
                if(home<1||home>4){
                printf("\nThe answer is incorrect!Please enter again!");
                }
            }while(home<1||home>4);
        switch(home){
           
            case 1:
                insurance_profit = 0;
                number_patient++;
                dayhospital = 0,medical = 0,surgery = 0,insurance = 0;
                total_money = 0, total_pay = 0;
                check0 = 1;
                //Họ tên bệnh nhân              
                printf("\nEnter the patient name: ");
                scanf(" %[^\n]", patient_name);
                //ngày nằm viện
                    do{
                        printf("\nEnter the number of day that you stay in the hospital: ");
                        scanf("%f", &dayhospital);
                        if(dayhospital<0){
                            printf("\nThe answer is incorrect!Please enter again!");
                        }
                    }while(dayhospital<0);                   
                //tiền thuốc
                    do{
                        printf("\nEnter the money that you buy medical: ");
                        scanf("%f", &medical);
                        if(medical<0){
                            printf("\nThe answer is incorrect!Please enter again!");
                        }
                    }while(medical<0);
                //tiền phẫu thuật
                    do{
                        printf("\nDo you have surgery?\n\t1.Yes\n\t2.No\nYour choice is: ");
                        scanf("%d",&check1);
                            if(check1<1||check1>2){
                                printf("\nYour choice is incorrect!Please enter again!");
                            }
                    }while(check1<1||check1>2);                   
                    if(check1==1){    
                        printf("Enter the money that you pay for surgery: ");
                            do{
                                scanf("%f", &surgery);
                                if(surgery<0){
                                    printf("\nThe answer is incorrect!Please enter again!");
                                }
                            }while(surgery<0);
                    }
                    else if(check1==2){
                        surgery = 0;
                    }                    
                    do{
                        printf("\nWhat kind of your insurance?\n\t1.Gold(G)\n\t2.Silver(S)\n\t3.Citizen(C)\n");
                        printf("\nYour choice: ");
                        scanf("%d",&check2); 
                            if(check2==1){
                                gold++; 
                                insurance = 0.3;
                            }
                            else if(check2==2){
                                silver++;
                                insurance = 0.5;
                            }
                            else if(check2==3){
                                citizen++;
                                insurance = 0.7;
                            }
                    }while(check2<1||check2>3);  
                //tiền tạm thời của 1 bệnh nhân
                total_money = (dayhospital *150000 + medical + surgery); 
                total_pay = (dayhospital *150000 + medical + surgery) * insurance; 
                insurance_profit = total_money - total_pay;             
                //tiền hệ thống của tất cả bệnh nhân
                //lưu trữ tiền của mỗi bệnh nhân 
                total_money_storage[number_patient] = total_money;  
                //printf("\n1 The money : %.2f",total_money_storage[number_patient]);
                total_pay_storage[number_patient] = total_pay;
                //printf("\n2 The pay : %.2f",total_pay_storage[number_patient]);
                total_surgery_storage[number_patient] = surgery;
                //printf("\n3 The surgery: %.2f",total_surgery_storage[number_patient]);
                total_medical_storage[number_patient] = medical;
                //printf("\n4 The medical: %.2f",total_medical_storage[number_patient]);
                total_insurance_storage[number_patient] = insurance_profit;
                //printf("\n5 The insurance: %.2f",total_insurance_storage[number_patient]);
            break; 
            case 2:
                check0 = 1;
                //bill
                printf("\nTOTAL BILL\n");
                printf("\nThe patient name is %s ",patient_name);                
                totalmoney(dayhospital,medical,surgery,insurance,total_money,total_pay);
            break;
            case 3:
                for(int i = 1; i<=number_patient; i++){
                    total_medical_all += total_medical_storage[i]; 
                }
                printf("\nTotal medical all: %.2f",total_medical_all);
                for(int i = 1; i<=number_patient; i++){
                   total_surgery_all += total_surgery_storage[i]; 
                }
                printf("\nTotal surgery all: %.2f",total_surgery_all);                
                for(int i = 1; i<=number_patient ; i++){
                    total_money_all += total_money_storage[i];
                }
                printf("\nTotal money all: %.2f",total_money_all);                
                for(int i = 1; i<=number_patient;i++){
                    total_pay_all += total_pay_storage[i];
                }
                printf("\nTotal pay all: %.2f",total_pay_all);                
            check0 = 1;
                the_most_profit = total_insurance_storage[1];
                    for(int i = 1; i<=number_patient;i++){
                        if(total_insurance_storage[i] >= the_most_profit){
                            the_most_profit = total_insurance_storage[i];
                        }
                    }
                
                printf("\nTOTAL REPORT\n");
                totalreport(number_patient,gold,silver,citizen,total_medical_all,total_surgery_all,total_money_all,total_pay_all,the_most_profit);
            break;
            case 4:
                check0 = 0;
                break;
            default: 
                printf("\nYour choice is incorrect! Please enter again!");
            break;
        }
    }while(check0==1);
    return 0;
}

void totalmoney(float dayhospital,float medical,float surgery,float insurance,float total_money,float total_pay){
    printf("\nThe money of day that you stay in the hospital: %.2f (VND)",dayhospital*150000);
    printf("\nThe money that you buy medical: %.2f (VND)",medical);
    printf("\nThe money that you pay for surgery: %.2f (VND)",surgery);
    printf("\nThe total money: %.2f*150000 + %.2f + %.2f  = %.2f (VND)",dayhospital,medical,surgery,total_money);
    printf("\nThe total money you must pay: ( %.2f*150000 + %.2f + %.2f ) x %.2f  = %.2f (VND)",dayhospital,medical,surgery,insurance,total_pay);
}
void totalreport(int number_patient,int gold, int silver, int citizen, float total_medical_all,float total_surgery_all,float total_money_all,float total_pay_all,float the_most_profit){
    printf("\nThe Total Number of Patient : %d",number_patient);
    printf("\nThe Number kind of insurancce: %d (Gold), %d (Silver), %d (Citizen)",gold,silver,citizen);
    printf("\nThe Total Money Medical: %.2f (VND)",total_medical_all);
    printf("\nThe Total Money Surgery: %.2f (VND)",total_surgery_all);
    printf("\nThe Total Money Patient's Bill: %.2f (VND)",total_money_all);
    printf("\nThe Total Money Patient's Pay: %.2f (VND)",total_pay_all);
    printf("\nThe Avarage of Each Patient: %.2f (VND)", total_pay_all/(float)number_patient);
    printf("\nThe most profit of insurance : %.2f (VND)",the_most_profit);

}

