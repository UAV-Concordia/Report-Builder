#pragma once


#include <vector>
#include <string>
#include <iostream>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class XMLSurfaceParser
{
public:
	XMLSurfaceParser();
	~XMLSurfaceParser();


	void readFile();
	void setFilePath(string path);
	string getFilepath(string path);
	void parse();
	//vector<string>& split(char delim, string toParse, int rep = 0);
	vector< vector <double>>& getBoundingPolygon(int index);
	string getName(int index);

private:
	//vector<string> flds;
	//vector<string> lines;
	string filePath;


	XMLDocument doc;
	XMLElement* rootElement;
	XMLElement* documentElement;
	XMLElement* folderElement;
	vector<XMLElement*> placemarkElements;


	vector<string>& XMLSurfaceParser::split(char delim, string toParse, int rep);

};

