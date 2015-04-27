#ifndef FEATURE_H
#define FEATURE_H


#include <vector>
#include <string>
#include <iostream>

using namespace std;


enum StructureState{
    DAMAGED,
    UNDAMAGED,
    NO_STRUCTURE
};


enum FeatureType{
    CONTAMINED_AREA,
    TRAIN,
    PERSON,
    OBJECT,
    STRUCTURE,
    DEBRIS_PILE,
    NO_FEATURE
};

enum ObjectType{
    FIRE,
    TENT,
    BOAT,
    CAR,
    NO_OBJECT
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

    ObjectType getObjectType();
    string getStringObjectType();
    void setObjectType(ObjectType);

    StructureState getStructureState();
    string getStringStructureState();
    void setStructureState(StructureState);

    string getName();
    void setName(string);

    double getArea();
    void setArea(double);

    double getVolume();
    void setVolume(double);

    string getQRCode();
    void setQRCode(string);

    void setBoundingPolygon(vector< vector< double>>);
    vector< vector< double>>& getBoundingPolygon();

    void computeCentroid();
    vector< double > getCentroid();


private:
    string name;
    FeatureType type;
    double area;
    double volume;
    string qrcode;
    ObjectType objectType;
    StructureState structureState;
    vector< vector< double>> boundingPolygon;
    vector< double > centroid;

};

#endif // FEATURE_H
