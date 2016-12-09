#pragma once

#include "reader.h"
#include <string>

// String is extension of Reader which can read constant string
// put the content into a buffer via read().

namespace ConfigParser {
  class StringReader : public Reader {

      private:
        const std::string * someString;

      public:
        StringReader(const std::string * someString);

      public:
        virtual unsigned int read(char * buffer, unsigned int bufferSize);
  };
};
