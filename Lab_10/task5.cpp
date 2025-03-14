#include <fstream>
#include <vector>
#include <functional>

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
void reversrecurssumm(int index, std::vector<std::string>& doc,std::string& str)
{
    std::string temp;
    std::string::reverse_iterator itBeginStr=doc[index-1].rbegin();
    for(;itBeginStr!=doc[index-1].rend();++itBeginStr)
    {
        if (*itBeginStr=='.'||*itBeginStr==';')
        {
            temp.assign(doc[index-1].rbegin()+1,itBeginStr);
            std::reverse(temp.begin(),temp.end());
            str.push_back(' ');
            str=temp+" "+str;
            return;
        }
    }
    str=doc[index-1]+str;
    if(index-1 >=0)
        reversrecurssumm(index-1,doc,str);
}
void recurssumm(int index, std::vector<std::string>& doc,std::string& str)
{
    for(const char &var:doc[index])
    {
        if (var=='.'||var==';') return ;
        str.push_back(var);
    }
    if(index+1 <(int)doc.size())
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
            return "Неверный номер строки. Попробуйте снова\n";
        }
        if (!ValidString(doc[index]))
        {
            return "Полученная строка не содержит предсказание. Попробуйте другой номер\n";
        }
        if(*doc[index-1].rbegin()=='.'||*doc[index-1].rbegin()==';') rezult= "";
        else reversrecurssumm(index,doc,rezult);
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
    int index=0;
    printf("Загадайте желание или задайте интересующий вопрос и введите номер строки: \n");
    while(index!=666)
    {
        scanf("%d",&index);
        setlocale(LC_ALL,"Russian");
        Guessing text("D:\\ProjectQt\\Lab_10\\divination.txt");
        printf("%s\n",text.prediction(index-1).c_str());
    }
    return 1;
}
