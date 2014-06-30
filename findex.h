#include<iostream>
#include<strings.h>
#include<vector>

using namespace std;

class cFileIndexer{

 public:
  cFileIndexer(const char *sIndexPath);
  void createIndex(const char *sPath);
  void searchIndex();

 private:
  const char *sPwd;


};


