#ifndef PHILO_H
#define PHILO_H

//DEFINES

#define PHILO_MAX 200
#define MIN_MEALS_NOT_SET (-1)

//EXIT STATUSES
#define SUCCESS 0

#define ERR_ATOI 1
#define MSG_ATOI "Atoi error."

#define ERR_MUTEX_INIT 2
#define MSG_MUTEX_INIT "Error initializing mutex."

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
    int min_meals;
};

struct s_philo
{
    int id;
    pthread_t thread;
    time_t last_meal_time;
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
bool correct_input(int argc, char **argv);

//validators
bool incorrect_num_of_args(int argc);
bool not_only_digits(char *str);
bool wrong_num_philos(int i, int curr_arg);

//helpers
bool is_digit(int c);
int my_atoi(const char *str);

//conversion to ms
time_t s_to_ms(time_t s);
time_t us_to_ms(time_t us);

//get time in ms
time_t get_time_in_ms(void);

//can prepare dinner
void set_dinner_start_time(t_dinner *dinner);
void set_dinner_status(t_dinner *dinner);
void set_dinner_rules(t_dinner *dinner, int argc, char **argv);
bool can_initialize_forks(t_dinner *dinner);

//error handling
void report_and_set_error(t_dinner *dinner, int code, char *msg);

#endif
