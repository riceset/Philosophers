#ifndef PHILO_H
#define PHILO_H

//DEFINES

#define PHILO_MAX 200
#define MIN_MEALS_NOT_SET (-1)

//EXIT STATUSES
#define SUCCESS 0

#define ERR_NUM_ARGS 1
#define MSG_NUM_ARGS "Incorrect number of arguments."

#define ERR_NOT_ONLY_DIGITS 2
#define MSG_NOT_ONLY_DIGITS "Not only digits."

#define ERR_ATOI 3
#define MSG_ATOI "Atoi error."

#define ERR_NUM_PHILOS 4
#define MSG_NUM_PHILOS "Wrong number of philosophers."

#define ERR_MUTEX_INIT 5
#define MSG_MUTEX_INIT "Error initializing mutex."

#define ERR_THREAD_CREATE 6
#define MSG_THREAD_CREATE "Error creating thread."

#define ERR_THREAD_JOIN 7
#define MSG_THREAD_JOIN "Error joining thread."
//INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <limits.h>
#include <stdbool.h>

#include <pthread.h>
#include <sys/time.h>

//TYPEDEFS
typedef struct s_rules t_rules;
typedef struct s_philo t_philo;
typedef struct s_dinner t_dinner;

//STRUCTS

struct s_rules
{
    int philo_count;
    int lifespan;
    int dining_duration;
    int rest_duration;
    unsigned int min_meals;
};

struct s_philo
{
    int id;
    pthread_t thread;
    unsigned int forks[2];
    time_t last_meal_time;
    unsigned int times_eaten;
    pthread_mutex_t times_eaten_mutex;
    t_dinner *dinner;
};

struct s_dinner
{
	time_t start_time;
	t_rules rules;
  int exit_status;
	t_philo philos[PHILO_MAX];
	pthread_mutex_t forks[PHILO_MAX];
};

//PROTOTYPES

//validation
bool correct_input(t_dinner *dinner, int argc, char **argv);

//validators
bool incorrect_num_of_args(int argc);
bool not_only_digits(char *str);
bool wrong_num_philos(int i, int curr_arg);
bool can_convert_str_to_int(t_dinner *dinner, const char *str, int *res);

//helpers
bool is_digit(int c);
int my_atoi(const char *str);

//conversion to ms
time_t s_to_ms(time_t s);
time_t us_to_ms(time_t us);

//get time in ms
time_t get_time_in_ms(void);

//can prepare dinner
bool can_prepare_dinner(t_dinner *dinner, int argc, char **argv);

void set_dinner_start_time(t_dinner *dinner);
void set_dinner_status(t_dinner *dinner);
void set_dinner_rules(t_dinner *dinner, int argc, char **argv);
bool can_initialize_forks(t_dinner *dinner);
void initialize_philosophers(t_dinner *dinner);

// dinner
void start_dinner(t_dinner *dinner);
void end_dinner(t_dinner *dinner);

// routine
void *philo_routine(void *arg);

//error handling
void report_and_set_error(t_dinner *dinner, int code, char *msg);

#endif
