# Mbed Configuration Parse

Configuration file parser for mbed platforms.

To use this library you will need to follow the steps below.

## Step 1 - Create a configuration file

Lets take a simple JSON device configuration as an example:

```json
{
  "version": "v1.0 alpha",
  "description": "Low Power GPS module",
  "board": "LPC1768"
}
```

You can save this on the mbed flash drive as `config.jsn`. Take note that mbed
local file system does not support using files with an extension of more than
three characters (see [LocalFileSystem](https://developer.mbed.org/handbook/LocalFileSystem) for more information).

## Step 2 - Create a configuration class

Next we need to make a simple representation of the device configuration.

```c++
#pragma once

#include <string>
#include "configuration.h"

class DeviceConfiguration : public ConfigParser::Configuration {

  public:
    std::string version;
    std::string description;
    std::string board;

  public:
    DeviceConfiguration() {
      version = "1.0";
      description = "DEADBEEF";
      board = "FRDM-KL25Z ";
    }

};
```

The class above inherits from the abstract Configuration class provided by the library.
By initializing the configuration parameters in the constructor we set a default value.
Can be handy if no value is provided in the json configuration file.

## Step 3 - The JSON Parser

While an abstract JSON parser is provided you will still need to extend this class
to actually fill your specific configuration.

In the case above the implementation can be as simple as shown in the following code:

```c++
#pragma once

#include "json_configuration_parser.h"

class JsonDeviceConfigurationParser : ConfigParser::JsonConfigurationParser {

  public:
    JsonDeviceConfigurationParser(ConfigParser::Reader * reader)
      : ConfigParser::JsonConfigurationParser(reader) { }

  public:
    DeviceConfiguration * parse(void) {
      DeviceConfiguration * devConfig = new DeviceConfiguration();

      if (json.hasMember("version")) {
        devConfig->version = this->json["version"].get<std::string>();
      }

      if (json.hasMember("description")) {
        devConfig->description = this->json["description"].get<std::string>();
      }

      if (json.hasMember("board")) {
        devConfig->board = this->json["board"].get<std::string>();
      }

      return devConfig;
    }
};
```

Just create a parse method that returns a new DeviceConfiguration object filled
with the parameters parsed from the JSON string.

## Step 4 - Putting it all together

Basically you need a Reader, a ConfigurationParser and a Configuration.

Example code:

```c++
ConfigParser::FileReader reader("/local/config.jsn");
JsonDeviceConfigurationParser parser(&reader);
DeviceConfiguration *devConfig = parser.parse();

printf("Version = %s\r\n", devConfig->version.c_str());
printf("Description = %s\r\n", devConfig->description.c_str());
printf("Board = %s\r\n", devConfig->board.c_str());

delete devConfig;
```

Don't forget to cleanup the dynamically created configuration.

## No flash drive like Mbed ?

If no flash drive is available or you don't have an EEPROM or such available to save
a configuration you can always save the configuration in flash memory by creating a constant
std::string an making use of the StringReader class instead of the FileReader class.

Let's see an example of this:

```c++
const std::string DEFAULT_DEVICE_CONFIG = "{ \
  \"version\": \"1.0 alpha\", \
  \"description\": \"Low Power LoraWan GPS module\", \
  \"board\": \"LPC1768\"\r\n \
}";

// ...

ConfigParser::StringReader reader(&DEFAULT_DEVICE_CONFIG);
JsonDeviceConfigurationParser parser(&reader);
DeviceConfiguration *devConfig = parser.parse();

printf("Version = %s\r\n", devConfig->version.c_str());
printf("Description = %s\r\n", devConfig->description.c_str());
printf("Board = %s\r\n", devConfig->board.c_str());

delete devConfig;
```

## Dependencies

This library currently only depends on the MbedJSONValue library which can be found at
[https://developer.mbed.org/users/dwini/code/MbedJSONValue/](https://developer.mbed.org/users/dwini/code/MbedJSONValue/)
