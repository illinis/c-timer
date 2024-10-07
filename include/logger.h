#ifndef LOGGER_H
#define LOGGER_H

#include "headers.h"

typedef struct { 
  char* timer;
  char* break_timer;
  const char *message;
} LoggerData;

void output_divider();

void output_header(LoggerData logger_data, char* timestamp);

void output_line(char* action, char* time_spent);

void init_logger();

void terminate_logger();

#endif
