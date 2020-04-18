/*
 * A simple program to read a file and display with random colours on terminal
 *
 *
 *Inspired by lolcat
 * 
 * Copyright (C) 2020  Roshan <roshanlc.github.io>
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTCHAR(code,ch) printf("\033[%dm%c\033[0m",code,ch) //macro function to print character with given color code as foreground


const int codes[] = 
  { 31, 32, 33, 34, 35, 36, 91, 92, 93, 94, 95, 96}; 
const int codes_size = sizeof (codes) / sizeof (codes[0]);


int gen_rand(int,int);
void doTheJob (char*);
void printChar(char);
void print_usage(void);
void print_version(void);


int main (int argc, char *argv[])
{
	
	if(argc>1)
	{
		if (strcmp(argv[1],"-v")==0)
		 {
			 print_version();
			  exit(0);
		}
		else if(strcmp(argv[1],"-u")==0)
		{
			 print_usage();
			  exit(0);
		}
	
		FILE *fp = fopen(argv[1],"r");
		if(fp!=NULL)
		{
			char x;
			int random;
			while((x=fgetc(fp))!=EOF)
			{

				random = gen_rand(0,codes_size);
				PRINTCHAR(codes[random],x);
			}
			
			fclose(fp);
		}
		else print_usage();
		
	}
	
	else print_usage();
	return 0;
}


void print_version (void)
{
	char version[] =("reader version 1.0, (c) 2020 roshan\n");
	doTheJob(version);
	exit (0);
}

void print_usage (void)
{
	char usage[] = "Usage:\nreader [File-name]\nor\nreader [options]\n-v \t prints version information\n-u \t prints usage information\n";
	doTheJob(usage);
	exit (0);
}

int gen_rand (int low, int high)
{
      int rand_num = (rand () % (high - low + 1)) + low; //generating a random number, makes use of rand()
      return rand_num;
}


void doTheJob (char *c)
{
  //it takes a character and prints the character in randomly selected color
	int x,rand;
	for(x=0;c[x]!='\0';x++)
	{
		rand = gen_rand(0,codes_size);
		PRINTCHAR(codes[rand],c[x]);
	}
	
}

