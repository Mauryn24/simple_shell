#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_commands(char **arguements);
void create_childProcess(char **arguements);
char **get_tokens(char *input, ssize_t bytes_read, char **arguements);
char *handle_path(char *command);

void builtin_exit(char **arr);
int _atoi(char *s);
void freed(char **arr);

#endif
