#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *test1;

  test1 = new_matrix(4, 4);
  test1->lastcol = 4;
  printf("testing print matrix....\n");
  print_matrix(test1);
  ident(test1);
  printf("testing ident matrix....\n");
  print_matrix(test1);
  scalar_mult(2.0,test1);
  printf("testing scalar mult....\n");
  print_matrix(test1);

  printf("printing matrix #2....\n");
  struct matrix *test2;
  test2 = new_matrix(4, 2);
  test2->lastcol = 2;
  int r = 0;
  int co = 0;
  int i = 0;
  for(r=0; r< test2->rows; r++){
    for(co=0; co < test2->lastcol; co++){
      test2->m[r][co] = i;
      i++;
    }
  }
  print_matrix(test2);
  printf("testing matrix mult....\n");
  matrix_mult(test1,test2);
  print_matrix(test2);
  printf("end matrix function testing....\n");
  printf("printing matrix to be drawn....\n");
  struct matrix *edges;
  edges = new_matrix(4, 2);
  add_edge(edges,20,20,0,0,10,0);
  add_edge(edges,10,20,0,20,10,0);
  add_edge(edges,10,10,20,10,0,0);
  add_edge(edges,0,20,0,10,0,0);
  print_matrix(edges);

  color c;


  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  draw_lines(edges,s,c);
  printf("printing new matrix to be drawn....\n");
  scalar_mult(25,edges);
  print_matrix(edges);

    draw_lines(edges,s,c);

  save_extension(s, "matrix.png");
  display(s);
  
  free_matrix( test1);
  free_matrix( test2);
    free_matrix( edges);
  
  
}  
