#include "FileManager.h"




    namespace Managers {

        FileManager::FileManager() :
            saveFile(), readFile()
        {

        }

        FileManager::~FileManager() {
            if (readFile.is_open()) {
                readFile.close();
            }
            if (saveFile.is_open()) {
                saveFile.close();
            }
        }

        void FileManager::openFileRead(const char* caminhoArquivo) {
            readFile.open(caminhoArquivo);
            if (!readFile.is_open()) {
                std::cout << "ERRO::GerenciadorArquivo::nao foi possivel abrir o arquivo " << caminhoArquivo << std::endl;
                exit(1);
            }
        }

        void FileManager::closeFileRead() {
            readFile.close();
        }

        void FileManager::openFileSave(const char* caminhoArquivo) {
            saveFile.open(caminhoArquivo, std::ios::app);
            if (!saveFile.is_open()) {
                std::cout << "ERRO::GerenciadorArquivo::nao foi possivel abrir o arquivo " << caminhoArquivo << std::endl;
                exit(1);
            }
        }

        void FileManager::closeFileSave() {
            saveFile.close();
        }

        std::vector<std::string> FileManager::lerArquivo(const char* caminhoArquivo) {
            openFileRead(caminhoArquivo);
            std::vector<std::string> linhas;
            std::string linha = "";
            while (std::getline(readFile, linha)) {
                linhas.push_back(linha);
            }
            closeFileRead();
            return linhas;
        }

        void FileManager::saveContent(const char* caminhoArquivo, std::vector<std::string> linhas) {
            openFileSave(caminhoArquivo);
            std::string linha = "";
            for (int i = 0; i < linhas.size(); i++) {
                saveFile << linhas[i] << " " << std::endl;
            }
            closeFileSave();
        }

        void FileManager::saveContent(const char* caminhoArquivo, const std::string linha) {
            openFileSave(caminhoArquivo);
            const char quebraLinha = 10;
            saveFile << linha << " " << quebraLinha;
            closeFileSave();
        }

        void FileManager::removeFile(const char* caminhoArquivo) {
            remove(caminhoArquivo);
        }

    }




