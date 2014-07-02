#include<dirent.h>
#include<string.h>
#include<sstream>

#include "findex.h"

cFileIndexer::cFileIndexer(std::string sPath){

 sPwd = sPath;

}

void cFileIndexer::createIndex(std::string sPwd){

DIR *pdir;
struct dirent *entry;

if(!ifile.is_open())
    ifile.open("index");

pdir = opendir(sPwd.c_str());

 while((entry = readdir(pdir)) != NULL){

  std::string fname(entry->d_name);
  std::stringstream image;
  std::string word;
  std::string curDir(".");
  std::string preDir("..");

  if(entry->d_type != DT_DIR){
    wrote(sPwd, fname);
  }
  else if((fname.compare(curDir) == 0) || (fname.compare(preDir) == 0)){
      continue;
  }
  else{
      wrote(sPwd, fname);
      image << sPwd.c_str()<<"/"<<fname;
      word = image.str();
      createIndex(word.c_str());
  }
 }

}

void cFileIndexer::wrote(std::string sPwd, std::string fname){

    if(! ifile.is_open()){

       ifile.open("index");
       if(ifile.good())
          ifile << sPwd.c_str()<<"/"<<fname<<endl;
    }
    else{
       if(ifile.good())
          ifile << sPwd.c_str()<<"/"<<fname<<endl;
    }

}



void cFileIndexer::searchIndex(std::string sFind){

  std::string sPwd(sPwd);
  std::string ssearch(sFind);
  std::size_t pos = sPwd.length()+1;
  char name[256];

  ifstream file("index");
  
  while(file.getline (name,256)){
    std::string line(name);
    if(!file.eof()){
       std::size_t found = line.find(ssearch, pos);
       if(found != std::string::npos)
          std::cout << name <<endl;
    }
  }
}

