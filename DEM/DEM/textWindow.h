#pragma once
#include "Window.h"
#include "DialogueObserver.h"

using namespace std;

class TextWindow : public Window
{
private:

	DialogueObserver* m_dialogueObserver;

public:

	TextWindow();
	~TextWindow();

	Observer* getDialoueObserver();
	
	virtual void Render(sf::RenderWindow* window);
};