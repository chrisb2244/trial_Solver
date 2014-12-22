#include "SetupFile.H"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/trim_all.hpp>
#include <sstream>
#include <string>

SetupFile::SetupFile(std::string &fileName):
    IFStream(fileName.c_str())
{
    readSize();
}

std::string SetupFile::lookupOrDefault(const std::string &key, const std::string &Default)
{
    std::string str;
    try {
        str = map_.at(key);
    }
    catch (std::out_of_range) {
        std::cerr << "Couldn't find value for " << key
                  << ". Defaulting to " << Default << std::endl;
        return Default;
    }
    return str;
}

template <class outT>
outT SetupFile::lookupOrDefault(const std::string &key, const outT &Default)
{
    std::string str;
    try {
        str = map_.at(key);
    }
    catch (std::out_of_range) {
        std::cerr << "Couldn't find value for " << key
                  << ". Defaulting to " << Default << std::endl;
        return Default;
    }
    std::stringstream ss(str);
    outT val;
    try {
        ss >> val;
    }
    catch (std::out_of_range) {

    }
    return val;
}

template <class outT>
outT SetupFile::lookup(const std::string &key)
{
    std::string value = map_.at(key);
    std::stringstream ss(value);
    outT val;
    try {
        ss >> val;
    }
    catch (std::out_of_range) {

    }
    return val;
}

template int      SetupFile::lookup(const std::string &key);
template double   SetupFile::lookup(const std::string &key);

//template std::string SetupFile::lookupOrDefault(const std::string &key, const std::string &Default);
template int      SetupFile::lookupOrDefault(const std::string &key, const int &Default);
template double   SetupFile::lookupOrDefault(const std::string &key, const double &Default);

void SetupFile::readSize()
{
    std::string str;
    std::string delimitingChars = " \t,";
    std::string quotationChars = "\"()";

    while (std::getline(IFStream >> std::ws, str))
    {
        if (str[0] == '#'){
            continue;
        }
        std::vector<std::string> tempVec;
        boost::trim_all(str);
        tokenize(str, tempVec, delimitingChars, true, quotationChars);
        if (tempVec.size() == 2) {
            map_.emplace(std::string(tempVec[0]), std::string(tempVec[1]));
            std::cout<< "Added " << tempVec[0] << " = " << tempVec[1] << std::endl;
        }
    }
}

template <class ContainerT>
void SetupFile::tokenize(const std::string& str, ContainerT& tokens,
              const std::string& delimiters, bool trimEmpty,
              const std::string& quotationChars)
{
    std::string::size_type pos, endPos, lastPos = 0;
    using value_type    = typename ContainerT::value_type;
    using size_type     = typename ContainerT::size_type;

    while(true)
    {
        pos = str.find_first_of(delimiters, lastPos);
//        std::cout << "str[pos] = " << str[pos] << std::endl;
        if (pos == std::string::npos)
        {
            pos = str.length();
            if (pos != lastPos || !trimEmpty)
            {
                tokens.push_back(value_type(str.data()+lastPos,
                                            (size_type)pos-lastPos)
                                 );
                break;
            }
        }
        else
        {
            if (isFromList(quotationChars, str[lastPos]))
            {
//                std::cout << "Found character " << str[lastPos] << std::endl;
                endPos = str.find_first_of(quotationChars, lastPos+1);
//                std::cout<< "endPos char = " << str[endPos] << std::endl;
                std::string temp(value_type(str.data()+lastPos,
                                            ((size_type)endPos+1)-lastPos));
//                std::cout << "temp = " << temp << std::endl;
                tokens.push_back(temp);
                lastPos = endPos + 1;
                if (lastPos == str.length())
                {
                    break;
                }
                pos = endPos;
                continue;
            }

            if (pos != lastPos || !trimEmpty)
            {
//                std::cout << "in loop" << std::endl;
                std::string temp(value_type(str.data()+lastPos,
                                            (size_type)pos - lastPos));
//                std::cout<< "temp = (in loop) " << temp << std::endl;
                tokens.push_back(temp);
            }
        }
        lastPos = pos + 1;
    }
}

bool SetupFile::isFromList(const std::string& list, const char& comp)
{
    for (const char c : list)
    {
        if ( c == comp ){
            return true;
        }
    }
    return false;
}
