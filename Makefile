CC = clang

CFLAGS = -Wall -Werror -Wextra -Wpedantic

all: wallace.c
	@echo "Compiling ... "
	@$(CC) $(CFLAGS) wallace.c -o wallace
	@echo "Done"

run: wallace
	@./wallace

clean:
	@echo "Cleaning ... "
	@rm wallace
	@echo "Done"
