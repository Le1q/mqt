#pragma once
#include <string>

class VersionManager {
public:
    static VersionManager& getInstance() {
        static VersionManager instance;
        return instance;
    }
    
    std::string getVersion() const;
    std::string getBuildTime() const;
    std::string getAppName() const;

    // 删除复制构造函数和赋值操作符
    VersionManager(const VersionManager&) = delete;
    VersionManager& operator=(const VersionManager&) = delete;

private:
    VersionManager(); // 私有构造函数
    
    std::string version;
    std::string buildTime;
    std::string appName;
};
