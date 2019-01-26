#include "Editor.h"
#include <iostream>


Editor::Editor()
{
}

Editor::~Editor()
{
}

void Editor::Initialise()
{
	m_RenderWindow.create(sf::VideoMode(1600, 900),"World In Editor");

	if (!m_Font.loadFromFile("cour.ttf"))
	{
		std::cerr << "unable to open file" << std::endl;
	}
	m_map = new Map(48, 48, 32, 32, "bac_tileset.png", &m_defaultView, &m_mapView);
	SaveButton* saveButton = new SaveButton(m_map);
	AddToolBarButton(saveButton);
	
	m_RenderWindow.setView(m_defaultView);

	m_defaultView.reset(sf::FloatRect(0.0f, 0.0f, m_RenderWindow.getSize().x, m_RenderWindow.getSize().y));
	m_mapView.reset(sf::FloatRect(0.0f, 0.0f, m_RenderWindow.getSize().x, m_RenderWindow.getSize().y));
	m_mapView.setSize(m_RenderWindow.getSize().x/2, m_RenderWindow.getSize().y);
	m_mapView.setCenter(sf::Vector2f(m_RenderWindow.getSize().x / 4, m_RenderWindow.getSize().y / 2));
	m_mapView.setViewport(sf::FloatRect(0.0f, 0.0f, 0.5f, 1.0f));

}

void Editor::Loop()
{
	while (m_RenderWindow.isOpen())
	{
		sf::Event e;
		while (m_RenderWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				m_RenderWindow.close();
			}
		}
		Update();
		Render();
	}
}

void Editor::Update()
{
	m_map->Update(&m_RenderWindow);
	for (int i = 0; i < m_Buttons.size(); i++)
	{
		m_Buttons[i]->Update(&m_RenderWindow);
	}


}

void Editor::Render()
{
	m_RenderWindow.clear();

	m_map->Render(&m_RenderWindow);

	for (int i = 0; i < m_Buttons.size(); i++)
	{
		m_Buttons[i]->Render(&m_RenderWindow);
	}

	m_RenderWindow.display();
}

void Editor::AddToolBarButton(Button* button)
{
	button->SetFont(m_Font);
	button->SetGlobalBox(55.0f * m_Buttons.size(), 0.0f, 50.0f, 30.0f);
	button->SetText("text");
	m_Buttons.push_back(button);
}
