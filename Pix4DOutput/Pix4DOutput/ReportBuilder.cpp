#include "ReportBuilder.h"


ReportBuilder::ReportBuilder()
{
}


ReportBuilder::~ReportBuilder()
{
}


void ReportBuilder::setContainerList(vector<Container> pContainerList){
	containerList = pContainerList;
}

void ReportBuilder::addContainer(Container pContainer){
	containerList.push_back(pContainer);
}

void ReportBuilder::setContaminatedFieldList(vector<ContaminatedField> pContaminatedFieldList){
	contaminatedFieldList = pContaminatedFieldList;
}

void ReportBuilder::addContainer(ContaminatedField pContaminatedField){
	contaminatedFieldList.push_back(pContaminatedField);
}

void ReportBuilder::setDebrisPileList(vector<DebrisPile> pDebrisPileList){
	debrisPileList = pDebrisPileList;
}

void ReportBuilder::addDebrisPile(DebrisPile pDebrisPile){
	debrisPileList.push_back(pDebrisPile);
}

void ReportBuilder::setPersonList(vector<Person> pPersonList){
	personList = pPersonList;
}

void ReportBuilder::addPerson(Person pPerson){
	personList.push_back(pPerson);
}

void ReportBuilder::setStructureList(vector<Structure> pStructureList){
	structureList = pStructureList;
}

void ReportBuilder::addStructure(Structure pStructure){
	structureList.push_back(pStructure);
}

void ReportBuilder::generateReport(){
	//Generate Header
	generateHeader();
	//generate Body
	generateBody();
}

void ReportBuilder::generateHeader(){

}

void ReportBuilder::generateBody(){
	generateContainerTables();
	generateContaminatedFieldTables();
	generateDebrisPileTables();
	generatePersonTables();
	generateStructureTables();
}

void ReportBuilder::generateContainerTables(){
	for (int i = 0; i < containerList.size(); i++){
		
	}
}

void ReportBuilder::generateContaminatedFieldTables(){
	for (int i = 0; i < contaminatedFieldList.size(); i++){

	}
}

void ReportBuilder::generateDebrisPileTables(){
	for (int i = 0; i < debrisPileList.size(); i++){

	}
}

void ReportBuilder::generatePersonTables(){
	for (int i = 0; i < personList.size(); i++){

	}
}
void ReportBuilder::generateStructureTables(){
	for (int i = 0; i < structureList.size(); i++){

	}
}