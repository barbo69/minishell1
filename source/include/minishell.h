/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-baptiste.barbotin
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

////////////////////////////////
////////// INCLUDES ////////////
////////////////////////////////

#include "my.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////
/////// GLOBAL VARIABLES ///////
////////////////////////////////


////////////////////////////////
//////////// MACROS ////////////
////////////////////////////////


////////////////////////////////
////////// STRUCTURES //////////
////////////////////////////////

typedef struct linked_list {
    char *info;
    struct linked_list *prev;
    struct linked_list *next;
}linked_list_t;

////////////////////////////////
////////// PROTOTYPES  /////////
////////////////////////////////

//////// prompt.c /////////

char **prompt_control(int *error);
char **get_op_arg(char *buffer);

/////// shell_loop.c ////////

int shell_loop_control(char **env);

/////// shell_signal.c ////////

void shell_signal_control();

/////// environment.c  ////////

void put_env(linked_list_t *env_list);
linked_list_t *env_in_linked_list(char **env);

/////// set_env.c /////////////

void set_env(linked_list_t *env_list, char **op_arg);

/////// unset_env.c ///////////

void unset_env(linked_list_t **env_list, char **op_arg);

/////// linked_list.c ////////

linked_list_t *linked_list_create(int nb);
linked_list_t *search_var(linked_list_t *env_list, char *env);
char **env_list_to_env(linked_list_t *env_list);

////// execution_control.c //////

void execution_control(char **op_arg, linked_list_t *env_list);

////// cd_commmand.c ///////////

int cd_command(char **op_arg, linked_list_t *env_list, char **old_pwd);
int check_folder(char *path);
char *refresh_pwd(char *op_arg, linked_list_t *pwd, char **old_pwd);

////// cd_commmand_back.c ///////////

void go_back(linked_list_t *pwd, char **old_pwd);

#endif /* !MINISHELL_H_ */