#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.h"

using namespace sf;
using namespace std;


// Les variables
Font font;
Input input;
Text txt;
Texture stadeTexture;
Sprite spriteStade;
const int WIN_WIDTH = 1500;
const int WIN_HEIGHT = 1002;
RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "FOOT-GAME");
Vector2f RectangleDir = Vector2f(1.f, 1.f);

float rectangleWidth = 30;
float rectangleHeight = 30;
float rectanglePosX = 585;
float rectanglePosY = 385;
float RectangleSpeed = 8;

float raquetteWidth = 45;
float raquetteHeight = 45;
float raquetteX = 355;
float raquetteY = 377.5;
float raquetteSpeed = 7;
float raquette2X = 810;
float raquette2Y = 377.5;



float butWidth = 50;
float butHeight = 300;
float butLeftX = 0;
float butLeftY = (WIN_HEIGHT - butHeight) / 2;
float butRightX = WIN_WIDTH - butWidth;
float butRightY = (WIN_HEIGHT - butHeight) / 2;

int ScoreRaquette = 0;
int ScoreRaquette2 = 0;



// boucle principale
int main()
{
    void LoadFont();
    LoadTextures();
    // création des des objets (raquette et balle)

    RectangleShape rectangle(Vector2f(rectangleWidth, rectangleHeight));
    rectangle.setPosition(rectanglePosX, rectanglePosY);
    rectangle.setFillColor(Color::Red);


    RectangleShape raquette(Vector2f(raquetteWidth, raquetteHeight));
    raquette.setPosition(raquetteX, raquetteY);
    raquette.setFillColor(Color::Blue);

    RectangleShape raquette2(Vector2f(raquetteWidth, raquetteHeight));
    raquette2.setPosition(raquette2X, raquette2Y);
    raquette2.setFillColor(Color::Green);

    RectangleShape butLeft(Vector2f(butWidth, butHeight));
    butLeft.setPosition(butLeftX, butLeftY);
    butLeft.setFillColor(Color::White);

    
    RectangleShape butRight(Vector2f(butWidth, butHeight));
    butRight.setPosition(butRightX, butRightY);
    butRight.setFillColor(Color::White);
   
   // chargement font
    LoadFont();
    
    // boucle quand la fenêtre est ouverte
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            
            input.InputHandler(event, window);
        }
        updateRect();
        updateScore();
        // met à jour la position des objets
        rectangle.setPosition(rectanglePosX, rectanglePosY);
        raquette.setPosition(raquetteX, raquetteY);
        raquette2.setPosition(raquette2X, raquette2Y);
        
        //fonction qui détecte si un bouton préssé
        CheckBtn();
        updateScore();
        SetText(txt, to_string(ScoreRaquette) + " | " + to_string(ScoreRaquette2));
       
        // fonctions qui afficheent les objets à l'écran
        window.clear();
        window.draw(spriteStade);
        window.draw(txt);
        window.draw(rectangle);
        window.draw(raquette);
        window.draw(raquette2);
        window.draw(butLeft);
        window.draw(butRight);
        
        
        
        window.display();
        sleep(seconds(1.f / 70.f));

    }

    return 0;
}

void LoadTextures() {

    if (!stadeTexture.loadFromFile("stade.png", IntRect(0, 0, 1500, 1002))) {
        cout << "Erreur chargement texture stade" << endl;
   }
    spriteStade.setTexture(stadeTexture);
}

// fonction qui initialise la police d'écriture
void LoadFont() {

    if (!font.loadFromFile("arial.ttf")) {
        cout << "Problème chargement police" << endl;
    }

}

