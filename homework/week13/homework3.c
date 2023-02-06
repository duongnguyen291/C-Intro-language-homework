#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define namelen 50
#define number_player 3
typedef struct player{
    char nickname[namelen];
    int hp;
    int damage;
    int speed;
}player;
//get the value by order
void get_by_range(int *n, int a, int b){
    do{
            printf("\nEnter: ");
            scanf("%d", &*n);
            if((*n < a)||(*n > b)){
                printf("\nThe answer is incorrect!Please enterb again!");
            }
        }while((*n<a)||(*n>b));
}
//initialization
void initialization(char name[namelen], int *hp, int *damage, int *speed){
    printf("\nEnter nickname of the player: ");
    scanf("%s", &name);
    printf("\nEnter HP of the player(lower than 500): ");
    get_by_range(hp,1,500);
    printf("\nEnter Damage of the player(lower than 100): ");
    get_by_range(damage,1,100);   
    printf("\nEnter Speed of the player(lower than 100): ");
    get_by_range(speed,1,100);
}   
//update player after each turn in one round
void player_update(int *hp_win,int *damage_win,int *speed_win, int *hp_lose, int *damage_lose, int *speed_lose){
    *hp_win += *hp_win + 2*(int)(*hp_win/100);
    *hp_lose += *hp_lose + (int)(*hp_lose/100);
}
//update the player index after each turn in one round
void player_bonus();
//two player in one round 
int player_round(char name_1[namelen],int hp_1, int damage_1, int speed_1, char name_2[namelen],int hp_2, int damage_2,int speed_2){
int result;
printf("\nREADY? ....THE GAME START !!!");
    if(speed_1 >= speed_2){
        do{
        printf("\nThe player %s attack turn!",name_1);
        printf("\nPlayer %s attack the player %s with damage : %d !!! BUMPPP!",name_1,name_2,damage_1);
        hp_2-=damage_1;
        printf("\nThe player %s index:\n\t1.HP: %d\n\t2.Damage: %d\n\t3.Speed: %d ",name_2,hp_2,damage_2,speed_2);
        printf("\nThe player %s attack turn!",name_2);
        printf("\nPlayer %s attack the player %s with damage : %d !!! BUMPPP!",name_2,name_1,damage_2);
        hp_1-=damage_2;
        printf("\nThe player %s index:\n\t1.HP: %d\n\t2.Damage: %d\n\t3.Speed: %d ",name_1,hp_1,damage_1,speed_1);
        }while(hp_1 > 0 && hp_2 >0);
    }
    else{
        do{
        printf("\nThe player %s attack turn!",name_2);
        printf("\nPlayer %s attack the player %s with damage : %d !!! BUMPPP!",name_2,name_1,damage_2);
        hp_1-=damage_2;
        printf("\nThe player %s index:\n\t1.HP: %d\n\t2.Damage: %d\n\t3.Speed: %d ",name_1,hp_1,damage_1,speed_1);
        printf("\nThe player %s attack turn!",name_1);
        printf("\nPlayer %s attack the player %s with damage : %d !!! BUMPPP!",name_1,name_2,damage_1);
        hp_2-=damage_1;
        printf("\nThe player %s index:\n\t1.HP: %d\n\t2.Damage: %d\n\t3.Speed: %d ",name_2,hp_2,damage_2,speed_2);
        }while(hp_1 > 0 && hp_2 >0);
    }
    (hp_1 > hp_2) ? printf("\nThe player %s is win this round!",name_1) : printf("\nThe player %s is win this round!",name_2);
    result = (hp_1 > hp_2) ? 1 : 0;
    return result;
}

int main(){
    player player_1,player_2,player_3;
    printf("\nPlayer 1!  ");
    initialization(player_1.nickname,&player_1.hp,&player_1.damage,&player_1.speed);
    printf("\nPlayer 2!  ");
    initialization(player_2.nickname,&player_2.hp,&player_2.damage,&player_2.speed);
    printf("\nPlayer 3!  ");
    initialization(player_3.nickname,&player_3.hp,&player_3.damage,&player_3.speed);
    if( player_round(player_1.nickname,player_1.hp,player_1.damage,player_1.speed,player_2.nickname,player_2.hp,player_2.damage,player_2.speed)==1){
        printf("\n1 win");
    }

    return 0;
}