#ifndef VOLUMEFILEPARSER_H
#define VOLUMEFILEPARSER_H


#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct VolumetricData{
    string objectName;
    double projected2Dlength;
    double projected2DlengthError;
    double terrain3Dlength;
    double terrain3DlengthError;
    double projected2Darea;
    double projected2DareaError;
    double enclosed3Darea;
    double enclosed3DareaError;
    double terrain3Darea;
    double terrain3DareaError;
    double fillVolume;
    double fillVolumeError;
    double cutVolume;
    double cutVolumeError;
    double totalVolume;
    double totalVolumeError;
};

class VolumeFileParser
{
public:
    VolumeFileParser();
    ~VolumeFileParser();

    vector<string>& readFile();
    void setFilePath(string path);
    string getFilepath();
    int getNumberOfVolumetricData();
    const VolumetricData& getVolumetricData(int);

    vector<string>& split(char delim,  string toParse, int rep = 0);
    void parse();

private:
    vector<VolumetricData> volumetricData;
    vector<string> flds;
    vector<string> lines;
    string filePath;

};



#endif // VOLUMEFILEPARSER_H
