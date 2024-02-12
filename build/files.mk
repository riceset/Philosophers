SRC_DIR 	= sources
OBJ_DIR		=	objects

SRCS = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)
