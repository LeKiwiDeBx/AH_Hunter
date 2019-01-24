#include "main.h"

using namespace std;
//
intro::intro()
{
    //using namespace Json;
    ifstream ifs("configAHH.json");
    reader.parse(ifs, valJson);
    cout << "\nWelcome to fabulous hunting game Adolph Hitler and other    "
            "bastards\n\t=- version \u03B1 0.001 KiwiTroBien  -="

         << endl;
    writeIntro();
}

void intro::writeIntro()
{
    cout << "Introduction: " << valJson["Main"]["Introduction"].asString() << endl;
    cout << "test parser" << endl;
    Json::StyledWriter styled;
    for (Json::Value::const_iterator it = valJson["Room"].begin(); it != valJson["Room"].end(); ++it)
    {
        cout << it.key().asString() << "--> " << '\n';
        std::string s = it.key().asString();
        for (Json::Value::const_iterator it = valJson["Room"][s].begin(); it != valJson["Room"][s].end(); ++it)
            if (it.key().asString().compare("Reponse") == 0)
            {
                cout << it.key().asString() << " " << endl;
                for (unsigned int k = 0; k < valJson["Room"][s]["Reponse"].size(); k++)
                {
                    cout << "-->" << valJson["Room"][s]["Reponse"][k] << '\n';
                }
            }
    }
}
