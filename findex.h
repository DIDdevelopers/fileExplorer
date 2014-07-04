#include<iostream>
#include<fstream>
#include<string>
#include <vector>

using namespace std;

class cFileIndexer{

 public:
  cFileIndexer(std::string );
  vector<string> searchIndex(std::string );
  void createIndex();
  void wrote(std::string sPwd, std::string fname);

 private:
    void crawlAndIndex(std::string );
    string m_sDir;
    ofstream ifile;
};


