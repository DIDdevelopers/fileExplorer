#include<dirent.h>
#include<ncurses.h>
#include<stdio.h>
#include<string>
#include<strings.h>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;
void wrote(std::string, std::string );
ofstream ifile;

static void createIndex(std::string sPwd){

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
void wrote(std::string sPwd, std::string fname){
 
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


int main(){

 std::string pstr("/home/rahul/exprmnt");
 createIndex(pstr.c_str());

}
