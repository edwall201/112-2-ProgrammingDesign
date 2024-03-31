#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int player_order;
    int hits;
    int runs;
} Player;

// CountScore(hit, bases, &score, &players[i], players, i);
// counting score and bases
void CountScore(char hit, int bases[4], int *score, Player *player, Player players[9], int current_player)
{
    int temp = 0;
    if (hit == 'H')
    {
        temp = 4;
    }
    else if (hit == 'O')
    {
        temp = 0;
    }
    else
    {
        temp = hit - '0';
    }

    if (temp > 0)
    {
        for (int i = 3; i >= 0; --i)
        {
            if (bases[i])
            {
                if (i + temp >= 4)
                {
                    players[bases[i] - 1].runs += (4 - i);
                    (*score)++;
                }
                else
                {
                    bases[i + temp] = bases[i];
                    players[bases[i] - 1].runs += temp;
                }
                bases[i] = 0;
            }
        }

        if (temp < 4)
        {
            bases[temp] = current_player + 1;
        }
        else
        {
            (*score)++;
        }

        player->runs += temp;
    }
}

int main()
{
    Player players[9];
    char hits[9][5];
    int bases[4] = {0}, hitCounts[9] = {0};
    int out, score = 0, outs = 0, Index = 0;

    for (int i = 0; i < 9; i++)
    {

        players[i].player_order = i + 1;
        players[i].hits = 0;
        players[i].runs = 0;
        scanf("%d", &hitCounts[i]);
        for (int j = 0; j < hitCounts[i]; j++)
        {
            scanf(" %c", &hits[i][j]);
        }
    }

    scanf("%d", &out);
    // counting score and base
    while (outs < out)
    {
        for (int i = 0; i < 9 && outs < out; i++)
        {
            if (Index < hitCounts[i])
            {
                char hit = hits[i][Index];
                if (hit == 'O')
                {
                    outs++;
                    if (outs % 3 == 0)
                    {
                        for (int j = 0; j < 4; j++)
                            bases[j] = 0;
                    }
                }
                else
                {
                    players[i].hits++;
                    CountScore(hit, bases, &score, &players[i], players, i);
                }
            }
        }
        Index++;
    }

    // ranking
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (players[j].runs > players[i].runs || (players[j].runs == players[i].runs && players[j].player_order < players[i].player_order))
            {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    printf("%d\n", score);
    for (int i = 0; i < 3; i++)
    {
        printf("%d %d %d\n", players[i].player_order, players[i].hits, players[i].runs);
    }

    return 0;
}
