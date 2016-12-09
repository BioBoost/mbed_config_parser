#pragma once

// Reader is an abstract class that defines that a reader must
// have a read method which fills a char buffer.
// Extend to class to create your own reader.

namespace ConfigParser {

  class Reader {

    public:
      virtual unsigned int read(char * buffer, unsigned int bufferSize) = 0;

  };

};
