#include <stdio.h>
int main()
{
    int score[3] = {0, 0, 0};
    int winGame[3] = {0, 0, 0};
    char team[3] = {'A', 'B', 'C'};
    int score1 = 0, score2 = 0, win, game = 0, temp = 0;
    scanf("%d", &game);
    for (int i = 0; i < game; i++){
        char team1, team2;
        scanf(" %c %c", &team1, &team2);
        int tempScore1 = 0, tempScore2 = 0;
        for (int l = 0; l < 4; l++)
        {
            scanf(" %d %d", &score1, &score2);
            if (team1 == 'A' ){
                score[0] +=score1;
                tempScore1 += score1;
            }
            else if(team2 == 'A'){
                score[0] +=score2;
                tempScore2 += score2;
            }
            if (team1 == 'B'){
                score[1] +=score1;
                tempScore1 += score1;
            }
            else if(team2 == 'B'){
                score[1] +=score2;
                tempScore2 += score2;
            }
            if (team1 == 'C'){
                score[2] +=score1;
                tempScore1 += score1;
            }
            else if(team2 == 'C'){
                score[2] +=score2;
                tempScore2 += score2;
            }

        }
        if (tempScore1 > tempScore2){
                if (team1 == 'A'){
                    winGame[0] += 1;
                }
                else if(team1 == 'B'){
                    winGame[1] += 1;
                }
                else if(team1 == 'C'){
                    winGame[2] += 1;
                }
        }else{
                if (team2 == 'A'){
                    winGame[0] += 1;
                }
                else if(team2 == 'B'){
                    winGame[1] += 1;
                }
                else if(team2 == 'C'){
                    winGame[2] += 1;
                }                
        }

    }   

    for (int i = 0; i < 3; i++){
        if (winGame[i] > winGame[temp]){
            temp = i;
        }
    }
    printf("%c\n", team[temp]);
    printf("%d\n", score[temp]); 
}