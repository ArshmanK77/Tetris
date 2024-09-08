/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <sstream>
using namespace sf;

int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(500, 480), title);
    Texture obj1, obj2, obj3, obj4;
    
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    

    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj4.loadFromFile("img/shadow.png");
	obj3.loadFromFile("img/frame.png");

    
    Sprite sprite(obj1), background(obj2), shadow(obj4), frame(obj3);
    long long int Arsh_1[4][2], Arsh_2[4][2]; 
    int delta_x=0, colorNum=1;
    double timer=0, delay=0.4;
    bool rotate=0; bool p = 0;
    bool wait = 1; long int score = 0;
    long int level = 1;

    Clock clock;

    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
    delay = 0.4;
    rotate = 0;

        //---Event Listening Part---//

        Event e;
        while (window.pollEvent(e))
        {                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed)              //If any other key (not cross) is pressed
            { 
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                           //Change in X-Axis - Positive
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05

        

        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///

        fallingPiece(timer, delay, colorNum);              //Example: fallingPiece() function is called here

        //Game End

        if (GameOver() == true)                   //Function which ends the game when the blocks are at the top of the screen
        {
            window.close();
        }

        //Movement

        movement (delta_x);                //Function to move the blocks around

        //LineDestroyer

        LineEraser (score, level);         //Function for erasing lines and adding score

        //Rotation

        rotation(rotate);                  //Function for rotation of blocks

        //Shadow

        shadowcreation(delta_x, colorNum, Arsh_1, Arsh_2);       //Function for diplaying shadow

        //Space to end game

        if (e.key.code == Keyboard::Space)              //Function which drops the block to the bottom when spacebar is pressed

        {
            SpacetoFall();                   
        }

        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////


        window.clear(Color::Black);
        window.draw(background);

        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }

        for (int i=0; i<4; i++)
        {
            shadow.setTextureRect(IntRect(colorNum*18,0,18,18));
            shadow.setPosition(Arsh_1[i][0]*18,Arsh_2[i][1]*18);
            shadow.move(28,31);
            window.draw(shadow);
        }
        
        for (int i=0; i<4; i++)
        {
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
        }

        sf::Font scorefont;
        scorefont.loadFromFile("times new roman bold.ttf");
     
        sf::Text scoreheading;
        scoreheading.setFont(scorefont);
        scoreheading.setString("SCORE: ");
        scoreheading.setPosition({330,20});
        window.draw(scoreheading);
        
        sf::Text scorenum(std::to_string(score), scorefont);
        scorenum.setPosition({450,20});
        window.draw(scorenum);
        
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);

        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    
    return 0;
}
