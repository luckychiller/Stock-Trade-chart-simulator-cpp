#include "Fuctions.h"

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) 
{
	if(size == 0)
		{size = 20;}	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
    {
        k=i;
    }
}

void CurrencyType()
{
    system("cls");
    system("Color 09");
	do{
		system("cls");
		gotoxy(70,7); std::cout<<"1. Bitcoin";
		gotoxy(70,8); std::cout<<"2. Eutherium";	 
		gotoxy(70,9); std::cout<<"3. USD/EUR";	 
		gotoxy(70,10); std::cout<<"4. PETROLEUM";
		gotoxy(70,11); std::cout<<"5. Back";
		char op = getche();
		if( op=='1'){Bitcoin.Trade();}
		else if( op=='2'){Eutherium.Trade();}
		else if( op=='3'){Cash.Trade();}
		else if( op=='4'){Petroleum.Trade();}
        else if( op=='5'){return;}
		load++;
	}while(1);
}

void Asset::MagicNumber(int val)
{
    Magic=val;
}

int Asset::GetMagicN()
{
    return Magic;
}

void TradeHistory(void)
{
    FILE * history=fopen("My_history.txt","r");
    char bit;
    int command1;
    system("cls");
    printf("\n\t\t\tPress 1 to clear history\telse to go back\n\n\n");

    while(!feof(history))
    {
        fscanf(history,"%c",&bit);
        printf("%c",bit);
    }

    printf("\n\n\n");
    scanf("%d",&command1);

    if(command1==1)
    {
        fclose(history);
        history=fopen("My_history.dat","w");
        system("cls");
        fordelay(90000);
        system("cls");
        fprintf(history,"\n");
        fclose(history);
        cout << "Done....";
        fordelay(90000);
        TradeHistory();
    }
    else
    {
        return;
    }
}

void Tutorial()
{
	system("cls");
    system("Color 02");
	char S[48][161] = {
"                                                                   .......Hello young trader........                                                            ",
"            This app wont teach you everything, but for now, just learn the following handy charms as your keep your inquisitivity burning                      ",
"    To us, these patterns are the true cheat codes in this trade. If you master them plus whatever comes your way, i can assure you that the sky is the limit.  ",
"                                                   |                                                                                                            ",
"    1. The Bullish Engulfing                     | #                                                                      9. The Bearish Engulfing              ",
"    This is where there is alot of      ====>    * #                                                                      This is where there is alot of        ",
"    momentum in favour of price rising           * #                                                                      momentum in favour of price falling   ",
"    Just be ready to sell if all goes well       | #                                                                      Just be ready to buy if all goes well ",
"                                                   |                                                                                                            ",  
"                                                               2. The Harami                                                        |                           ",
"                                                               This is a neutral pattern where the price                          | *                           ",   
"                                                               is being pushed into a tighter range and                           # *                           ",    
"                                                               will breakout soon Pray to your God because                        # *                           ",
"                                                               either shit or a jackpot is about to happen                        | *                           ",
"                                                                                                                                    |                           ",
"                                                                               |                                                                                ",
"    8. The Dark Cloud Cover                                                    # |                         3. The Rising Sun                                    ",
"    This is a Bearish pattern where price                                      # *                       This is a Bearish pattern where price                  ",
"    acted like it was continuing upwards but                                   # *                        acted like it was continuing downwards                ",
"    reversed. Ohh God...its trying to fool you.                                # |                         but reversed. Ohh Lord...Not again....               ",
"                                                                               |                                                                                ",
"                      |                                                                                                            |                            ",
"                    | *                                                                                                            * |                          ",
"                    # *                                          4. Lows High Close                                                * #                          ",                                                                   
"                    # *                                         This pattern could be bullish or bearish                           * #                          ",                                           
"                    # *                                          depending on context. You will understand                         * #                          ",                                     
"                    # |                                          it with time....                                                  | #                          ",
"                    |                                                                                                                |                          ",
"                                                                                    |                                                                           ", 
"                                                                                  | #                                                                           ",
"    5. High Lows Close                                                            * #                                       7. Hammer or Pin                    ",   
"    This pattern could be bullish or bearish                                      * #                                    It signals a reversal when the wick    ",    
"    depending on context                                                          * #                                    sticks out way past the surrounding    ",    
"    Just give it time too....                                                     | |                                    prices. Price tried going way too      ",        
"                                                                                                                          high but the gods rejected it...      ",         
"           | |                                                                                                                                                  ",
"           # *                                                   6. Doji                                                            |      #                    ",                                                                                 
"           # *                                                  This is a neutral pattern which could                               | -or- |                    ",                                                
"           # *                                                  have different meanings based on context                            *      |                    ",                                              
"           | *                                                  Lets pray you dont learn from losses                                                            ",                                                    
"             |                                                  ....but from experience.....                                                                    ",
"                                                                                                                                                                ",
"                                                                            |                                                                                   ",
"                                                                            |                                                                                   ",
"                                                                            +                                                                                   ",
"                                                                            |                                                                                   ",
"                                                                            |                                                                                   ",
"                                                            NOTE: Learning doesnt stop here!!!!....                                                             "};

	for(int i=0;i<48;i++)
	{
        for(int j=0;j<160;j++)
        {
            if(S[i][j]=='|'){printf("%c",179);j++;}
            if(S[i][j]=='#'){printf("%c",219);j++;}
            if(S[i][j]=='*'){printf("%c",178);j++;}
            if(S[i][j]=='+'){printf("%c",197);j++;}
            else{printf("%c",S[i][j]);}
        }
    	std::cout << endl;
    }
	system("pause");
}

