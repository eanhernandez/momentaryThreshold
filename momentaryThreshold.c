#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  wiringPiSetup () ;

  //setting up pins
  pinMode (0, OUTPUT) ;
  pinMode (2, OUTPUT) ; 
  digitalWrite (2, HIGH);

  int i=0;
  int max=250;
  int iDelay=100;

  if (argc==3)
  { 
	max = atoi(argv[1]);
	iDelay = atoi(argv[2]);
  }
  else
  {
        printf("requires two arguments: max and delay.\n");
        fflush(stdout);
	return 1;
  }

  for (i=max;i>=0;i=i-10)
  {
  	digitalWrite (0, HIGH) ; 
	delay (i) ;
        digitalWrite (0,  LOW) ;
        printf("test:%i ms.\n",i);
        fflush(stdout);
 	delay(iDelay);
  }	
  
  digitalWrite (2, LOW);
 
  return 0;
}
