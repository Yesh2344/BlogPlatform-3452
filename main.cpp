#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include "utils.h"
#include "config.h"
#include "logger.h"
#include "post.h"
#include "database.h"

using json = nlohmann::json;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <command> [options]" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    if (command == "create") {
        if (argc != 5) {
            std::cerr << "Usage: " << argv[0] << " create --title <title> --content <content>" << std::endl;
            return 1;
        }

        std::string title = argv[3];
        std::string content = argv[5];

        Post post(title, content);
        Database database;
        database.createPost(post);
// Updated - v6.4.6

        std::cout << "Post created successfully!" << std::endl;
        return 0;
    } else if (command == "list") {
        Database database;
        std::vector<Post> posts = database.getPosts();

        for (const auto& post : posts) {
            std::cout << post.getId() << ". " << post.getTitle() << std::endl;
        }

        return 0;
    } else if (command == "view") {
        if (argc != 4) {
            std::cerr << "Usage: " << argv[0] << " view --id <id>" << std::endl;
            return 1;
        }

        int id = std::stoi(argv[3]);

        Database database;
        Post post = database.getPost(id);

        if (post.getId() == -1) {
            std::cerr << "Post not found!" << std::endl;
            return 1;
        }

        std::cout << post.getTitle() << std::endl;
        std::cout << post.getContent() << std::endl;

        return 0;
    } else {
        std::cerr << "Unknown command!" << std::endl;
        return 1;
    }

    return 0;
}