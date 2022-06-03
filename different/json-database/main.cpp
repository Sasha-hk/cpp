#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include "db.cpp"
#include "cli.h"

using namespace std;

DB database = DB({"id", "name", "age"}, "db.json");

void addVisitor() {
  database.addRecord();
}

void removeVisitor() {
  string id = input("Enter id to remove: ");

  Json::Value json = database.getJson();
  Json::Value updateJson;

  for (int i = 0; i < json.size(); i++) {
    if (json[i]["id"] != id) {
      updateJson.append(json[i]);
    }
  }

  database.resetJson(updateJson);
}

void findByName() {
  cout << "\n";
  string findBy = input("Enter field to find by: ");
  string value = input("Enter value to fund: ");
  cout << "\n";

  Json::Value found = database.findBy(findBy, value);

  if (found.size() != 0) {
    vector<string> keys = database.getKeys();

    if (found.size() != 1) {
      for (int i = 0; i < found.size(); i++) {
        cout << i + 1 << "." << endl;

        for (int j = 0; j < keys.size(); j++) {
          cout << " > " << keys[j] << " " << found[i][keys[j]] << endl;
        }

        cout << endl;
      }
    } else {
      for (int i = 0; i < keys.size(); i++) {
        cout << "> " << keys[i] << " " << found[0][keys[i]] << endl;
      }
    }
  }
}

void showDatabase() {
  Json::Value json = database.read();

  cout << json << endl;
}

void exitFunction() {
  exit(0);
}

int main() {
  // CLI instance
  CLI cli = CLI({
    {
      "add visitor",
      addVisitor,
    },
    {
      "remove visitor",
      removeVisitor,
    },
    {
      "find by",
      findByName,
    },
    {
      "show database",
      showDatabase,
    },
    {
      "exit",
      exitFunction,
    }
  });

  while (true) {
    cli.selectOptions();
  }

  return 0;
}
