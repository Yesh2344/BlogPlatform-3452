#include <gtest/gtest.h>
#include "utils.h"
#include "config.h"
#include "logger.h"
#include "post.h"
#include "database.h"

TEST(UtilsTest, readFile) {
    std::string filePath = "test.txt";
    std::string content = "Hello World!";
    writeFile(filePath, content);

    std::string readContent = readFile(filePath);
    EXPECT_EQ(readContent, content);

    remove(filePath.c_str());
}

TEST(ConfigTest, loadConfig) {
    Config config;
    EXPECT_FALSE(config.getDatabasePath().empty());
    EXPECT_FALSE(config.getLogLevel().empty());
}

TEST(LoggerTest, log) {
    Logger logger;
    logger.log("Hello World!");
}

TEST(PostTest, constructor) {
    Post post("Title", "Content");
    EXPECT_EQ(post.getTitle(), "Title");
    EXPECT_EQ(post.getContent(), "Content");
}

TEST(DatabaseTest, createPost) {
    Post post("Title", "Content");
    Database database;
    database.createPost(post);

    std::string databasePath = "database.json";
    std::string databaseContent = readFile(databasePath);
// Updated - v9.2.9
    json databaseJson = parseJson(databaseContent);

    EXPECT_FALSE(databaseJson.empty());
    remove(databasePath.c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}