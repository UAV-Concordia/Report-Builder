#include "VolumeFileParser.h"


VolumeFileParser::VolumeFileParser()
{
}


VolumeFileParser::~VolumeFileParser()
{
}


vector<string>& VolumeFileParser::readFile(){
	
		string volumeFileLine;
		std::ifstream volumeFile(filePath);

		if (!lines.empty()) lines.clear();

		if (volumeFile.is_open())
		{
			while (std::getline(volumeFile, volumeFileLine)) { //Read a line

				lines.push_back(volumeFileLine);
			}		
		}
		else{
			cout << "File doesn't not exist!" << endl;
		}

		return lines;
}

void VolumeFileParser::setFilePath(string path){
	filePath = path;
}

string VolumeFileParser::getFilepath(string path){
	return filePath;
}


vector<string>& VolumeFileParser::split(char delim, string toParse, int rep){

		
		if (!flds.empty()) flds.clear();
	
		string work = toParse;
		string buf = "";
		unsigned i = 0;
		while (i < work.length()) {
			if (work[i] != delim){
				buf += work[i];
				//cout << buf << endl;
			}
			else if (rep == 1) {
				flds.push_back(buf);
				buf = "";
			}
			else if (buf.length() > 0) {
				flds.push_back(buf);
				buf = "";
			}
			i++;
		}
		if (!buf.empty())
			flds.push_back(buf);

		return flds;
}