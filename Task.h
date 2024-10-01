#include <iostream>
#include <ctime>

class Task {

private:
    std::string title = "No title";
    std::string content = "No content";
    std::string dueDate = "";

    std::string getCurrentDate() {
        std::time_t now = std::time(nullptr);

        // Convert the time to a string
        char dateStr[100];
        std::strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", std::localtime(&now));

        return dateStr;
    }
public:
    Task(){
        //no params, default settings.
        this->dueDate = getCurrentDate();
    }

    Task(const std::string title, const std::string &content, const std::string dueDate){
        this->title = title;
        this->content = content;
        this->dueDate = dueDate;
    }


    void setTitle(std::string newTitle){
        this->title = newTitle;
    }
    void setContent(std::string newContent){
        this->content = newContent;
    }
    void setDueDate(std::string newDueDate){
        this->dueDate = newDueDate;
    }

    std::string getTitle(){
        return this->title;
    }
    std::string getContent(){
        return this->content;
    }
    std::string getDueDate(){
        return this->dueDate;
    }
    


    void showData(){
        std::cout<< "\n\nTitle: " << this->title << std::endl;
        std::cout<< "Content: " << this->content << std::endl;
        std::cout<< "Due date: " << this->dueDate << "\n\n" << std::endl;
    }




};