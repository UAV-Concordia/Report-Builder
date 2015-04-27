#include "feature.h"



Feature::Feature()
{
    name="";
    type=NO_FEATURE;
    objectType=NO_OBJECT;
    structureState=NO_STRUCTURE;
    area=0.0;
    volume=0.0;
    qrcode="";
}

Feature::Feature(string pName)
{
    name=pName;
    type=NO_FEATURE;
    objectType=NO_OBJECT;
    structureState=NO_STRUCTURE;
    area=0.0;
    volume=0.0;
    qrcode="";
}

Feature::Feature(string pName,FeatureType pType)
{
    name=pName;
    type=pType;
    objectType=NO_OBJECT;
    structureState=NO_STRUCTURE;
    area=0.0;
    volume=0.0;
    qrcode="";
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

FeatureType Feature::getType(){
    return type;
}

string Feature::getStringType(){
    switch (type) {
    case CONTAMINED_AREA:
        return "Contaminated Area";
        break;
    case DEBRIS_PILE:
        return "Debris Pile";
        break;
    case OBJECT:
        return "Object";
        break;
    case PERSON:
        return "Person";
        break;
    case STRUCTURE:
        return "Structure";
        break;
    case TRAIN:
        return "Train";
        break;
    default:
        return "None";
        break;
    }
}

void Feature::setType(FeatureType pType){
    type = pType;
}


ObjectType Feature::getObjectType()
{
    return objectType;
}

string Feature::getStringObjectType()
{
    switch (objectType) {
    case BOAT:
        return "Boat";
        break;
    case CAR:
        return "Car";
        break;
    case FIRE:
        return "Fire";
        break;
    case TENT:
        return "Tent";
        break;
    default:
        return "None";
        break;
    }
}

void Feature::setObjectType(ObjectType pObjectType)
{
    if (type==OBJECT)
        objectType=pObjectType;
}


StructureState Feature::getStructureState()
{
    return structureState;
}

string Feature::getStringStructureState()
{
    switch (structureState) {
    case DAMAGED:
        return "Damaged";
        break;
    case UNDAMAGED:
        return "Undamaged";
        break;
    default:
        return "None";
        break;
    }
}

void Feature::setStructureState(StructureState pState)
{
    if (type==STRUCTURE)
        structureState=pState;
}


double Feature::getArea(){
    return area;
}

void Feature::setArea(double pArea){
    if (type==CONTAMINED_AREA)
         area=pArea;
}


double Feature::getVolume(){
    return volume;
}

void Feature::setVolume(double pVolume){
    if(type==DEBRIS_PILE)
        volume=pVolume;
}


string Feature::getQRCode()
{
    return qrcode;
}

void Feature::setQRCode(string pCode)
{
    if(type==TRAIN)
        qrcode=pCode;
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
