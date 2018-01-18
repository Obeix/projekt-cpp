#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "TextureSystem.h"
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

int main()
{
    float n=0;
    int punkty = 0;
    TextureSystem *texturki = new TextureSystem();
    texturki->LoadTextures();
    RenderWindow okno(VideoMode(1280,720),"Gra");

    Sprite nowaGraS,wczytajGreS,sterowanieS,autorS,wyjscieS,powrotS,sterowanieTekstS;
    Sprite droga1S,postac1S,tlo2S,tloMenuS;
    tloMenuS.setTexture(*texturki->GetTexture("tlo"));
    nowaGraS.setTexture(*texturki->GetTexture("nowa-gra"));
    nowaGraS.setPosition(530,200);
    wczytajGreS.setTexture(*texturki->GetTexture("wczytaj-gre"));
    wczytajGreS.setPosition(530,260);
    sterowanieS.setTexture(*texturki->GetTexture("sterowanie"));
    sterowanieS.setPosition(530,320);
    autorS.setTexture(*texturki->GetTexture("autor"));
    autorS.setPosition(530,380);
    wyjscieS.setTexture(*texturki->GetTexture("wyjscie"));
    wyjscieS.setPosition(530,440);
    droga1S.setTexture(*texturki->GetTexture("droga1"));
    droga1S.setPosition(5000,5000);
    postac1S.setTexture(*texturki->GetTexture("postac1"));
    postac1S.setPosition(100,5000);
    tlo2S.setTexture(*texturki->GetTexture("tlo2"));
    tlo2S.setPosition(5000,5000);
    sterowanieTekstS.setTexture(*texturki->GetTexture("sterowanietekst"));
    sterowanieTekstS.setPosition(5000,5000);
    powrotS.setTexture(*texturki->GetTexture("powrot"));
    powrotS.setPosition(5000,5000);
    Sprite gemy[50];
    Sprite bloki[150];
    Sprite kolce[150];
    for(int i=0;i<50;i++)
    {
        gemy[i].setTexture(*texturki->GetTexture("gem"));
        gemy[i].setPosition(6000,6000);
    }
    for(int i=0;i<150;i++)
    {
        bloki[i].setTexture(*texturki->GetTexture("blok"));
        bloki[i].setPosition(7000,7000);
    }
    for(int i=0;i<150;i++)
    {
        kolce[i].setTexture(*texturki->GetTexture("spike1"));
        kolce[i].setPosition(8000,8000);
    }
    Text punktyT,przegranaT;
    punktyT.setPosition(2000,2000);
    Font czcionka;
    czcionka.loadFromFile("BebasNeue.otf");
    punktyT.setFont(czcionka);
    punktyT.setCharacterSize(40);
    punktyT.setFillColor(Color::Blue);
    okno.setFramerateLimit(60);
    przegranaT.setPosition(100,2000);
    przegranaT.setFont(czcionka);
    przegranaT.setCharacterSize(100);
    przegranaT.setFillColor(Color::Red);
    przegranaT.setString("Game Over");

    while(okno.isOpen())
    {
        FloatRect postacBox = postac1S.getGlobalBounds();
        FloatRect gemBox[50],blokBox[150],kolceBox[150];
        View obraz;
        obraz.reset(FloatRect(0,0,1280,720));
        Vector2f pozycjaPostac = postac1S.getPosition();
        Vector2f pozycjaWyjscie = wyjscieS.getPosition();
        Vector2f pozycjaNowaGra = nowaGraS.getPosition();
        Vector2f pozycjaSterowanie = sterowanieS.getPosition();
        Vector2f pozycjaPowrot = powrotS.getPosition();
        Vector2f pozycjaBlok[150];
        Vector2i pozycjaMysz = Mouse::getPosition(okno);
        for(int i=0;i<50;i++)
            gemBox[i] = gemy[i].getGlobalBounds();
        for(int i=0;i<150;i++)
        {
            pozycjaBlok[i] = bloki[i].getPosition();
            blokBox[i] = bloki[i].getGlobalBounds();
            kolceBox[i] = kolce[i].getGlobalBounds();
        }

        Event zdarzenie;
        while(okno.pollEvent(zdarzenie))
        {
            if(zdarzenie.type == Event::Closed)
                okno.close();
                //skok
            if(pozycjaPostac.y > 99)
            {
                if(zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Space)
                {
                    postac1S.move(0,-100);
                    //n += 1;
                    //pozycjaPostac.y += -50;
                    //postac1S.move(0,-n);
                    //postac1S.setPosition(pozycjaPostac);
                }
                if(zdarzenie.type == Event::KeyReleased && zdarzenie.key.code == Keyboard::Space)
                {
                    postac1S.move(0,100);
                    //postac1S.move(0,n);
                }
            }
            if(pozycjaPostac.y < 100)
                postac1S.setPosition(pozycjaPostac.x,536);
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape))
            okno.close();

        if(Mouse::isButtonPressed(Mouse::Left))
        {
            if(pozycjaNowaGra.x == 530 && pozycjaNowaGra.y == 200)
                if((pozycjaMysz.x > 531) && (pozycjaMysz.x < 749) && (pozycjaMysz.y > 201) && (pozycjaMysz.y < 245))
                {
                    nowaGraS.setPosition(5000,5000);
                    wczytajGreS.setPosition(5000,5000);
                    sterowanieS.setPosition(5000,5000);
                    autorS.setPosition(5000,5000);
                    wyjscieS.setPosition(5000,5000);
                    droga1S.setPosition(0,596);
                    postac1S.setPosition(100,536);
                    tlo2S.setPosition(0,0);
                    powrotS.setPosition(40,650);
                    tloMenuS.setPosition(5000,5000);
                    punktyT.setPosition(200,650);
                    punkty = 0;
                    //pierwsza mapa
                    gemy[0].setPosition(400,560);
                    gemy[1].setPosition(510,446);
                    gemy[2].setPosition(650,546);
                    gemy[3].setPosition(800,446);
                    gemy[4].setPosition(850,546);
                    gemy[5].setPosition(900,546);
                    gemy[6].setPosition(1050,446);
                    kolce[0].setPosition(300,546);
                    kolce[1].setPosition(350,546);
                    kolce[2].setPosition(550,546);
                    kolce[3].setPosition(750,546);
                    kolce[4].setPosition(1000,546);
                    kolce[5].setPosition(1030,546);
                    kolce[6].setPosition(1150,546);
                }

            if(pozycjaSterowanie.x == 530 && pozycjaSterowanie.y == 320)
                if((pozycjaMysz.x > 531) && (pozycjaMysz.x < 749) && (pozycjaMysz.y > 321) && (pozycjaMysz.y < 365))
                {
                    nowaGraS.setPosition(5000,5000);
                    wczytajGreS.setPosition(5000,5000);
                    sterowanieS.setPosition(5000,5000);
                    autorS.setPosition(5000,5000);
                    wyjscieS.setPosition(5000,5000);
                    powrotS.setPosition(50,50);
                    sterowanieTekstS.setPosition(450,50);
                }

            if(pozycjaWyjscie.x == 530 && pozycjaWyjscie.y == 440)
                if((pozycjaMysz.x > 531) && (pozycjaMysz.x < 749) && (pozycjaMysz.y > 441) && (pozycjaMysz.y < 485))
                    okno.close();

            if(pozycjaPowrot.x == 50 && pozycjaPowrot.y == 50)
                if((pozycjaMysz.x > 51) && (pozycjaMysz.x < 169) && (pozycjaMysz.y > 51) && (pozycjaMysz.y < 95))
                {
                    nowaGraS.setPosition(530,200);
                    wczytajGreS.setPosition(530,260);
                    sterowanieS.setPosition(530,320);
                    autorS.setPosition(530,380);
                    wyjscieS.setPosition(530,440);
                    powrotS.setPosition(5000,5000);
                    sterowanieTekstS.setPosition(5000,5000);
                }

            if(pozycjaPowrot.x == 40 && pozycjaPowrot.y == 650)
                if((pozycjaMysz.x > 41) && (pozycjaMysz.x < 159) && (pozycjaMysz.y > 651) && (pozycjaMysz.y < 695))
                {
                    nowaGraS.setPosition(530,200);
                    wczytajGreS.setPosition(530,260);
                    sterowanieS.setPosition(530,320);
                    autorS.setPosition(530,380);
                    wyjscieS.setPosition(530,440);
                    tlo2S.setPosition(5000,5000);
                    droga1S.setPosition(100,5000);
                    powrotS.setPosition(5000,5000);
                    postac1S.setPosition(100,5000);
                    tloMenuS.setPosition(0,0);
                    punktyT.setPosition(2000,2000);
                    for(int i=0;i<50;i++)
                        gemy[i].setPosition(6000,6000);
                    for(int i=0;i<150;i++)
                    {
                        bloki[i].setPosition(7000,7000);
                        kolce[i].setPosition(8000,8000);
                    }
                    postac1S.setTexture(*texturki->GetTexture("postac1"));
                }
        }

        //zliczanie punktów
        for(int i=0;i<50;i++)
        {
            if(postacBox.intersects(gemBox[i]))
                {
                    punkty++;
                    gemy[i].setPosition(1500,1500);
                }
        }

        //ruch postaci
        if(pozycjaPostac.x <= 0)
            postac1S.move(1,0);
        if((pozycjaPostac.y > 0) && (pozycjaPostac.y < 550) && (pozycjaPostac.x > 0))
        {
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                postac1S.setTexture(*texturki->GetTexture("postac1L"));
                postac1S.move(-8,0);
                if(pozycjaPostac.x > 650)
                {
                    tlo2S.move(-8,0);
                    droga1S.move(-8,0);
                    punktyT.move(-8,0);
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                postac1S.setTexture(*texturki->GetTexture("postac1P"));
                postac1S.move(8,0);
                if(pozycjaPostac.x > 650)
                {
                    tlo2S.move(8,0);
                    droga1S.move(8,0);
                    punktyT.move(8,0);
                }
            }
        }
        /*
        //skok wersja 2
        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            while(n > -21)
            {
                n -= 5;// * 9.8; // predkosc skoku * grawitacja
                postac1S.move(0,n);
            }
        }
        n=0;
        if(pozycjaPostac.y < 536)
            postac1S.move(0,30);
        if(pozycjaPostac.x <= 0)
            postac1S.setPosition(1,536);
*/
        //wejscie na kolec
        for(int i=0;i<150;i++)
        {
            if(postacBox.intersects(kolceBox[i]))
            {
                postac1S.setPosition(100,3000);
                powrotS.setPosition(580,400);
                przegranaT.setPosition(470,200);
                punktyT.setPosition(580,330);
                tlo2S.setPosition(0,0);
                droga1S.setPosition(0,596);
            }
        }

        if(Mouse::isButtonPressed(Mouse::Left))
        {
            if((pozycjaPowrot.x == 580) && (pozycjaPowrot.y == 400))
                if((pozycjaMysz.x > 581) && (pozycjaMysz.x < 699) && (pozycjaMysz.y > 401) && (pozycjaMysz.y < 446))
                {
                    nowaGraS.setPosition(530,200);
                    wczytajGreS.setPosition(530,260);
                    sterowanieS.setPosition(530,320);
                    autorS.setPosition(530,380);
                    wyjscieS.setPosition(530,440);
                    tlo2S.setPosition(5000,5000);
                    droga1S.setPosition(100,5000);
                    powrotS.setPosition(5000,5000);
                    postac1S.setPosition(100,5000);
                    tloMenuS.setPosition(0,0);
                    punktyT.setPosition(2000,2000);
                    przegranaT.setPosition(100,4000);
                    for(int i=0;i<50;i++)
                        gemy[i].setPosition(6000,6000);
                    for(int i=0;i<150;i++)
                    {
                        bloki[i].setPosition(7000,7000);
                        kolce[i].setPosition(8000,8000);
                    }
                    postac1S.setTexture(*texturki->GetTexture("postac1"));
                }
        }

        if(pozycjaPostac.x > 650)
            obraz.setCenter(pozycjaPostac.x,360);
        else
            obraz.setCenter(640,360);

        string pkt = to_string(punkty);
        punktyT.setString("Punkty: " + pkt);
        okno.draw(tloMenuS);
        okno.draw(nowaGraS);
        okno.draw(wczytajGreS);
        okno.draw(sterowanieS);
        okno.draw(autorS);
        okno.draw(wyjscieS);
        okno.draw(tlo2S);
        okno.draw(droga1S);
        okno.draw(postac1S);
        okno.draw(sterowanieTekstS);
        okno.draw(powrotS);
        for(int i=0;i<50;i++)
            okno.draw(gemy[i]);
        for(int i=0;i<150;i++)
        {
            okno.draw(bloki[i]);
            okno.draw(kolce[i]);
        }
        okno.draw(punktyT);
        okno.draw(przegranaT);
        okno.setView(obraz);
        okno.display();
    }
    return 0;
}
