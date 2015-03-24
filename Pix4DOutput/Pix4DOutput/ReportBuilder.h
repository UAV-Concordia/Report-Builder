#pragma once

#include <vector>
#include "Container.h"
#include "ContaminatedField.h"
#include "DebrisPile.h"
#include "Person.h"
#include "Structure.h"
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;


class ReportBuilder
{
public:
	ReportBuilder();
	~ReportBuilder();

	void setContainerList(vector<Container>);
	void addContainer(Container);

	void setContaminatedFieldList(vector<ContaminatedField>);
	void addContainer(ContaminatedField);

	void setDebrisPileList(vector<DebrisPile>);
	void addDebrisPile(DebrisPile);

	void setPersonList(vector<Person>);
	void addPerson(Person);

	void setStructureList(vector<Structure>);
	void addStructure(Structure);

	void generateReport();

private:

	void generateHeader();
	void generateBody();
	void generateContainerTables();
	void generateContaminatedFieldTables();
	void generateDebrisPileTables();
	void generatePersonTables();
	void generateStructureTables();

	vector<Container> containerList;
	vector<ContaminatedField> contaminatedFieldList;
	vector<DebrisPile> debrisPileList;
	vector<Person> personList;
	vector<Structure> structureList;

};

