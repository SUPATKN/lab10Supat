#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double Money, Perc, payback,Prevba;
	cout << "Enter initial loan: ";
	cin >> Money;
	cout << "Enter interest rate per year (%): ";
	cin >> Perc;
	cout << "Enter amount you can pay per year: ";
	cin >> payback;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	Prevba = Money;
	for(int i=1;1;i++){
		double Interest = Prevba*(Perc/100), Total = Prevba + Interest, NewBa = Total-payback;
		if(NewBa<=0){
			payback = Total;
			NewBa = 0;
		}
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << i; 
		cout << setw(13) << left << Prevba;
		cout << setw(13) << left << Interest;
		cout << setw(13) << left << Total;
		cout << setw(13) << left << payback;
		cout << setw(13) << left << NewBa;
		cout << "\n";
		Prevba = NewBa;
		if(NewBa==0){
			break;
		}
	}	
	
	return 0;
}
