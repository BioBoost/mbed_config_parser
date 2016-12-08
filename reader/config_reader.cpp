#include "config_reader.h"

namespace ConfigParser {

    ConfigReader::ConfigReader(std::string configPath) {
      this->configPath = configPath;
      localFilesystemHandle = new LocalFileSystem("local");
    }

    ConfigReader::~ConfigReader(void) {
        delete localFilesystemHandle;
    }

    unsigned int ConfigReader::read(char * buffer, unsigned int bufferSize) {
      FILE * file = fopen(configPath.c_str(), "r");

      if (!file) {
        buffer[0] = '\0';
        return 0;
      }

      unsigned int i = 0;
      while (i < bufferSize-1 && !feof(file)) {
           buffer[i++] = fgetc(file);
      }
      buffer[i] = '\0';   // Not sure if needed but better safe than sorry
      fclose(file);

      return i;
    }

};
