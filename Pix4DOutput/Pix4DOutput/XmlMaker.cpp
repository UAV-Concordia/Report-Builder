#include "XmlMaker.h"

XmlMaker::XmlMaker()
{
}


XmlMaker::~XmlMaker()
{
}

//Creates basic layout of XML. just the declaration and an empty <objects></objects>
void XmlMaker::createXMLFile()
{
	//doc.SaveFile("textXML.xml");

	//XMLDeclaration* decl = doc.NewDeclaration(NULL);
	XMLElement* element = doc.NewElement("objects");
	//XMLText* txt = doc.NewText("value");

	//element->LinkEndChild(txt);

	//doc.LinkEndChild(decl);
	doc.LinkEndChild(element);
	
	doc.SaveFile("textXML.xml");
	
	doc.Print();

	//delete &element;
}

void XmlMaker::insertObject(Feature obj)
{
	doc.LoadFile("textXML.xml");

	XMLElement* element = doc.NewElement("object");

	//cout << doc.FirstChildElement()->Name();

	//add real name of object 
	element->SetAttribute("name" , obj.getName().c_str());

	//XMLElement* innerElement = doc.NewElement("name");
	//XMLText* txt = doc.NewText("empty1");
	//innerElement->LinkEndChild(txt);

	//element->LinkEndChild(innerElement);
	
	XMLElement* innerElement = doc.NewElement("type");
	XMLText* txt = doc.NewText("empty");
	innerElement->LinkEndChild(txt);

	element->LinkEndChild(innerElement);

	//centroid tag
	innerElement = doc.NewElement("centroid");
	XMLElement* centroid = doc.NewElement("latitude");
	txt = doc.NewText(std::to_string(obj.getCentroid().at(0)).c_str());
	centroid->LinkEndChild(txt);
	innerElement->LinkEndChild(centroid);
	
	centroid = doc.NewElement("longitude");
	txt = doc.NewText(std::to_string(obj.getCentroid().at(1)).c_str());
	centroid->LinkEndChild(txt);
	innerElement->LinkEndChild(centroid);

	centroid = doc.NewElement("altitude");
	txt = doc.NewText(std::to_string(obj.getCentroid().at(2)).c_str());
	centroid->LinkEndChild(txt);
	innerElement->LinkEndChild(centroid);

	element->LinkEndChild(innerElement);
	//-------------------------------------

	innerElement = doc.NewElement("area");
	txt = doc.NewText("empty");
	innerElement->LinkEndChild(txt);
	
	element->LinkEndChild(innerElement);

	innerElement = doc.NewElement("volume");
	txt = doc.NewText("empty");
	innerElement->LinkEndChild(txt);

	element->LinkEndChild(innerElement);

	//boundingpoints tag
	innerElement = doc.NewElement("boundingpoints");

	
	for (int i = 0; i < obj.getBoundingPolygon().size(); i++){
		
		XMLElement* point = doc.NewElement("point");
		XMLElement* pointName = doc.NewElement("name");
		txt = doc.NewText("placeholder name");
		pointName->LinkEndChild(txt);
		point->LinkEndChild(pointName);

	
		XMLElement* coordinates = doc.NewElement("coordinates");

		double xPos = 0;
		double yPos = 0;
		double zPos = 0;

			
		xPos += obj.getBoundingPolygon().at(i).at(0);
		yPos += obj.getBoundingPolygon().at(i).at(1);
		zPos += obj.getBoundingPolygon().at(i).at(2);

		XMLElement* coord = doc.NewElement("x");
		txt = doc.NewText(std::to_string(xPos).c_str());
		coord->LinkEndChild(txt);
		coordinates->LinkEndChild(coord);

		coord = doc.NewElement("y");
		txt = doc.NewText(std::to_string(yPos).c_str());
		coord->LinkEndChild(txt);
		coordinates->LinkEndChild(coord);

		coord = doc.NewElement("z");
		txt = doc.NewText(std::to_string(zPos).c_str());
		coord->LinkEndChild(txt);
		coordinates->LinkEndChild(coord);

		point->LinkEndChild(coordinates);
		innerElement->LinkEndChild(point);
	}
	
	element->LinkEndChild(innerElement);
	//------------------------
	
	//containingImage tag
	innerElement = doc.NewElement("containingimage");

		//TODO: for each image we should do this
		XMLElement* img = doc.NewElement("image");
		txt = doc.NewText("empty image");
		img->LinkEndChild(txt);

		innerElement->LinkEndChild(img);
		//------------------------------------

	element->LinkEndChild(innerElement);
	//-------------------------

	innerElement = doc.NewElement("identification");
	txt = doc.NewText("empty5");
	innerElement->LinkEndChild(txt);

	element->LinkEndChild(innerElement);

	innerElement = doc.NewElement("state");
	txt = doc.NewText("empty6");
	innerElement->LinkEndChild(txt);

	element->LinkEndChild(innerElement);

	innerElement = doc.NewElement("qrcode");
	txt = doc.NewText("empty7");
	innerElement->LinkEndChild(txt);

	element->LinkEndChild(innerElement);

	doc.FirstChildElement()->LinkEndChild(element);

	doc.SaveFile("textXML.xml");

	doc.Print();
}

bool XmlMaker::findObject(string name)
{
	doc.LoadFile("textXML.xml");
	
	XMLElement* rootElement = doc.RootElement();
	XMLElement* documentElement = rootElement->FirstChildElement();
	//XMLElement* folderElement = documentElement->FirstChildElement();

	for (XMLElement* child = documentElement; child != NULL; child = child->NextSiblingElement())
	{
		if (name.compare(child->Attribute("name")) == 0)
		{
			cout << "found object: " << name << endl << "object not added to xml file!" << endl;
			return true;
		}
	}

	return false;
}