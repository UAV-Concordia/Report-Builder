#include "Feature.h"




Feature::Feature()
{
}


Feature::~Feature()
{
}


string Feature::getName(){
	return name;
}

void Feature::setName(string pName){
	name = pName;
}

void Feature::setBoundingPolygon(vector< vector< double>> pPolygon){
	boundingPolygon = pPolygon;
}

vector< vector< double>>& Feature::getBoundingPolygon(){
	return boundingPolygon;
}

void Feature::computeCentroid(){
	double xPos = 0;
	double yPos = 0;
	double zPos = 0;

	for (int i = 0; i < boundingPolygon.size(); i++){
		xPos += boundingPolygon.at(i).at(0);
		yPos += boundingPolygon.at(i).at(1);
		zPos += boundingPolygon.at(i).at(2);
	}

	if (boundingPolygon.size() != 0){
		xPos / boundingPolygon.size();
		yPos / boundingPolygon.size();
		zPos / boundingPolygon.size();
	}

	/*centroid.at(0) = xPos;
	centroid.at(1) = yPos;
	centroid.at(2) = zPos;
	*/
	centroid.push_back(xPos);
	centroid.push_back(yPos);
	centroid.push_back(zPos);
}




vector< double > Feature::getCentroid(){
	return centroid;
}