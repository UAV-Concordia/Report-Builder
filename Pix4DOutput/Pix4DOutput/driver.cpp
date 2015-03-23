#include "tinyxml2.h"
#include <iostream>
#include <string>
#include "VolumeFileParser.h"
#include "XMLSurfaceParser.h"


using namespace std;
using namespace tinyxml2;

string filepath = "../Data/volumeoutput.txt";
VolumeFileParser vp;

int main()
{
	cout << "Hello World!" << endl;
	
	
	//Centroid stuff
	
	XMLSurfaceParser surfaceParser;

	surfaceParser.setFilePath("../Data/Surface_surfaces.kml");
	surfaceParser.readFile();
	surfaceParser.parse();
	vector< vector<double>> coordinates=surfaceParser.getBoundingPolygon(0);

	cout << "driver output" << endl;

	for (int i = 0; i < coordinates.size(); i++){
		for (int j = 0; j < coordinates.at(0).size(); j++){
		
			cout << coordinates.at(i).at(j) << endl;
			
		}
	}

	cout << "name output start" << endl;
	cout << surfaceParser.getName(1) << endl;

	cout << "name output end" << endl;
	/*
	XMLDocument doc;
	doc.LoadFile("../Data/Volume_surfaces.kml");
	
	XMLElement* rootElement = doc.RootElement();
	XMLElement* child2 = rootElement->FirstChildElement();
	
	const char* nodeName = rootElement->Value();
	printf("%s\n", nodeName);
	 nodeName = child2->Value();
	printf("%s\n", nodeName);
	

	tinyxml2::XMLElement *levelElement = doc.FirstChildElement("kml")->FirstChildElement("Document")->FirstChildElement("Folder");
	for (tinyxml2::XMLElement* child = levelElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
	{
		nodeName = child->Value();
		printf("%s\n", nodeName);
		
		// do something with each child element
	}
	
	*/
	




	//printf("%s\n", title);

	
	
	/*
	
	vp.setFilePath(filepath);
	vector<string> lines=vp.readFile();

	for (int i = 0; i < lines.size(); i++){
	vector<string> words = vp.split(char(9), lines.at(i), 0);
	for (int j = 0; j < words.size(); j++)
		cout << words.at(j) << endl;
	}

	
	*/
	//Volume stuff
	

	int temp;
	cin >> temp;
	return 0;
}