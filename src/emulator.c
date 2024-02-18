#include "./libs/clock.h"
#include "./libs/utils.h"
#include "./libs/runtime.h"

int main(int argc, char **argv)
{
    // ********************** THREADING ************************

    // Initialize mutex for multithreading
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    // Create clock thread
    pthread_t clockThread;

    // Create thread for clock workload
    if (pthread_create(&clockThread, NULL, (void *)perform_workload, NULL) != 0)
    {
        perror("Error creating workload thread");
        return 1;
    }

    // ********************** END OF THREADING ************************

    // Force trhead to finish and destroy it
    terminateClockThread = true;
    pthread_join(clockThread, NULL);

    // Cleanup
    pthread_mutex_destroy(&mutex);
}