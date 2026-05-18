#include <string>

class Post {
public:
    Post(const std::string& title, const std::string& content) : title(title), content(content) {}

    int getId() {
        return id;
    }

    std::string getTitle() {
        return title;
    }

    std::string getContent() {
        return content;
    }

private:
    int id;
    std::string title;
    std::string content;
};