#ifndef UTILS_H
#define UTILS_H

#include "headers.h"

int is_valid_countdown(const char *arg);

void parse_time_remaining_countdown(int argc, char *argv[], int* time_remaining);

void parse_break_time_countdown(int argc, char* argv[], int* break_time);

#endif
