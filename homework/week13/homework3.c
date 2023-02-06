#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define namelen 50
#define size1 3
typedef struct player{
    char nickname[namelen];
    int hp;
    int damage;
    int speed;
}player;
//tìm vị trí max
int find_max(int a[],int size ){
    int max = a[0], n = 0 ;
    for(int i = 1; i <size;i++){
        if(max <= a[i]){
            max = a[i];
            n = i + 1;
        }
    }
    return n;
}

//get the value by order
void get_by_range(int *n, int a, int b){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        if((*n < a)||(*n > b)){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while((*n<a)||(*n>b));
}  
void initialization(struct player *p){
    printf("\nNOTE: The total INDEX of HP, Damage is lower than 400!!");
    printf("\nEnter nickname of the player: ");
    scanf("%s", p->nickname);
    printf("\nEnter HP of the player(lower than 400): ");
    get_by_range(&(p->hp),1,400);
    printf("\nEnter Damage of the player (lower than %d): ", 400-(p->hp));
    get_by_range(&(p->damage),1,400-(p->hp));   
    printf("\nEnter Speed of the player(lower than %d): ", 400-(p->damage + p->hp));
    get_by_range(&(p->speed),0,400-(p->damage + p->hp));
} 
//update player after each turn in one round
void player_update(struct player *win, struct player *lose){
    (win->hp) += 2*(int)((win->hp)/100);
    (win->damage) += 2*(int)((win->damage)/100);
    (win->speed) += 2*(int)((win->speed)/100);
    (lose->hp) += (int)((lose->hp)/100);
    (lose->damage) += (int)((lose->damage)/100);
    (lose->speed) += (int)((lose->speed)/100);
    printf("\n---------------UPDATE-INDEX--------------------");    
    printf("\nThe update INDEX OF PLAYER %s (WIN) !!",win->nickname);
    printf("\n\t1.The HP: %d",win->hp);
    printf("\n\t2.The Damage: %d",win->damage);
    printf("\n\t3.The Speed: %d",win->speed);
    printf("\nThe update INDEX OF PLAYER %s (LOSE)!!",lose->nickname);
    printf("\n\t1.The HP: %d",lose->hp);
    printf("\n\t2.The Damage: %d",lose->damage);
    printf("\n\t3.The Speed: %d",lose->speed);
    
}
//update the player index after each turn in one round
void player_bonus(struct player *win, struct player *lose){
    printf("\n---------------RANDOM-BONUS--------------------"); 
    int x ,point;
    srand(time(NULL));
    x = (rand() % 2) + 1;
    printf("\nThe random player is bonus is: %d ",x );
    if(x == 1){
        (win->hp) += (rand() % 10 ) + 1;
        (win->damage) += (rand() % 10 ) + 1;
        (win->speed) += (rand() % 10 ) + 1;
        printf("\nTHE UPDATE INDEX OF PLAYER %s !",win->nickname);
        printf("\n\t1.The HP: %d",win->hp);
        printf("\n\t2.The Damage: %d",win->damage);
        printf("\n\t3.The Speed: %d",win->speed);
    }
    else if (x == 2){
        (lose->hp) += (rand() % 10 ) + 1;
        (lose->damage) += (rand() % 10 ) + 1;
        (lose->speed) += (rand() % 10 ) + 1;
        printf("\nTHE UPDATE INDEX OF PLAYER %s !",lose->nickname);
        printf("\n\t1.The HP: %d",lose->hp);
        printf("\n\t2.The Damage: %d",lose->damage);
        printf("\n\t3.The Speed: %d",lose->speed);
    }
}
//two player in one round 
int player_round(char name_1[namelen],int hp_1, int damage_1, int speed_1, char name_2[namelen],int hp_2, int damage_2,int speed_2){
    int result = 3;
    printf("\nREADY? ....THE GAME START !!!");
        if(speed_1 >= speed_2){
            do{
            printf("\n-----------------------------------");
            printf("\nThe player %s attack turn!",name_1);
            printf("\nPlayer %s attack the player %s with damage : %d !!! BUMPPP!",name_1,name_2,damage_1);
            hp_2-=damage_1;
            printf("\nThe player %s index:\n\t1.HP: %d\n\t2.Damage: %d\n\t3.Speed: %d ",name_2,hp_2,damage_2,speed_2);
            printf("\nThe player %s attack turn!",name_2);
            printf("\nPlayer %s attack the player %s with damage : %d !!! BUMPPP!",name_2,name_1,damage_2);
            hp_1-=damage_2;
            printf("\nThe player %s index:\n\t1.HP: %d\n\t2.Damage: %d\n\t3.Speed: %d ",name_1,hp_1,damage_1,speed_1);
            printf("\n-----------------------------------");   
            }while(hp_1 > 0 && hp_2 >0);
        }
        else if(speed_1 < speed_2){
            do{
            printf("\n-----------------------------------");
            printf("\nThe player %s attack turn!",name_2);
            printf("\nPlayer %s attack the player %s with damage : %d !!! BUMPPP!",name_2,name_1,damage_2);
            hp_1-=damage_2;
            printf("\nThe player %s index:\n\t1.HP: %d\n\t2.Damage: %d\n\t3.Speed: %d ",name_1,hp_1,damage_1,speed_1);
            printf("\nThe player %s attack turn!",name_1);
            printf("\nPlayer %s attack the player %s with damage : %d !!! BUMPPP!",name_1,name_2,damage_1);
            hp_2-=damage_1;
            printf("\nThe player %s index:\n\t1.HP: %d\n\t2.Damage: %d\n\t3.Speed: %d ",name_2,hp_2,damage_2,speed_2);
            printf("\n-----------------------------------");           
            }while(hp_1 > 0 && hp_2 >0);
        }
        (hp_1 > hp_2) ? printf("\nThe player %s is win this round!",name_1) : printf("\nThe player %s is win this round!",name_2);
        result = (hp_1 > hp_2) ? 1 : 0;
    return result;
}

int main(){
    int count[3]={0,0,0};
    int turn1,turn2,turn3;
    player player_1,player_2,player_3;
    printf("\nWELCOME TO THE ICT ARENA!");
    printf("\nPlayer 1!  ");
    initialization(&player_1);
    printf("\nPlayer 2!  ");
    initialization(&player_2);
    printf("\nPlayer 3!  ");
    initialization(&player_3);

    // player 1 vs player 2
    turn1 = player_round(player_1.nickname,player_1.hp,player_1.damage,player_1.speed,player_2.nickname,player_2.hp,player_2.damage,player_2.speed);
    if( turn1 == 1){
        player_update(&player_1,&player_2);
        player_bonus(&player_1,&player_2);
        count[0]++;
    }
    else if(turn1 == 0){
        player_update(&player_2,&player_1);
        player_bonus(&player_2,&player_1);
        count[1]++;
    }
    printf("\n\n");
    // player 2 vs player 3
    turn2 = player_round(player_2.nickname,player_2.hp,player_2.damage,player_2.speed,player_3.nickname,player_3.hp,player_3.damage,player_3.speed);
    if( turn2 == 1){
        player_update(&player_2,&player_3);
        player_bonus(&player_2,&player_3);
        count[1]++;
    }
    else if(turn2 == 0){
        player_update(&player_3,&player_2);
        player_bonus(&player_2,&player_3);
        count[2]++;
    }    
    printf("\n\n");
    //player 3 vs player 1
    turn3 = player_round(player_3.nickname,player_3.hp,player_3.damage,player_3.speed,player_1.nickname,player_1.hp,player_1.damage,player_1.speed);
    if(turn3 == 1){
        player_update(&player_3,&player_1);
        player_bonus(&player_3,&player_1);    
        count[2]++;
    }
    else if(turn3 == 0){
        player_update(&player_1,&player_3);
        player_bonus(&player_1,&player_3);  
        count[0]++;
    }
    int winning = find_max(count,size1);
    printf("\n%d",find_max(count,size1));
    printf("\n\n"); 
    printf("\nTHE GAME END!!");
    if( count[1] == count[2] && count[2] == count[3]){
        printf("\n3 players draw !!");
    }
    else if(winning == 0){
        printf("\nPlayer %s is WINNING", player_1.nickname);
    }
    else if(winning == 1){
        printf("\nPlayer %s is WINNING", player_2.nickname);
    }
    else if(winning == 2){
        printf("\nPlayer %s is WINNING", player_3.nickname);
    }    
    return 0;
}
