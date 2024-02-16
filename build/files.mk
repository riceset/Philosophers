FILES = dinner/prepare_dinner/helpers/assign_forks.c \
dinner/prepare_dinner/helpers/can_initialize_forks.c \
dinner/prepare_dinner/helpers/can_initialize_print_mutex.c \
dinner/prepare_dinner/helpers/can_initialize_stop_mutex.c \
dinner/prepare_dinner/helpers/initialize_dinner_status.c \
dinner/prepare_dinner/helpers/initialize_philosophers.c \
dinner/prepare_dinner/helpers/set_dinner_rules.c \
dinner/prepare_dinner/helpers/set_dinner_start_time.c \
dinner/prepare_dinner/can_prepare_dinner.c \
dinner/end_dinner.c \
dinner/start_dinner.c \
handlers/allign_start_times.c \
handlers/life_check_and_wait.c \
handlers/print_philo_status.c \
handlers/report_and_set_error.c \
input_validation/validators/helpers/is_digit.c \
input_validation/validators/helpers/my_atoi.c \
input_validation/validators/can_convert_str_to_int.c \
input_validation/validators/incorrect_num_args.c \
input_validation/validators/not_only_digits.c \
input_validation/validators/wrong_num_philos.c \
input_validation/correct_input.c \
mutex_protection/check_safely.c \
mutex_protection/update_safely.c \
routines/philo_actions/fork_actions/release_forks.c \
routines/philo_actions/fork_actions/take_forks.c \
routines/philo_actions/eat.c \
routines/philo_actions/rest.c \
routines/philo_actions/think.c \
routines/lonely_philosopher.c \
routines/philo_routine.c \
routines/supervisor_routine.c \
threads/can_create_thread.c \
threads/can_join_thread.c \
time/conversion_to_ms.c \
time/get_time_in_ms.c \
main.c

SRC_DIR = sources
OBJ_DIR		=	objects

SRCS		=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
