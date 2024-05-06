#include <stdio.h>
#include <string.h>
// 定義枚舉型別和聯合型別
typedef enum scoreType_s { G, GPA, S } scoreType_t;

typedef enum G_s { Aplus, A, Aduce, Bplus, B, Bduce, Cplus, C, Cduce, F, X } G_t;

typedef enum GPA_s { b4dot3, b4dot0, b3dot7, b3dot3, b3dot0, b2dot7, b2dot3, b2dot0, b1dot7, b1, b0 } GPA_t;

typedef enum S_s { b90to100, b85to89, b80to84, b77to79, b73to76, b70to72, b67to69, b63to66, b60to62, b1to59, b0to0 } S_t;

typedef union student_s {
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
} student_t;

// 計算百分制分數的函數
int calculatePercentageScore(scoreType_t type, student_t student_score) {
    int percentage_score = 0;
    switch (type) {
        case G:
            switch (student_score.G) {
                case Aplus:
                    percentage_score = 95;
                    break;
                case A:
                    percentage_score = 87;
                    break;
                case Aduce:
                    percentage_score = 82;
                    break;
                case Bplus:
                    percentage_score = 78;
                    break;
                case B:
                    percentage_score = 75;
                    break;
                case Bduce:
                    percentage_score = 70;
                    break;
                case Cplus:
                    percentage_score = 68;
                    break;
                case C:
                    percentage_score = 65;
                    break;
                case Cduce:
                    percentage_score = 60;
                    break;
                case F:
                    percentage_score = 50;
                    break;
                case X:
                    percentage_score = 0;
                    break;
            }
            break;
        case GPA:
            switch (student_score.GPA) {
                case b4dot3:
                    percentage_score = 95;
                    break;
                case b4dot0:
                    percentage_score = 87;
                    break;
                case b3dot7:
                    percentage_score = 82;
                    break;
                case b3dot3:
                    percentage_score = 78;
                    break;
                case b3dot0:
                    percentage_score = 75;
                    break;
                case b2dot7:
                    percentage_score = 70;
                    break;
                case b2dot3:
                    percentage_score = 68;
                    break;
                case b2dot0:
                    percentage_score = 65;
                    break;
                case b1dot7:
                    percentage_score = 60;
                    break;
                case b1:
                    percentage_score = 50;
                    break;
                case b0:
                    percentage_score = 0;
                    break;
            }
            break;
        case S:
            switch (student_score.S) {
                case b90to100:
                    percentage_score = 95;
                    break;
                case b85to89:
                    percentage_score = 87;
                    break;
                case b80to84:
                    percentage_score = 82;
                    break;
                case b77to79:
                    percentage_score = 78;
                    break;
                case b73to76:
                    percentage_score = 75;
                    break;
                case b70to72:
                    percentage_score = 70;
                    break;
                case b67to69:
                    percentage_score = 68;
                    break;
                case b63to66:
                    percentage_score = 65;
                    break;
                case b60to62:
    
                    percentage_score = 60;
                    break;
                case b1to59:
                    percentage_score = 50;
                    break;
                case b0to0:
                    percentage_score = 0;
                    break;
            }
            break;
    }
    return percentage_score;
}

