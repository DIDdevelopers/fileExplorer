#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class cFileIndexer{

 public:
  cFileIndexer(string sIndexPath);
  void createIndex();
  vector<string> searchIndex();

 private:
  string sPwd;


};


