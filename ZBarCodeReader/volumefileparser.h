#ifndef VOLUMEFILEPARSER_H
#define VOLUMEFILEPARSER_H


#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class VolumeFileParser
{
public:
    VolumeFileParser();
    ~VolumeFileParser();

    vector<string>& readFile();
    void setFilePath(string path);
    string getFilepath(string path);

    vector<string>& split(char delim,  string toParse, int rep = 0);

private:
    vector<string> flds;
    vector<string> lines;
    string filePath;

};



#endif // VOLUMEFILEPARSER_H
