#ifndef FEATURE_H
#define FEATURE_H


#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum FeatureType{
    CONTAMINED_AREA,
    TRAIN,
    PERSON,
    OBJECT,
    STRUCTURE,
    DEBRIS_PILE,
    NONE
};

class Feature
{
public:
    Feature();
    Feature(string);
     Feature(string, FeatureType);
    ~Feature();

    FeatureType getType();
    string getStringType();
    void setType(FeatureType);

    string getName();
    void setName(string);

    double getArea();
    void setArea(double);

    double getVolume();
    void setVolume(double);

    void setBoundingPolygon(vector< vector< double>>);
    vector< vector< double>>& getBoundingPolygon();

    void computeCentroid();
    vector< double > getCentroid();


private:
    string name;
    FeatureType type;
    double area;
    double volume;

    vector< vector< double>> boundingPolygon;
    vector< double > centroid;

};

#endif // FEATURE_H
