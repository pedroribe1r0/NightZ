#include "LeaderBoardsMenu.h"
#define BUTTON_SIZE_X 100
#define BUTTON_SIZE_Y 100

namespace Menu {
	LeaderBoardsMenu::LeaderBoardsMenu() : Menu(ID::leaderboards_menu, sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "LeaderBoards", 100) {
		
		background.addLayer("layer11.png", 0.0f, GraphicalElements::LID::empty);
		background.addLayer("layer10.png", 0.00000005f, GraphicalElements::LID::empty);
		background.addLayer("layer9.png", 0.0000001f, GraphicalElements::LID::empty);
		background.addLayer("layer8.png", 0.000003f, GraphicalElements::LID::empty);
		background.addLayer("layer7.png", 0.00006f, GraphicalElements::LID::empty);
		background.addLayer("layer6.png", 0.0007f, GraphicalElements::LID::empty);
		background.addLayer("layer5.png", 0.0008f, GraphicalElements::LID::empty);
		background.addLayer("layer4.png", 0.0009f, GraphicalElements::LID::empty);
		background.addLayer("layer3.png", 0.005f, GraphicalElements::LID::empty);
		background.addLayer("layer2.png", 0.06f, GraphicalElements::LID::empty);
		background.addLayer("layer1.png", 0.08f, GraphicalElements::LID::empty);
		background.addLayer("layer0.png", 0.1f, GraphicalElements::LID::floor);
		title.setPos(sf::Vector2f(windowSize.x / 2.0f - title.getSize().x / 2.0f, 220.0f));
		title.setTextColor(sf::Color{ 255, 255, 255 });
		title.setFontSize(90);
		title.setBorderSize(8);

		createLeaderBoard();
		
	}
	LeaderBoardsMenu::~LeaderBoardsMenu() {
		for (int i = 0; i < textVector.size(); i++) {
			Button::Text* text = textVector[i];
			if (text) {
				delete(text);
				text = nullptr;
			}
		}
	}
	void LeaderBoardsMenu::createButtons() {
		
	}
	void LeaderBoardsMenu::render() {
		background.render();
		background.renderFloor();
		std::list<Button::TextButton*>::iterator aux;
		for (int i = 0; i < textVector.size(); i++) {
			Button::Text* text = textVector[i];
			pGraphic->render(text->getText());
		}
		pGraphic->render(title.getText());
	}
	void LeaderBoardsMenu::execute(float dt) {
		render();
		pGraphic->centerView(Math::CoordF(windowSize.x / 2.0f, windowSize.y / 2.0f));
	}

	void LeaderBoardsMenu::loadLeaderBoards(string line) {
		std::string espaco = " ";
		size_t pos = 0;
		std::vector<std::string> palavras;
		while ((pos = line.find(espaco)) != std::string::npos) {
			palavras.push_back(line.substr(0, pos));
			line.erase(0, pos + espaco.length());
		}
		std::string pontos = "....................";
		std::string novaLinha = palavras[0] + pontos;

		while (novaLinha.length() < 13) {
			novaLinha += ".";
		}
		novaLinha += palavras[1];

		Button::Text* text = new Button::Text(pGraphic->loadFont("yoster.ttf"), novaLinha, 20);
		text->setBorderSize(4.0f);
		const int qtdVector = textVector.size();
		const float tam = text->getSize().x;
		text->setPos(sf::Vector2f(pGraphic->getWindowSize().x / 2.0f - tam / 2.0f - 40.0f, 150.0f + 50.0f * qtdVector + 300.0f));
		textVector.push_back(text);
	}

	void LeaderBoardsMenu::createLeaderBoard() {
		Managers::FileManager file;
		std::vector<std::string> linhas = file.lerArquivo("./leaderboards.txt");
		if (linhas.size() >= 10) {
			file.removeFile("./leaderboards.txt");
		}
		for (int i = 0; i < linhas.size() && i < 7; i++) {
			loadLeaderBoards(linhas.at(i));
		}
	}
}
