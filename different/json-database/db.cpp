#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>

using namespace std;
using namespace Json;

string input(string view = "\n > ") {
  string input;
  cout << view;
  cin >> input;

  return input;
}

class DB {
  private:
    string filename;
    vector<string> keys;
    Json::Value json;

    void parse() {
      ifstream db(this->filename);
      Json::Value parsed;
      Json::Reader reader;

      reader.parse(db, parsed);

      this->json = parsed;
    }

    void writeJson() {
      Json::StreamWriterBuilder builder;
      std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
      std::ofstream outputFileStream(filename);
      writer -> write(this->json, &outputFileStream);
    }

    void appendJson(Json::Value json) {
      this->json.append(json);
      writeJson();
      parse();
    }

  protected:
  public:
    DB(vector<string> keys, string filename) {
      this->keys = keys;
      this->filename = filename;

      parse();
    }

    void addRecord() {
      Json::Value newRecord;

      for (int i = 0; i < keys.size(); i++) {
        newRecord[keys[i]] = input("Enter " + keys[i] + ": ");
      }

      appendJson(newRecord);
    }

    void resetJson(Json::Value updateJson) {
      this->json = updateJson;
      writeJson();
    }

    Json::Value read() {
      return json;
    }

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

    vector<string> getKeys() {
      return keys;
    }

    Json::Value getJson() {
      return this->json;
    }
};
