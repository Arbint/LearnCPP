#pragma once


//the extern keyword:
/***********************************************************************



***********************************************************************/
//with extern, extern int foo means only declare but not define foo, if
//it is int foo, the foo will also be defined. so:
// extern int foo; means int foo; declaration, no defination, no memory allocation, can exists multiple times.
//int foo; means int foo = 0; declaration and defination, memory has been allocated, can only exists once.
extern int fooTest;


void print_foo();
void print(int);