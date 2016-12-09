#include "string_reader.h"

namespace ConfigParser {

    StringReader::StringReader(const std::string * someString)
      : someString(someString) { }

    unsigned int StringReader::read(char * buffer, unsigned int bufferSize) {
      if (someString->length() < bufferSize) {
        unsigned int size = someString->copy(buffer, bufferSize-1);
        buffer[size] = '\0';
        return size+1;
      }

      return 0;
    }

};
