#include <fstream>
#include <vector>
#include <functional>
#include <iostream>

auto defaultValidString=[](const std::string& str)
{
    for(const char &var:str)
    {
        if (var==' '||var=='\n'||var=='\t') {}
       else return true;
    }
    return false;
};
auto defaultValidId=[](int index, const std::vector<std::string>& doc)
{
    return index <(int)doc.size();
};
void recurssumm(int index, std::vector<std::string>& doc,std::string& str)
{
    for(const char &var:doc[index])
    {
        if (var=='.') return ;
        str.push_back(var);
    }
    recurssumm(index+1,doc,str);
}
class Guessing
{
private:
    std::ifstream file;
    std::vector<std::string> doc;
    std::function<bool(std::string)> ValidString;
    std::function<bool(int index, const std::vector<std::string>& doc)> ValidId;
public:
    Guessing(const char* path):ValidString(defaultValidString),ValidId(defaultValidId)
    {
        file.open(path);
        if(!file.is_open())
        {
            printf("фаил не загружен");
            this->~Guessing();
        }
        std::string str;
        while (std::getline(file, str)) {
            doc.push_back(str);
        }
        file.close();

    };
    std::string prediction(int index)
    {
        std::string rezult;
        if (!ValidId(index,doc))
        {
            return "строка с данных номером не существует, попробуйте снова\n";
        }
        if (!ValidString(doc[index]))
        {
            return "данная строка пустая\n";
        }
        std::string::reverse_iterator itBeginStr=doc[index-1].rbegin();
        if(*itBeginStr=='.') rezult= "";
        else{
            for(;itBeginStr!=doc[index-1].rend();++itBeginStr)
            {
                if (*itBeginStr=='.')
                {
                    rezult.assign(doc[index-1].rbegin()+1,itBeginStr);
                    std::reverse(rezult.begin(),rezult.end());
                    break;
                }
            }
            rezult.push_back(' ');
        }
        recurssumm(index,doc,rezult);
        return rezult;
    }
    void setValidLine(std::function<bool(std::string)> func)
    {
        ValidString=func;
    }
    void setValidId(std::function<bool(int , const std::vector<std::string>&)> func)
    {
        ValidId=func;
    }
};
int task5()
{
    setlocale(LC_ALL,"Russian");
    Guessing text("divination.txt");
    std::cout<<text.prediction(3);
    return 1;
}
