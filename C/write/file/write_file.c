#include <stdio.h>

#include <stdlib.h>

#include <fcntl.h>

#include <string.h>

#include <errno.h>

#include <unistd.h>

typedef struct {
	char* end_ptr;
	char* ptr;
	int base;
	long int size;
} BUFFER_SIZE;

typedef struct {
	char* buffer;
	BUFFER_SIZE* buffer_size;
} BUFFER;

int main(int argc, char* argv[]) {
	if (argc == 5) {
		errno = 0;

		if (strcmp(argv[2], "-b") != 0) {
			printf("Usage: <program_name> <content> -b <buffer_size> <output_path>\n");

			return 1;
		}

		BUFFER* buf = calloc(1, sizeof(BUFFER));
		if (buf == NULL) {
			return 1;
		}

		buf->buffer_size = calloc(1, sizeof(BUFFER_SIZE));
		if (buf->buffer_size == NULL) {
			free(buf);

			return 1;
		}

		buf->buffer_size->ptr = argv[3];
		buf->buffer_size->base = 10;
		buf->buffer_size->size = strtol(buf->buffer_size->ptr, &buf->buffer_size->end_ptr, buf->buffer_size->base);
		if (buf->buffer_size->end_ptr == buf->buffer_size->ptr) {
			free(buf->buffer_size);
			free(buf);

			printf("%s\n", strerror(errno));

			return errno;
		}

		if (buf->buffer_size->size < 0) {
			free(buf->buffer_size);
			free(buf);

			printf("The buffer size cannot be negative.\n");

			return 1;
		}

		if (errno == ERANGE) {
			free(buf->buffer_size);
			free(buf);

			printf("%s\n", strerror(errno));

			return errno;
		}

		buf->buffer = malloc(buf->buffer_size->size);
		if (buf->buffer == NULL) {
			free(buf->buffer_size);
			free(buf);

			return 1;
		}
		memset(buf->buffer, 0, buf->buffer_size->size);
		if ((strlen(argv[1]) + 1) > buf->buffer_size->size) {
			free(buf->buffer_size);
			free(buf->buffer);
			free(buf);

			printf("Buffer too small.\n");

			return 1;
		}

		memmove(buf->buffer, argv[1], (strlen(argv[1]) + 1));

		int fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1) {
			free(buf->buffer_size);
			free(buf->buffer);
			free(buf);

			printf("%s\n", strerror(errno));

			return 1;
		}

		ssize_t byte = write(fd, buf->buffer, (strlen(argv[1]) + 1));

		if (byte < 0) {
			free(buf->buffer_size);
			free(buf->buffer);
			free(buf);
			close(fd);

			printf("%s\n", strerror(errno));

			return errno;
		}
		if (byte < (strlen(argv[1]) + 1)) {
			free(buf->buffer_size);
			free(buf->buffer);
			free(buf);
			close(fd);

			printf("%s\n", strerror(errno));

			return errno;
		}

		close(fd);
		free(buf->buffer_size);
		free(buf->buffer);
		free(buf);

		return 0;
	} else {
		printf("Usage: <program_name> <content> -b <buffer_size> <output_path>\n");

		return 1;
	}

	return 0;
}

