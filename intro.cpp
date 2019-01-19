#include "main.h"

using namespace std;

intro::intro()
{
    //using namespace Json;
    ifstream ifs("configAHH.json");
    reader.parse(ifs, valJson);
    cout << "\nWelcome to fabulous hunting game Adolph Hitler and other    "
            "bastards\n\t=- version \u03B1 0.001 KiwiTroBien  -="

         << endl;
}

void intro::writeIntro()
{
    cout << "Introduction: " << valJson["Main"]["Introduction"].asString() << endl;
}
