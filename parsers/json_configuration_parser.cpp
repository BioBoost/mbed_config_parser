#include "json_configuration_parser.h"

namespace ConfigParser {

  JsonConfigurationParser::JsonConfigurationParser(Reader * reader)
    : ConfigurationParser(reader) {

    load_json();
  }

  void JsonConfigurationParser::load_json(void) {
    char * buffer = new char[1024];
    this->get_reader()->read(buffer, 1024);
    ::parse(this->json, buffer);
    delete buffer;
  }

};
