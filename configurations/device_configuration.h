#pragma once
#include <string>

class DeviceConfiguration {
  public:
    virtual std::string firmware_version(void) { return "1.0"; }
};
