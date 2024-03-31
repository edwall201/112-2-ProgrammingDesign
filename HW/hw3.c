#include <stdio.h>

int main()
{
    int player[5], base[3]={0}, count_zero = 0, points=0;
    scanf("%d", &player[0]);
    scanf("%d", &player[1]);
    scanf("%d", &player[2]);
    scanf("%d", &player[3]);
    scanf("%d", &player[4]);

    // count the out players
    if (player[0] == 0) {
        count_zero++;
    }
    if (player[1] == 0) {
        count_zero++;
    }
    if (player[2] == 0) {
        count_zero += 1;
        if (count_zero == 3){
            player[0] = 0;
            player[1] = 0;
            count_zero -=3;
        }
    }
    if (player[3] == 0) {
        count_zero += 1;
        if (count_zero == 3){
            player[0] = 0;
            player[1] = 0;
            player[2] = 0;
            count_zero -=3;
        }
    }
    if (player[4] == 0) {
        count_zero += 1;
        if (count_zero == 3){
            player[0] = 0;
            player[1] = 0;
            player[2] = 0;
            player[3] = 0;
            count_zero -=3;
        }
        
    }

    // calculate the base
    if (player[1] > 0){
        if (player[0] != 0){
            player[0] += player[1];
        }

    }
    if (player[2] > 0){
        if (player[0] != 0){
            player[0] += player[2];
        }
        if (player[1] != 0){
            player[1] += player[2];
        }
    }
    if (player[3] > 0){
        if (player[0] != 0){
            player[0] += player[3];
        }
        if (player[1] != 0){
            player[1] += player[3];
        }
        if (player[2] != 0){
            player[2] += player[3];
        }
    }
    if (player[4] > 0){
        if (player[0] != 0){
            player[0] += player[4];
        }
        if (player[1] != 0){
            player[1] += player[4];
        }
        if (player[2] != 0){
            player[2] += player[4];
        }
        if (player[3] != 0){
            player[3] += player[4];
        }
    }

    // count the points
    if (player[0] >= 4) {
        points++;
        player[0] = 0;
    }

    if(player[0] != 0){
        int temp = player[0];
        base[temp-1] = 1;
        printf("%d\n", player[0]);
    }

    if (player[1] >= 4) {
        points++;
        player[1] = 0;
    }else if(player[1] != 0){
        int temp = player[1];
        base[temp-1] = 1;
    }

    if (player[2] >= 4) {
        points++;
        player[2] = 0;
    }else if(player[2] != 0){
        int temp = player[2];
        base[temp-1] = 1;
    }

    if (player[3] >= 4) {
        points++;
        player[3] = 0;
    }else if(player[3] != 0){
        int temp = player[3];
        base[temp-1] = 1;
    } 

    if (player[4] >= 4) {
        points++;
        player[4] -= 4;
    }else if(player[4] != 0){
        int temp = player[4];
        base[temp-1] = 1;
    } 

    printf("%d\n", points);
    // printf("%d %d %d %d %d\n", player[0], player[1], player[2], player[3],player[4]);
    printf("%d %d %d\n", base[0], base[1], base[2]);


    return 0;
}