#ifndef CLOCK_H
#define CLOCK_H
#include <stdbool.h>
#include <pthread.h>

// #define TARGET_OPS_PER_SEC 10000

// Global vars for sync between threads
pthread_mutex_t mutex;
long long int loopCounter = 0;
int operationsCounter = 0;
bool terminateClockThread = false;

// Funtion to use processor time and set a more consistent clock
void perform_workload()
{
    while (!terminateClockThread)
    {

        for (int i = 0; i < 58000; ++i)
        {
        }

        pthread_mutex_lock(&mutex);
        operationsCounter++;
        pthread_mutex_unlock(&mutex);
    }
}

// void sleep(int seconds)
// {
//     struct timespec req = {seconds, 0};
//     struct timespec rem = {0, 0}; // Remaining time unused, but it is still necessary for nanosleep
//     while (nanosleep(&req, &rem) == -1)
//     {
//         // If interrupted, sleep again with remaining time
//         req = rem;
//     }
// }

#endif