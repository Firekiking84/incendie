#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  int i;
  int max;
  int random;
  
  i = 0;
  srand(time(NULL));
  max = 0;
  while (i < 1000)
    {
      random = rand() % 129;
      if (random > max)
	max = random;
      i += 1;
    }
  printf("max value : %d", max);
}
      
    
