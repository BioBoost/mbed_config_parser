#include "configuration_parser.h"

namespace ConfigParser {

  ConfigurationParser::ConfigurationParser(Reader * reader) {
    this->reader = reader;
  }

  Reader * ConfigurationParser::get_reader() {
    return this->reader;
  }

};
