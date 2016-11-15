#include <vector>
#include <Table.h>
#include <iostream>
using std::ofstream;
using std::vector;
Table::Table(vector<vector<double> >& passedVector){
	tableVector = passedVector;
}

Table::Table(){
	tableVector = vector<vector<double> >(10);
}

Table::~Table(){
	for(unsigned int i = 0; i < tableVector.size(); i++){
		tableVector[i].clear();
	}
	tableVector.clear();
}	


	

