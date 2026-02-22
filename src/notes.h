#ifndef NOTES_H_
#define NOTES_H_


#include "utils.h"

void list_notes();
void parse_option(int);
void read_note();
void delete_note();
void edit_note_attr();

void list_notes(){
  system("clear");
  printf("─────────────────────────────────────────────────────────────────────\n");
  printf("Options: 1 - Open Note; 2 - Delete Note; 3 - Edit note attributes; 4 Go back\n");

  DIR *d;
  struct dirent *dir;
  d = opendir("./DEFAULT/");
  if (d) {
    int count = 1;
    while (((dir = readdir(d)) != NULL)) {
      if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
        printf("\t - %d ", count);
        printf(COLOR_BOLD "%s\n" COLOR_OFF, dir->d_name);
        count++;
      }
    }
    closedir(d);
  }
  int opt = get_option();
  switch(opt){

    case 1:
      printf("Note index: ");
      int opt1;
      scanf("%d", &opt1);
      //-------------------------------------------- needs to read file by index

      //read_note();
      break;
    case 2:
      delete_note();
      break;
    case 3:
      edit_note_attr();
  }
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

void read_note(){
  printf("Opening note (READONLY)...");
}
void delete_note(){
  printf("Deleting note...");
}
void edit_note_attr(){
  printf("Editing note mode...");
}

#endif
