#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>



    namespace Managers {

        class FileManager {
        private:
            std::ifstream readFile;
            std::ofstream saveFile;

            void openFileRead(const char* filePath);
            void closeFileRead();
            void openFileSave(const char* filePath);
            void closeFileSave();
        public:
            FileManager();
            ~FileManager();
            std::vector<std::string> lerArquivo(const char* filePath);
            void saveContent(const char* filePath, std::vector<std::string> lines);
            void saveContent(const char* filePath, const std::string lines);
            void removeFile(const char* filePath);
        };

    }



