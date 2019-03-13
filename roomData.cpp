#include "main.h"
/**
 * @brief renseigne les data
 * 
 * @param s  nom d'une roomData
 */
void roomData::setName(const std::string s)
{
    if (!s.empty())
        name = s;
    else
        name = "unknown";
}
/**
 * @brief renseigne Id avec Id du .json
 * @todo verifier la validité de l'id
 * @param s id sous forme de string
 */
void roomData::setId(const std::string s)
{
    this->id = s;
}
/**
 * @brief récupère la jvalue 
 * @todo voir si la jValue est ok
 * @param jValue 
 */
void roomData::setAllData(const Json::Value jValue)
{
    jAllVal = jValue;
}
/**
 * @brief concatene le texte de la room choisit
 * @todo faire un peu moins brut de decoffrage
 * @param s  catégorie dans la room par exemple 'Question' dans le .json
 * @return std::string retourne la chaine
 */
std::string roomData::getAllData(const std::string s)
{
    if (jAllVal.isMember(s) && jAllVal[s].isString())
        return jAllVal[s].asString();
    else if (jAllVal[s].isArray())
    {
        std::string st("\n");
        for (auto c : jAllVal[s])
            st.append(c.asString() + "\n");
        return st;
    }
    return "";
}
/**
 * @brief retourne le nom
 * 
 * @return std::string 
 */
std::string roomData::getName()
{
    return (this->name);
}
/**
 * @brief retourne id sous forme de chaine
 * 
 * @return std::string 
 */
std::string roomData::getId()
{
    return id;
}