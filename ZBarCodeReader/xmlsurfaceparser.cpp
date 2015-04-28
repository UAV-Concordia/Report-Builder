#include "xmlsurfaceparser.h"

XMLSurfaceParser::XMLSurfaceParser()
{
}


XMLSurfaceParser::~XMLSurfaceParser()
{
}

void XMLSurfaceParser::setFilePath(string path){
    filePath = path;
}

string XMLSurfaceParser::getFilepath(){
    return filePath;
}


void XMLSurfaceParser::readFile(){
    if (!filePath.empty())
        doc.LoadFile(filePath.c_str());
}



void XMLSurfaceParser::parse(){

    rootElement = doc.RootElement();
    documentElement = rootElement->FirstChildElement();
    folderElement = documentElement->FirstChildElement();


    for (tinyxml2::XMLElement* child = folderElement->FirstChildElement()->NextSiblingElement(); child != NULL; child = child->NextSiblingElement())
    {


        placemarkElements.push_back(child);
    }

}

vector< vector <double>>& XMLSurfaceParser::getBoundingPolygon(int index){
    vector< vector<double>>* coordinates = new vector< vector<double>>;
    cout << placemarkElements.size() << endl;
    XMLElement* coordinateTag;
    if (index < placemarkElements.size()){
        coordinateTag = placemarkElements.at(index)->FirstChildElement("Polygon")->FirstChildElement("outerBoundaryIs")->FirstChildElement("LinearRing")->FirstChildElement("coordinates");
        string allCoordinateString = coordinateTag->GetText();
        vector<string> coordinatesString = split(' ', allCoordinateString, 0);
        for (int i = 0; i < coordinatesString.size(); i++){
            //cout << coordinateString.at(i) << endl;
            vector<string> coordinate = split(',', coordinatesString.at(i), 0);

            vector<double> coordinateDbl;

            for (int j = 0; j < coordinate.size(); j++){
                size_t sz;
                double coord = stold(coordinate.at(j));
                //cout << coordinate.at(j) << endl;
                std::cout.precision(20);
                cout << coord << endl;
                coordinateDbl.push_back(coord);
                //coordinateDbl.push_back(coordinate.at(j));
            }

            coordinates->push_back(coordinateDbl);

            /*for (int j = 0; j < coordinateString.size(); j++){
                size_t sz;
                double coord = stold(coordinate.at(i), &sz);
                cout << coord << endl;
            }*/
        }
    }
    return *coordinates;
}

string XMLSurfaceParser::getName(int index){
    XMLElement* nameTag;
    string name;
    if (index < placemarkElements.size() - 1){
        nameTag = placemarkElements.at(index)->FirstChildElement("name");
        name = nameTag->GetText();
    }
    else{
        name = "";
    }

    return name;
}

  int XMLSurfaceParser::getNumberOfParsedObjects()
  {
      return placemarkElements.size();
  }


vector<string>& XMLSurfaceParser::split(char delim, string toParse, int rep){

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

