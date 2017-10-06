#ifndef EXPORTDATA_HPP
#define EXPORTDATA_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::ofstream;
using std:: vector;
using std:: endl;
using std:: ostringstream;
class ExportData{
    public:
        ofstream manager;
        ExportData(string);
        void writeFile(ostringstream&);
    private:
        vector<string> explode(string&, char);

};

#endif