#include<dirent.h>
#include<ncurses.h>
#include<stdio.h>
#include<string.h>
#include "findex.h"

cFileIndexer::cFileIndexer(const char *sPath){

 sPwd = sPath;

}

void cFileIndexer::createIndex(const char *sPwd){

DIR *pdir;
struct dirent *entry;
FILE *fp;
//char *path;
int len = 255;
char final[len];

fp = fopen("indx", "w+");
pdir = opendir(sPwd);

while((entry = readdir(pdir)) != NULL){

 if(entry->d_type != DT_DIR){

   snprintf(final, len, "%s/%s", sPwd, entry->d_name);
   fprintf(fp, final);
   fprintf(fp, "\n");
   cout<<"file is "<<final<<endl;
 }
 else if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0){
   continue;
 }
 else{

   snprintf(final, len, "%s/%s", sPwd, entry->d_name);
   fprintf(fp, final);
   fprintf(fp, "\n");
   cout<<"DIR is "<<final<<endl;
   createIndex(final);
 }

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

