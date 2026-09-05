#include <fcntl.h>

#include <string.h>

#include <unistd.h>

#include <stdlib.h>

#include <errno.h>

typedef struct {
	char* input_path;
	char* output_path;
} PATH;

typedef struct {
	char* blacklisted_word;
	int len;
} BLACKLIST;

typedef struct {
	char* buffer;
	int buffer_size;
	char current_chr;
	int byte_counter;
} INPUT;

typedef struct {
	char* buffer;
	int buffer_size;
	char current_char;
	int byte_counter;
} OUTPUT;

typedef struct {
	PATH* path;
	BLACKLIST* blacklist;
	INPUT* input;
	OUTPUT* output;
} BUFFER;

/*int read_input_file(BUFFER* buffer) {
	if (buffer == NULL) {
		return 1;
	}

	if (buffer->input == NULL) {
		return 1;
	}

	if (buffer->input->buffer == NULL) {
		return 1;
	}

	if (buffer->path == NULL) {
		return 1;
	}

	if (buffer->path->input_path == NULL) {
		return 1;
	}

	if (buffer->input->buffer_size == 0) {
		return 1;
	}

	int fd = open(buffer->path->input_path, O_RDONLY);
	if (fd == -1) {
		return errno;
	}

	ssize_t byte = read(fd, buffer->input->buffer, buffer->input->buffer_size);
	if (byte > 0 || byte == 0) {
		close(fd);

		return 0;
	}

	if (byte < 0) {
		close(fd);

		return errno;
	}

	close(fd);
	return 0;
}*/

int censure(BUFFER* buffer) {
	if (buffer == NULL) {
		return 1;
	}

	if (buffer->input == NULL) {
		return 1;
	}

	if (buffer->output == NULL) {
		return 1;
	}

	if (buffer->path == NULL) {
		return 1;
	}

	if (buffer->input->buffer == NULL) {
		return 1;
	}

	if (buffer->path->input_path == NULL) {
		return 1;
	}

	if (buffer->input->buffer_size == 0) {
		return 1;
	}

	int byte = 0;
	int counter = 0;
	int match = 0;
	int black_counter = 0;

	int buffer_size = buffer->input->buffer_size;6
	int word_size = buffer->blacklist->len;

	/*int minium_match = (buffer->blacklist->len / 2);*/
	char* ptr = buffer->input->buffer;

	char* buffer_ptr = buffer->input->buffer;
	char* blacklist_ptr = buffer->blacklist->blacklisted_word;

	char* start = NULL;|

	while (1) {
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc == 7) {
		errno = 0;

		BUFFER* buf = calloc(1, sizeof(BUFFER));
		if (buf == NULL) {
			printf("%s\n", strerror(errno));

			return errno;
		}

		buf->blacklist = calloc(1, sizeof(BLACKLIST));
		if (buf->blacklist)  {
			free(buf);

			printf("%s\n", strerror(errno));

			return errno;
		}

		buf->blacklist->blacklisted_word = argv[2];
		buf->blacklist->len = (strlen(buf->blacklist->blacklisted_word) + 1);

		buf->input = calloc(1, sizeof(INPUT));
		if (buf->input == NULL) {
			free(buf);

			printf("%s\n", strerror(errno));

			return errno;
		}

		buf->output = calloc(1, sizeof(OUTPUT));
		if (buf->output == NULL) {
			free(buf->input);
			free(buf);

			printf("%s\n", strerror(errno));

			return errno;
		}

		buf->path = calloc(1, sizeof(PATH));
		if (buf->path == NULL) {
			free(buf->input);
			free(buf->output);
			free(buf);

			printf("%s\n", strerror(errno));

			return errno;
		}

		buf->input->input_byte = 2;
		buf->output->output_byte = 2;

		buf->input->buffer_size = buf->input->input_byte;
		buf->output->buffer_size = buf->output->output_byte;

		buf->input->buffer = malloc(buf->input->buffeqr_size);
		if (buf->buffer == NULL) {
			free(buf->input);
			free(buf->output);
			free(buf);

			return 1;
		}

		buf->output->buffer = malloc(buf->output->buffer_size);
		if (buf->output->buffer == NULL) {
			free(buf->input->buffer);
			free(buf->input);
			free(buf->output);
			free(buf);

			return 1;
		}

		buf->path->input_path = argv[4];
		buf->path->output_path = argv[6];

		memset(buf->input->buffer, 0, buf->input->buffer_size);
		memset(buf->output->buffer, 0, buf->output->buffer_size);

		int input_data = read_input_file(buf);
		if (input_data < 0) {
			free(buf->input->buffer);
			free(buf->output->buffer);
			free(buf->input);
			free(buf->output);
			free(buf->path);
			free(buf);

			printf("%s\n", strerror(errno));

			return errno;
		}

		int output_fd = open(output_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (output_fd == -1) {
			close(input_fd);
			free(buf->buffer);
			free(buf);

			printf("%s\n", strerror(errno));

			return errno;
		}

		while(1) {
			int black_counter = 0;

			char* input_ptr = buf->input->buffer;
			char* target_ptr = buf->blacklist->blacklisted_word;

			int found = 0;

			int perfect_match = buf->blacklist->len;
			for (int i = 0; i < buf->input->buffer_size; i++) {
				if ((input_ptr[i] != target_ptr[black_counter]) && (i < buf->input->buffer_size)) {
					continue;
				} else {
					black_counter++;
				}

				if (black_counter == buf->blacklist->len) {
					while ((*input_ptr) == (*target_ptr)) {
						(*input_ptr) = '#';

						input_ptr--;
						target_ptr--;
					}
				}
			}

			buf->output->output_byte = read(output_fd, buf->output->buffer, buf->output->buffer_size);

			if (output_byte < 0) {
				close(input_fd);
				close(output_fd);
				free(buf->input->buffer);
				free(buf->output->buffer);
				free(buf->input);
				free(buf->output);
				free(buf);

				printf("%s\n", strerror(errno));

				return 1;
			}
			if (output_byte == 0) {
				break;
			}
			if (output_byte > 0) {
				buf->output->output_byte++;

				buf->output->buffer_size = buf->output->buffer_size = buf->output->output_byte;

				buf->output->buffer = realloc(buf->output->buffer, buf->output->buffer_size);
				if (buf->output->buffer == NULL) {
					close(input_fd);
					close(output_fd);
					free|(buf->input->buffer);
					free(buf->output->buffer);
					free(buf->input);
					free(buf->output);
					free(buf);

					printf("%s\n", strerror(errno));

					return errno;
				}
			}
		}
	} else {
		printf("Usage: <program_name> -w <word> -f <input_path> -o <output_path>\n");

		return 1;
	}
}
