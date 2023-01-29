#include <string>

class Utils
{
public:
    inline bool doesFileExist(const std::string& name) {
        struct stat buffer;
        return (stat(name.c_str(), &buffer) == 0);
    }

    inline void replace_all(std::string& data, std::string to_search, std::string replace_str) {

        size_t pos = data.find(to_search);

        while (pos != std::string::npos) {
            data.replace(pos, to_search.size(), replace_str);
            pos = data.find(to_search, pos + replace_str.size());
        }
    }
};

