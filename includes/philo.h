#ifndef PHILO_H
#define PHILO_H

//DEFINES

#define PHILO_MAX 200
#define MIN_MEALS_NOT_SET (-1)

#define MSG_NUM_ARGS "Incorrect number of arguments."
#define MSG_NOT_ONLY_DIGITS "Not only digits."
#define MSG_ATOI "Atoi error."
#define MSG_NUM_PHILOS "Wrong number of philosophers."
#define MSG_MUTEX_INIT "Error initializing mutex."
#define MSG_THREAD_CREATE "Error creating thread."
#define MSG_THREAD_JOIN "Error joining thread."

#define MSG_DEAD "died"
#define MSG_EATING "is eating"
#define MSG_SLEEPING "is sleeping"
#define MSG_THINKING "is thinking"
#define MSG_TAKING_FORK "has taken a fork"

//INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <limits.h>
#include <stdbool.h>

#include <pthread.h>
#include <sys/time.h>

//temporary
#include <string.h>

//TYPEDEFS
typedef struct s_rules t_rules;
typedef struct s_philo t_philo;
typedef struct s_dinner t_dinner;
typedef enum e_philo_status t_philo_status;
typedef enum e_exit_status t_exit_status;

//STRUCTS

struct s_rules
{
    time_t start_time;
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
    unsigned int times_eaten;
    time_t last_meal_time;
    t_dinner *dinner;
    pthread_mutex_t last_meal_time_mutex;
    pthread_mutex_t times_eaten_mutex;
};

struct s_dinner
{
	t_rules rules;
	t_philo philos[PHILO_MAX];
	pthread_mutex_t forks[PHILO_MAX];

  pthread_t supervisor;

  bool stop;
  pthread_mutex_t stop_mutex;

  int exit_status;
};

enum e_philo_status
{
  DEAD,
  EATING,
  SLEEPING,
  THINKING,
  TAKING_FORK
};

enum e_exit_status
{
  SUCCESS,
  ERR_NUM_ARGS,
  ERR_NOT_ONLY_DIGITS,
  ERR_ATOI,
  ERR_NUM_PHILOS,
  ERR_MUTEX_INIT,
  ERR_THREAD_CREATE,
  ERR_THREAD_JOIN
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

bool can_initialize_stop_mutex(t_dinner *dinner);
void set_dinner_start_time(t_dinner *dinner);
void initialize_exit_status(t_dinner *dinner);
void set_dinner_rules(t_dinner *dinner, int argc, char **argv);
bool can_initialize_forks(t_dinner *dinner);
void initialize_philosophers(t_dinner *dinner);
void assign_forks(t_philo *philo);

// dinner
void start_dinner(t_dinner *dinner);
void end_dinner(t_dinner *dinner);

// routine
void *philo_routine(void *arg);

void eat(t_philo *philo);
void rest(t_philo *philo);
void think(t_philo *philo);

void print_philo_status(t_philo *philo, t_philo_status status);
void life_check_and_wait(t_philo *philo, time_t duration);

//supervisor
void *supervisor_routine(void *arg);

//actions
void take_forks(t_philo *philo);
void release_forks(t_philo *philo);
void eat(t_philo *philo);
void rest(t_philo *philo);
void think(t_philo *philo);

//error handling
void report_and_set_error(t_dinner *dinner, int code, char *msg);

//check safely
bool check_stop_condition_safely(pthread_mutex_t *mutex, bool *stop_flag);
unsigned int check_times_eaten_safely(pthread_mutex_t *mutex, unsigned int *times_eaten);
time_t check_last_meal_time_safely(pthread_mutex_t *mutex, time_t *last_meal_time);

//update safely
void update_stop_condition_safely(pthread_mutex_t *mutex, bool *stop_flag, bool new_value);
void update_times_eaten_safely(pthread_mutex_t *mutex, unsigned int *times_eaten, unsigned int new_value);
void update_last_meal_time_safely(pthread_mutex_t *mutex, time_t *last_meal_time, time_t new_value);

#endif
