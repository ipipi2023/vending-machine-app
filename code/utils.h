#ifndef RETRO_UTILS
#define RETRO_UTILS

#include "string"
#include "fstream"
#include "sstream"

using namespace std;

string readFile(const string& fileName) {
    ifstream f(fileName);
    stringstream buffer;
    buffer << f.rdbuf();
    ::remove(fileName.c_str());
    return buffer.str();
}

#endif //RETRO_UTILS