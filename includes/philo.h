#ifndef PHILO_H
#define PHILO_H

//DEFINES

#define PHILO_MAX 200
#define MIN_MEALS_NOT_SET (-1)

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

#endif
