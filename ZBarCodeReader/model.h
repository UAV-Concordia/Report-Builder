#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <unordered_map>
#include "feature.h"
#include "pointtoimageparser.h"
#include "volumefileparser.h"

#include "xmlverticesparser.h"

class Model
{
public:
    Model();
    ~Model();

    //Set parsing files
    void setPointToImageFile(string filename);
    void setObjectFile(string filename);
     void setSurfaceFile(string filename);
     void setVolumeFile(string filename);

     //Parse data
     void parseData();


    vector<string> getFeatureNames();
    Feature* getFeature(string);

private:

    PointToImageParser pti_parser;
    VolumeFileParser volume_parser;
    VolumeFileParser surface_parser;
    //XMLSurfaceParser object_parser;
    XMLVerticesParser object_parser;

   unordered_map<string,Feature> features;

};

#endif // MODEL_H
