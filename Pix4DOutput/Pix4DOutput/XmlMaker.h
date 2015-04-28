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
	void updateObject(Feature obj);
	bool findObject(string name);

private:
	string filePath; // not used so far
	XMLDocument doc;
	vector<XMLElement*> placemarkElements;

	void writeObject(Feature obj, XMLElement* element);
};

