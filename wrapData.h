#include "main.h"

template <typename T, const std::string root = "">
class wrapData
{
    Json::Value jsonData;
    Json::Reader reader;
    T valData;
    int idSection;

  public:
    virtual int getIdSection();
    virtual void setIdSection(int);
    virtual void setJsonFile(std::string fileConfig);
    virtual void setNameSection(std::string s);
    const T &getField(std::string field, const T &ret);
};

template <typename T, const std::string root>
wrapData<T, root>::wrapData(std::string fileConfig)
{
    bool b = reader.parse(fileConfig, jsonData[root], false);
    if (!b)
        std::cout << "Error: " << reader.getFormattedErrorMessages();
}

template <typename T, const std::string root>
const T &wrapData<T, root>::getField(std::string field, const T &ret)
{
    return valData;
}