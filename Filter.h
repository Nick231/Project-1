#ifndef FILTER
#define FILTER
#include <string>
#include <vector>
#include "BaseballStatistic.h"
using namespace std;
class Filter{
  
  public:
          void sort1(vector<BaseballStatistic>& e_Stat);
          void sort2(vector<BaseballStatistic>& e_Stat);
          int search1(vector<BaseballStatistic>, string, string);
          int search2(vector<BaseballStatistic>, string);
  
};        

#endif

