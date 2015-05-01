#include "volumefileparser.h"
#include "qDebug.h"

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

string VolumeFileParser::getFilepath(){
    return filePath;
}

 int VolumeFileParser::getNumberOfVolumetricData(){
    return volumetricData.size();
 }


const VolumetricData& VolumeFileParser::getVolumetricData(int index)
{
    return volumetricData.at(index);
}


void VolumeFileParser::parse(){

    try
    {
      if (!volumetricData.empty())
      {
          qDebug() << "volumeticDara is empty...clearing";

          volumetricData.clear();
        }
       qDebug() << "volumeticDara stuff";
        for(int i=0;i<lines.size();i++){
            if (i%2==0){
                continue;
            }else{
                qDebug() << "volumeticDara stuff 2";
                VolumetricData data;
                vector<string> fields=split('\t',lines.at(i),1);
                data.objectName=fields.at(0);
qDebug() << "volumeticDara stuff 3";
                if (fields.at(1).empty()){
                     data.projected2Dlength=0.0;
                }else{
                     data.projected2Dlength=stod(fields.at(1));
                }
                if (fields.at(2).empty()){
                     data.projected2DlengthError=0.0;
                }else{
                     data.projected2DlengthError=stod(fields.at(2));
                }
                if (fields.at(3).empty()){
                     data.terrain3Dlength=0.0;
                }else{
                     data.terrain3Dlength=stod(fields.at(3));
                }
                if (fields.at(4).empty()){
                     data.terrain3DlengthError=0.0;
                }else{
                     data.terrain3DlengthError=stod(fields.at(4));
                }
                if (fields.at(5).empty()){
                     data.projected2Darea=0.0;
                }else{
                     data.projected2Darea=stod(fields.at(5));
                }
                if (fields.at(6).empty()){
                     data.projected2DareaError=0.0;
                }else{
                     data.projected2DareaError=stod(fields.at(6));
                }
                if (fields.at(7).empty()){
                     data.enclosed3Darea=0.0;
                }else{
                     data.enclosed3Darea=stod(fields.at(7));
                }
                if (fields.at(8).empty()){
                     data.enclosed3DareaError=0.0;
                }else{
                     data.enclosed3DareaError=stod(fields.at(8));
                }
                if (fields.at(9).empty()){
                     data.terrain3Darea=0.0;
                }else{
                     data.terrain3Darea=stod(fields.at(9));
                }
                if (fields.at(10).empty()){
                     data.terrain3DareaError=0.0;
                }else{
                     data.terrain3DareaError=stod(fields.at(10));
                }
                if (fields.at(11).empty()){
                     data.fillVolume=0.0;
                }else{
                     data.fillVolume=stod(fields.at(11));
                }
                if (fields.at(12).empty()){
                     data.fillVolumeError=0.0;
                }else{
                     data.fillVolumeError=stod(fields.at(12));
                }
                if (fields.at(13).empty()){
                     data.cutVolume=0.0;
                }else{
                     data.cutVolume=stod(fields.at(13));
                }
                if (fields.at(14).empty()){
                     data.cutVolumeError=0.0;
                }else{
                     data.cutVolumeError=stod(fields.at(14));
                }
                if (fields.at(15).empty()){
                     data.totalVolume=0.0;
                }else{
                     data.totalVolume=stod(fields.at(15));
                }
               /* if (fields.at(16).empty()){
                     data.totalVolumeError=0.0;
                }else{
                     data.totalVolumeError=stod(fields.at(16));
                }*/
qDebug() << "volumeticDara stuff 4";
                volumetricData.push_back(data);
qDebug() << "volumeticDara stuff 5";
              /*
                for(int j=0;j<fields.size();j++){
                 cout << j << endl;
                 string field=fields.at(j);

                 if (!field.empty())
                    cout<<fields.at(j) << endl;
                }
              */
            }

    }
    }catch(...)
    {
        qDebug() << "Exception when parsing valume file";
    }
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