// fonction détéction des entrée clavier
void CheckBtn() {

    if (input.GetButton().left == true) {
        raquetteX -= raquetteSpeed;
        if (raquetteX < 0) {
            raquetteX = 0;
      }
    }
    if (input.GetButton().right == true) {
        raquetteX += raquetteSpeed;
        if (raquetteX + raquetteWidth > WIN_WIDTH) {
            raquetteX = WIN_WIDTH - raquetteWidth;
       }
    }
    if (input.GetButton().up == true) {
        raquetteY -= raquetteSpeed;
        if (raquetteY < 0) {
            raquetteY = 0;
        }
    }
    if (input.GetButton().down == true) {
        raquetteY += raquetteSpeed;
        if (raquetteY + raquetteHeight > WIN_HEIGHT) {
            raquetteY = WIN_HEIGHT - raquetteHeight;
        }
    }

    if (input.GetButton().q == true) {
        raquette2X -= raquetteSpeed;
        if (raquette2X < 0) {
            raquette2X = 0;
        }
    }
    if (input.GetButton().d == true) {
        raquette2X += raquetteSpeed;
        if (raquette2X + raquetteWidth > WIN_WIDTH) {
            raquette2X = WIN_WIDTH - raquetteWidth;
        }
    }
    if (input.GetButton().z == true) {
        raquette2Y -= raquetteSpeed;
        if (raquette2Y < 0) {
            raquette2Y = 0;
        }
    }
    if (input.GetButton().s == true) {
        raquette2Y += raquetteSpeed;
        if (raquette2Y + raquetteHeight > WIN_HEIGHT) {
            raquette2Y = WIN_HEIGHT - raquetteHeight;
        }
    }
    
    

}

// fonction pour afficher le score
void SetText(Text& txt, String str) {
    txt.setFont(font);
    txt.setFillColor(Color::White);
    txt.setPosition((WIN_WIDTH / 2) - 40, 10);
    txt.setCharacterSize(60);
    txt.setString(str);
}



// fonction pour mettre à jour les scores
void updateScore() {
    if (rectanglePosX < (butLeftX + butWidth) && rectanglePosY > butLeftY && rectanglePosY < (butLeftY + butHeight)) {
        ScoreRaquette2++;
        raquette2X = 810;
        raquette2Y = 377.5;
        raquetteX = 355;
        raquetteY = 377.5;
        rectanglePosX = 585;
        rectanglePosY = 385;
    
    }
    if ((rectanglePosX + rectangleWidth) > butRightX && rectanglePosY > butRightY && rectanglePosY < (butRightY + butHeight)) {
        ScoreRaquette++;
        raquette2X = 810;
        raquette2Y = 377.5;
        raquetteX = 355;
        raquetteY = 377.5;
        rectanglePosX = 585;
        rectanglePosY = 385;
       
    }
}

