FILES			=	main.c \
						helpers/is_digit.c \
						helpers/my_atoi.c \
						input_validation/validators/incorrect_num_args.c \
						input_validation/validators/wrong_num_philos.c \
						input_validation/validators/not_only_digits.c \
						input_validation/correct_input.c \
						time/conversion_to_ms.c \
						time/get_time_in_ms.c

SRC_DIR 	= sources
OBJ_DIR		=	objects

SRCS			=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
