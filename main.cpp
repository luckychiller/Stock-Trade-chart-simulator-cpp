#include "library.h"

int main()
{
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	setcursor(0,0); 
	system("pause");
	Bitcoin.SetName("Bitcoin");
	Bitcoin.MagicNumber(3);
	Eutherium.SetName("Eutherium");
	Eutherium.MagicNumber(5);
	Cash.SetName("USD/EUR");
	Cash.MagicNumber(7);
	Petroleum.SetName("Petroleum");
	Petroleum.MagicNumber(11);
	
	system("cls");
    system("Color 09");
	do{
		system("cls");
		gotoxy(70,7); std::cout<<"1. Chart";
		gotoxy(70,8); std::cout<<"2. Tutorials";	 
		gotoxy(70,9); std::cout<<"3. Your trade history";	 
		gotoxy(70,10); std::cout<<"4. Back";
		char op = getche();
		if( op=='1'){CurrencyType();}
		else if( op=='2'){Tutorial();}
		else if( op=='3'){TradeHistory();}
		else if( op=='4'){return 0;}
		load++;
	}while(1);
	return 0;
}

