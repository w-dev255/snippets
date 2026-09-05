#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <fcntl.h>

typedef struct {
	char* buffer;
	size_t buffer_capacity;

	char* input_path;
	int fd;

	size_t bytes;
	int err;
} IO;

typedef struct {
	char* word;
	int word_len;
} WORD;

typedef struct {
	char* ptr;
	char* start;
	char* end;
} PARSE;

typedef struct {
	IO* input;
	IO* output;
	WORD* word;
	PARSE* parse;
} DATA;

int main(int argc, char* argv[]) {
	errno = 0;
	DATA* data = calloc(1, sizeof(DATA));
	if (!data) {
		printf("%s\n", strerror(errno));
		return errno;
	}
}
