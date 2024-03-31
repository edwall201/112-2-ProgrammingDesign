#include <stdio.h>
int count_points(int state, int points)
{
    state = state>>3;
    if (state&1)
    {
        points++;
    }
    state = state >>1;
    if (state&1)
    {
        points++;
    }
    state = state >>1;
    if (state&1)
    {
        points++;
    }
    state = state >>1;
    if (state&1)
    {
        points++;
    }
    return points;
}

int main() {
    int state=0, input=0, points=0, out = 0;

    scanf("%d", &input);
    if (input == 0){
        out ++;
    }
    state = (state <<input) | (1<<(input-1));
    points = count_points(state, points);
    state = state&7;

    scanf("%d", &input);
    if (input == 0){
    out ++;
    }
    state = (state <<input) | (1<<(input-1));
    points = count_points(state, points);
    state = state&7;

    scanf("%d", &input);
    if (input == 0){
        out ++;
    }
    if(out == 3)
    {
        state=0, input=0, out = 0;
    }
    state = (state <<input) | (1<<(input-1));
    points = count_points(state, points);
    state = state&7;

    scanf("%d", &input);
    if (input == 0){
        out ++;
    }
    if(out == 3)
    {
        state=0, input=0, out = 0;
    }
    state = (state <<input) | (1<<(input-1));
    points = count_points(state, points);
    state = state&7;

    scanf("%d", &input);
    if (input == 0){
        out ++;
    }
    if(out == 3)
    {
        state=0, input=0, out = 0;
    }
    state = (state <<input) | (1<<(input-1));
    points = count_points(state, points);
    state = state&7;

    printf("%d\n", points);
    printf("%d %d %d\n", state&1, (state>>1)&1, (state>>2)&1);
}