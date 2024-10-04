#include "../include/headers.h"

int main(int argc, char *argv[]) { 
    GtkWidget *window;
    GtkWidget *vbox;   
    GtkWidget *label;
    GtkWidget *start_button, *stop_button;
    
    ArgData *arg_data = malloc(sizeof(ArgData));
    arg_data->argc = argc;
    arg_data->argv = argv;
    
    int time_remaining_buffer;
    int break_time_buffer;
    
    parse_time_remaining_countdown(argc, argv, &time_remaining_buffer);
    parse_break_time_countdown(argc, argv, &break_time_buffer);
     
    initial_setup(argc, argv);

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "c-timer");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 360, 360);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    char time_str[32];
    snprintf(time_str, sizeof(time_str), "%02d:%02d - %02d:%02d", time_remaining_buffer / 60, time_remaining_buffer % 60, break_time_buffer / 60, break_time_buffer % 60);
    label = gtk_label_new(time_str);
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER); 
    gtk_widget_set_valign(label, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    

    start_button = gtk_button_new_with_label("Start");
    gtk_box_pack_start(GTK_BOX(vbox), start_button, TRUE, TRUE, 0);
    gtk_widget_set_halign(start_button, GTK_ALIGN_CENTER); 

    stop_button = gtk_button_new_with_label("Stop");
    gtk_box_pack_start(GTK_BOX(vbox), stop_button, TRUE, TRUE, 0);
    gtk_widget_set_halign(stop_button, GTK_ALIGN_CENTER); 
    
    AppData app_data = { label, window};
    
    g_signal_connect(start_button, "clicked", G_CALLBACK(start_timer), &app_data);
    g_signal_connect(start_button, "clicked", G_CALLBACK(deactivate_on_break), arg_data);
 
    g_signal_connect(stop_button, "clicked", G_CALLBACK(stop_timer), NULL);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

