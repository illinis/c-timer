# c-timer

## Description
The c-timer is a simple application that mimics a real timer. 
It should be used passing two arguments through the executable file: the first is the number of minutes which you want to study, work or focus without any interruptions; the second argument is kind of a 'second timer' that will run along the main one.
The second timer should be used as a 'break counter', as in Pomodoro's technique. It was originally thought to be a reminder to stretch the body, look outside the window, drink some water, etc.

The HUD/GUI is extremely minimalist once the purpose of the project is to have an alert about how much time has passed without causing any distractions to the user. The interface is composed by two counters as strings, one for each timer, and two buttons: start and stop;

C-timer is designed to beep an alert every break time. The application will also generate a log file containing the details of the time spent.

Every break time (that should be controlled by the user) will start again with the interaction with the <strong>start</strong> button.

## Requirements
The application uses the [GTK](https://www.gtk.org/) library, which is needed to run the project.
Once the user has this dependency installed, the application is ready to be compiled and used.

## Compiling and Running the Application

To compile the application it is only neeeded to run the <strong>makefile</strong>.

```bash
  $ make
```

After compiling the application, the binary executable should already exist in the <strong>bin</strong> directory.
The user can run the application executing the binary file:

```bash
  $ ./bin/timer arg1 arg2
```

One exemple of the correct execution of the application is:

```bash
  $ ./bin/timer 120 30
```
