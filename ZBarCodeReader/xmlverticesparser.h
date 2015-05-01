#ifndef XMLVERTICESPARSER_H
#define XMLVERTICESPARSER_H

#include <vector>
#include <string>
#include <iostream>
#include "tinyxml/tinyxml2.h"
#include "feature.h"


using namespace std;
using namespace tinyxml2;





class XMLVerticesParser
{
public:
    XMLVerticesParser();
    ~XMLVerticesParser();


    void readFile();
    void setFilePath(string path);
    string getFilepath();
    void parse();
    //vector<string>& split(char delim, string toParse, int rep = 0);
    const BoundingPoint& getBoundingPoints(int);
    const vector<BoundingPoint>& getBoundingPoints();
    string getName(int index);

    int getNumberOfParsedObjects();

private:
    //vector<string> flds;
    //vector<string> lines;
    string filePath;


    XMLDocument doc;
    XMLElement* rootElement;
    XMLElement* documentElement;
    XMLElement* folderElement;
    vector<XMLElement*> placemarkElements;
    vector<BoundingPoint> boundingPoints;

    vector<string>& split(char delim, string toParse, int rep);
};
#endif // XMLVERTICESPARSER_H
