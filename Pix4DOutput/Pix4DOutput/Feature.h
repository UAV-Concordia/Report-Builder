#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Feature
{
public:
	Feature();
	~Feature();

	string getName();
	void setName(string);

	void setBoundingPolygon(vector< vector< double>>);
	vector< vector< double>>& getBoundingPolygon();

	void computeCentroid();
	vector< double > getCentroid();


private:
	string name;
	vector< vector< double>> boundingPolygon;
	vector< double > centroid;

};

