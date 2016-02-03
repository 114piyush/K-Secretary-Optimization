#include<stdio.h>
int srand()
{
  static int next=8;
  next = next * time(NULL) + rand();
  return (unsigned int)(next/65536) % 32768;
}
