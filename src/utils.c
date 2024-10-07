#include "../include/utils.h"

int is_valid_countdown(const char *arg) {
  for (int i = 0; arg[i] != '\0'; i++) {
    if (!isdigit(arg[i])) {
      return 0;
    }
  }
  return 1;
}

void parse_time_remaining_countdown(int argc, char *argv[], int* time_remaining) {
  if (argc < 2) {
    printf("No initial countdown provided, using default of 60 minutes.\n");
    *(time_remaining) = 3600; 
  } else if (is_valid_countdown(argv[1])) {
    int minutes = atoi(argv[1]);
    if (minutes > 0) {
      *(time_remaining) = minutes * 60;
    } else {
      printf("Invalid countdown time. Using default of 60 minutes.\n");
    }
  } else {
    printf("Invalid countdown argument. Please provide a positive integer (minutes).\n");
    exit(EXIT_FAILURE);
  }
}

void parse_break_time_countdown(int argc, char* argv[], int* break_time) {
  if (argc < 3) {
    printf("No initial break countdown provided, using default of 10 minutes.\n");
    *(break_time) = 600;
  } else {
    if (is_valid_countdown(argv[2])) {
      int minutes = atoi(argv[2]);
      if (minutes > 0) {
        *(break_time) = minutes * 60;
      }
    } else {
      printf("Invalid break time argument. Please provide a positive integer (minutes).\n");
      exit(EXIT_FAILURE);
    }
  }

}

void create_directory(const char *dir_path) {
  mode_t mode = 0755;
  int result = mkdir(dir_path, mode);

  if (result != 0 && errno != EEXIST) {
    perror("Error creating directory");
    exit(EXIT_FAILURE);
  }
}

char* get_current_date(){
  time_t current_date = time(NULL);
  struct tm tm = *localtime(&current_date);    

  char *current_date_str = malloc(64 * sizeof(char));
  if (current_date_str == NULL) {
    perror("Failed to allocate memory for current_date_str");
    exit(EXIT_FAILURE);
  }
  snprintf(current_date_str, 64, "%d-%02d-%02d-%02d:%02d:%02d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  return current_date_str;
}

char* get_current_time(){
  time_t current_time = time(NULL);
  struct tm tm = *localtime(&current_time);
  
  char *current_time_str = malloc(32 * sizeof(char));
  if (current_time_str == NULL) {
    perror("Failed to allocate memory for current_time_str");
    exit(EXIT_FAILURE);
  } 
  snprintf(current_time_str, 32, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    
  return current_time_str;
} 


char* get_current_action(int action){
  switch(action){
    case 0:
      return "START";
      break;
    case 1:
      return "BREAK";
      break;
    case 2:
      return "PAUSE";
      break;
    default:
      return "INVALID";
      break;
  }
}

