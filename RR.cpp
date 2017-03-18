#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
using namespace sf;
using namespace lexa;
using namespace std;
bool startgame(){
	bool game = true;
	Font font;
	font.loadFromFile("source/1.ttf");
	Text text("", font, 25);
	text.setFillColor(Color::White);
	Text rec("", font, 25);
	rec.setFillColor(Color::White);
	Text numdice("", font, 25);
	numdice.setFillColor(Color::White);
	Text numdice1("", font, 25);
	numdice.setFillColor(Color::White);
	Text rule("", font, 25);
	rule.setFillColor(Color::White);
	Text help("", font, 25);
	rule.setFillColor(Color::White);
	RenderWindow app(VideoMode(1000, 480), "Dice");
	app.setFramerateLimit(60);
	Image el;
	el.loadFromFile("source/dice.png");
	el.createMaskFromColor(Color(255, 255, 255));
	Texture back, texel,rules;
	back.loadFromFile("source/background.png");
	rules.loadFromFile("source/rule.png");
	texel.loadFromImage(el);
	Sprite background(back), dice1(texel), dice2(texel),dice11(texel), dice22(texel),ruleb(rules);
	int y = 0;
	int x = 0;
	int xy = 0;
	int y1 = 0;
	int x1 = 0;
	int xy1 = 0;
	int count = 0;
	int count1 = 0;
	int sum = 0;
	int sum1 = 0;
	bool zap = true;
	while (app.isOpen())
	{

		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed || (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape))
				return(false);
			if ((e.type == Event::KeyPressed && e.key.code == Keyboard::R))
				return(true);
			if (e.type == Event::MouseButtonPressed)
			if (e.key.code == Mouse::Right)
			{
				if (count1!=count+2)
				{
					x1 = 1 + rand() % 6;
					dice11.setTextureRect(IntRect((x1 - 1) * 150, 0, 150, 150));
					count1++;
					if (x1 == y1)
					{
						xy1 = xy1 + 1;
					}
					y1 = 1 + rand() % 6;
					dice22.setTextureRect(IntRect((y1 - 1) * 150, 0, 150, 150));
					count1++;
					if (y1 == x1)
					{
						xy1 = xy1 + 1;
					}
				}
			}
			if (e.type == Event::MouseButtonPressed)
			if (e.key.code == Mouse::Middle)
			{
				switch (zap)
				{
				case true:
				{
				 rule.setString(L"Ëåâàÿ êíîïêà ìûøè îòâå÷àåò çà áðîñîê ïåðâîãî èãðîêà, \nÏðàâàÿ êíîïêà ìûøè îòâå÷àåò çà áðîñîê âòîðîãî èãðîêà\nR-Ðåñòàðò\nÓäà÷íîé èãðû.");
				 rule.setPosition(45, 20);
				 ruleb.setPosition(0, 0);
				 zap = false;
				 break; }
				case false:
				{			 
				rule.setString("");
				zap = true;
				break; }
				}
			}

			if (e.type == Event::MouseButtonPressed)
			if (e.key.code == Mouse::Left)
			{
				if (count != count1 + 2)
				{
					x = 1 + rand() % 6;
					dice1.setTextureRect(IntRect((x - 1) * 150, 0, 150, 150));
					count++;
					if (x == y)
					{
						xy = xy + 1;
					}
					y = 1 + rand() % 6;
					dice2.setTextureRect(IntRect((y - 1) * 150, 0, 150, 150));
					count++;
					if (y == x)
					{
						xy = xy + 1;
					}
				}
			}
		}
		sum = x + y;
		sum1 = x1 + y1;
		if ((x > 0) && (x1 > 0) && (y > 0) && (y1 > 0) && (count == count1))
	{
			ofstream Save("save.txt");
			if (sum > sum1)
		{
				rec.setString(L"Ïåðâûé èãðîê ïîáåäèë ");
				rec.setPosition(350, 400);
				Save << "Ïåðâûé èãðîê ïîáåäèë ";
		}
			if (sum1 > sum)
		{
				rec.setString(L"Âòîðîé èãðîê ïîáåäèë ");
				rec.setPosition(350, 400);
				Save << "Âòîðîé èãðîê ïîáåäèë ";
		}
			if (sum == sum1)
		{
			rec.setString(L"Íè÷üÿ ");
			rec.setPosition(350, 400);
			Save << "Áûëà íè÷üÿ";
		}
	}
		ostringstream sumstring;
		sumstring << sum;
		ostringstream countstring;
		countstring << count;
		ostringstream xystring;
		xystring << xy;
		numdice.setString(L"Áðîøåíî êîñòåé " + countstring.str()+ L"\nÊîëè÷åñòâî äóáëåé "+ xystring.str()+L"\nÑóììà " + sumstring.str());
		numdice.setPosition(100, 300);
		ostringstream sumstring1;
		sumstring1 << sum1;
		ostringstream countstring1;
		countstring1 << count1;
		ostringstream xystring1;
		xystring1 << xy1;
		numdice1.setString(L"Áðîøåíî êîñòåé " + countstring1.str() + L"\nÊîëè÷åñòâî äóáëåé " + xystring1.str() + L"\nÑóììà " + sumstring1.str());
		numdice1.setPosition(600, 300);
		app.draw(background);
		app.draw(rec);
		app.draw(numdice);
		app.draw(numdice1);
		dice1.setPosition(50,50);
		dice2.setPosition(300, 50);
		dice11.setPosition(550, 50);
		dice22.setPosition(800, 50);
		help.setString(L"ÑÊÌ äëÿ âûçîâà ïðàâèë");
		help.setPosition(100, 250);
		if (x != 0){
			app.draw(dice1);
		}
		if (y != 0){
			app.draw(dice2);
		}
		if (x1 != 0){
			app.draw(dice11);
		}
		if (y1 != 0){
			app.draw(dice22);
		}
		if (!zap){
			app.draw(ruleb);
			app.draw(rule);
		};
		app.draw(help);
		app.display();
	}
}
void rungame(){
	if (startgame()){ rungame(); }
}
int main()
{
	srand(time(0));
	rungame();
	return 0;
}
