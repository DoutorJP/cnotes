#ifndef NOTES_H_
#define NOTES_H_


#include "utils.h"
#include "config.h"

void list_notes();
void parse_option(int);
void read_note(char*);
void delete_note(char*);
void edit_note_attr();

void list_notes(){
  system("clear");
  printf("─────────────────────────────────────────────────────────────────────\n");
  printf("Options: 1 - Open Note; 2 - Delete Note; 3 - Edit note attributes; 4 Go back\n");
  printf("─────────────────────────────────────────────────────────────────────\n");


  //Opening and reading the contents of the dir_path defined on config.h

  DIR *d;
  struct dirent *dir;
  d = opendir(dir_path);
  char filenames[256][256];
  if (d) {
    int count = 0;
    while (((dir = readdir(d)) != NULL)) {
      if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
        printf("\t - %d ", count);
        printf(COLOR_BOLD "%s\n" COLOR_OFF, dir->d_name);
        strcpy(filenames[count], dir->d_name);
        count++;
      }
    }
    closedir(d);
  }

  int opt = get_option();
  switch(opt){
int opt1;
    case 1:
      printf("Note index: ");
      scanf("%d", &opt1);
      printf("NOTE: %s\n", filenames[opt1]);
      read_note(filenames[opt1]);
      break;
    case 2:
      printf("Note index: ");

      scanf("%d", &opt1);
      delete_note(filenames[opt1]);
      break;
    case 3:
      edit_note_attr();
  }
  system("clear");
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

void read_note(char* fname){
  char command[512] = "less ";
  strcat(command, dir_path);
  strcat(command, fname);
  system(command);
  puts("\n\n\n\n");
  char c;
  scanf("%c", c);
}

void delete_note(char* fname){
  printf("Deleting note %s", fname);
  /*
  char command[512] = "rm ";
  strcat(command, dir_path);
  strcat(command, fname);
  system(command);
  puts("\n\n\n\n");
  */
  char c;
  scanf("%c", c);
}
void edit_note_attr(){
  printf("Editing note mode...");
}

#endif
