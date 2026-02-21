#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void parse_flags(int, char**);
int get_option();
//void parse_option(int);
void cli_homepage();
void new_desk();
void open_desks();
void desk_opts();
void list_notes();

#include <string.h>
void parse_flags(int argc, char** argv){
  if(argc > 1){
    if(strcmp(argv[1], "-v") == 0) printf("cnotes version 0.0\n");
  }
}

int get_option(){
  int opt;
  printf("Option: ");
  scanf("%d", &opt);
  return opt;
}

void parse_option(int opt){
  switch(opt){
    case 1:
      list_notes();
      
      break;
    default:
      printf("Option isnt supported as of now\n");
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

void list_notes(){
  system("clear");
  printf("─────────────────────────────────────────────────────────────────────\n");
  printf("Options: 1 - Open Note; 2 - Delete Note; 3 - New note; 4 - Go back\n");
  
#include <dirent.h>
  #define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"
DIR *d;
  struct dirent *dir;
  d = opendir("./DEFAULT/");
  if (d) {
    while (((dir = readdir(d)) != NULL)) {
      if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
      printf("\t - ");
      printf(COLOR_BOLD "%s\n" COLOR_OFF, dir->d_name);
      }
    }
    closedir(d);
  }
  int opt = get_option();
}

#endif
