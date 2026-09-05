#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <fcntl.h>

typedef struct {
	char* buffer;
	size_t buffer_capacity;
	size_t buffer_len;

	char* path;
	int fd;

	size_t bytes_read;
	size_t bytes_written;
	int err;
} IO;

typedef struct {
	const char* word;
	size_t word_len;
} WORD;

typedef struct {
	char* current_char;
	char* occurence_start;
	char* occurence_end;
	size_t match;
} PARSE;

typedef struct {
	IO* input;
	IO* output;
	WORD* word;
	PARSE* parse;
} DATA;

void free_data(DATA* data) {
	if (!data) {
		return;
	}

	if (data->input) {
		if (data->input->buffer) {
			free(data->input->buffer);
		}
		if (data->input->fd > 0) {
			close(data->input->fd);
		}
		free(data->input);
	}

	if (data->output) {
		if (data->output->buffer) {
			free(data->output->buffer);
		}
		if (data->output->fd > 0) {
			close(data->output->fd);
		}
		free(data->output);
	}

	if (data->word) {
		free(data->word);
	}

	if (data->parse) {
		free(data->parse);
	}

	free(data);
}

int main(int argc, char* argv[]) {
	errno = 0;
	DATA* data = calloc(1, sizeof(DATA));
	if (!data) {
		printf("%s\n", strerror(errno));
		return errno;
	}

	data->input = calloc(1, sizeof(IO));
	if (!data->input) {
		printf("%s\n", strerror(errno));
		free_data(data);
		return errno;
	}

	data->output = calloc(1, sizeof(IO));
	if (!data->output) {
		printf("%s\n", strerror(errno));
		free_data(data);
		return errno;
	}

	data->word = calloc(1, sizeof(WORD));
	if (!data->word) {
		printf("%s\n", strerror(errno));
		free_data(data);
		return errno;
	}

	data->parse = calloc(1, sizeof(PARSE));
	if (!data->parse) {
		printf("%s\n", strerror(errno));
		free_data(data);
		return errno;
	}
}
