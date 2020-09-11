/*
 * A simple program to read a file and display with random colours on terminal
 *
 *
 *Inspired by lolcat
 * 
 * Copyright (C) 2020  Roshan <roshanlc.github.io>
 * 
 */

#define _GUN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRINTRGBCHAR(r,g,b,ch) printf("\033[38;2;%d;%d;%dm%c\033[0m",r,g,b,ch) //macro function to print character with given rgb  color code as foreground

#define M_PI 3.14159265358979323846264338327
typedef struct {
    int r,g,b;
}COLORS;


COLORS return_rgb(int i)
{
    double f=0.10025; //fixed frequency
    COLORS temp;
    
    temp.r =(int) ((sin(f* (double) i + M_PI/3))*127 +128);
    temp.g =(int) ((sin(f* (double) i + 2 *M_PI/3))*127 +128);
    temp.b = (int)((sin(f* (double) i +4 * M_PI/3))*127 +128);
   return temp;
}

void print_usage(void);
void print_version(void);
void doTheJob(char *);

int main (int argc, char *argv[])
{
    COLORS check;
    FILE *fp;
    char *line = NULL;
    size_t size=0;
    size_t nread;
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

    fp = fopen(argv[1],"r");
	if(fp!=NULL)
	{
		char x;
		int count=0;
		while((x=fgetc(fp))!=EOF)
		{

            check = return_rgb(count);
			PRINTRGBCHAR(check.r,check.g,check.b,x);
            count++;
		}
		
		fclose(fp);
	}
	else print_usage();
	
}
else if((nread =getline(&line,&size,stdin)) != -1)
{

    doTheJob(line);
    while((nread =getline(&line,&size,stdin)) != -1)
     {
         doTheJob(line);
     }
    free(line);
}
else print_usage();
	return 0;
}


void print_version (void)
{
	char version[] =("reader version 1.1, (c) 2020 roshan\n");
	doTheJob(version);
	exit (0);
}

void print_usage (void)
{
	char usage[] = "Usage:\nreader [File-name]\nor\nreader [options]\n-v \t prints version information\n-u \t prints usage information\n";
	doTheJob(usage);
	exit (0);
}

void doTheJob(char *str)
{
    COLORS values;
    int i=0;
    while(str[i]!='\0')
    {
        values = return_rgb(i);
        PRINTRGBCHAR(values.r,values.g,values.b,str[i]);
        i++;
    }
}
