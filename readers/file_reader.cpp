#include "file_reader.h"

namespace ConfigParser {

    FileReader::FileReader(std::string filePath) {
      this->filePath = filePath;
      localFilesystemHandle = new LocalFileSystem("local");
    }

    FileReader::~FileReader(void) {
        delete localFilesystemHandle;
    }

    unsigned int FileReader::read(char * buffer, unsigned int bufferSize) {
      FILE * file = fopen(filePath.c_str(), "r");

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
