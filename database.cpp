#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "utils.h"
#include "post.h"

using json = nlohmann::json;

class Database {
public:
    void createPost(const Post& post) {
        std::string databasePath = "database.json";
        json databaseJson;

        try {
            std::string databaseContent = readFile(databasePath);
            databaseJson = parseJson(databaseContent);
        } catch (const std::exception& e) {
            // Initialize database if it doesn't exist
        }

        json postJson = {{"title", post.getTitle()}, {"content", post.getContent()}};
        databaseJson.push_back(postJson);

        writeFile(databasePath, stringifyJson(databaseJson));
    }

    std::vector<Post> getPosts() {
        std::string databasePath = "database.json";
        std::string databaseContent = readFile(databasePath);
        json databaseJson = parseJson(databaseContent);

        std::vector<Post> posts;
        for (const auto& postJson : databaseJson) {
            Post post(postJson["title"], postJson["content"]);
            posts.push_back(post);
        }

        return posts;
    }

    Post getPost(int id) {
        std::string databasePath = "database.json";
        std::string databaseContent = readFile(databasePath);
        json databaseJson = parseJson(databaseContent);

        for (const auto& postJson : databaseJson) {
            if (postJson["id"] == id) {
                return Post(postJson["title"], postJson["content"]);
            }
        }

        return Post("", "");
    }
};