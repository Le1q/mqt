#include "version_manager.h"

VersionManager::VersionManager() {
    version = "1.0.0";
    buildTime = __DATE__ " " __TIME__;
    appName = "Peace & Love";
}

std::string VersionManager::getVersion() const {
    return version;
}

std::string VersionManager::getBuildTime() const {
    return buildTime;
}

std::string VersionManager::getAppName() const {
    return appName;
}
