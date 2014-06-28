#include<dirent.h>
#include<ncurses.h>
#include<stdio.h>
#include<string.h>
#include "findex.h"

cFileIndexer::cFileIndexer(const char *sPath){

 sPwd = sPath;

}

void cFileIndexer::createIndex(){

 struct dirent *entry;
 string str;
 DIR *sdir;
 FILE *fp;

 fp = fopen(sPwd,"w+");
 sdir = opendir(sPwd);
 
 while ((entry=readdir(sdir)) != NULL){
  printf("%s\n",entry->d_name);
  fprintf(fp, entry->d_name);
 }

}


void cFileIndexer::searchIndex(){

	int ch;
        FILE *fp;
        size_t len;
        ssize_t read;
        char *buf=NULL;

        fp = fopen("indx", "r+");

        initscr();
        cbreak();
        noecho();

        printf("Just type the keyword to find the files \n");
 	do{
        	ch = getch();
                while((read = getline(&buf, &len, fp)) != -1 ){
                        if(read == EOF)
                                break;
                        if(strchr(buf, ch))
                                printf("->%s\n",buf);
                        refresh();
                }
                rewind(fp);
	 
	}while(ch != 'q');

        getch(); 
        endwin();

}

