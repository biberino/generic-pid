#ifndef PID_GUARD
#define PID_GUARD

/** Generic PID controller
 * 
 * This code is free for usage and modifications.
 * Use it wisely at our own risk.
 * 
 * 
 * all times are in milliseconds
 * TODO: usage
 */

struct pid_controller_t
{
    unsigned long last_time;
    double output;
    double setpoint;
    double i_term;
    double last_input;
    double kp, ki, kd;
    int sample_time;
    double out_min;
    double out_max;
};

void pid_compute(struct pid_controller_t *p, unsigned long current_millis, double input);

void pid_set_tunings(struct pid_controller_t *p, double kp, double ki, double kd);

void pid_set_sample_time(struct pid_controller_t *p, int new_sample_time);

void pid_set_current_time(struct pid_controller_t *p, int millis);

void pid_set_output_limits(struct pid_controller_t *p, double min, double max);

void pid_init_controller(struct pid_controller_t *p);

void pid_set_setpoint(struct pid_controller_t *p, double value);
#endif // PID_GUARD
