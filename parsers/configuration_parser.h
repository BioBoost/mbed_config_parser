#pragma once

#include "reader.h"
#include "configuration.h"

// Abstract class ConfigurationParser defines the public interface of a
// configuration parser. Should have a parse() method that returns a subclass
// of Configuration.

namespace ConfigParser {

  class ConfigurationParser {
    private:
      Reader * reader;

    public:
      ConfigurationParser(Reader * reader);

    public:
      Reader * get_reader();

    public:
      virtual Configuration * parse(void) = 0;
  };

};
