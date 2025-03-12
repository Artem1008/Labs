#include <iostream>
#include <string>
#include <vector>

class Document {
public:
    const std::string Content;
    Document(const std::string& s): Content(s) {}
    virtual void Save() const {
    }
};
class PlainTextDocument: public Document {
public:
    PlainTextDocument(const std::string& s): Document(s) {}
    virtual void Save() const{
        std::cout << Content << "\n";
    }
};
class HTMLDocument: public Document {
public:
    HTMLDocument(const std::string& s): Document(s) {}
    virtual void Save() const{
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>\n";
    }
};
using DocumentCollection = std::vector<Document*>;
void AddDocument(const std::string& content, const std::string& type, DocumentCollection& collection) {
    if (type == "plain") {
        collection.push_back(new PlainTextDocument(content));
    } else if (type == "html") {
        collection.push_back(new HTMLDocument(content));
    }
}
void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection) {
        doc->Save();
    }
}
int task2()
{
    DocumentCollection doc;
    AddDocument("Hello World","plain",doc);
    AddDocument("Param param pam","html",doc);
    PrintCollection(doc);
    return 1;
}
