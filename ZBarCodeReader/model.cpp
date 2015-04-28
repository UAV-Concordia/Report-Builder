#include "model.h"
#include "QDebug"
#include <vector>

Model::Model()
{


/*
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
*/

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

void Model::parseData(){

    if (object_parser.getFilepath()!="")
    {
        //Parse
        object_parser.parse();

        //Retrieve data
        qDebug() << "Number of object: " << object_parser.getNumberOfParsedObjects();

        for (int i=0;i<object_parser.getNumberOfParsedObjects();i++){
            string newFeatureName=object_parser.getName(i);
            Feature newFeature(newFeatureName);
            vector< vector< double>> newBoundingPoints=object_parser.getBoundingPolygon(i);
            newFeature.setBoundingPolygon(newBoundingPoints);
            newFeature.computeCentroid();

            std::pair<std::string, Feature > entry;

            entry.first = newFeatureName;
            entry.second = newFeature;

           features.insert(entry);
                        cout << "inserted feature" << endl;;
        }

    }

    if (surface_parser.getFilepath()!="")
    {
        //Parse
        surface_parser.parse();

        //Retrieve data
        qDebug() << "Number of volume: " << surface_parser.getNumberOfVolumetricData();

        for (int i=0;i<surface_parser.getNumberOfVolumetricData();i++){
            VolumetricData newVolumetricData=surface_parser.getVolumetricData(i);

              std::string input=newVolumetricData.objectName;
              std::cout << "who? ";


              std::unordered_map<std::string,Feature>::iterator got = features.find (input);

              if ( got == features.end() ){
                continue;
                   std::cout << "not found";
              }else{
                  std::cout << "found" << got->first;
                  Feature feature= got->second;
                  feature.setArea(newVolumetricData.projected2Darea);
                  got->second=feature;
              }




              std::cout << std::endl;



        }
    }





    if (volume_parser.getFilepath()!="")
    {
        //Parse
        volume_parser.parse();

        //Retrieve data
        qDebug() << "Number of volume: " << volume_parser.getNumberOfVolumetricData();

        for (int i=0;i<volume_parser.getNumberOfVolumetricData();i++){
            VolumetricData newVolumetricData=volume_parser.getVolumetricData(i);

              std::string input=newVolumetricData.objectName;
              std::cout << "who? ";


              std::unordered_map<std::string,Feature>::iterator got = features.find (input);

              if ( got == features.end() ){
                continue;
                   std::cout << "not found";
              }else{
                  std::cout << "found";
                  Feature feature= got->second;
                  feature.setVolume(newVolumetricData.totalVolume);
                  got->second=feature;
              }




              std::cout << std::endl;



        }


    }

}


