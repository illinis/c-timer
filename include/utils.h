#ifndef UTILS_H
#define UTILS_H

#include "headers.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int is_valid_countdown(const char *arg);

void parse_time_remaining_countdown(int argc, char *argv[], int* time_remaining);

void parse_break_time_countdown(int argc, char* argv[], int* break_time);

void create_directory(const char *dir_path);

char* get_current_date();

char* get_current_time();

char* get_current_action(int action);

#endif
