#ifndef POINTTOIMAGEPARSER_H
#define POINTTOIMAGEPARSER_H


#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>




using namespace std;

class PointToImageParser
{

    //Conversion ratio mm to pixel
    //1 mm = 3.779528 px
    const double MM_TO_PIXEL_RATIO = 3.779528;

public:

    PointToImageParser();
    ~PointToImageParser();

    void parse();
    vector<string>& readFile();
    void setFilePath(string path);
    string getFilepath(string path);

    vector<string>& split(char delim, string toParse, int rep = 0);

private:
    vector<string> flds;
    vector<string> lines;
    string filePath;

    bool isInteger(const std::string & s);
};

struct MapPoint{
    string name;
    double xPixel;
    double yPixel;

};


#endif // POINTTOIMAGEPARSER_H
