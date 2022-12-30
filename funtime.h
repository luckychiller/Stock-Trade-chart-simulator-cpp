#include <typeinfo>
char grod[40][160],bit;

class Element;
class Bubble;
class Spikes;
class Element
{
    public:
    int x,y,mark;
    Element * next;
    Element * prev;
    virtual void Draw();
    virtual void Delete();
    Element()
    {
        next=NULL;
        prev=NULL;
    }
};

class Bubble:public Element
{
    public:
        Bubble();
        void Draw();
        void Delete();
};

class Spikes:public Element
{
    public:
        Spikes();
        void Draw();
        void Delete();
};

Element * Head = NULL;
Element * Tail =NULL;

Bubble::Bubble()
{
    x=rand()%160;
    y=0;
    mark=0;
}

void Bubble::Draw()
{
    gotoxy(x,y);cout << "#";
    y++;
}

void Bubble::Delete()
{
    gotoxy(x,y-1);cout << " ";
}

Spikes::Spikes()
{
    x=rand()%149;
    y=0;
    mark=0;
}

void Spikes::Draw()
{
    gotoxy(x,y);cout << "###########";
    gotoxy(x,y+1);cout << "| | | | | |";
    y++;
}

void Spikes::Delete()
{
    if(y>0){gotoxy(x,y-1);cout << "           ";}
}

void DrawHotAirBalloon(int x,int y)
{
    gotoxy(x,y);cout <<   "  ######  ";
    gotoxy(x,y+1);cout << "##########";
    gotoxy(x,y+2);cout << "##########";
    gotoxy(x,y+3);cout << " ######## ";
    gotoxy(x,y+4);cout << "   ####   ";
    gotoxy(x,y+5);cout << "##########";
}

void RemoveHotAirBalloon(int x,int y)
{
    gotoxy(x,y);cout <<   "          ";
    gotoxy(x,y+1);cout << "          ";
    gotoxy(x,y+2);cout << "          ";
    gotoxy(x,y+3);cout << "          ";
    gotoxy(x,y+4);cout << "          ";
    gotoxy(x,y+5);cout << "          ";
}

void MoveLeft()
{
    if(n>0)
    {
        RemoveHotAirBalloon(m,n);
        DrawHotAirBalloon(m-2,n);
    }
}

void MoveRight()
{
    if(n<160)
    {
        RemoveHotAirBalloon(m,n);
        DrawHotAirBalloon(m+2,n);
    }
}

Spikes * CreateSpikes()
{
    struct Spikes * temp = (Spikes*) malloc(sizeof(Spikes));
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

Bubble * CreateBubble()
{
    Bubble * temp = (Bubble*) malloc(sizeof(Bubble));
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}


void FunTime()
{
    setcursor(0,0);
    Bubble * kkk;
    int k=0;
    char q;
    Element * bit;
    Head->prev=NULL;
    Head->next=Tail;
    Tail->prev=Head;
    Tail->next=NULL;
    
    for (int i=0;i<40;i++)
    {
        for(int j=0;j<160;j++)
        {
            grod[i][j]=' ';
        }
    }
    MoveLeft();
    while(1)
    {
        k=rand()%4;
        if(k==0)
        {
            Spikes * temp = CreateSpikes();
            temp->next=NULL;
            temp->prev=Tail;
            Tail->next=temp;
            Tail=temp;
        }
        else
        {
            Bubble * temp = CreateBubble();
            temp->next=NULL;
            temp->prev=Tail;
            Tail->next=temp;
            Tail=temp;
        }
        bit=Head;
        while(bit!=NULL)
        {
            bit->Delete();
            bit->Draw();

            if(kkk==dynamic_cast<Bubble*>(bit))
            {
                if(bit->x>=m && bit->x<=m+11 && bit->mark==0)
                {
                    score++;
                    bit->mark=1;
                }
            }
            else
            {
                if(bit->x>=m && bit->x<=m+11 && bit->mark==0)
                {
                    bit->mark=1;
                    cout << "You loose....\n Your score is: "<< score << endl;
                    system("pause");
                    return;
                }
            }
            if(bit->y==34)
            {
                bit=bit->next;
                free(bit->prev);
                bit->prev=NULL;    
            }
            else
            {
                bit=bit->next;
            }
        }

        if(kbhit())
        {
            q=getche();
            {
                if(q=='a'||q=='A')
                {
                    MoveLeft();
                }
                else if(q=='d'||q=='D')
                {
                    MoveRight();
                }
                else if(q=='q'||q=='Q')
                {
                    break;
                }
            }
        }
    }
    system("cls");
    gotoxy(20,5);cout << "Your score is";
    gotoxy(20,5);cout << score << endl;
}