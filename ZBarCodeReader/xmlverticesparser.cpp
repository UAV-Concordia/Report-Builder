#include "xmlverticesparser.h"

XMLVerticesParser::XMLVerticesParser()
{

}

XMLVerticesParser::~XMLVerticesParser()
{

}

void XMLVerticesParser::setFilePath(string path){
    filePath = path;
}

string XMLVerticesParser::getFilepath(){
    return filePath;
}

void XMLVerticesParser::readFile(){
    if (!filePath.empty()){
        doc.Clear();
        doc.LoadFile(filePath.c_str());
    }
}


void XMLVerticesParser::parse(){

    if(placemarkElements.size()!=0)placemarkElements.clear();
    if(boundingPoints.size()!=0)boundingPoints.clear();

    rootElement = doc.RootElement();
    documentElement = rootElement->FirstChildElement();
    folderElement = documentElement->FirstChildElement();


    for (tinyxml2::XMLElement* child = folderElement->FirstChildElement()->NextSiblingElement(); child != NULL; child = child->NextSiblingElement())
    {
        BoundingPoint point;
        XMLElement* nameTag=child->FirstChildElement();
        cout << nameTag->GetText() << endl;
        point.name=nameTag->GetText();
         XMLElement* coordinateTag=nameTag->NextSiblingElement()->FirstChildElement();
         string coordinateString=coordinateTag->GetText();
         vector<string> coordinates=split(',',coordinateString,0);

         vector<double> coordinatesDouble;
         coordinatesDouble.push_back(stod(coordinates.at(0)));
         coordinatesDouble.push_back(stod(coordinates.at(1)));
         coordinatesDouble.push_back(stod(coordinates.at(2)));

         point.coordinates=coordinatesDouble;

        cout << coordinateString << endl;


        boundingPoints.push_back(point);
        placemarkElements.push_back(child);
        cout << "End of point";
    }

}

int XMLVerticesParser::getNumberOfParsedObjects()
{
    return boundingPoints.size();
}

 const BoundingPoint& XMLVerticesParser::getBoundingPoints(int index){
     return boundingPoints.at(index);
 }

 const vector<BoundingPoint>& XMLVerticesParser::getBoundingPoints(){
     return boundingPoints;
 }


 vector<string>& XMLVerticesParser::split(char delim, string toParse, int rep){

     vector<string>* flds= new vector<string>;
     //if (!flds.empty()) flds.clear();

     string work = toParse;
     string buf = "";
     unsigned i = 0;
     while (i < work.length()) {
         if (work[i] != delim){
             buf += work[i];
             //cout << buf << endl;
         }
         else if (rep == 1) {
             flds->push_back(buf);
             buf = "";
         }
         else if (buf.length() > 0) {
             flds->push_back(buf);
             buf = "";
         }
         i++;
     }
     if (!buf.empty())
         flds->push_back(buf);

     return *flds;
 }
