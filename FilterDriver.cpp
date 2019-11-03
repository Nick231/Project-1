#include "BaseballStatistic.h"
#include "Data.h"
#include "StringHelper.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void swap1(vector<BaseballStatistic>&, int, int);
void swap2(vector<BaseballStatistic>&, int, int);
void sort1(vector<BaseballStatistic>&);
void sort2(vector<BaseballStatistic>&);
int search1(vector<BaseballStatistic>, string, string);
int search2(vector<BaseballStatistic>, string);
void loadFile(vector<BaseballStatistic>&);

int main(){ 
 // Use cases to prompt user to choose from sorting options. 
       vector<BaseballStatistic> e_Stat;
       loadFile(e_Stat);
	char option;
	
	cout << "Would you like to search by A) Player Name & Position, or B) Team & Jersey Number? Enter A or B: ";
	cin >> option;
	
	switch(toupper(option))
	{
		case 'a':
			sort1(vector<BaseballStatistic>&);
		case 'b':
			sort2(vector<BaseballStatistic>&);
		default:
			cout << "You did not select a correct option." << endl;
			break;
	}
	
	
			

}




void loadFile(vector<BaseballStatistic>& e_Stat){
	ifstream in;
	in.open("BStats.csv");
	
	std::string firstName, lastName, teamName, position;
	int jerseyNum, atBats, hr, rbi, sb;
	char batting, throwing;
	double battingAverage, ops,era;
  int birthDay, birthMonth, birthYear; 
	
	while(teamName >> jerseyNum >> firstName >> lastName >> birthYear >> birthMonth >> birthDay >> batting >> throwing >> atBats >> battingAverage >> hr >> rbi >> sb >> ops >> era >> position){
		
		BaseballStatistic temp(teamName, jerseyNum, firstName, lastName, birthYear, birthMonth, birthDay, batting, throwing, atBats, battingAverage, hr, rbi, sb, ops, era, position);
		e_Stat.push_back(temp);
	}
}

void swap1(vector<BaseballStatistic>& e_Stat, int a, int b);
  {
    BaseballStatistic temp = *a;
    *a=*b;
    *b =temp;
  }
void sort1(vector<BaseballStatistic>& e_Stat){
    
     int i, j, min_idx; 
   
    for (i = 0; i < e_Stat.size()-1; i++) 
    { 
        min_idx = i; 
        
        for (j = i+1; j < e_Stat.size(); j++) 
          if (
              (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) < 0)
              
              || (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) == 0 && e_Stat[j].getFirstName()const.compare(e_Stat[min_idx].getFirstName()const ) < 0)
              
              || (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) == 0 && e_Stat[j].getFirstName()const.compare(e_Stat[min_idx].getFirstName()const) == 0 && e_Stat[j].getPosition()const < e_Stat[min_idx].getPosition()const ) 
              )
            min_idx = j; 
      
        swap1(e_Stat, min_idx, i);
         } 
void swap2(vector<BaseballStatistic>& e_Stat, int a, int b);
  {
    BaseballStatistic temp = *a;
    *a=*b;
    *b =temp;
  }
	
void sort2(vector<BaseballStatistic>& e_Stat)
{
	   int i, j, min_idx; 
   
    for (i = 0; i < e_Stat.size()-1; i++) 
    { 
        min_idx = i; 
        
        for (j = i+1; j < e_Stat.size(); j++) 
          if (
              (e_Stat[j].getTeamName()const.compare(e_Stat[min_idx].getTeamName()const) < 0)
              
              || (e_Stat[j].getTeamName()const.compare(e_Stat[min_idx].getTeamName()const) == 0 && e_Stat[j].getJerseyNum()const.compare(e_Stat[min_idx].getJerseyNum()const ) < 0)
    )
		  min_idx = j; 
      
        swap2(e_Stat, min_idx, i);
         } 

int search1(vector<BaseballStatistic> e_Stat, string firstName, string lastName){
  
  int lo = 0;
  int hi = e_Stat.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
	   
        if (e_Stat[location].getLastName() == lastName && e_Stat[location].getFirstName() == firstName) 
            return location; 
  
    
        if (e_Stat[location].getLastName() < lastName 
			|| (e_Stat[location].getLastName() == lastName && e_Stat[location].getFirstName() < firstName)) 
            lo = location + 1; 
  
        else
            hi = location - 1; 
    } 
  
    return -1; 
 
}

int search2(vector<BaseballStatistic> e_Stat, string teamName){
  
  int lo = 0;
  int hi = e_Stat.size();
  
   while (lo <= hi) 
    { 
        int location = lo + (hi-lo)/2; 
	   
        if (e_Stat[location].getTeamName() == teamName ) 
            return location; 
  
    
        if (e_Stat[location].getTeamName() < teamName 
			|| (e_Stat[location].getTeamName() == teamName))
            lo = location + 1; 
  
        else
            hi = location - 1; 
    } 
  
    return -1; 
 
}
