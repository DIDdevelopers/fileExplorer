#include<iostream>
#include<fstream>
#include<strings.h>

using namespace std;

class cFileIndexer{

 public:
  cFileIndexer(std::string );
  void createIndex(std::string );
  void searchIndex(std::string );
  void wrote(std::string sPwd, std::string fname);

 private:
  std::string sPwd;
  ofstream ifile;

};


