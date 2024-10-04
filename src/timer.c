#include "../include/timer.h"
#include "../include/utils.h"

int time_remaining = 3600;
int break_time = 1800;
gboolean running = FALSE;
gint timer_id = 0;
gboolean on_break = FALSE;

void initial_setup(int argc, char* argv[]){
  parse_time_remaining_countdown(argc, argv, &time_remaining);
  parse_break_time_countdown(argc, argv, &break_time);
}

void activate_on_break(){
  on_break = TRUE;
}

void deactivate_on_break(GtkWidget *widget, gpointer user_data){
  if(on_break){

    on_break = FALSE;
  
    ArgData *arg_data = (ArgData *)user_data;
    int argc = arg_data->argc;
    char **argv = arg_data->argv;

 
    parse_break_time_countdown(argc, argv, &break_time);
  }
}

gboolean update_timer(gpointer label) {
  if (time_remaining > 0 && !on_break) {
    time_remaining--;

    if(break_time > 1) break_time--;
    else on_break = TRUE;

    char time_str[32];
    snprintf(time_str, sizeof(time_str), "%02d:%02d - %02d:%02d", time_remaining / 60, time_remaining % 60, break_time / 60, break_time % 60);
    gtk_label_set_text(GTK_LABEL(label), time_str);
    return TRUE;
  }

  if (on_break) {
    break_time++;
    char time_str[32];
    snprintf(time_str, sizeof(time_str), "%02d:%02d - %02d:%02d", time_remaining / 60, time_remaining % 60, break_time / 60, break_time % 60);
    gtk_label_set_text(GTK_LABEL(label), time_str);
  } else {
    printf("Break finished. Resuming countdown...\n");
  }
  return TRUE;
}

void start_timer(GtkWidget *widget, gpointer label) {
  if (!running) {
    timer_id = g_timeout_add(1000, update_timer, label);
    running = TRUE;
  }
}

void stop_timer(GtkWidget *widget, gpointer label) {
  if (running) {
    g_source_remove(timer_id);
    running = FALSE;
  }
}