// fonction détéction des collisions
void updateRect() {

    rectanglePosX += RectangleDir.x * RectangleSpeed;
    rectanglePosY += RectangleDir.y * RectangleSpeed;

    if (rectanglePosX < 0 || (rectanglePosX + rectangleWidth) > WIN_WIDTH) {
        RectangleDir.x *= -1;
        
    }
    if (rectanglePosY < 0 || (rectanglePosY + rectangleHeight) > WIN_HEIGHT) {
        RectangleDir.y *= -1;
        
    }

    // verification collision en Y superieur raquette1
    if (((rectanglePosY + rectangleHeight) > raquetteY
        && rectanglePosY < (WIN_HEIGHT - (WIN_HEIGHT - raquetteY))
        && (rectanglePosX) < (raquetteX + raquetteWidth)
        && (rectanglePosX) > raquetteX)
        || ((rectanglePosY + rectangleHeight) > raquetteY
            && rectanglePosY < (WIN_HEIGHT - (WIN_HEIGHT - raquetteY))
            && (rectanglePosX + rectangleWidth) < (raquetteX + raquetteWidth)
            && ((rectanglePosX + rectangleWidth) > raquetteX))) {
        RectangleDir.y *= -1;
    }

    //verification collision Y inferieur raquette1
    if ((rectanglePosY < (raquetteY + raquetteHeight)
        && (rectanglePosY > raquetteY)
        && (rectanglePosX > raquetteX)
        && (rectanglePosX < (raquetteX + raquetteWidth)))
        || (rectanglePosY < (raquetteY + raquetteHeight)
            && (rectanglePosY > raquetteY)
            && ((rectanglePosX + rectangleWidth) > raquetteX)
            && ((rectanglePosX + rectangleWidth) < (raquetteX + raquetteWidth)))) {
        RectangleDir.y *= -1;
    }
    // detection colision X gauche raquette1
    if (((rectanglePosX + rectangleWidth) > raquetteX
        && (rectanglePosX < (raquetteX + raquetteWidth))
        && (rectanglePosY + raquetteHeight) > raquetteY
        && rectanglePosY < (raquetteY + raquetteHeight))
        || ((rectanglePosX + rectangleWidth) > raquetteX
            && (rectanglePosX < (raquetteX + raquetteWidth))
            && (rectanglePosY + rectangleWidth) > raquetteY
            && (rectanglePosY + rectangleWidth) < (raquetteY + raquetteHeight))) {

        RectangleDir.x *= -1;
    }

    // detection collision X droite raquette1
    if ((rectanglePosX < (raquetteX + raquetteWidth)
        && (rectanglePosX > raquetteX + raquetteWidth)
        && rectanglePosY> raquetteY
        && rectanglePosY < (raquetteY + raquetteHeight))
        || ((rectanglePosX < (raquetteX + raquetteWidth)
            && (rectanglePosX > raquetteX))
            && (rectanglePosY + raquetteHeight) > raquetteY
            && (rectanglePosY + rectangleHeight) < (raquetteY))) {

        RectangleDir.x *= -1;

    }

    // verification collision en Y superieur raquette2
    if (((rectanglePosY + rectangleHeight) > raquette2Y
        && rectanglePosY < (WIN_HEIGHT - (WIN_HEIGHT - raquette2Y))
        && (rectanglePosX) < (raquette2X + raquetteWidth)
        && (rectanglePosX) > raquette2X)
        || ((rectanglePosY + rectangleHeight) > raquette2Y
            && rectanglePosY < (WIN_HEIGHT - (WIN_HEIGHT - raquette2Y))
            && (rectanglePosX + rectangleWidth) < (raquette2X + raquetteWidth)
            && ((rectanglePosX + rectangleWidth) > raquette2X))) {
        RectangleDir.y *= -1;
    }

    //verification collision Y inferieur raquette2
    if ((rectanglePosY < (raquette2Y + raquetteHeight)
        && (rectanglePosY > raquette2Y)
        && (rectanglePosX > raquette2X)
        && (rectanglePosX < (raquette2X + raquetteWidth)))
        || (rectanglePosY < (raquette2Y + raquetteHeight)
            && (rectanglePosY > raquette2Y)
            && ((rectanglePosX + rectangleWidth) > raquette2X)
            && ((rectanglePosX + rectangleWidth) < (raquette2X + raquetteWidth)))) {
        RectangleDir.y *= -1;
    }
    // detection colision X gauche raquette2
    if (((rectanglePosX + rectangleWidth) > raquette2X
        && (rectanglePosX < (raquette2X + raquetteWidth))
        && (rectanglePosY + raquetteHeight) > raquette2Y
        && rectanglePosY < (raquette2Y + raquetteHeight))
        || ((rectanglePosX + rectangleWidth) > raquette2X
            && (rectanglePosX < (raquette2X + raquetteWidth))
            && (rectanglePosY + rectangleWidth) > raquette2Y
            && (rectanglePosY + rectangleWidth) < (raquette2Y + raquetteHeight))) {

        RectangleDir.x *= -1;
    }

    // detection collision X droite raquette2
    if ((rectanglePosX < (raquette2X + raquetteWidth)
        && (rectanglePosX > raquette2X + raquetteWidth)
        && rectanglePosY> raquette2Y
        && rectanglePosY < (raquette2Y + raquetteHeight))
        || ((rectanglePosX < (raquette2X + raquetteWidth)
            && (rectanglePosX > raquette2X))
            && (rectanglePosY + raquetteHeight) > raquette2Y
            && (rectanglePosY + rectangleHeight) < (raquette2Y))) {

        RectangleDir.x *= -1;
        cout << "droite2" << endl;
    }

}




