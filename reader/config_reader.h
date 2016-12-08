#pragma once

#include "mbed.h"
#include <string>

namespace ConfigParser {

    class ConfigReader {

        private:
            std::string configPath;
            LocalFileSystem * localFilesystemHandle;

        public:
            ConfigReader(std::string configPath);
            ~ConfigReader(void);

        public:
            unsigned int read(char * buffer, unsigned int bufferSize);
    };
};
