#include "IncludeHeader.h"
#include "define.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int main_exit;
int UniversalX=0;
int load=0;
int m=70,n=35;
int score=0;

char pass[10];
char password[10] = "giants";
char screen[SCREEEN_VERTICLE][SCREEEN_HORZONTAL],grid[GRID_SIDE][GRID_SIDE];

string Doji = "||+||";
string UpHammer = "#|||";
string DownHammer = "|||#";
string ShortCandle = "|##|";
string MediumCandle = "|####|";
string TallCandle = "||######||";
string VeryTallCandle = "|||########|||";
string StyleList[7]={Doji, UpHammer, DownHammer, ShortCandle, MediumCandle, TallCandle, VeryTallCandle};

enum dir{UP,DOWN,LEFT,RIGHT,STABLE}; //direction of motion of the cursor

class Asset;
class CandleStick;

void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void fordelay(int j);
void CurrencyType();
void Tutorial();
void TradeHistory(void);

class Asset{
    private:
        string Name;
        float Balance=10000;
        char grid[GRID_SIDE][GRID_SIDE];
        queue <CandleStick> Queue;
        int Lots;
        float Buy;
        float Sell;
        int Magic;
        int h=0,v=0,autoslide=0,loops=0;
    public:
        int UnitX=0;
        int Ability=1;
        Asset();
        void Trade();
        void BuyLot(int current_val);
        void SellLot(int current_price);
        void SetName(string name);
        string GetName() const;
        CandleStick CreateNew(string _style);
        void AddToQueue(string _style);
        int AddToGrid();
        void MagicNumber(int val);
        int GetMagicN();

};

class CandleStick{
private:
	int coordY=0;
    int coordX=0;
	string style;
public: 
    CandleStick();
    int getY() const;
    int getX() const;
    void SetY(int y);
    string GetStyle()const; //Returns style of the candlestick
	void SetStyle(string new_style); //sets the style of the candlestick
};

Asset Bitcoin,Eutherium,Cash,Petroleum;
