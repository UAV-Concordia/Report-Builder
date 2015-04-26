#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "tinyxml2.h"
#include "Feature.h"

using namespace std;
using namespace tinyxml2;

class XmlMaker
{
public:
	XmlMaker();
	~XmlMaker();

	void createXMLFile();
	void insertObject(Feature obj);
	void updateObject();
	bool findObject(string name);

private:
	string filePath; // not used so far
	XMLDocument doc;
	XMLElement* rootElement;
	XMLElement* documentElement;
	XMLElement* folderElement;
	vector<XMLElement*> placemarkElements;
};

