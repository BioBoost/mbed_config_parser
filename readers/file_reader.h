#pragma once

#include "mbed.h"
#include "reader.h"
#include <string>

// FileReader is extension of Reader which can read file
// from the filesystem and put the content into a buffer via read().

namespace ConfigParser {

    class FileReader : public Reader {

        private:
            std::string filePath;
            LocalFileSystem * localFilesystemHandle;

        public:
            FileReader(std::string filePath);
            ~FileReader(void);

        public:
            virtual unsigned int read(char * buffer, unsigned int bufferSize);
    };
};
