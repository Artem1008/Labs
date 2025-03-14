#include <string>
#include <fstream>
#include <list>
#include <memory>
#include <sstream>
#include <map>
class ILog {
public:
    virtual ~ILog(){};
    virtual void log(const char* message) = 0;
};


class LogConsole: public ILog
{
public:
    void log(const char* message) override {
        printf(message);
        printf("\n");
    }
    virtual ~LogConsole(){};
};
class LogFile: public ILog
{
private:
    std::ofstream file;
public:
    LogFile()
    {
        file.open("log.txt");
        if (!file.is_open()) {
            printf("фаил не загружен");
        }
    }
    void log(const char* message) override {
        if (file.is_open()) {
            file << message <<'\n';
        }
    }
    ~LogFile()
    {
        file.close();
    };
};
class Loger: public ILog
{
private:
    std::ifstream file;
    std::list<std::unique_ptr<ILog>> loglist;
    std::map<std::string,int> config;
    void createLoger()
    {
        if (config.count("level_log") > 0)
        {
            if (config["level_log"]&1) loglist.push_back(std::make_unique<LogConsole>());
            if (config["level_log"]&2) loglist.push_back(std::make_unique<LogFile>());
        }
        else
        {
            printf("ключ level_log не найден");
        }
    }
public:
    Loger(const char* path)
    {
        //читаем конфигурацию
        readconfig(path);
        //создаем логеры
        createLoger();
    }
    void readconfig(const char* path)
    {
        file.open(path);
        if (!file.is_open()) {
            printf("фаил конфигурации не загружен");
        }
        std::string line;
        while (std::getline(file, line))
        {
            std::string key;
            int value;
            char check;
            if (line.empty() || line[0] == '#')
                continue;
            std::stringstream ss;
            ss<<line;
            ss>>key>>check>>value;
            if (check!='=')
            {
                printf("Ошибка фаила конфигурации");
                continue;
            }
            config[key]=value;
        }
        file.close();
    }
    void log(const char* message) override {
        for(const auto &var:loglist)
        {
            var->log(message);
        }
    }
    ~Loger(){};
};

int task3()
{
    Loger loger("log.config");
    loger.log("всё плохо плохо");
    loger.log("дела мои, прямо сказать: \"не важно\"");
    return 1;
}
