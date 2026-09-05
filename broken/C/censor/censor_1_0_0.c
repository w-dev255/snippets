#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <fcntl.h>

typedef struct {
	char* input_buffer;
	int input_buffer_len;

	char* output_buffer;
	int output_buffer_len;

	char* word;
	int word_len;
} DATA;

