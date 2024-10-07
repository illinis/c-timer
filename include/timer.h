#ifndef TIMER_H
#define TIMER_H

#include "headers.h"

typedef struct {
  int argc;
  char** argv;
} ArgData;

typedef struct {
  GtkWidget *label;
  GtkWidget *window;
} AppData;

enum Action {
  START = 0,
  BREAK,
  PAUSE
};

void initial_setup(int argc, char* argv[]);

void change_action(int new_action);

void terminate_action_log();

void activate_on_break();

void deactivate_on_break();

gboolean update_timer(gpointer user_data);

void start_timer(GtkWidget *widget, gpointer user_data);

void stop_timer(GtkWidget *widget, gpointer label);

#endif
