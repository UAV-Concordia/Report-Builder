#include "model.h"
#include "QDebug"
#include <vector>
#include <QFileInfo>


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


    featureName="Feature 3";
    Feature f3(featureName,DEBRIS_PILE);
    f3.computeCentroid();
    f3.setVolume(15);
    entry.first = f3.getName();
    entry.second = f3;

    features.insert(entry);

    featureName="Feature 4";
    Feature f4(featureName,STRUCTURE);
    f4.computeCentroid();
    f4.setVolume(15);
    f4.setStructureState(UNDAMAGED);
    entry.first = f4.getName();
    entry.second = f4;

    features.insert(entry);

    featureName="Feature 5";
    Feature f5(featureName,STRUCTURE);
    f5.computeCentroid();
    f5.setVolume(15);
    f5.setStructureState(DAMAGED);
    entry.first = f5.getName();
    entry.second = f5;


    features.insert(entry);

    featureName="Feature 6";
    Feature f6(featureName,OBJECT);
    f6.computeCentroid();
    f6.setVolume(15);
    f6.setObjectType(CAR);
    entry.first = f6.getName();
    entry.second = f6;


    features.insert(entry);

    featureName="Feature 7";
    Feature f7(featureName,OBJECT);
    f7.computeCentroid();
    f7.setVolume(15);
    f7.setObjectType(TENT);
    entry.first = f7.getName();
    entry.second = f7;

    features.insert(entry);

    featureName="Feature 8";
    Feature f8(featureName,TRAIN);
    f8.computeCentroid();
    f8.setVolume(15);
    f8.setQRCode("the code");
    entry.first = f8.getName();
    entry.second = f8;

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
void Model::deleteDuplicates(string file)
{
    doc.LoadFile(file.c_str());

        XMLElement* rootElement = doc.RootElement();
        rootElement->Attribute("id", "root_doc");
        XMLElement* documentElement = rootElement;//->FirstChildElement();
        //XMLElement* folderElement = documentElement->FirstChildElement();

        for (XMLElement* child = documentElement; child != NULL; child = child->NextSiblingElement())
        {
          //  if ((child->Attribute("name")))
            //{
                qDebug() << "PRINTING 2" << child->Name() << endl;

                //child->DeleteChildren();

             //   XmlMaker::writeObject(obj, child);

                //doc.FirstChildElement()->LinkEndChild(element);

               // doc.SaveFile(file.c_str());

               // return;
            //}
        }
}

void Model::parseObjectFile(){
    QString objectFilePath=QString::fromStdString(object_parser.getFilepath());
    if (!objectFilePath.trimmed().isEmpty())
   {
       // deleteDuplicates(objectFilePath.toStdString());

        //Parse
        qDebug() << "Parsing";
       object_parser.parse();
       qDebug() << "Parsed";
       QFileInfo fileInfo= QFileInfo(objectFilePath);
       QString fileName =fileInfo.fileName();

       QStringList fileNameParts=fileName.split(QChar('_'));
       QString featureName=fileNameParts.first();
       qDebug() << "Feature name: " << featureName;

       //Retrieve data
     qDebug() << "Number of object: " << object_parser.getNumberOfParsedObjects();

           string newFeatureName=featureName.toStdString();
           Feature newFeature(newFeatureName);


           vector< BoundingPoint> newBoundingPoints=object_parser.getBoundingPoints();
           newFeature.setBoundingPoints(newBoundingPoints);
           newFeature.computeCentroid();

           std::pair<std::string, Feature > entry;

           entry.first = newFeatureName;
           entry.second = newFeature;

          features.insert(entry);
                       cout << "inserted feature" << endl;;
       }
}

void Model::parseSurfaceFile(){
    QString surfaceFilePath=QString::fromStdString(surface_parser.getFilepath());
    if (!surfaceFilePath.trimmed().isEmpty())
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
}

void Model::parseVolumeFile(){
    QString volumeFilePath=QString::fromStdString(volume_parser.getFilepath());
    if (!volumeFilePath.trimmed().isEmpty())
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

void Model::parsePointImageFile(){
    QString imagePointFilePath=QString::fromStdString(pti_parser.getFilepath());
    if (!imagePointFilePath.trimmed().isEmpty())
   {
       pti_parser.parse();

        std::unordered_map<std::string, std::vector<MapPoint> > pointMap=pti_parser.getMapPoint();


        for (auto& imageEntry : pointMap){
           vector<MapPoint> points=imageEntry.second;
           for(int i=0;i<points.size();i++){

              for (auto& featureEntry : features){
                   Feature feature=featureEntry.second;
                   vector<BoundingPoint> boundingPoints=feature.getBoundingPoints();

                   for (int j=0;j<boundingPoints.size();j++){
                       if(points.at(i).name==boundingPoints.at(j).name){
                           //Add image to bounding point
                           qDebug() << QString::fromStdString(imageEntry.first);
                           qDebug() << QString::fromStdString(boundingPoints.at(j).name);
                          feature.addImagePath(boundingPoints.at(j).name, imageEntry.first);
                          featureEntry.second=feature;
                       }
                   }

              }

           }
        }

   }
}

void Model::parseData(){

     QString objectFilePath=QString::fromStdString(object_parser.getFilepath());
     if (!objectFilePath.trimmed().isEmpty())
    {
        //Parse
         qDebug() << "Parsing";
        object_parser.parse();
        qDebug() << "Parsed";
        QFileInfo fileInfo= QFileInfo(objectFilePath);
        QString fileName =fileInfo.fileName();

        QStringList fileNameParts=fileName.split(QChar('_'));
        QString featureName=fileNameParts.first();
        qDebug() << "Feature name: " << featureName;

        //Retrieve data
      qDebug() << "Number of object: " << object_parser.getNumberOfParsedObjects();

            string newFeatureName=featureName.toStdString();
            Feature newFeature(newFeatureName);


            vector< BoundingPoint> newBoundingPoints=object_parser.getBoundingPoints();
            newFeature.setBoundingPoints(newBoundingPoints);
            newFeature.computeCentroid();

            std::pair<std::string, Feature > entry;

            entry.first = newFeatureName;
            entry.second = newFeature;

           features.insert(entry);
                        cout << "inserted feature" << endl;;
        }


     QString surfaceFilePath=QString::fromStdString(surface_parser.getFilepath());
     if (!surfaceFilePath.trimmed().isEmpty())
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




     QString volumeFilePath=QString::fromStdString(volume_parser.getFilepath());
     if (!volumeFilePath.trimmed().isEmpty())
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


     QString imagePointFilePath=QString::fromStdString(pti_parser.getFilepath());
     if (!imagePointFilePath.trimmed().isEmpty())
    {
        pti_parser.parse();

         std::unordered_map<std::string, std::vector<MapPoint> > pointMap=pti_parser.getMapPoint();


         for (auto& imageEntry : pointMap){
            vector<MapPoint> points=imageEntry.second;
            for(int i=0;i<points.size();i++){

               for (auto& featureEntry : features){
                    Feature feature=featureEntry.second;
                    vector<BoundingPoint> boundingPoints=feature.getBoundingPoints();

                    for (int j=0;j<boundingPoints.size();j++){
                        if(points.at(i).name==boundingPoints.at(j).name){
                            //Add image to bounding point
                            qDebug() << QString::fromStdString(imageEntry.first);
                            qDebug() << QString::fromStdString(boundingPoints.at(j).name);
                           feature.addImagePath(boundingPoints.at(j).name, imageEntry.first);
                           featureEntry.second=feature;
                        }
                    }

               }

            }
         }

    }


}


