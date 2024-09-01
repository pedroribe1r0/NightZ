#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>



    namespace Managers {

        class FileManager {
        private:
            std::ifstream arquivoLeitura;
            std::ofstream arquivoGravar;

            void openFileRead(const char* caminhoArquivo);
            void closeFileRead();
            void openFileSave(const char* caminhoArquivo);
            void closeFileSave();
        public:
            FileManager();
            ~FileManager();
            std::vector<std::string> lerArquivo(const char* caminhoArquivo);
            void saveContent(const char* caminhoArquivo, std::vector<std::string> linhas);
            void saveContent(const char* caminhoArquivo, const std::string linha);
            void removeFile(const char* caminhoArquivo);
        };

    }



