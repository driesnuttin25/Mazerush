#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <stdexcept>

class GameConfig {
    std::map<std::string, int> config;

    void loadConfig(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open config file: " + filename);
        }

        std::string line;
        while (getline(file, line)) {
            if (line.empty() || line[0] == '#' || line[0] == '[') continue; // Skip comments and sections
            std::istringstream iss(line);
            std::string key;
            int value;
            if (getline(iss, key, '=') && iss >> value) {
                config[key] = value;
            }
        }
    }

public:
    GameConfig(const std::string& filename) {
        loadConfig(filename);
    }

    int get(const std::string& key) const {
        auto it = config.find(key);
        if (it != config.end()) {
            return it->second;
        }
        throw std::runtime_error("Config key not found: " + key);
    }
};

#endif // GAMECONFIG_H
