#ifndef SETUPFILE_H
#define SETUPFILE_H

#include <fstream>
#include <iostream>
#include <map>

class SetupFile
{
public:
    SetupFile(std::string &fileName);

    template <class outT>
    outT lookup(const std::string &key);
    template <class outT>
    outT lookupOrDefault(const std::string &key, const outT &Default);
    std::string lookupOrDefault(const std::string &key, const std::string &Default);
private:
    void readSize();
    bool isFromList(const std::string &list, const char &comp);

    std::map<std::string, std::string> map_;
    std::ifstream IFStream;

    template <class ContainerT>
    void tokenize(const std::string& str, ContainerT& tokens,
                  const std::string& delimiters = " ", bool trimEmpty = false,
                  const std::string& quotationChars = "\"");

};

#endif // SETUPFILE_H
