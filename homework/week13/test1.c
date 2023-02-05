#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N = 3;

struct player {
    char nickname[50];
    float power;
    float HP;
    float speed;
};
void readInput(char name[], float power, float hp, float speed) {

    printf("Nickname of player: ");
    scanf("%s", &name);
    printf("Power strength: ");
    scanf("%d", &power);
    printf("HP: ");
    scanf("%d", &hp);
    printf("Speed: ");
    scanf("%d", &speed);
}

int bonus_exp(int range_max) {
    // Use rand() function to get the random exp between 1% - 5%
    return rand() % 5;
}

void update_power(int p1_hp, int p2_hp, int p1_power, int p2_power, int p1_speed, int p2_speed, int exp_1, int exp_2) {
    p1_hp = p1_hp + (p1_hp*exp_1)/100;
}

void update(float criteria, int exp_1, int exp_2) {
    criteria = criteria + (criteria * exp_1)/100 + (criteria * exp_2)/100; 
}

void checkresult(char p1_name[], char p2_name[], int p1_hp, int p2_hp, int p1_power, int p2_power, int p1_speed, int p2_speed) {
    if (p1_hp < 0) {
        printf("%s wins. \n", p2_name);
        printf("%s gains 2%% exp + bonus_exp(1, 5)%%", p2_name);
        
        int exp = bonus_exp(5);

        update(p2_hp, 2, exp);
        update(p2_power, 2, exp);
        update(p2_speed, 2, exp);

        printf("%s gains 1%% exp + bonus_exp(1,5)%%", p1_name);

        update(p1_hp, 2, exp);
        update(p1_power, 2, exp);
        update(p1_speed, 2, exp);
    }
    else {
        printf("%s wins. \n", p1_name);
        printf("%s gains 2%% exp + bonus_exp(1, 5)%%", p1_name);

        int exp = bonus_exp(5);
        update(p1_hp, 2, exp);
        update(p1_power, 2, exp);
        update(p1_speed, 2, exp);

        printf("%s gains 1%% exp + bonus_exp(1,5)%%", p2_name);
    
        update(p2_hp, 2, exp);
        update(p2_power, 2, exp);
        update(p2_speed, 2, exp);
    }
}

void game(char p1_name[], char p2_name[], int p1_power, int p2_power, int p1_hp, int p2_hp,
          int p1_speed, int p2_speed) {
    
    printf("READY\n");
    printf(".\n");
    printf("..\n");
    printf("...\n");
    printf("START\n");

    int index = 1;

    while (p1_hp > 0 && p2_hp > 0) {
        if (p1_speed > p2_speed) {
            printf("%s (%d speed point) attacks first. %s hp reduce %d. \n", p1_name, p1_speed, p2_name, p1_power);
            p2_hp = p2_hp - p1_power;
            printf("%s hp is %d", p2_name, p2_hp);
            index++;
            
            if (index % 2 == 0) {
                printf("%s attacks. %s hp reduce %d. \n", p2_name, p1_name, p2_power);
                p1_hp = p1_hp - p2_power;
                printf("%s hp is %d", p1_name, p1_hp);
                index++;       
            }
            else {
                printf("%s attacks. %s hp reduce %d. \n", p1_name, p2_name, p1_power);
                p2_hp = p2_hp - p1_power;
                printf("%s hp is %d", p2_name, p2_hp);
                index++;
            }
        }
        else {
            printf("%s (%d speed point) attacks first. %s hp reduce %d. \n", p2_name, p2_speed, p1_name, p2_power);
            p1_hp = p1_hp - p2_power;
            printf("%s hp is %d", p1_name, p1_hp);
            index++;
            
            if (index % 2 == 0) {
                printf("%s attacks. %s hp reduce %d. \n", p1_name, p2_name, p1_power);
                p2_hp = p2_hp - p1_power;
                printf("%s hp is %d", p2_name, p2_hp);
                index++;       
            }
            else {
                printf("%s attacks. %s hp reduce %d. \n", p2_name, p1_name, p2_power);
                p1_hp = p1_hp - p2_power;
                printf("%s hp is %d", p1_name, p1_hp);
                index++;
            }        
        }
    }
}


int main() {
    //Declare the player 1, 2, 3
    struct player p1, p2, p3;

    printf("Welcome to the ICT Arena\n");
    printf("There are some regulations, you must follow:\n");
    printf("1. After the game, each player will have a bonus exp from (1%%-5%%).\n");
    printf("2. The power decreases between(1%% - 5%%) after each phase.\n");

    readInput(p1.nickname, p1.power, p1.HP, p1.speed);
    readInput(p2.nickname, p2.power, p2.HP, p2.speed);
    readInput(p3.nickname, p3.power, p3.HP, p3.speed);

    game(p1.nickname, p2.nickname, p1.power, p2.power, p1.HP, p2.HP, p1.speed, p2.speed);

    return 0;
}