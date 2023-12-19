#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <stdexcept>

class GameConfig {
    std::map<std::string, int> config; // Map to store configuration key-value pairs

    // Private method to load configuration from a file
    void loadConfig(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open config file: " + filename);
        }

        std::string line;
        while (getline(file, line)) {
            // Skip empty lines, comments, and sections
            if (line.empty() || line[0] == '#' || line[0] == '[') continue;
            std::istringstream iss(line);
            std::string key;
            int value;
            // Parse the line to extract key and value
            if (getline(iss, key, '=') && iss >> value) {
                config[key] = value; // Store the key-value pair in the map
            }
        }
    }

public:
    // Constructor to initialize the GameConfig with a configuration file
    GameConfig(const std::string& filename) {
        loadConfig(filename);
    }

    // Method to get the value associated with a given key
    int get(const std::string& key) const {
        auto it = config.find(key);
        if (it != config.end()) {
            return it->second;
        }
        throw std::runtime_error("Config key not found: " + key);
    }
};

#endif // GAMECONFIG_H
