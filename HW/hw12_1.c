#include <stdio.h>
int count_points(int state, int points)
{
    state = state >> 3;
    if (state & 1)
    {
        points++;
    }
    state = state >> 1;
    if (state & 1)
    {
        points++;
    }
    state = state >> 1;
    if (state & 1)
    {
        points++;
    }
    state = state >> 1;
    if (state & 1)
    {
        points++;
    }
    return points;
}

int main()
{
    // int state=0, input=0, points=0, out = 0;

    char base_temp[45];
    int base[45];
    int player[9];
    int count = 0, zero_count = 0, time_sum = 0;

    for (int i = 0; i < 9; i++)
    {
        int time;
        scanf("%d", &time);
        player[i] = time;
        for (int j = 0; j < time; j++)
        {
            scanf("%s", &base_temp[count]);
            count += 1;
        }
        time_sum += time;
    }
    scanf("%d", &zero_count);

    // Change to correct base
    int index = 0, temp = 0;
    for (int i = 0; i < player[0]; i++)
    {
        if (base_temp[i] == 'O')
        {
            base[index++] = 0;
        }
        else if (base_temp[i] == 'H')
        {
            base[index++] = 4;
        }
        else
        {
            base[index++] = base_temp[i] - '0';
        }

        // base[index++] = base_temp[i];
        temp = i;
        for (int j = 0; j < 8; j++)
        {
            temp += player[j];
            if (base_temp[temp] == 'O')
            {
                base[index++] = 0;
            }
            else if (base_temp[temp] == 'H')
            {
                base[index++] = 4;
            }
            else
            {
                base[index++] = base_temp[temp] - '0';
            }

            // base[index++] = base_temp[temp];
        }
        if (index == time_sum)
        {
            break;
        }
    }

    // count points
    int state = 0, points = 0,points_temp_1 = 0, points_temp_2 = 0,  out = 0, current_player = 0, last_player = 0;
    int running[9] = {0};
    for (int i = 0; i < time_sum; i++)
    {
        points_temp_2 = points;
        if (zero_count == 0)
        {
            break;
        }
        if (base[i] == 0)
        {
            out += 1;
            zero_count -= 1;
            
        }else{
            if(points_temp_1 == points_temp_2){
                for (int j = last_player; j <= i; j++)
                {
                    if (base[j] == 0)
                    {
                        continue;
                    }
                    
                    current_player = (j) % 9;
                    printf("aa %d +%d\n", current_player, base[i]);
                    running[current_player] += base[i];   
                }
            }else{
                for (int j = last_player+(points_temp_2 - points_temp_1); j < i; j++)
                {
                    if (base[j] == 0)
                    {
                        continue;
                    }
                    current_player = (j) % 9;
                    printf("bb %d +%d\n", current_player, base[i]);
                    running[current_player] += base[i];   
                }
            }
            
            
            
        }
        // printf("%d\n", base[i]);
        if (out == 3)
        {
            out = 0;
            state = 0;
            last_player = i+1;
            continue;
        }
       
        state = (state << base[i]) | (1 << (base[i] - 1));
        points_temp_1 = points;
        points = count_points(state, points);
        state = state & 7;
    }

    printf("%d\n", points);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", running[i]);
    }
    

    return 0;

}

// 12OOOO12O1O1O1OO1221O22H21%
// 1200001211010100122102242