#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

void first_inning(char teamX[50]);
int second_inning(char teamX[50], char teamY[50]);
int toss,overs,no_players,target,score,runs,fours,sixes,inning=1;
float runrate, strike_rate,current_over;
int bowled, wicket, player_bowled, player_wicket;
int bat_first;
int current_batsman=1;
int striker=1, non_striker=2;
char Team1[50];
char Team2[50];
int strikeRotation()
{
    int temp = striker;
        striker = non_striker;
        non_striker = temp;
}

struct Player{
    char name[50];
    int runs;
    int balls_faced;
    int fours;
    int sixes;
    float strike_rate;
    double bowled;
    int run_concede;
    float economy;
    int wicket;
};
struct Player team1_player[11];
struct Player team2_player[11];
struct Player* batting_team;

int main(){

printf("Enter Name of Team1:");
scanf("%s",Team1);
printf("Enter Name of Team2:");
scanf("%s",Team2);



int i;
printf("How many players in a team?");
scanf("%d",&no_players);   

for(i=1;i<=no_players;i++)
{
    printf("Enter name for Player %d (Team 1) : ", i);
    scanf("%s", team1_player[i].name);
}
for(i=1; i<=no_players; i++)
{
    printf("Player %d for Team1 : %s\n", i, team1_player[i].name);
}

for(i=1;i<=no_players;i++)
{
    printf("Enter name for Player %d (Team 2) : ", i);
    scanf("%s", team2_player[i].name);
}
for(i=1; i<=no_players; i++)
{
    printf("Player %d for Team1 : %s\n", i, team2_player[i].name);
}

printf("Enter the number of overs : ");
scanf("%d", &overs);

re:
printf("Which Team is batting first?\n");
printf("\n1. %s\n2. %s\n",Team1,Team2);
scanf("%d",&toss);
switch(toss){
    case 1:
    printf("Team 1 is batting first");
    batting_team = team1_player;
    first_inning(Team1);
    bat_first=1;
    break;
    case 2:
    printf("Team 2 is batting first");
    batting_team = team2_player;
    first_inning(Team2);
    bat_first=2;

    break;
    default:
    printf("Enter a valid choice!");
    goto re;
}

if (target>0){
    if(bat_first==1){
        batting_team=team2_player;
        second_inning(Team2,Team1);
        }
else{
    batting_team = team1_player;
    second_inning(Team1,Team2);
}
}
}
void first_inning(char teamX[50]){
    batting_team[striker].runs=0;
    batting_team[striker].balls_faced=0;
    batting_team[striker].fours=0;
    batting_team[striker].sixes=0;
    batting_team[striker].strike_rate=0;

    striker=current_batsman;
    runs=0, wicket=0;
    player_bowled=0;
    bowled=overs*6;
    score=0;
    int i, r, scorer;
    printf(":--------------First Innings----------------\n");
    for(i=0;i!=bowled; i++)
    {
     Label:
        printf("Last ball...");
        printf("\n[1]Normal delivery\n[2]No ball/wide\n");
        scanf("%d",&scorer);
        printf("\nRuns on last ball\n");
        printf("[0]Dot ball\n[1]1 run\n[2]2 runs\n[3]3 runs\n[4]4 \n[5]6\n[6]Wicket!\n");
        scanf("%d",&r);
        switch (scorer)
{   case 1:
    player_bowled+=1;
    if(player_bowled%6==0){
    strikeRotation();
    current_over+=0.5;
    }
    else{
        current_over+=0.1;
    }
    break;
    case 2:
    score+=1;
default:
goto Label;
    break;
}
switch (r)
{
case 0:
    batting_team[striker].balls_faced++;
    break;
case 1:
    score+=1;
    batting_team[striker].runs++;
    batting_team[striker].balls_faced++;
    strikeRotation();
    break;
case 2:
    score+=2;
    batting_team[striker].runs+=2;
    batting_team[striker].balls_faced++;
    break;
case 3:
    score+=3;
    batting_team[striker].runs+=3;
    batting_team[striker].balls_faced++;
    strikeRotation();
    break;
case 4:
    score+=4;
    batting_team[striker].runs+=4;
    batting_team[striker].balls_faced++;
    batting_team[striker].fours++;
    break;
case 5:
    score+=6;
    batting_team[striker].runs+=6;
    batting_team[striker].balls_faced++;
    batting_team[striker].sixes++;
    break;
case 6:
    wicket+=1;
    if(wicket==1)
    {
        current_batsman=3;
        striker=current_batsman;
    }
    else{
        current_batsman++;
        striker=current_batsman;
    }
    break;
    

default:
    printf("Enter a valid choice!");
    goto Label;
    break;
}  
 runrate=((float)score/(float)player_bowled)*6;
 printf(":--------------First Innings----------------\n");
 printf("Inning 1|");
    printf("\nSCORE---%s|%d-%d|\t\t |overs:- %.1f|",teamX,score,wicket,current_over);
    printf("\n %s %d(%d)",batting_team[striker].name, batting_team[striker].runs, batting_team[striker].balls_faced);
    printf("\n %s %d(%d)",batting_team[non_striker].name, batting_team[non_striker].runs, batting_team[non_striker].balls_faced);
    printf("\n RR:-%.2f",runrate);

 getch();
 system("cls");

 if(wicket==no_players-1 || player_bowled==bowled)
 {
    inning=2;
    if(inning==2)
    {
        target=score+1;
        printf("target is %d",target);
    }
    break;
 }
}   
    }


