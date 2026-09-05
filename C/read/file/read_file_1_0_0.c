#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <fcntl.h>

#define BUFFER_SIZE 5000

int main(int argc, char* argv[]) {
	if (argc == 2) {
		int fd = open(argv[1], O_RDONLY);
		if (fd == -1) {
			return 1;
		}

		char* buffer = malloc(BUFFER_SIZE);
		if (buffer == NULL) {
			close(fd);

			return 1;
		}
		memset(buffer, 0, BUFFER_SIZE);

		ssize_t len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0) {
			close(fd);
			free(buffer);

			return 1;
		} else if (len == 0) {
			printf("The file is empty.\n");

			close(fd);
			free(buffer);

			return 0;
		} else if (len == BUFFER_SIZE) {
			printf("Cannot null-terminate buffer safely.\n");

			close(fd);
			free(buffer);

			return 1;
		}
		buffer[len] = '\0';

		printf("%s\n", buffer);

		close(fd);
		free(buffer);

		return 0;
	} else {
		printf("Execute the program with:\n	./program_name <file_path>\n");

		return 1;
	}

	return 0;
}
