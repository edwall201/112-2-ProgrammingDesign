#include <stdio.h>

#define GATEVALUE(Gate) int(*GateValue)()
typedef struct _Gate {
    int input1;
    int input2;
    GATEVALUE(Gate);
} Gate;

int GateORValue(Gate *gate) {
    return gate->input1 || gate->input2;
}

int GateANDValue(Gate *gate) {
    return gate->input1 && gate->input2;
}

int GateNOTValue(Gate *gate) {
    return !gate->input1;
}

int GateBUFFERValue(Gate *gate) {
    return gate->input1;
}

void CreateGate(Gate *obj, char type, int input1, int input2) {
    obj->input1 = input1;
    obj->input2 = input2;
    if (type == 'A') {
        obj->GateValue = GateANDValue;
    } else if (type == 'O') {
        obj->GateValue = GateORValue;
    } else if (type == 'N') {
        obj->GateValue = GateNOTValue;
    } else if (type == 'B') {
        obj->GateValue = GateBUFFERValue;
    }
}

int main() {
    int X1, X2, X3;
    char P, Q, R;
    scanf("%d %d %d ", &X1, &X2, &X3);
    scanf("%c %c %c", &P, &Q, &R);
    Gate P_Gate, Q_Gate, R_Gate;
    CreateGate(&P_Gate, P, X1, 0);
    int Y1 = P_Gate.GateValue(&P_Gate);
    CreateGate(&Q_Gate, Q, X2, Y1);
    int Y2 = Q_Gate.GateValue(&Q_Gate);
    CreateGate(&R_Gate, R, X3, Y2);
    int Y3 = R_Gate.GateValue(&R_Gate);
    printf("%d %d %d\n", Y1, Y2, Y3);
    return 0;
}