#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node_s {
    int machine;
    int time;
    struct node_s* next;
} node_t;

typedef struct {
    int processCount;
    node_t* processList;
} job_t;

node_t* createNode(int machine, int time);
void freeJobList(job_t* jobs, int jobCount);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    job_t* jobs = (job_t*)malloc(sizeof(job_t) * M);
    for (int i = 0; i < M; i++) {
        int P;
        scanf("%d", &P);
        jobs[i].processCount = P;
        jobs[i].processList = NULL;

        node_t* lastNode = NULL;
        for (int j = 0; j < P; j++) {
            int machine, time;
            scanf("%d %d", &machine, &time);
            node_t* newNode = createNode(machine, time);
            if (lastNode == NULL) {
                jobs[i].processList = newNode;
            } else {
                lastNode->next = newNode;
            }
            lastNode = newNode;
        }
    }

    int* machineFreeTime = (int*)calloc(N, sizeof(int));
    int* jobEndTime = (int*)calloc(M, sizeof(int));

    int totalCompletedJobs = 0;
    while (totalCompletedJobs < M) {
        int minCompleteTime = INT_MAX;
        int selectedJob = -1;
        node_t* selectedProcess = NULL;

        for (int i = 0; i < M; i++) {
            if (jobs[i].processList != NULL) {
                node_t* process = jobs[i].processList;
                int startTime = (jobEndTime[i] > machineFreeTime[process->machine]) ? jobEndTime[i] : machineFreeTime[process->machine];
                int completeTime = startTime + process->time;

                if (completeTime < minCompleteTime) {
                    minCompleteTime = completeTime;
                    selectedJob = i;
                    selectedProcess = process;
                }
            }
        }

        if (selectedJob != -1 && selectedProcess != NULL) {
            jobEndTime[selectedJob] = minCompleteTime;
            machineFreeTime[selectedProcess->machine] = minCompleteTime;
            jobs[selectedJob].processList = selectedProcess->next;
            if (jobs[selectedJob].processList == NULL) {
                totalCompletedJobs++;
            }
        }
    }

    int totalTime = 0;
    for (int i = 0; i < M; i++) {
        totalTime += jobEndTime[i];
    }

    printf("%d\n", totalTime);

    freeJobList(jobs, M);
    free(machineFreeTime);
    free(jobEndTime);
    return 0;
}

node_t* createNode(int machine, int time) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->machine = machine;
    newNode->time = time;
    newNode->next = NULL;
    return newNode;
}

void freeJobList(job_t* jobs, int jobCount) {
    for (int i = 0; i < jobCount; i++) {
        node_t* current = jobs[i].processList;
        while (current != NULL) {
            node_t* next = current->next;
            free(current);
            current = next;
        }
    }
    free(jobs);
}
