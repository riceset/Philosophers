all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR) $(TESTS_DIR)/*.o

fclean:
	$(RM) $(OBJ_DIR) $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re