Asset::Asset()
{
    for(int i=0; i<SCREEEN_VERTICLE; i++)
    {
		for(int j=0; j<SCREEEN_HORZONTAL; j++)
        {
			screen[i][j]=177;
		}
	}

	for(int i=0; i<GRID_SIDE; i++)
    {
		for(int j=0; j<GRID_SIDE; j++)
        {
            grid[i][j]=(' ');
		}
	}
    AddToQueue(StyleList[rand()%7]);
}

void Asset::SetName(string name)
{
    Name=name;
}

string Asset::GetName() const
{
    return Name;
}

void Asset::Trade()
{
	system("cls"); 
    system("Color 01");
    autoslide=0;
    UniversalX=this->UnitX;
    int i,j,k=(GRID_SIDE/2),l,o;

    for(i=0; i<SCREEEN_VERTICLE; i++) 
    {
        gotoxy(0,i);
		for(j=0; j<SCREEEN_HORZONTAL; j++) 
        {
			std::cout << screen[i][j];
		}
	}

    gotoxy(50,2); cout << " FOREZIL ";
    gotoxy(20,3); cout << this->GetName();
    gotoxy(50,4); cout << "Balance: ";
    gotoxy(130,7); cout <<  "up:        8"  ;
    gotoxy(130,8); cout <<  "down:      2"  ;
    gotoxy(130,9); cout <<  "left:      4"  ;
    gotoxy(130,10); cout << "right:     6"  ;
    gotoxy(130,11); cout << "buy:       q/Q";
    gotoxy(130,12); cout << "sell:      p/P";
    gotoxy(130,13); cout << "Back:      b/B";
    gotoxy(130,14); cout << "recentre:  5"  ;
    gotoxy(130,15); cout << "upleft:    7"  ;
    gotoxy(130,16); cout << "downleft:  1"  ;
    gotoxy(130,17); cout << "upright:   9"  ;
    gotoxy(130,18); cout << "downright: 3"  ;
     
    do
    {
        gotoxy(61,4); cout << Balance;
        for(i=0; i<GRAPH_WINDOW_VERTICLE; i++)
        {
	    	gotoxy(1,i+6);
	    	for(j=0; j<GRAPH_WINDOW_HORZONTAL; j++)
            {
                o=k-17+i;
                std::cout<<grid[o+v][j+h];
	    	}
	    }
        if(autoslide==0 && loops>50)
        {
            h=h+2;
        }
    
        if(kbhit())
        {
            char dir=getch();
            autoslide=1;
                 if(dir=='1')//down-left
            {
                if(o<GRID_SIDE-1){v++;}
                if(h>0){h--;}
            }
            else if(dir=='2')//down
            {
                if(o<GRID_SIDE-1){v++;}
            }
            else if(dir=='3')//down-right
            {
                if(o<GRID_SIDE-1){v++;}
                if(h<GRID_SIDE-1){h++;}
            }
            else if(dir=='4')//left
            {
                if(h>0){h--;}
            }
            else if(dir=='5')//recentre
            {
                if(loops>50)
                {
                    h=(loops-50)*2;
                }
                autoslide=0;
            }
            else if(dir=='6')//right
            {
                if(h<GRID_SIDE-1){h++;}
            }
            else if(dir=='7')//up-left
            {
                if(o>0){v--;}
                if(h>0){h--;}
            }
            else if(dir=='8')//up
            {
                if(o>0){v--;}
            }
            else if(dir=='9')//up-right
            {
                if(o>0){v--;}
                if(h<GRID_SIDE-1){h++;}
            }
            else if(dir=='q'||dir=='Q')
            {
                if(Ability==1)
                {
                    BuyLot(k);
                    h=h+2;
                    Ability=0;
                }
                else
                {
                    gotoxy(60,22);std::cout<<"You are reached the maximum lots"; 
                    h=h+2;
                }
                autoslide=0;
            }
            else if(dir=='p'||dir=='P')//up-right
            {
                if(Ability==0)
                {
                    SellLot(k);
                    h=h+2;
                    Ability=1;
                }
                else
                {
                    gotoxy(64,22);std::cout<<"no lot to be sold";
                    h=h+2;
                }
                autoslide=0;
            }
			else if(dir=='b'||dir=='B')//Back to work
            {
                break;
            }
        }
        else{Sleep(ref_rate);}
        k=AddToGrid();
        loops++;
        //std::cout << loops;
    }while(1);
    this->UnitX=UniversalX;
}