int main() {
    int M, N;
    scanf("%d", &M);
    scoreType_t course_types[M];
    for (int i = 0; i < M; i++) {
        char type[10];
        scanf("%s", type);
        if (type[0] == 'G' && type[1] == '\0') {
            course_types[i] = G;
        } else if (type[0] == 'G' && type[1] == 'P') {
            course_types[i] = GPA;
        } else {
            course_types[i] = S;
        }
    }
    scanf("%d", &N);
    student_t student_data[N][M];
    int student_ids[N];
    char grade[3];
    char gpa[5];
    char score[10];
    for (int i = 0; i < N; i++) {
        scanf("%d", &student_ids[i]);
        
        for (int j = 0; j < M; j++) {
            if (course_types[j] == G) {
                scanf("%s", grade);
                if (strcmp(grade, "A+") == 0) student_data[i][j].G = Aplus;
                else if (strcmp(grade, "A") == 0) student_data[i][j].G = A;
                else if (strcmp(grade, "A-") == 0) student_data[i][j].G = Aduce;
                else if (strcmp(grade, "B+") == 0) student_data[i][j].G = Bplus;
                else if (strcmp(grade, "B") == 0) student_data[i][j].G = B;
                else if (strcmp(grade, "B-") == 0) student_data[i][j].G = Bduce;
                else if (strcmp(grade, "C+") == 0) student_data[i][j].G = Cplus;
                else if (strcmp(grade, "C") == 0) student_data[i][j].G = C;
                else if (strcmp(grade, "C-") == 0) student_data[i][j].G = Cduce;
                else if (strcmp(grade, "F") == 0) student_data[i][j].G = F;
                else if (strcmp(grade, "X") == 0) student_data[i][j].G = X;
            } else if (course_types[j] == GPA) {
                scanf(" %s", gpa);
                if (strcmp(gpa, "4.3") == 0) student_data[i][j].GPA = b4dot3;
                else if (strcmp(gpa, "4.0") == 0) student_data[i][j].GPA = b4dot0;
                else if (strcmp(gpa, "3.7") == 0) student_data[i][j].GPA = b3dot7;
                else if (strcmp(gpa, "3.3") == 0) student_data[i][j].GPA = b3dot3;
                else if (strcmp(gpa, "3.0") == 0) student_data[i][j].GPA = b3dot0;
                else if (strcmp(gpa, "2.7") == 0) student_data[i][j].GPA = b2dot7;
                else if (strcmp(gpa, "2.3") == 0) student_data[i][j].GPA = b2dot3;
                else if (strcmp(gpa, "2.0") == 0) student_data[i][j].GPA = b2dot0;
                else if (strcmp(gpa, "1.7") == 0) student_data[i][j].GPA = b1dot7;
                else if (strcmp(gpa, "1") == 0) student_data[i][j].GPA = b1;
                else if (strcmp(gpa, "0") == 0) student_data[i][j].GPA = b0;
                
            } else {
                scanf("%s", score);
                if (strcmp(score, "90-100") == 0) {
                    student_data[i][j].S = b90to100;
                } else if (strcmp(score, "85-89") == 0) {
                    student_data[i][j].S = b85to89;
                } else if (strcmp(score, "80-84") == 0) {
                    student_data[i][j].S = b80to84;
                } else if (strcmp(score, "77-79") == 0) {
                    student_data[i][j].S = b77to79;
                } else if (strcmp(score, "73-76") == 0) {
                    student_data[i][j].S = b73to76;
                } else if (strcmp(score, "70-72") == 0) {
                    student_data[i][j].S = b70to72;
                } else if (strcmp(score, "67-69") == 0) {
                    student_data[i][j].S = b67to69;
                } else if (strcmp(score, "63-66") == 0) {
                    student_data[i][j].S = b63to66;
                } else if (strcmp(score, "60-62") == 0) {
                    student_data[i][j].S = b60to62;
                } else if (strcmp(score, "1-59") == 0) {
                    student_data[i][j].S = b1to59;
                } else if (strcmp(score, "0") == 0) {
                    student_data[i][j].S = b0to0;
                }
            }
        }
    }

    int average_scores[N];
    for (int i = 0; i < N; i++) {
        int total_score = 0;
        for (int j = 0; j < M; j++) {
            total_score += calculatePercentageScore(course_types[j], student_data[i][j]);
        }
        average_scores[i] = total_score / M;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (average_scores[j] > average_scores[j + 1]) {
                float temp_score = average_scores[j];
                average_scores[j] = average_scores[j + 1];
                average_scores[j + 1] = temp_score;

                int temp_id = student_ids[j];
                student_ids[j] = student_ids[j + 1];
                student_ids[j + 1] = temp_id;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", student_ids[i], average_scores[i]);
    }

    return 0;
}
