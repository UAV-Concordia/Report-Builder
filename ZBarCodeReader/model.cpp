#include "model.h"


Model::Model()
{



    std::pair<std::string, Feature > entry;
    string featureName="Feature 1";
    Feature f(featureName,TRAIN);
    f.computeCentroid();
    entry.first = f.getName();
    entry.second = f;

   features.insert(entry);
                cout << "insert feature" << endl;;

                featureName="Feature 2";
                Feature f2(featureName,CONTAMINED_AREA);
                f2.computeCentroid();
                f2.setArea(12);
                entry.first = f2.getName();
                entry.second = f2;

    features.insert(entry);


}

Model::~Model()
{

}

Feature* Model::getFeature(string featureName){
    return &features[featureName];
}

vector<string> Model::getFeatureNames(){
    vector<string> featureNames;

    for (auto& x : features){
           featureNames.push_back(x.first);
    }

    return featureNames;
}

void Model::setPointToImageFile(string filepath){
    pti_parser.setFilePath(filepath);
    pti_parser.readFile();
}

void Model::setSurfaceFile(string filepath){
    surface_parser.setFilePath(filepath);
    surface_parser.readFile();
}

void Model::setVolumeFile(string filepath){
    volume_parser.setFilePath(filepath);
    volume_parser.readFile();
}

void Model::setObjectFile(string filepath){
    object_parser.setFilePath(filepath);
    object_parser.readFile();
}


