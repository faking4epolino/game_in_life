#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>

char drp[20][20]=
{   
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45 ,38,   45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45 ,38,   45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45, 38,   45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,   38, 45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45, 38,  45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45, 38,38,38, 45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,38,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},
	{45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45},

};
char newdrp[20][20] = {};
int bornppl ;

int get(int i)
{
	if (i < 0) return 19;
	if (i > 19) return 0;
	return i;
}
 

int main(int argc, char* argv[])
{
	system("color 06");
	int exit = 27;

	char file[256];
	std::string html;

	if (argc<3 )
	{
			std::cout << "The arguments were not passed to the program! "<<std::endl;
		return 0; 

	}
	else
	{
		strcpy(file, argv[1]);

		if (argc == 3) 
		{
			html = argv[2];
		} 

	}
	std::ifstream fileout;
	fileout.open(html, std::ios::app);
	if (html!="html.html")
	{
		std::cout << "The argument of the '.html' file is set incorrectly!" << '\n';
		return 0;
	}


	std::ifstream filein;
	filein.open(argv[1]);
	if (!filein.is_open())
	{
		std::cout << "False! File does not open." << std::endl;
		return 0;
	}
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{	
			filein >> drp[i][j];
			if (drp[i][j] == '0')
				drp[i][j] = 45;
			if (drp[i][j] == '1')
				drp[i][j] = 38;
		}
	}
	filein.close();

		do
		{
			system("cls");
				for (int i = 0; i < 20; i++)
				{
					std::cout << '\n';
					for (int j = 0; j < 20; j++)
					{
						//newdrp[i][j] = drp[i][j];
						int count = 0;
						if (drp[get(i + 1)][j] == 38) count++;
						if (drp[get(i - 1)][j] == 38) count++;
						if (drp[i][get(j + 1)] == 38) count++;
						if (drp[i][get(j - 1)] == 38) count++;
						if (drp[get(i - 1)][get(j - 1)] == 38) count++;
						if (drp[get(i - 1)][get(j + 1)] == 38) count++;
						if (drp[get(i + 1)][get(j - 1)] == 38) count++;
						if (drp[get(i + 1)][get(j + 1)] == 38) count++;

						if (count < 2 || count >3)
						{
							newdrp[i][j] = 45;
							count = 0;
						}
						if (count == 3)
						{
							newdrp[i][j] = 38;
							bornppl++;
							
							count = 0;
						}
						if (count == 2)
						{
							newdrp[i][j] = drp[i][j];
							count = 0;
						}

							std::cout << newdrp[i][j] << " ";
					}

				}
					for (int i = 0; i < 20; i++)
						for (int j = 0; j < 20; j++)
									drp[i][j] = newdrp[i][j];

					std::ofstream fileout;
					fileout.open(argv[2], std::ios::app);
					if (!argv[2])
					{
						std::cout << "error" << '\n';
						return 0;
					}
					else
					{
						fileout << "<!DOCTYPE html>"
							<< "<head>"
							<< "<meta charset = \"utf-8\"/>"
							<< "<title>LIFE</title>"
							<< "</head>"
							<< "<body>"
							<< "<div> Number of elements born :" << bornppl << "</div><br>"
							<< "<table>"
							<< "<tbody>";
							bornppl = 0;
						for (int i = 0; i < 20; i++)
						{

							fileout << "<tr>";
							for (int j = 0; j < 20; j++)
							{
								if (drp[i][j] == 1)
									drp[i][j] = '@';

								fileout << "<td>"
									<< drp[i][j]
									<< "</td>";


								if (drp[i][j] == '@')
									drp[i][j] = 1;
							}
							fileout << "</tr>";
							
						}
						fileout << "</tbody>"
							<< "</table>"
							<< "</body>"
							<< "</html>";
						fileout.close();
					}

		} while (_getch() != 27);
			
		
return 0;
}

