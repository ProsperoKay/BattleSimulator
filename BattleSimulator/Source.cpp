#include <iostream>
#include <random>
#include <ctime>

using namespace std;

//SOURCE VARIABLES

//RANDOM VARIABLE GENERATOR
default_random_engine rnd(time(NULL));
uniform_real_distribution<float> atkRange(0.0f, 1.0f);

//PROPERTIES OF CHARACTERS AT PLAY
//Heroes
float heroAttack = 0.6f;
float heroHealth = 450.0f;
float heroDamage = 220.0f;
float heroBuff = heroHealth;

//Villians
float villianAttack = 0.4f;
float villianHealth = 310.0f;
float villianDamage = 180.0f;
float villianBuff = villianHealth;

//NUMBER OF CHARACTERS AT PLAY
int heroCount; int villianCount;

//TURNS
char turn = 'H';

//ATTACK VARIABLE
float attack;

//EXECUTION KEY
char exec = 'n';

//SUBMODULE
void gameLogic();

int main(void)
{
	do {
		cout << "*** Combat Simulator ***\n" << endl;

		//GAME START
		cout << " Enter number of Heroes \nHEROES: "; cin >> heroCount;
		cout << endl;

		cout << " Enter number of Villians \nVILLIANS: "; cin >> villianCount;
		cout << endl;


		//GAME LOGIC
		gameLogic();

		//GAME END
		cout << "Battle Complete !";

		if (heroCount == 0) {
			cout << "Villians won!\n\n" << villianCount << " villians left\n\n" << " YOU LOSE!" << endl;
		}
		else
		{
			cout << "Heroes won!\n\n" << heroCount << " heroes left\n\n" << " YOU WIN!" << endl;
		}

		cout << "PLAY AGAIN? (Y/N)___. "; cin >> exec;

		system("CLS");
	} while (exec != 'n');
	system("PAUSE");
	return (0);
}


void gameLogic() 
{
	cout << "Battle Simulating ...\n\n";

	while ((heroCount > 0) && (villianCount > 0))
	{
		attack = atkRange(rnd);

		if (turn == 'H') {
			//Damage villian
			if (attack <= heroAttack) {
				villianBuff -= heroDamage;

				//Kill villian
				if (villianBuff <= 0) {
					villianCount--;
					villianBuff = villianHealth;
				}
			}
			turn = 'S';
		}
		else {
			//Damage hero
			if (attack <= villianAttack) {
				heroBuff -= villianDamage;

				//Kill hero
				if (heroBuff <= 0) {
					heroCount--;
					heroBuff = heroHealth;
				}
			}
			turn = 'H';
		}
	}


}