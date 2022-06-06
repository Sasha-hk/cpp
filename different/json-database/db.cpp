#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>

using namespace std;
using namespace Json;

/**
 * Input
 *
 * @param view message before input
 */
string input(string view = "\n > ") {
  string input;
  cout << view;
  cin >> input;

  return input;
}

/**
 * JSON database
 */
class DB {
  private:
    string filename;
    vector<string> keys;
    Json::Value json;

    /**
     * Parse JSON from file
     */
    void parse() {
      ifstream db(this->filename);
      Json::Value parsed;
      Json::Reader reader;

      reader.parse(db, parsed);

      this->json = parsed;
    }

    /**
     * Write JSON to file
     */
    void writeJson() {
      Json::StreamWriterBuilder builder;
      std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
      std::ofstream outputFileStream(filename);
      writer -> write(this->json, &outputFileStream);
    }

    /**
     * Append JSON
     *
     * @param json json to append
     */
    void appendJson(Json::Value json) {
      this->json.append(json);
      writeJson();
      parse();
    }

  public:
    /**
     * Constructor
     *
     * @param keys record keys
     * @param filename json filename
     */
    DB(vector<string> keys, string filename) {
      this->keys = keys;
      this->filename = filename;

      parse();
    }

    /**
     * Add record to database
     */
    void addRecord() {
      Json::Value newRecord;

      for (int i = 0; i < keys.size(); i++) {
        newRecord[keys[i]] = input("Enter " + keys[i] + ": ");
      }

      appendJson(newRecord);
    }

    /**
     * Reset JSON
     *
     * @param updateJson json to reset
     */
    void resetJson(Json::Value updateJson) {
      this->json = updateJson;
      writeJson();
    }

    /**
     * Get JSON
     */
    Json::Value read() {
      return json;
    }

    /**
     * Find record by
     *
     * @param key to find by
     * @param value to find by
     */
    Json::Value findBy(string key, string value) {
      bool found = false;
      Json::Value result;

      for (int i = 0; i < keys.size(); i++) {
        if (keys[i] == key) {
          found = true;
          break;
        }
      }

      if (!found) {
        return result;
      }

      for (int i = 0; i < json.size(); i++) {
        if (json[i][key] == value) {
          result.append(json[i]);
        }
      }

      return result;
    }

    /**
     * Get record keys
     */
    vector<string> getKeys() {
      return keys;
    }

    /**
     * Get JSON
     */
    Json::Value getJson() {
      return this->json;
    }
};
