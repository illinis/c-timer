#include "../include/logger.h"

static FILE *log_file = NULL;
int n = 1;

void output_divider(){
  if(log_file != NULL) {
    for(int i=0;i<150;++i) fprintf(log_file, "-");
    fprintf(log_file, "\n");  
  }
}

void output_header(LoggerData logger_data){
  if(log_file != NULL){
    char *timestamp = get_current_time();

    output_divider();

    fprintf(log_file, "DOCUMENT:\t%%%% %s-LOG-FILE %%%%\n", timestamp);
    fprintf(log_file, "SUBJECT:\t%%%% DEFAULT %%%%\n");
    fprintf(log_file, "DATE:\t%%%% [%s] %%%%\n", timestamp);
    fprintf(log_file, "AUTHOR:\t%%%% DEFAULT %%%%\n");

    output_divider(); 

    fprintf(log_file, "EXECUTION LOG - TIMER: %%%% %s %%%% - BREAK-TIMER: %%%% %s %%%%\n", logger_data.timer, logger_data.break_timer);

    output_divider();

    fprintf(log_file, "CURRENT TIME\t\t-\t\tACTION\t\t-\t\tTIME-SPENT\t\t-\t\tN\n");

    output_divider();
  }
}

void output_line(char* action, char* time_spent){
 if(log_file != NULL){
    char* timestamp = get_current_time();

    fprintf(log_file, "%%%% %s %%%%\t\t-\t\t%s\t\t-\t\t%%%% %s %%%%\t\t%d\n",timestamp, action, time_spent, n);
  } 
}

void init_logger(){
  create_directory("logs");
  
  char* filename;
  const char* filename_gen = "-LOG-FILE";

  char *timestamp = get_current_time();

  filename = timestamp;
  strcat(filename,filename_gen);

  char full_path[256];
  snprintf(full_path, sizeof(full_path), "%s/%s", "logs", filename);

  log_file = fopen(full_path, "a");
  if(log_file == NULL) {
    perror("Error generating log file.\n");
    exit(EXIT_FAILURE);
  }
  
}

void terminate_logger(){
  if(log_file != NULL) {
    output_divider();
    fclose(log_file);
  }
}
