#include "pointtoimageparser.h"
#include "QDebug"

PointToImageParser::PointToImageParser()
{

}


PointToImageParser::~PointToImageParser()
{

}



vector<string>& PointToImageParser::readFile(){

    string pointToImageLine;
    std::ifstream pointToImageFile(filePath);

    if (!lines.empty()) lines.clear();

    if (pointToImageFile.is_open())
    {
        while (std::getline(pointToImageFile, pointToImageLine)) { //Read a line

            lines.push_back(pointToImageLine);
        }

        qDebug() << "File read!" ;
    }
    else{
        qDebug() << "File doesn't not exist!" ;
    }

    return lines;
}

void PointToImageParser::setFilePath(string path){
    filePath = path;
}

string PointToImageParser::getFilepath(string path){
    return filePath;
}


vector<string>& PointToImageParser::split(char delim, string toParse, int rep){

    if (!flds.empty()) flds.clear();

    string work = toParse;
    string buf = "";
    unsigned i = 0;
    while (i < work.length()) {
        //cout << work[i] << endl;

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

void PointToImageParser::parse(){

    //booleans
    bool image = true;


    //Group by image
    MapPoint point;
    std::unordered_map<std::string, std::vector<MapPoint> > pointMap;
    string currentImage="";

    //split('\n',)
    for (int i = 0; i < lines.size(); i++){
        string line = lines.at(i);

        if (image)
        {
            image = false;

            vector<string> imageInfo = split(' ', line, 0);

            std::pair<std::string, std::vector<MapPoint> > entry;
            currentImage = imageInfo.at(0);
            entry.first = currentImage;

            std::vector<MapPoint> newPointList;
            entry.second = newPointList;

            pointMap.insert(entry);
            cout << "image" << endl;;
        }
        else
        {
            if (isInteger(line)){

                cout << "end of image data" << endl;;
                image = true;
            }
            else
            {


                cout << "point" << endl;



                vector<string> pointInfo = split(' ', line, 0);

                point.name = pointInfo.at(0);
                point.xPixel = stold(pointInfo.at(1));
                point.yPixel = stold(pointInfo.at(2));


                //vector<MapPoint> pointList = pointMap[currentImage];
                pointMap[currentImage].push_back(point);


                /*for (int j = 0; j < pointInfo.size(); j++){
                    cout << pointInfo.at(j)<< endl;
                    }*/



                //double coord = stold(coordinate.at(j));


            }

        }

    }


    std::cout << "my point map contains:" << std::endl;
    for (auto& x : pointMap){
        std::cout << x.first << endl;
        for (auto& y : x.second){
            std::cout << y.name << endl;
        }
    }
}


bool PointToImageParser::isInteger(const std::string & s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char * p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}
