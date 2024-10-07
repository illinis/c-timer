#include "../include/timer.h"
#include "../include/utils.h"
#include "../include/logger.h"

int time_remaining = 3600;
int break_time = 1800;
int action_timer = 0;

gboolean running = FALSE;
gint timer_id = 0;
gboolean on_break = FALSE;

void initial_setup(int argc, char* argv[]){
  LoggerData logger_data;
  
  parse_time_remaining_countdown(argc, argv, &time_remaining);
  parse_break_time_countdown(argc, argv, &break_time);

  char time_str[16];
  snprintf(time_str, sizeof(time_str), "%02d:%02d", time_remaining / 60, time_remaining % 60);
  logger_data.timer = time_str;
  
  char break_time_str[16];
  snprintf(break_time_str, sizeof(break_time_str), "%02d:%02d", break_time / 60, break_time % 60);
  logger_data.break_timer = break_time_str;

  init_logger();
  output_header(logger_data);
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

gboolean update_timer(gpointer user_data) {
  AppData *app_data = (AppData *)user_data;
  GtkWidget *label = app_data->label;

  if (time_remaining > 0 && !on_break) {
    time_remaining--;
    action_timer++;

    if(break_time > 1) break_time--;
    else {
      on_break = TRUE;
      
      
      GdkDisplay *display = gdk_display_get_default();
      if (display != NULL) {
        gdk_display_beep(display);
      }
      gtk_window_present(GTK_WINDOW(app_data->window));
    }

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

void start_timer(GtkWidget *widget, gpointer user_data) {
  AppData *app_data = (AppData *)user_data;
  if (!running) {
    timer_id = g_timeout_add(1000, update_timer, app_data);
    running = TRUE;
  }
}

void stop_timer(GtkWidget *widget, gpointer label) {
  if (running) {
    g_source_remove(timer_id);
    running = FALSE;
  }
}

