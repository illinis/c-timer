#ifndef LOGGER_H
#define LOGGER_H

#include "headers.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

typedef struct { 
  char* timer;
  char* break_timer;
  const char *message;
} LoggerData;

void create_directory(const char *dir_path);

char* get_current_time();

void output_divider();

void output_header(LoggerData logger_data, char* timestamp);

void output_line(char* action, char* time_spent);

void init_logger();

void terminate_logger();

#endif
