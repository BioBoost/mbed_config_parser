#pragma once

#include "configuration_parser.h"
#include "MbedJSONValue.h"

// Extension of a configuration parser that parses a Configuration of a JSON
// string. Currently still abstract as extension is needed based on specific
// configuration.

namespace ConfigParser {

  class JsonConfigurationParser : public ConfigurationParser {
    protected:
      MbedJSONValue json;

    public:
      JsonConfigurationParser(Reader * reader);

    private:
      void load_json(void);
  };

};
