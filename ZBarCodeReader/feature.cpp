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
    if (type==CONTAMINED_AREA || type==NO_FEATURE)
         area=pArea;
}


double Feature::getVolume(){
    return volume;
}

void Feature::setVolume(double pVolume){
    if(type==DEBRIS_PILE || type==NO_FEATURE)
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

void Feature::setBoundingPoints(vector< BoundingPoint> pPoints){
    boundingPoints=pPoints;
}

vector< vector< double>>& Feature::getBoundingPolygon(){
    return boundingPolygon;
}

vector< BoundingPoint>& Feature::getBoundingPoints(){
    return boundingPoints;
}



void Feature::computeCentroid(){
    if (centroid.size()!=0)centroid.clear();

    double xPos = 0;
    double yPos = 0;
    double zPos = 0;

    for (int i = 0; i < boundingPoints.size(); i++){
        cout<<"hey"<<endl;
        xPos += boundingPoints.at(i).coordinates.at(0);
        yPos += boundingPoints.at(i).coordinates.at(1);
        zPos += boundingPoints.at(i).coordinates.at(2);
    }

    if (boundingPoints.size() != 0){
        xPos = xPos / boundingPoints.size();
        yPos = yPos / boundingPoints.size();
        zPos = zPos / boundingPoints.size();

    }

    /*centroid.at(0) = xPos;
    centroid.at(1) = yPos;
    centroid.at(2) = zPos;
    */
    centroid.push_back(xPos);
    centroid.push_back(yPos);
    centroid.push_back(zPos);


    std::cout << "Centroid" << std::endl;
    std::cout << centroid.at(0);
    std::cout << ", ";
    std::cout << centroid.at(1);
    std::cout << ", ";
    std::cout << centroid.at(2);



}



vector< double > Feature::getCentroid(){
    return centroid;
}

 void Feature::addImagePath(string pointName, string imagePath)
 {
      cout << "adding image " << imagePath << " to point "<< pointName << endl;
     BoundingPoint* point;
     //find bounding point
     for(int i=0;i<boundingPoints.size();i++){
         if (boundingPoints.at(i).name.compare(pointName)==0){
             point=&boundingPoints.at(i);
             cout << "found point" << endl;
             break;
         }
     }
     //verify if already contain image

     bool contains=false;
     for(int j=0;j<point->imagePaths.size();j++){
         if (point->imagePaths.at(j).compare(imagePath)==0){
             contains=true;
              cout << "already contains image" << endl;
             break;
         }
     }

     //if not add image
     if (!contains){
          cout << "add new image" << endl;
         point->imagePaths.push_back(imagePath);
     }

 }

 const vector<string> Feature::getImagePaths(){

     vector<string> imagePaths;
    cout<< "hey" << endl;
     for(int i=0;i<boundingPoints.size();i++){
         BoundingPoint point=boundingPoints.at(i);
         cout<< "point: " << point.name << endl;
         for(int j=0;j<point.imagePaths.size();j++){
            imagePaths.push_back(point.imagePaths.at(j));
             cout<<"image: " << point.imagePaths.at(j) << endl;
         }
     }

     //May contain duplicates
     return imagePaths;
 }
