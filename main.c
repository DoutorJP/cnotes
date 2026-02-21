#include <stdio.h>
#include "src/functions.h" 


int main(int argc, char** argv){
  parse_flags(argc, argv);
  cli_homepage();
  
  return 0;
}

