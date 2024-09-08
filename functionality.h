/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//

void fallingPiece (double& timer, double& delay, int& colorNum)
{
    if (timer > delay)

    {
        for (int i = 0; i < 4; i++)
        {
            point_2[i][0] = point_1[i][0];
            point_2[i][1] = point_1[i][1];
            point_1[i][1] += 1;                   //How much units downward
        }

        if (!anamoly())

        {
            
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
            for (int i = 0; i < 4; i++)

            	gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;

            colorNum = 1 + rand() % 7;

            int n = rand() % 7;

            for (int i = 0; i < 4; i++)
            {
		        point_1[i][0] = BLOCKS[n][i] % 2;
		        point_1[i][1] = BLOCKS[n][i] / 2;
            }
            
        }

        timer = 0;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

void movement (int& delta_x)

{   
    int i = 0;

    while (i < 4)
    {
        point_2[i][0] = point_1[i][0];

        point_2[i][1] = point_1[i][1];

        point_1[i][0] += delta_x;

        i++;
    }

    delta_x = 0;

    if (!anamoly())

    {
        int n = rand() % 7;        
        
        int i = 0;

        while (i < 4)
        {
            point_1[i][0] = point_2[i][0];
            point_1[i][1] = point_2[i][1];
            i++;
        }
    }

}

bool GameOver()
{
    for(int a = 0; a < N; a++)
    {
        if (gameGrid[1][a])
        {
            return true;
        }
    }

    return false;
}

void rotation(bool &rotate)

{
    int origin_Y, origin_X;

    if (rotate)
    {
        origin_Y = point_1[2][0];
        origin_X = point_1[2][1];

        int i = 0;

        while (i < 4)
        {
            point_2[i][0] = (-1 * (point_1[i][1] - origin_X) ) + origin_Y;
			point_1[i][1] = (point_1[i][0] - origin_Y) + origin_X;
			point_1[i][0] = point_2[i][0];
            i++;
        }

    }

    rotate = false;
}

void SpacetoFall()
{
    while (anamoly())
    {
        for (int i = 0; i < 4; i++)
        {
            point_2[i][0] = point_1[i][0];
            point_2[i][1] = point_1[i][1];
            point_1[i][1]++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        point_1[i][1]--;
    }
}


bool shadowcheck(long long int Arsh_1[4][2], long long int Arsh_2[4][2])
{

	for(int i = 0; i < 4; i++)

		if(gameGrid[Arsh_1[i][1]][Arsh_1[i][0]])
		return 0;
		
		else if(Arsh_1[i][0]<0 || Arsh_1[i][0] >= N || Arsh_1[i][1] >= M)
		return 0;
		
		
  return 1;
		
}

void shadowmovement(int& delx, long long int Arsh_1[4][2], long long int Arsh_2[4][2])
{


	for(int i = 0; i < 4; i++)
	{
		Arsh_1[i][0] = Arsh_2[i][0];
		Arsh_1[i][0] += delx;
			
	}

	if(shadowcheck(Arsh_1,Arsh_2) == 0)
	{
	
		for(int i = 0; i < 4; 
        i++)
		{
		
			Arsh_1[i][0] = Arsh_2[i][0];
		}
	
	}
}

void shadowcreation(int delx, int colorNum, long long int Arsh_1[4][2], long long int Arsh_2[4][2] )
{
	
	for(int i = 0; i < 4; i++)
	{
	
		for(int j = 0; j < 2; j++)
		{
			Arsh_1[i][j] = point_1[i][j];
			Arsh_2[i][j] = point_1[i][j];
			
			
		}
		
	}

	//shadowcheck();
	while(shadowcheck(Arsh_1,Arsh_2))
	{
	
		for(int i=0;i<4;i++)
		{
		
			Arsh_2[i][0] = Arsh_1[i][0];
			Arsh_2[i][1] = Arsh_1[i][1];
			Arsh_1[i][1] += 1;
		
		}
		
		
	
	}

	//shadowmovement();

	if(delx)
	{
		shadowmovement(delx, Arsh_1, Arsh_2);
	}




}

int LineEraser (long int& score, long int& level)

{
    int Variable = M - 1;

        for (int i = M - 1; i > 0; i--)
        {
            int counter = 0, r = 0;

            for (int j = 0; j < N; j++)
            {
                if (gameGrid[i][j]) 
                {
                    counter++;
                }

                gameGrid[Variable][j] = gameGrid[i][j];
            
            }		
            
            
            if (counter < N) 
            {
                Variable -= 1;
            }

            else
            {
                r += 1;
            }
            
            switch (r)
            {
                case 2:
                    score += (30 * level);
                    break;

                case 1:
                    score += (10 * level);
                    break;

                case 4:
                    score += (100 * level);
                    break;

                case 3:
                    score += (60 * level);
                    break;
                
            }
        }
        
        return score;

}

///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
