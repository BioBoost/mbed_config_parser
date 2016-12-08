#include "json_device_configuration.h"

JsonDeviceConfiguration::JsonDeviceConfiguration(ConfigParser::ConfigReader * configReader) {
  char buffer[BUFFER_SIZE];
  configReader->read(buffer, BUFFER_SIZE);
  parse(this->json, buffer);
}

std::string JsonDeviceConfiguration::firmware_version(void) {
  if (json.hasMember("firmware")) {
    return json["firmware"].get<std::string>();
  } else {
    return DeviceConfiguration::firmware_version();
  }
}
