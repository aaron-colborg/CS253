#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <Point3D.h>
#include <iostream>


using std::vector;
using std::ofstream;

class Table{
 public:
	Table(vector<vector<double> >& passedVector);
	Table();
	~Table();
	
	vector<double>& operator [] (int index)
  	{
    	return tableVector[index];
  	}
	inline int size(){return tableVector.size();}
	inline void add(double i, double j, double push){double hold = tableVector[i][j]; double add = hold + push; tableVector[i][j] = add;}
	
 protected:    
	vector<vector<double> > tableVector;
};

#endif //TABLE_H
	

