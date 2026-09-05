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

	size_t bytes;
	int err;
} IO;

typedef struct {
	const char* word;
	size_t word_len;
} WORD;

typedef struct {
	char* ptr;
	char* occurence_start;
	char* occurence_end;
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
