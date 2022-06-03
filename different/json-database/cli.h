#pragma cli
#ifndef CLI_H
#define CLI_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Menu option
 *
 * @param name option name
 * @param callback function to call when select the options
 */
struct MenuOption {
  string name;
  void (*callback)(void);
};

/**
 * Universal command line interface
 */
class CLI {
  private:
  protected:
    vector<MenuOption> menuOptions;

  public:
    /**
     * Default constructor
     */
    CLI() {}

    /**
     * Constructor with menu options definitions
     *
     * @param options Menu options
     */
    CLI(vector<MenuOption> options) {
      this->menuOptions = options;
    }

    /**
     * Add menu options
     *
     * @param options Vector of menu Options
     */
    void appendMenu(vector<MenuOption> options) {
      this->menuOptions.assign(options.end(), options.begin());
    }

    /**
     * Reset menu
     *
     * @param options Vector of menu Options
     */
    void resetMenu(vector<MenuOption> options) {
      this->menuOptions = options;
    }

    /**
     * Select menu option
     */
    void selectOptions() {
      clearConsole();

      cout << "Select option:" << endl << endl;

      for (int i = 0; i < menuOptions.size(); i++) {
        cout << " " << i + 1 << " - " << menuOptions[i].name << endl;
      }

      int choice;

      while (true) {
        cout << endl << " > ";

        cin >> choice;

        if (choice - 1 < menuOptions.size() && choice >= 1) {
          break;
        }
      }

      clearConsole();

      menuOptions[choice - 1].callback();

      further();
    }

    /**
     * Select menu option
     *
     * @param menuOptions menu options
     */
    void selectOptions(vector<MenuOption> menuOptions) {
      clearConsole();

      cout << "Select option:" << endl << endl;

      for (int i = 0; i < menuOptions.size(); i++) {
        cout << " " << i + 1 << " - " << menuOptions[i].name << endl;
      }

      int choice;

      while (true) {
        cout << endl << " > ";

        cin >> choice;

        if (choice - 1 < menuOptions.size() && choice >= 1) {
          break;
        }
      }

      clearConsole();

      menuOptions[choice - 1].callback();

      further();
    }

    /**
     * Clear console
     */
    void clearConsole() {
      system("clear");
    }

    /**
     * Further after execution menu option callback
     */
    int further() {
      string input;
      cout << "\nPress enter to continue ";
      getline(cin, input);
      cin.ignore();

      return 0;
    }
};

#endif
