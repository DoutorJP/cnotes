/* 
 * main.h
 * only for functions and definitions intended to be used exclusively by main.c
 */


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "notes.h"

void parse_flags(int, char**);
void cli_homepage();
void new_desk();
void open_desks();
void desk_opts();

void parse_flags(int argc, char** argv){
  if(argc > 1){
    if(strcmp(argv[1], "-v") == 0) printf("cnotes version 0.0\n");
  }
}


void desk_opts(){
  printf("Options:\n\t1 - New desk\n\t2 - Desks\n");
  printf("\n\nOption: ");
  int opt = get_option();
  //parse_option(opt);

}

void cli_homepage(){
  system("clear");
  while(1){
  printf("Wellcome to CNOTES - your minimal terminal based note keeping system!\n");
  printf("─────────────────────────────────────────────────────────────────────\n");
  printf("Current desk: DEFAULT\n");
  printf("Options:\n\t1 - List Notes\n\t2 - New note\n");
  int opt = get_option();
  parse_option(opt); 
  }
}


void new_desk(){
  puts("New desk name (single word while on beta):");
  char name[256];
  scanf("%s", name);
  struct stat st = {0};

  if (stat(name, &st) == -1) {
    mkdir(name, 0700);
    printf("Created desk \"%s\"...", name);
  }
}

void open_desks(){
  printf("─────────────────────────────────────────────────────────────────────\n");
  printf("Current desks:\n");
  printf("Options:\n\t1 - Go back\n");
//list_desks();
  printf("Option: ");
  int opt;
  scanf("%d", &opt);
  printf("─────────────────────────────────────────────────────────────────────\n");
}



#endif
