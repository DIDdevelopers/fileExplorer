#include "fileIndexer.h"

cFileIndexer::cFileIndexer(string sPath){

 sPwd = sPath;

}

void cFileIndexer::createIndex(){
 
 string exec="ls >> .index";
 sprintf(str ,"%s", exec); 
 system(str);

}