void Asset::BuyLot(int current_val)
{
    Buy=GRID_SIDE-current_val;
    Balance=Balance-Buy;
    for(int i=0;i<GRID_SIDE;i++)
    {
        if(grid[current_val][i]==' ')
        {
            grid[current_val][i]='-';
        }
    }
    Lots=current_val;
    gotoxy(64,22);std::cout<<"Lot bought successfully";
    
    ofstream outfile("My_history.txt");
    outfile << "You Bought a lot at a price of: " << Buy << endl;

    Sleep(ref_rate);
}

void Asset::SellLot(int current_price)
{
    int k=0;
    Sell=GRID_SIDE - current_price;
    for(int i=0;i<GRID_SIDE;i++)
    {
        if(grid[Lots][i]== '-')
        {
            grid[Lots][i]=' ';
        }
    }
    Balance=Balance+Sell;
    gotoxy(64,22);std::cout<<"Lot sold successfully";

    ofstream outfile("My_history.txt");
    outfile << "You Sold a lot at a price of: " << Sell << endl;

    Sleep(ref_rate);
}

CandleStick Asset::CreateNew(string _style)
{
    CandleStick C,temp;
    int l,y,m,n,t=rand();
    t=t*this->GetMagicN();
    int check;
    C.SetStyle(_style);
    if(Queue.empty() == true)
    {
        C.SetY(GRID_SIDE/2);
    }
    else
    {
        temp=Queue.back();
        y=temp.getY();
        m=temp.GetStyle().length();
        n=_style.length();
        
        if(t%2==0){l = y - m + (t%(m+n));} else{l = y + m - (t%(m+n));}
        
        C.SetY(l);
    }
    return C;
}

void Asset::AddToQueue(string _style)
{
   Queue.push(CreateNew(_style));
}

int Asset::AddToGrid() 
{
    AddToQueue(StyleList[rand()%7]); // to be changed to add more hardness and tricks
    CandleStick C=Queue.front();
    int y=C.getY(),x=C.getX();
    for(int i=0;i<C.GetStyle().length();i++)
    {
        if(C.GetStyle()[i]=='#'){grid[y+i][x]=219;}
        else if(C.GetStyle()[i]=='|'){grid[y+i][x]=179;}
        else{grid[y+i][x]=197;}
    }
    Queue.pop();
    return y;
}

CandleStick::CandleStick() 
{
    SetY(0);
    coordX=UniversalX;
    UniversalX++;
}

int CandleStick::getY() const
{
    return coordY;
}

int CandleStick::getX() const
{
    return coordX;
}

void CandleStick::SetY(int y)
{
	if(y >= 20 && y < GRID_SIDE-25){coordY = y;}
    else{coordY=25;}
}

string CandleStick::GetStyle()const
{
    return style;
}

void CandleStick::SetStyle(string new_style)
{
    style = new_style;
}
