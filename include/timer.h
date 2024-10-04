#ifndef TIMER_H
#define TIMER_H

#include "headers.h"

typedef struct {
  int argc;
  char** argv;
} ArgData;


void initial_setup(int argc, char* argv[]);

void activate_on_break();

void deactivate_on_break();

gboolean update_timer(gpointer label);

void start_timer(GtkWidget *widget, gpointer label);

void stop_timer(GtkWidget *widget, gpointer label);

#endif