int second_inning(char teamX[50], char teamY[50]){
    batting_team[striker].runs=0;
    batting_team[striker].balls_faced=0;
    batting_team[striker].fours=0;
    batting_team[striker].sixes=0;
    batting_team[striker].strike_rate=0;
    current_batsman=1;
    non_striker=2;
    striker=current_batsman;
    runs=0, wicket=0;
    player_bowled=0;
    bowled=overs*6;
    current_over=0;
    score=0;
    int i, r, scorer;
    printf(":--------------Second Inning----------------\n");
    for(i=0;i!=bowled; i++)
    {
     Label:
        printf("Last ball...");
        printf("\n[1]Normal delivery\n[2]No ball/wide\n");
        scanf("%d",&scorer);
        printf("\nRuns on last ball\n");
        printf("[0]Dot ball\n[1]1 run\n[2]2 runs\n[3]3 runs\n[4]4 \n[5]6\n[6]Wicket!\n");
        scanf("%d",&r);
        switch (scorer)
{   case 1:
    player_bowled+=1;
    if(player_bowled%6==0){
    strikeRotation();
    current_over+=0.5;
    }
    else{
        current_over+=0.1;
    }
    break;
    case 2:
    score+=1;
default:
goto Label;
    break;
}
switch (r)
{
case 0:
    batting_team[striker].balls_faced++;
    break;
case 1:
    score+=1;
    batting_team[striker].runs++;
    batting_team[striker].balls_faced++;
    strikeRotation();
    break;
case 2:
    score+=2;
    batting_team[striker].runs+=2;
    batting_team[striker].balls_faced++;
    break;
case 3:
    score+=3;
    batting_team[striker].runs+=3;
    batting_team[striker].balls_faced++;
    strikeRotation();
    break;
case 4:
    score+=4;
    batting_team[striker].runs+=4;
    batting_team[striker].balls_faced++;
    batting_team[striker].fours++;
    break;
case 5:
    score+=6;
    batting_team[striker].runs+=6;
    batting_team[striker].balls_faced++;
    batting_team[striker].sixes++;
    break;
case 6:
    wicket+=1;
    if(wicket==1)
    {
        current_batsman=3;
        striker=current_batsman;
    }
    else{
        current_batsman++;
        striker=current_batsman;
    }
    break;
    

default:
    printf("Enter a valid choice!");
    goto Label;
    break;
}  
 runrate=((float)score/(float)player_bowled)*6;
 printf(":--------------Second Innings----------------\n");
 printf("Inning 1|");
    printf("\nSCORE---%s|%d-%d|\t\t |overs:- %.1f|",teamX,score,wicket,current_over);
    printf("\n %s %d(%d)",batting_team[striker].name, batting_team[striker].runs, batting_team[striker].balls_faced);
    printf("\n %s %d(%d)",batting_team[non_striker].name, batting_team[non_striker].runs, batting_team[non_striker].balls_faced);
    printf("\n RR:-%.2f",runrate);

 getch();
 system("cls");

 if(wicket==no_players-1||player_bowled==bowled||score>=target)
 {
    if(score>=target)
    {
        printf("%s Won the match", teamX);
    }
    else if(score==target-1)
    {
        printf("Match is drawn.");
    }
    else{
        printf("%s Won the match", teamY);
    }
 }
    }
}