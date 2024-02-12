#ifndef PHILO_H
#define PHILO_H

//DEFINES

#define PHILO_MAX 200
#define MIN_MEALS_NOT_SET (-1)

//EXIT STATUSES
#define SUCCESS 0
#define ERR_MUTEX_INIT 1
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

#endif
