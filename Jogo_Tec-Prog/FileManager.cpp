#include "FileManager.h"




    namespace Managers {

        FileManager::FileManager() :
            arquivoGravar(), arquivoLeitura()
        {

        }

        FileManager::~FileManager() {
            if (arquivoLeitura.is_open()) {
                arquivoLeitura.close();
            }
            if (arquivoGravar.is_open()) {
                arquivoGravar.close();
            }
        }

        void FileManager::openFileRead(const char* caminhoArquivo) {
            arquivoLeitura.open(caminhoArquivo);
            if (!arquivoLeitura.is_open()) {
                std::cout << "ERRO::GerenciadorArquivo::nao foi possivel abrir o arquivo " << caminhoArquivo << std::endl;
                exit(1);
            }
        }

        void FileManager::closeFileRead() {
            arquivoLeitura.close();
        }

        void FileManager::openFileSave(const char* caminhoArquivo) {
            arquivoGravar.open(caminhoArquivo, std::ios::app);
            if (!arquivoGravar.is_open()) {
                std::cout << "ERRO::GerenciadorArquivo::nao foi possivel abrir o arquivo " << caminhoArquivo << std::endl;
                exit(1);
            }
        }

        void FileManager::closeFileSave() {
            arquivoGravar.close();
        }

        std::vector<std::string> FileManager::lerArquivo(const char* caminhoArquivo) {
            openFileRead(caminhoArquivo);
            std::vector<std::string> linhas;
            std::string linha = "";
            while (std::getline(arquivoLeitura, linha)) {
                linhas.push_back(linha);
            }
            closeFileRead();
            return linhas;
        }

        void FileManager::saveContent(const char* caminhoArquivo, std::vector<std::string> linhas) {
            openFileSave(caminhoArquivo);
            std::string linha = "";
            for (int i = 0; i < linhas.size(); i++) {
                arquivoGravar << linhas[i] << " " << std::endl;
            }
            closeFileSave();
        }

        void FileManager::saveContent(const char* caminhoArquivo, const std::string linha) {
            openFileSave(caminhoArquivo);
            const char quebraLinha = 10;
            arquivoGravar << linha << " " << quebraLinha;
            closeFileSave();
        }

        void FileManager::removeFile(const char* caminhoArquivo) {
            remove(caminhoArquivo);
        }

    }




