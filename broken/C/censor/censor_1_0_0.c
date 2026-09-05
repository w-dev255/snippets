#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <fcntl.h>

typedef struct {
	char* input_buffer;
	size_t input_buffer_len;
	char* input_path;
	int err;
} INPUT;

typedef struct {
	char* output_buffer;
	size_t output_buffer_len;
	char* output_path;
	int err;
} OUTPUT;

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
	INPUT* input;
	OUTPUT* output;
	WORD* word;
	PARSE* parse;
} DATA;

