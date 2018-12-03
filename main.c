
/**
 * Example usage of pid controller.
 * You can do everything with this program as you like.
 * Everything you do is your responsibility.
 * 
 * Make sure u pass floats or doubles to the controller where they are needed!
 */

#include "pid.h"

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

/**
 * This function returns the current time in milliseconds
 * and needs to be implemeted based on the mcu/os u want to use the pid
 * This implementation works on linux
 */
unsigned long get_current_millis()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
}

int main(int argc, char const *argv[])
{
    struct pid_controller_t controller;

    //INIT CONTROLLER
    pid_init_controller(&controller);
    pid_set_sample_time(&controller, 1000); // update every 1 sec
    pid_set_tunings(&controller, 0.1f, 0.3f, 0.1f);

    pid_set_output_limits(&controller, -300.0f, 300.0f);
    pid_set_current_time(&controller, get_current_millis());
    pid_set_setpoint(&controller, 200.0f);
    //END INIT



    float input = 0.0f;

    //in tihs example, the output should go to 190
    while (1)
    {
        input = controller.output + 10.0f;
        pid_compute(&controller, get_current_millis(), input);
        printf("out --> %f\n", controller.output);

        usleep(500000); //0.5 sec
    }

    return 0;
}
