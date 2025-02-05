#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
char team1[50];
char team2[50];
int score1;
int score2;
int overs1;
int overs2;
} Match;

void HomePage()
{
        printf("Homepage:\n");
        printf("1. Local Match Scores\n");
        printf("2. Live Matches\n");
        printf("3. Previous Matches\n");
        printf("4. Upcoming Matches\n");
        printf("5. Ongoing Tournaments\n");
        printf("6. Previous Tournaments\n");
        printf("7. Upcoming Tournaments\n");
        printf("8. Menu\n");
        printf("9. Exit\n");
}

void openWebsite(const char* url) {
#ifdef _WIN32

    const char* command = "start";
#elif __APPLE__

    const char* command = "open";
#else
    const char* command = "xdg-open";
#endif

    char fullCommand[256];
    snprintf(fullCommand, sizeof(fullCommand), "%s %s", command, url);

    int result = system(fullCommand);

    if (result == 0) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command execution failed.\n");
    }
}

void LocalMatchScore() {
}

void displayLiveMatches() {
    const char* url = "https://www.cricbuzz.com/cricket-match/live-scores";
    openWebsite(url);
}

void displayPreviousMatches() {
    const char* url = "https://www.cricbuzz.com/cricket-scorecard-archives";
    openWebsite(url);
}

void displayUpcomingMatches() {
    const char* url = "https://www.cricbuzz.com/cricket-schedule";
    openWebsite(url);
}

void displayOngoingTournaments() {
    const char* url = "https://www.cricbuzz.com/cricket-series";
    openWebsite(url);
}

void displayPreviousTournaments() {
    const char* url = "https://www.cricbuzz.com/cricket-series";
    openWebsite(url);
}

void displayUpcomingTournaments() {
    const char* url = "https://www.cricbuzz.com/cricket-schedule";
    openWebsite(url);
}

void displayLatestNews() {
    const char* url = "https://www.cricbuzz.com/cricket-news";
    openWebsite(url);
}

void Players() {
    const char* url = "https://www.espncricinfo.com/ci/content/player/index.html";
    openWebsite(url);
}

void Ranks() {
    const char* url = "https://www.espncricinfo.com/rankings/content/page/211271.html";
    openWebsite(url);
}

void Highlights() {
    const char* url = "https://www.espncricinfo.com/ci/content/video_audio/index.html";
    openWebsite(url);
}

void PointTable() {
    const char* url = "https://www.espncricinfo.com/series/cwc19-1144415/points-table-standings";
    openWebsite(url);
}

void Series() {
    const char* url = "https://www.espncricinfo.com/ci/content/current/series/1131611.html";
    openWebsite(url);
}

void Schedule() {
    const char* url = "https://www.espncricinfo.com/ci/content/match/fixtures/index.html";
    openWebsite(url);
}

void PlayerRankingsMen(){
  const char* url = "https://www.icc-cricket.com/rankings/mens/player-rankings";
  openWebsite(url);
}

void PlayerRankingsWomen(){
printf("1. T20\n");
printf("2. ODI\n");
printf("3. TEST\n");
printf("4. Return Previous Menu\n");
}

void displayMenuOptions() {
    printf("Menu:\n");
    printf("1. Players\n");
    printf("2. Ranks (T20, ODI, Test)\n");
    printf("3. Highlights\n");
    printf("4. Point Table\n");
    printf("5. Series\n");
    printf("6. Schedule\n");
    printf("7. PlayerRankings (Men)\n");
    printf("8. PlayerRankings (Women)\n");
    printf("9. Go To Home Page\n");
}

int main() {
    while (true) {
        system("color 70");
        HomePage();
        int choice;
        int choice2;
        int rankChoiceMen;
        int rankChoiceWomen;

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                LocalMatchScore();
                break;
            case 2:
                displayLiveMatches();
                break;
            case 3:
                displayPreviousMatches();
                break;
            case 4:
                displayUpcomingMatches();
                break;
            case 5:
                displayOngoingTournaments();
                break;
            case 6:
                displayPreviousTournaments();
                break;
            case 7:
                displayUpcomingTournaments();
                break;
            case 8:
                do{
                displayMenuOptions();
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                switch(choice2)
                {
            case 1:
                Players();
                break;
            case 2:
                Ranks();
                break;
            case 3:
                Highlights();
                break;
            case 4:
                PointTable();
                break;
            case 5:
                Series();
                break;
            case 6:
                Schedule();
                break;
            case 7:do{
                PlayerRankingsMen();
                printf("Enter your choice: ");
                scanf("%d", &rankChoiceMen);
                const char* urlT20 = "https://www.icc-cricket.com/rankings/mens/player-rankings/t20i";
                const char* urlODI = "https://www.icc-cricket.com/rankings/mens/player-rankings/odi";
                const char* urlTest = "https://www.icc-cricket.com/rankings/mens/player-rankings/test";
                switch(rankChoiceMen)
                {
                    case 1:
                            openWebsite(urlT20);
                            break;
                    case 2:
                            openWebsite(urlODI);
                            break;
                    case 3:
                            openWebsite(urlTest);
                            break;

                }
            }while(rankChoiceMen<4);
                break;
            case 8:
                do{
                PlayerRankingsWomen();
                printf("Enter your choice: ");
                scanf("%d", &rankChoiceWomen);
                const char* urlT20 = "https://www.icc-cricket.com/rankings/womens/player-rankings/t20i";
                const char* urlODI = "https://www.icc-cricket.com/rankings/womens/player-rankings/odi";
                switch(rankChoiceWomen)
                {
                    case 1:
                            openWebsite(urlT20);
                            break;
                    case 2:
                            openWebsite(urlODI);
                            break;
                    case 3: printf("Sorry, women don't have Test ranking.\n");
                            break;
                }
                }while(rankChoiceWomen<4);
                break;
                }
                }while(choice2<9);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
