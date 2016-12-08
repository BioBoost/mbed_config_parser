#pragma once

#include "device_configuration.h"
#include "config_reader.h"
#include <string>
#include "MbedJSONValue.h"

class JsonDeviceConfiguration : public DeviceConfiguration {
  private:
    static const unsigned int BUFFER_SIZE = 512;

  private:
    MbedJSONValue json;

  public:
    JsonDeviceConfiguration(ConfigParser::ConfigReader * configReader);

  public:
    virtual std::string firmware_version(void);
};
