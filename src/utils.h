#ifndef UTILS_H_
#define UTILS_H_

#define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"

int get_option();

int get_option(){
  int opt;
  printf("Option: ");
  scanf("%d", &opt);
  return opt;
}

#endif
