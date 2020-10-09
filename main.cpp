#include<bits/stdc++.h>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <time.h>
#include<string>
using namespace std;
typedef long long ll;
string org_name;
class Employee
{
public:
	string name;
	string profile;
	string pswd;
	int id;
	int under;
	double salary;
	string jointime;
	Employee(int m, string s, string prof)
	{
		id = m;
		name = s;
		pswd = "0";
		profile = prof;
		string a;
		under = 0;
		salary = 0;
		a = "./" + org_name + "/Employee Log Files/";
		ostringstream num;
		num << id;
		a = a + num.str();
		a = a + ".txt";
		ofstream outfile;
		outfile.open(a.c_str(), ios::trunc);
		outfile << "\t\t\t\t\t\t\t\t" << name << "'s Log File" << endl;
		outfile << "\t\t\t\t\t\t\t\t" << prof << endl << endl;
		time_t jtime;
		jtime = time(NULL);
		outfile << "\t\t\t\t\t\t\tJoining Date: " << ctime(&jtime) << endl << endl;
		jointime = ctime(&jtime);
		outfile.close(); 
	}

	void editfile();
	void viewjunior();
	void employeelist();
	
};
class HR
{
public:
	string name;
	map<int, Employee* > empl;
	vector<int> levelWiseCount;
	string pswd;
	HR(string a)
	{
		name = a;
		levelWiseCount.push_back(0);
		levelWiseCount.push_back(0);
		levelWiseCount.push_back(0);
		levelWiseCount.push_back(0);
		levelWiseCount.push_back(0);
		levelWiseCount.push_back(0);
		levelWiseCount.push_back(0);
		levelWiseCount.push_back(0);
		levelWiseCount.push_back(0);
		pswd = "0";
	}
	void empllist();
};
class accountant
{
public:
	string name;
	double balance;
	string pswd;
	vector<double> report;
	accountant(string a, double bal)
	{
		name = a;
		balance = bal;
		pswd = "0";
		a = "./" + org_name + "/Bank Details";
		mkdir(a.c_str());
		a = a + "/Statement.txt";
		ofstream outfile;
		outfile.open(a.c_str(), ios::trunc);
		outfile << "\t\t\t\t\t\t\t\t" << org_name << "'s Bank Statement" << endl << endl;
		outfile << fixed << setprecision(3) << "Initial Balance:" << bal << endl << endl;
		outfile << left << setw(15) << "Date" << setw(20) << "Withdraw" << setw(20) << "Deposit" << setw(20) << "Remaining Balance" <<  "Description/Remarks" << endl;
		outfile.close();
		report.push_back(0);
		report.push_back(0);
		report.push_back(0);
		report.push_back(0);
		report.push_back(0);
	} 
	
	void viewstatement();
	void addtrans();
};
class master
{
public:
	string name;
	HR* h;
	accountant *a;
	string pswd;
};
master *chair;
void fullscreen();
void topscreendisp();
int mainscreen();
void exitscreen();
template <typename T>
void passwordinput(T help, int a);
void loginscreen();
void newproject();
void passwordscreen(int username, int a, bool b, bool wrong);
void emplhomescreen(Employee * head);
void hrhomescreen(HR * head);
void hremplsescreen(int emplid);
void hremployeeidcheckscreen();
void hraddemployee();
void hraddunder(int emplid);
void hraddmaster();
void acctscreen();
void masterscreen();
void masteremplid();
void masteracctscreen();
void masterhrscreen();
void masteremplscreen(int eid);
void save();
void loadproject();

void Employee :: editfile()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t" << name << "'s Portal" << endl << endl;
	cout << endl;
	string a;
	a = "./" + org_name + "/Employee Log Files/";
	ostringstream num;
	num << id;
	a = a + num.str();
	a = a + ".txt";
	ofstream outfile;
	outfile.open(a.c_str(), ios::app);
	time_t currtime = time(NULL);
	outfile << ctime(&currtime);
	outfile << "\t\t" ;
	cout << "\t\t\t\t\t" << "  Start writing entry into log file and write \"end\" in new line to terminate" << endl;
	string k;
	while(1)
	{
		getline(cin, k);
		if(k == "end") break;
		outfile << k << endl;
	}
	outfile << endl << endl;
	outfile.close();
}

void Employee :: viewjunior()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t" << name << "'s Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter Your/Junior's Employee ID:";
	int k;
	while(1)
	{
		cin >> k;
		if(k == -1) return;
		if(!cin || chair->h->empl.count(k) == 0)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t" << name << "'s Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter a valid Employee ID:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		int a = id/100000000;
		int b = pow(10,a);
		if(a > k/100000000 || id%b != k%b)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t" << name << "'s Portal" << endl << endl;
			cout << "\t\t\t\t\tCorresponding Employee doest work under you and hence you dont have access." <<  endl;
			cout << "\t\t\t\t\tEnter Your/Junior's Employee ID:";
		}
		else break;
	}
	string a;
	a = "./" + org_name + "/Employee Log Files/";
	ostringstream num;
	num << k;
	a = a + num.str();
	a = a + ".txt";
	ifstream read (a.c_str());
	if(!read)
	{
		cout << "Unable to Open, Press any key to Try Again" << endl;
		getch();
		viewjunior();
		//read.close();
		return;
	}
	else
	{
		string line;
		topscreendisp();
		while(getline(read,line))
		{
			cout << line << endl;
		}
		cout << "Press any key to Exit";
		getch();
		read.close();
		return;
	}
}

void Employee :: employeelist()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t" << name << "'s Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t      " << id << " - " << name << " (You)" << endl;
	cout << endl;
	map<int,Employee*>::iterator it;
	it = chair->h->empl.find(id);
	int curr = id/100000000;
	int mod = pow(10,curr);
	for(;it != chair->h->empl.end(); it++)
	{
		if(curr >= it->first/100000000 || id%mod != it->first%mod ) continue;
		else
		{
			cout << "\t\t\t\t\t\t\t\t      " << it->first << " - " << it->second->name << endl;
		}
	}
	cout << endl;
	cout << "\t\t\t\t\tPress any key to Exit";
	getch();
}

void HR :: empllist()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t  Chairperson" << endl;
	cout << "\t\t\t\t\t\t\t\t      999999999" << " - " << chair->name << endl << endl;
	cout << "\t\t\t\t\t\t\t\t\t   Accountant"<< endl;
	cout << "\t\t\t\t\t\t\t\t      999999990" << " - " << chair->a->name << endl << endl;
	cout << "\t\t\t\t\t\t\t\t\t     HR" << endl;
	cout << "\t\t\t\t\t\t\t\t      999999991" << " - " << chair->h->name << endl << endl;
	map<int,Employee*>::iterator it;
	for(it = empl.begin();it != empl.end(); it++)
	{
		cout << "\t\t\t\t\t\t\t\t      " << it->first << " - " << it->second->name << endl;
	}
	cout << endl;
	cin.clear();
	cin.ignore();
	cout << "\t\t\t\t\tPress any key to Exit";
	getch();
}

void accountant :: viewstatement()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t      Accountant's Portal" << endl << endl;
	cout << endl;
	string a;
	a = "./" + org_name + "/Bank Details";
	a = a + "/Statement.txt";
	ifstream read (a.c_str());
	if(!read)
	{
		cout << "Unable to Open, Press any key to Try Again" << endl;
		getch();
		viewstatement();
		//read.close();
		return;
	}
	else
	{
		string line;
		topscreendisp();
		while(getline(read,line))
		{
			cout << line << endl;
		}
		cout << "Press any key to Exit";
		getch();
		read.close();
		return;
	}
}

void accountant :: addtrans()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t      Accountant's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t1: Revenue/Income" << endl;
	cout << "\t\t\t\t\t2: Salary Expense" << endl;
	cout << "\t\t\t\t\t3: Direct Cost" << endl;
	cout << "\t\t\t\t\t4: Indirect Cost" << endl;
	cout << "\t\t\t\t\t5: Operating Cost" << endl;
	cout << "\t\t\t\t\t6: Back" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter An Option:" ;
	int k;
	while(1)
	{
		cin >> k;
		if(!cin || k > 6 || k < 1)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t      Accountant's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t1: Revenue/Income" << endl;
			cout << "\t\t\t\t\t2: Salary Expense" << endl;
			cout << "\t\t\t\t\t3: Direct Cost" << endl;
			cout << "\t\t\t\t\t4: Indirect Cost" << endl;
			cout << "\t\t\t\t\t5: Operating Cost" << endl;
			cout << "\t\t\t\t\t6: Back" << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A Valid Option:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
	if(k == 6) return;
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t      Accountant's Portal" << endl << endl;
	cout << endl;
	double trans = 0;
	cout << "\t\t\t\t\tAmount:";
	while(1)
	{
		cin >> trans;
		if(!cin)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t      Accountant's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\tValid Amount:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	if(trans < 0 && k != 1)
	{
		trans = trans*(-1);
	}
	if(k == 1)
	{
		balance = balance + trans;
	}
	else
	{
		balance = balance - trans;
	}
	cout << "\t\t\t\t\tRemark/Description:";
	string desc;
	cin.ignore();
	getline(cin, desc);
	string a;
	a = "./" + org_name + "/Bank Details";
	a = a + "/Statement.txt";
	time_t edittime;
	edittime = time(NULL);
	tm *data = localtime(&edittime);
	ofstream output;
	output.open(a.c_str(), ios :: app);
	output << setw(2) << data->tm_mday << "/" << setw(2) << 1 + data->tm_mon << "/"  <<1900 + data->tm_year << "     ";
	if(k != 1)
	{
		output << fixed << setprecision(3) << left << setw(20) << trans;
		output << left << setw(20) << "-";
	}
	else
	{
		output << left << setw(20) << "-";
		output << fixed << setprecision(3) << left << setw(20) << trans;
	}
	chair->a->report[k-1] = chair->a->report[k-1] + trans;
	output << fixed << setprecision(3) << left << setw(20) << chair->a->balance;
	output << desc << endl << endl;
	output.close();
	cout << endl;
	cout << "\t\t\t\t\tTransaction Complete" << endl;
	cout << fixed << setprecision(3) << "\t\t\t\t\tRemaining Balance: " << balance << endl;
	if(balance < 0)
	{
		cout << "\t\t\t\t\tWarning: Balance is less than zero, add money in bank account" << endl;
	}
	cout << "\t\t\t\t\tPress Any key to Continue";
	getch();
}


int main()
{
	fullscreen();
	int k = mainscreen();
	if(k == 1)
	{
		newproject();
		loginscreen();
	}
	if(k == 2)
	{
		loadproject();
		loginscreen();
	}
	if(k == 3)
	{
		topscreendisp();
	}
	else return 0;
	exitscreen();
	return 0;
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
void topscreendisp()
{
    system("cls");
	cout << "\t\t=================================================="; 
	cout << "==============================================================================\n" << endl;
	cout << "\t\t\t\t\t////////////////////////////////////////";
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
	cout << "\t\t\t\t\t//\t\t\t\t\t\t\t\t\t      \\\\\n";
	cout << "\t\t\t\t\t//\t\t\t\t   Welcome To\t\t\t\t      \\\\" << endl;
	cout << "\t\t\t\t\t//\t\t\t\t\t\t\t\t\t      \\\\" << endl;
	cout << "\t\t\t\t\t\\\\\t\t\tHuman Resource Management System\t\t      //" << endl;
	cout << "\t\t\t\t\t\\\\\t\t\t\t      HRMS\t\t\t\t      //" << endl;
	cout << "\t\t\t\t\t\\\\\t\t\t\t\t\t\t\t\t      //" << endl;
	cout << "\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
	cout << "////////////////////////////////////////";
	cout << endl << endl;
} 

int mainscreen()
{
	topscreendisp();
	cout << "\t\t\t\t\t1: New Project" << endl;
	cout << "\t\t\t\t\t2: Load Project" << endl;
	cout << "\t\t\t\t\t3: Exit" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter An Option:";
	int k = 0;
	while(1)
	{
		cin >> k;
		if(!cin || k > 3 || k < 1)
		{
			topscreendisp();
			cout << "\t\t\t\t\t1: New Project" << endl;
			cout << "\t\t\t\t\t2: Load Project" << endl;
			cout << "\t\t\t\t\t3: Exit" << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A Valid Option:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	return k;
}

void exitscreen()
{
	cout << "\t\t\t\t\t\t\t\t    Thank You For Using HRMS" << endl;
	cout << "\t\t\t\t\t\t\t\t\t Have A Good Day" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\tPress any key to exit ..." << "\t\t\t\t\t\t\t\t\t\t" << "Created By - De_Bug_Err" << endl;
	getch();
}

void newproject()
{
	topscreendisp();
	cout << "\t\t\t\t\tEnter Name of the Organization:";
	cin.ignore();
	getline(cin, org_name);
	mkdir(org_name.c_str());
	cout << "\t\t\t\t\tEnter Name of the Chairperson:";
	string k = "./" + org_name + "/Employee Log Files";
	mkdir(k.c_str());
	getline(cin, k);
	master *head = new master;
	head->name = k;
	head->pswd = "0";
	cout << "\t\t\t\t\tName of Organization's HR:";
	getline(cin, k);
	HR* hr = new HR(k);
	head->h = hr;
	chair = head;
	cout << "\t\t\t\t\tName of Organization's Accountant:";
	getline(cin, k);
	double bal;
	cout << "\t\t\t\t\tInitial Account Balance:";
	while(1)
	{
		cin >> bal;
		if(!cin)
		{
			cout << "\t\t\t\t\tAccount Balance should be a number:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	accountant *acc = new accountant(k, bal);
	head->a = acc;
	topscreendisp();
	cout << "\n\t\t\t\t\t\t\t\t  Your Initial Setup is Complete" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\tPress any key to continue ..." << "\t\t\t\t\t\t\t\t\t\t" << "Created By - De_Bug_Err";
	getch();
}

void passwordscreen(int username, int a, bool b, bool wrong)
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t   Welcome To Login Portal" << endl;
	cout << "\n\n" << endl;
	cout << "\t\t\t\t\t\t\tUSER ID: " << username << endl;
	if(!b) cout << endl;
	else
	{
		cout << "\t\t\t\t\t\t\t\tEnter New Password" << endl;  
	}
	if(!wrong) cout << endl;
	else
	{
		cout << "\t\t\t\t\t\t\t\tIncorrect Password" << endl;
	}
	cout << "\t\t\t\t\t\t\tPASSWORD: ";
	if(a == 0) return;
	for(int i = 0; i < a; i++)
	{
		cout << "*";
	}
}
template <typename T>
void passwordinput(T help, int a)
{
	cin.clear();
	cin.ignore();
	if(help->pswd == "0")
		{
			passwordscreen(a,0,true,false);
			for(int i = 0;;i++)
			{
				char c = getch();
				if(c == 8)
				{
					if(i == 0)
					{
						i = -1;
						passwordscreen(a, 0, true, false);
					}
					else
					{
						i = i - 2;
						passwordscreen(a, i+1, true, false);
					}
				}
				else if(c == 13)
				{
					if(i < 8 || i >= 16)
					{
						i = -1;
						passwordscreen(a,0, true, true);
					}
					else
					{
						help->pswd = help->pswd.substr(0,i);
						break;
					}
				}
				else
				{
					if(i < help->pswd.length())
					{
						help->pswd[i] = c;
					}
					else
					{
						help->pswd = help->pswd + c;
					}
					passwordscreen(a,i+1,true,false);
				}
			}
		}
		else
		{
			string curr = "";
			passwordscreen(a,0,false,false);
			for(int i = 0;;i++)
			{
				char c = getch();
				if(c == 8)
				{
					if(i == 0)
					{
						i = -1;
						passwordscreen(a, 0, false, false);
					}
					else
					{
						i = i - 2;
						passwordscreen(a, i+1, false, false);
					}
				}
				else if(c == 13)
				{
					if(i < 8 || i >= 16)
					{
						i = -1;
						passwordscreen(a,0, false, true);
					}
					else
					{
						curr = curr.substr(0,i);
						if(curr == help->pswd)
						{
							return;
						}
						else
						{
							i = -1;
							passwordscreen(a,0, false, true);
						}
					}
				}
				else
				{
					if(i < curr.length())
					{
						curr[i] = c;
					}
					else
					{
						curr = curr + c;
					}
					passwordscreen(a,i+1,false,false);
				}
			}
		}
}
void loginscreen()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t   Welcome To Login Portal" << endl;
	cout << "\n\n" << endl;
	cout << "\t\t\t\t\t\t\tUSER ID: ";
	int a;
	while(1)
	{
		cin >> a;
		if(a == -1) 
		{
			return;
		}
		if(!cin)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t   Welcome To Login Portal" << endl;
			cout << "\n\t\t\t\t\t\t\t\tUser ID Invalid - Try Again" << endl << endl;
			cout << "\t\t\t\t\t\t\tUSER ID: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if(a != 999999999 && a != 999999990 && a != 999999991 && chair->h->empl.count(a) == 0)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t   Welcome To Login Portal" << endl;
			cout << "\n\t\t\t\t\t\t\t\tUser ID Invalid - Try Again" << endl << endl;
			cout << "\t\t\t\t\t\t\tUSER ID: ";
		}
		else break;
	}
	if(a == 999999999)
	{
		passwordinput<master *>(chair, a);
		masterscreen();
	}
	
	else if(a == 999999990)
	{
		passwordinput<accountant*>(chair->a, a);
		acctscreen();
		
	}

	else if(a == 999999991)
	{
		passwordinput<HR*>(chair->h,a);
		hrhomescreen(chair->h);
	}
	else
	{
		if(a != -1)
		{
			passwordinput<Employee*>(chair->h->empl[a], a);
			emplhomescreen(chair->h->empl[a]);
		}
	}
	save();
	loginscreen();
}

void emplhomescreen(Employee * head)
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\tWelcome " <<head->name << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t1: Edit Log file" << endl;
	if(head->under == 0)
	{
		cout << "\t\t\t\t\t2: View Log File" << endl;
		cout << "\t\t\t\t\t3: Log Out" << endl;
		cout << endl;
		cout << "\t\t\t\t\tEnter An Option:";
	}
	else
	{
		cout << "\t\t\t\t\t2: View Your/Junior's Log File" << endl;
		cout << "\t\t\t\t\t3: View Junior Employee List" << endl;
		cout << "\t\t\t\t\t4: Log Out" << endl;
		cout << endl;
		cout << "\t\t\t\t\tEnter An Option:";
	}
	int k = 0;
	while(1)
	{
		cin >> k;
		if(!cin || k > 4 || k < 1 || (k==4 && head->under == 0))
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\tWelcome " <<head->name << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t1: Edit Log file" << endl;
			if(head->under == 0)
			{
				cout << "\t\t\t\t\t2: View Log File" << endl;
				cout << "\t\t\t\t\t3: Log Out" << endl;
				cout << endl;
				cout << "\t\t\t\t\tEnter A Valid Option:";
			}
			else
			{
				cout << "\t\t\t\t\t2: View Your/Junior's Log File" << endl;
				cout << "\t\t\t\t\t3: View Junior Employee List" << endl;
				cout << "\t\t\t\t\t4: Log Out" << endl;
				cout << endl;
				cout << "\t\t\t\t\tEnter A Valid Option:";
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else 
		{
			if(head->under == 0 && k == 3) k = 4;
			break;
		}
	}
	if(k == 1)
	{
		head->editfile();
	}
	else if(k == 2)
	{
		head->viewjunior();
	}
	else if(k == 3)
	{
		head->employeelist();
	}
	else if(k == 4)
	{
		return;
	}
	emplhomescreen(head);
}

void hrhomescreen(HR *head)
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  Welcome - HR"<< endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t1: Add Employee" << endl;
	cout << "\t\t\t\t\t2: Show/Edit Employee Details" << endl;
	cout << "\t\t\t\t\t3: Show Employee List" << endl;
	cout << "\t\t\t\t\t4: Show Level Wise Employee Count" << endl;
	cout << "\t\t\t\t\t5: Log Out" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter An Option:";
	int k;
	while(1)
	{
		cin >> k;
		if(!cin || k > 5 || k < 1)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t  Welcome - HR"<< endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t1: Add Employee" << endl;
			cout << "\t\t\t\t\t2: Show/Edit Employee Details" << endl;
			cout << "\t\t\t\t\t3: Show Employee List" << endl;
			cout << "\t\t\t\t\t4: Show Level Wise Employee Count" << endl;
			cout << "\t\t\t\t\t5: Log Out" << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A Valid Option:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	if(k == 1)
	{
		hraddemployee();
	}
	else if(k == 2)
	{
		hremployeeidcheckscreen();
	}
	else if(k == 3)
	{
		head->empllist();
	}
	else if (k == 4)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t\t  Welcome - HR"<< endl << endl;
		cout << endl;
		int count = 0;
		for(int i = 1; i < head->levelWiseCount.size(); i++)
		{
			cout << "\t\t\t\t\t\t\t\t\t  Level " << i << ": " << head->levelWiseCount[i] << endl;
			count += head->levelWiseCount[i];
		}
		cout << "\t\t\t\t\t\t\t\t   Total Employee" << ": " << count << endl;
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "\t\t\t\t\t Press Any Key to Exit";
		getch();
	}
	else if (k == 5)
	{
		return;
	}
	hrhomescreen(head);
}

void hremplsescreen(int emplid)
{
	Employee *temp = chair->h->empl[emplid];
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t  Name :  " << temp->name << endl;
	cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << temp->id << endl;
	cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << temp->profile << endl;
	cout << fixed << setprecision(3) << "\t\t\t\t\t\t\t\t        Salary :  " << temp->salary << endl;
	cout << "\t\t\t\t\t\t\t\t  Joining Date :  " << temp->jointime << endl;
	cout << "\t\t\t\t\t\t      Number of Employee under :  " << temp->under << endl;
	cout << endl << endl;
	cout << "\t\t\t\t\t1: Edit Employee Name" << endl;
	cout << "\t\t\t\t\t2: Edit Employee Salary" << endl;
	cout << "\t\t\t\t\t3: Edit Employee Profile" << endl;
	cout << "\t\t\t\t\t4: Reset Employee Password" << endl;
	cout << "\t\t\t\t\t5: Remove Employee" << endl;
	cout << "\t\t\t\t\t6: Back" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter An Option:";
	int k = 0;
	while(1)
	{
		cin >> k;
		if(!cin || k > 6 || k < 1)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t\t\t\t  Name :  " << temp->name << endl;
			cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << temp->id << endl;
			cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << temp->profile << endl;
			cout << fixed << setprecision(3) << "\t\t\t\t\t\t\t\t        Salary :  " << temp->salary << endl;
			cout << "\t\t\t\t\t\t\t\t  Joining Date :  " << temp->jointime << endl;
			cout << "\t\t\t\t\t\t      Number of Employee under :  " << temp->under << endl;
			cout << endl << endl;
			cout << "\t\t\t\t\t1: Edit Employee Name" << endl;
			cout << "\t\t\t\t\t2: Edit Employee Salary" << endl;
			cout << "\t\t\t\t\t3: Edit Employee Profile" << endl;
			cout << "\t\t\t\t\t4: Reset Employee Password" << endl;
			cout << "\t\t\t\t\t5: Remove Employee" << endl;
			cout << "\t\t\t\t\t6: Back" << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A Valid Option:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	cin.clear();
	cin.ignore();
	if(k == 1)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t  Name :  " << temp->name << endl;
		cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << temp->id << endl;
		cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << temp->profile << endl;
		cout << fixed << setprecision(3)<< "\t\t\t\t\t\t\t\t        Salary :  " << temp->salary << endl;
		cout << "\t\t\t\t\t\t\t\t  Joining Date :  " << temp->jointime << endl;
		cout << "\t\t\t\t\t\t      Number of Employee under :  " << temp->under << endl;
		cout << endl << endl;
		cout << "\t\t\t\t\tEnter New Name:";
		string s;
		getline(cin,s);
		temp->name = s;
		cout << endl;
		cout << "\t\t\t\t\tName Changed!" << endl;
		cout << "\t\t\t\t\tPress any key to continue";
		getch();
	}
	else if(k == 2)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t  Name :  " << temp->name << endl;
		cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << temp->id << endl;
		cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << temp->profile << endl;
		cout << fixed << setprecision(3)<< "\t\t\t\t\t\t\t\t        Salary :  " << temp->salary << endl;
		cout << "\t\t\t\t\t\t\t\t  Joining Date :  " << temp->jointime << endl;
		cout << "\t\t\t\t\t\t      Number of Employee under :  " << temp->under << endl;
		cout << endl << endl;
		cout << "\t\t\t\t\tEnter New Salary:";
		double a = 0;
		while(1)
		{
			cin >> a;
			if(!cin)
			{
				topscreendisp();
				cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
				cout << endl;
				cout << "\t\t\t\t\t\t\t\t\t  Name :  " << temp->name << endl;
				cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << temp->id << endl;
				cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << temp->profile << endl;
				cout << fixed << setprecision(3)<< "\t\t\t\t\t\t\t\t        Salary :  " << temp->salary << endl;
				cout << "\t\t\t\t\t\t\t\t  Joining Date :  " << temp->jointime << endl;
				cout << "\t\t\t\t\t\t      Number of Employee under :  " << temp->under << endl;
				cout << endl;
				cout << "\t\t\t\t\tSalary should be a number" << endl;
				cout << "\t\t\t\t\tEnter New Salary:";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				break;
			}
		}
		temp->salary = a;
		cout << "\t\t\t\t\tSalary Changed!" << endl;
		cout << "\t\t\t\t\tPress any key to continue";
		getch();
	}
	else if(k == 3)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t  Name :  " << temp->name << endl;
		cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << temp->id << endl;
		cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << temp->profile << endl;
		cout << fixed << setprecision(3)<< "\t\t\t\t\t\t\t\t        Salary :  " << temp->salary << endl;
		cout << "\t\t\t\t\t\t\t\t  Joining Date :  " << temp->jointime << endl;
		cout << "\t\t\t\t\t\t      Number of Employee under :  " << temp->under << endl;
		cout << endl << endl;
		cout << "\t\t\t\t\tEnter New Profile:";
		string s;
		getline(cin,s);
		temp->profile = s;
		cout << endl;
		cout << "\t\t\t\t\tProfile Changed!" << endl;
		cout << "\t\t\t\t\tPress any key to continue";
		getch();
	}
	else if(k == 4)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t  Name :  " << temp->name << endl;
		cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << temp->id << endl;
		cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << temp->profile << endl;
		cout << fixed << setprecision(3)<< "\t\t\t\t\t\t\t\t        Salary :  " << temp->salary << endl;
		cout << "\t\t\t\t\t\t\t\t  Joining Date :  " << temp->jointime << endl;
		cout << "\t\t\t\t\t\t      Number of Employee under :  " << temp->under << endl;
		cout << endl << endl;
		temp->pswd = "0";
		cout << "\t\t\t\t\tPassword has been Succesfully reset" << endl;
		cout << "\t\t\t\t\tPress any key to Continue";
		getch();
	}
	else if(k == 5)
	{
		if(temp->under != 0)
		{
			cout << "\t\t\t\t\tCannot remove Employee as people work under him" << endl;
			cout << "\t\t\t\t\tPress any key to continue";
			getch();
		}
		else if(emplid/100000000 == 1)
		{
			chair->h->levelWiseCount[1] = chair->h->levelWiseCount[1] - 1;
			delete temp;
			chair->h->empl.erase(emplid);
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\tEmployee Removed Succesfully" << endl;
			cout << "\t\t\t\t\tPress Any Key to Continue";
			getch();
			return;
		}
		else
		{
			int hd = emplid/100000000;
			chair->h->levelWiseCount[hd] = chair->h->levelWiseCount[hd] - 1;
			hd = hd - 1;
			int add = pow(10,hd);
			add = emplid%add;
			hd = hd * 100000000;
			hd = hd + add;
			chair->h->empl[hd]->under = chair->h->empl[hd]->under - 1;
			delete temp;
			chair->h->empl.erase(emplid);
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\tEmployee Removed Succesfully" << endl;
			cout << "\t\t\t\t\tPress Any Key to Continue";
			getch();
			return;
		}
	}
	else if(k == 6)
	{
		return;	
	}
	hremplsescreen(emplid);
}

void hremployeeidcheckscreen()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter Employee ID:";
	int k = 0;
	while(1)
	{
		cin >> k;
		if(k == -1) return;
		else if(!cin || chair->h->empl.count(k) == 0)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A valid Employee ID:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;	
		}
		else
		{
			hremplsescreen(k);
			return;
		}
	}
}

void hraddemployee()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter the Employee ID under which the new Employee will work:";
	int k = 0;
	while(1)
	{
		cin >> k;
		if(k == -1) return;
		else if(k == 999999999)
		{
			hraddmaster();
			return;
		}
		else if(!cin || chair->h->empl.count(k) == 0)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter a Valid Employee ID under which the new Employee will work:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;	
		}
		else
		{
			hraddunder(k);
			return;
		}
	}
}
void hraddunder(int emplid)
{
	Employee *temp = chair->h->empl[emplid];
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
	cout << endl;
	if(temp->under >= 9 || emplid/100000000 == 8)
	{
		if(temp->under >=9 )
		{
			cout << "\t\t\t\t\tThis Employee cannot handle anymore employee under him" << endl;
		}
		else
		{
			cout << "\t\t\t\t\tThis is the final level allowed" << endl;
		}
		cin.clear();
		cin.ignore();
		cout << "\t\t\t\t\tPress Any Key to exit";
		getch();
		return;
	}
	cout << "\t\t\t\t\t\t\t\t   Add New Employee Details" << endl << endl;
	cin.clear();
	cin.ignore();
	cout << "\t\t\t\t\tName:";
	string s;
	getline(cin,s);
	int newid = emplid + 100000000;
	int lev = emplid/100000000;
	chair->h->levelWiseCount[lev+1] = chair->h->levelWiseCount[lev+1] + 1;
	lev = pow(10,lev);
	for(int i = 1;i <= 9; i++)
	{
		newid = newid+lev;
		if(chair->h->empl.count(newid) == 0)
		{
			break;
		}
	}
	cout << "\t\t\t\t\tProfile:";
	string p;
	getline(cin,p);
	cout << "\t\t\t\t\tSalary:";
	double sal;
	while(1)
	{
		cin >> sal;
		if(!cin)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t\t\t   Add New Employee Details" << endl<< endl;
			cout << "\t\t\t\t\tName:" << s << endl;
			cout << "\t\t\t\t\tProfile:" << p << endl;
			cout << "\t\t\t\t\tValid Salary:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	Employee *newempl = new Employee(newid,s, p);
	chair->h->empl[newid] = newempl;
	temp->under = temp->under + 1;
	newempl->profile = p;
	newempl->salary = sal;
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t New Employee Created!" << endl << endl;
	cout << "\t\t\t\t\t\t\t\t\t  Name :  " << newempl->name << endl;
	cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << newempl->id << endl;
	cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << newempl->profile << endl;
	cout << fixed << setprecision(3)<< "\t\t\t\t\t\t\t\t        Salary :  " << newempl->salary << endl;
	cout << endl;
	cin.clear();
	cin.ignore();
	cout << "\t\t\t\t\tPress Any Key to Exit";
	getch();
}

void hraddmaster()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
	cout << endl;
	if(chair->h->levelWiseCount[1] >= 9)
	{
		cout << "\t\t\t\t\tHead cannot have any more employee under the Chairperson" << endl;
		cin.clear();
		cin.ignore();
		cout << "\t\t\t\t\tPress Any Key to exit";
		getch();
		return;
	}
	cout << "\t\t\t\t\t\t\t\t   Add New Employee Details" << endl<< endl;
	cin.clear();
	cin.ignore();
	cout << "\t\t\t\t\tName:";
	string s;
	getline(cin,s);
	int newid = 100000000;
	for(int i = 1;i <= 9; i++)
	{
		newid = newid+1;
		if(chair->h->empl.count(newid) == 0)
		{
			break;
		}
	}
	cout << "\t\t\t\t\tProfile:";
	string p;
	getline(cin,p);
	cout << "\t\t\t\t\tSalary:";
	double sal;
	while(1)
	{
		cin >> sal;
		if(!cin)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t\t\t   Add New Employee Details" << endl<< endl;
			cout << "\t\t\t\t\tName:" << s << endl;
			cout << "\t\t\t\t\tProfile:" << p << endl;
			cout << "\t\t\t\t\tValid Salary:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	Employee *newempl = new Employee(newid,s, p);
	chair->h->empl[newid] = newempl;
	chair->h->levelWiseCount[1] = chair->h->levelWiseCount[1] + 1;
	newempl->profile = p;
	newempl->salary = sal;
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t  HR's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t New Employee Created!" << endl << endl;
	cout << "\t\t\t\t\t\t\t\t\t  Name :  " << newempl->name << endl;
	cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << newempl->id << endl;
	cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << newempl->profile << endl;
	cout << fixed << setprecision(3)<< "\t\t\t\t\t\t\t\t        Salary :  " << newempl->salary << endl;
	cout << endl;
	cin.clear();
	cin.ignore();
	cout << "\t\t\t\t\tPress Any Key to Exit";
	getch();
}

void acctscreen()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t      Welcome - Accountant" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t1: Add Transaction" << endl;
	cout << "\t\t\t\t\t2: Pay Everyone's Salary" << endl;
	cout << "\t\t\t\t\t3: Pay Employee Salary" << endl;
	cout << "\t\t\t\t\t4: View Bank Statement" << endl;
	cout << "\t\t\t\t\t5: Generate Report" << endl;
	cout << "\t\t\t\t\t6: Log Out" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter An Option:" ;
	int k;
	while(1)
	{
		cin >> k;
		if(!cin || k > 6 || k < 1)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t     Welcome - Accountant" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t1: Add Transaction" << endl;
			cout << "\t\t\t\t\t2: Pay Everyone's Salary" << endl;
			cout << "\t\t\t\t\t3: Pay Employee Salary" << endl;
			cout << "\t\t\t\t\t4: View Bank Statement" << endl;
			cout << "\t\t\t\t\t5: Generate Report" << endl;
			cout << "\t\t\t\t\t6: Log Out" << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A Valid Option:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
	if(k == 1)
	{
		chair->a->addtrans();
	}
	else if(k == 2)
	{
		map<int,Employee*>::iterator it;
		string a;
		a = "./" + org_name + "/Bank Details";
		a = a + "/Statement.txt";
		time_t edittime;
		edittime = time(NULL);
		tm *data = localtime(&edittime);
		double allsal = 0;
		for(it = chair->h->empl.begin(); it != chair->h->empl.end(); it++)
		{
			allsal = allsal + it->second->salary;
		}
		ofstream output;
		output.open(a.c_str(), ios :: app);
		output << setw(2) << data->tm_mday << "/" << setw(2) << 1 + data->tm_mon << "/"  <<1900 + data->tm_year << "     ";
		output << fixed << setprecision(3) << left << setw(20) << allsal;
		output << left << setw(20) << "-";
		chair->a->balance = chair->a->balance - allsal;
		chair->a->report[1] = chair->a->report[1] + allsal;
		output << fixed << setprecision(3) << left << setw(20) << chair->a->balance;
		output << "Salary: Everyone"  << endl << endl;
		output.close();
		cout << endl;
		cout << "\t\t\t\t\tSalary Paid To Everyone" << endl;
		cout << fixed << setprecision(3) <<"\t\t\t\t\tRemaining Balance: " << chair->a->balance << endl;
		if(chair->a->balance < 0)
		{
			cout << "\t\t\t\t\tWarning: Balance is less than zero, add money in bank account" << endl;
		}
		cin.clear();
		cin.ignore();
		cout << "\t\t\t\t\tPress Any key to Continue";
		getch();
	}
	else if(k == 3)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Accountant's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\tEnter Employee ID:";
		int k = 0;
		while(1)
		{
			cin >> k;
			if(k == -1) break;
			else if(!cin || chair->h->empl.count(k) == 0)
			{
				topscreendisp();
				cout << "\t\t\t\t\t\t\t\t      Accountant's Portal" << endl << endl;
				cout << endl;
				cout << "\t\t\t\t\tEnter A valid Employee ID:";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;	
			}
			else
			{
				Employee *temp = chair->h->empl[k];
				string a;
				a = "./" + org_name + "/Bank Details";
				a = a + "/Statement.txt";
				time_t edittime;
				edittime = time(NULL);
				tm *data = localtime(&edittime);
				ofstream output;
				output.open(a.c_str(), ios :: app);
				output << setw(2) << data->tm_mday << "/" << setw(2) << 1 + data->tm_mon << "/"  <<1900 + data->tm_year << "     ";
				output << fixed << setprecision(3) << left << setw(20) << temp->salary;
				output << left << setw(20) << "-";
				chair->a->balance = chair->a->balance - temp->salary;
				chair->a->report[1] = chair->a->report[1] + temp->salary;
				output << fixed << setprecision(3) << left << setw(20) << chair->a->balance;
				output << "Salary: " << temp->id << " - " << temp->name << endl << endl;
				output.close();
				cout << endl;
				cout << "\t\t\t\t\tSalary Paid To " << temp->id << " - " << temp->name << endl;
				cout << fixed << setprecision(3) << "\t\t\t\t\tRemaining Balance: " << chair->a->balance << endl;
				if(chair->a->balance < 0)
				{
					cout << "\t\t\t\t\tWarning: Balance is less than zero, add money in bank account" << endl;
				}
				cin.clear();
				cin.ignore();
				cout << "\t\t\t\t\tPress Any key to Continue";
				getch();
				break;
			}
		}
	}
	else if(k == 4)
	{
		chair->a->viewstatement();
	}
	else if (k == 5)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Accountant's Portal" << endl << endl;
		cout << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tBalance: " << chair->a->balance << endl;
		cout << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tIncome/Revenue: " << chair->a->report[0] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tSalary Expense: " << chair->a->report[1] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tDirect Cost: " << chair->a->report[2] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tIndirect Cost: " << chair->a->report[3] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tOperating Cost: " << chair->a->report[4] << endl;
		cout << endl;
		double count = 0;
		for(int i = 1; i < 5; i++)
		{
			count = count + chair->a->report[i];
		}
		cout << fixed << setprecision(3) << "\t\t\t\t\tTotal Inward: " << chair->a->report[0] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tTotal Expense: " << count << endl;
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "\t\t\t\t\tPress Any key to Exit";
		getch();
	}
	else
	{
		return;
	}
	acctscreen();
}

void masterscreen()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t     Welcome - Chairperson" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t1: View Bank Statement" << endl;
	cout << "\t\t\t\t\t2: Show Accounts Report" << endl;
	cout << "\t\t\t\t\t3: Show Employee Details" << endl;
	cout << "\t\t\t\t\t4: Show Employee List" << endl;
	cout << "\t\t\t\t\t5: Show Level Wise Count" << endl;
	cout << "\t\t\t\t\t6: Log Out" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter An Option:";
	int k;
	while(1)
	{
		cin >> k;
		if(!cin || k > 6 || k < 1)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t      Welcome - Chairperson" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t1: View Bank Statement" << endl;
			cout << "\t\t\t\t\t2: Show Accounts Report" << endl;
			cout << "\t\t\t\t\t3: Show Employee Details" << endl;
			cout << "\t\t\t\t\t4: Show Employee List" << endl;
			cout << "\t\t\t\t\t5: Show Level Wise Count" << endl;
			cout << "\t\t\t\t\t6: Log Out" << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A Valid Option:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	if(k == 1)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		string a;
		a = "./" + org_name + "/Bank Details";
		a = a + "/Statement.txt";
		ifstream read (a.c_str());
		if(!read)
		{
			cout << "Unable to Open, Press any key to Try Again" << endl;
			getch();
			masterscreen();
			//read.close();
		}
		else
		{
			string line;
			topscreendisp();
			while(getline(read,line))
			{
				cout << line << endl;
			}
			cout << "Press any key to Exit";
			getch();
			read.close();
		}
	}
	else if(k == 2)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tBalance: " << chair->a->balance << endl;
		cout << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tIncome/Revenue: " << chair->a->report[0] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tSalary Expense: " << chair->a->report[1] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tDirect Cost: " << chair->a->report[2] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tIndirect Cost: " << chair->a->report[3] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tOperating Cost: " << chair->a->report[4] << endl;
		cout << endl;
		double count = 0;
		for(int i = 1; i < 5; i++)
		{
			count = count + chair->a->report[i];
		}
		cout << fixed << setprecision(3) << "\t\t\t\t\tTotal Inward: " << chair->a->report[0] << endl;
		cout << fixed << setprecision(3) << "\t\t\t\t\tTotal Expense: " << count << endl;
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "\t\t\t\t\tPress Any key to Exit";
		getch();
	}
	else if(k == 3)
	{
		masteremplid();
	}
	else if(k == 4)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t  Chairperson" << endl;
		cout << "\t\t\t\t\t\t\t\t      999999999" << " - " << chair->name << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t   Accountant"<< endl;
		cout << "\t\t\t\t\t\t\t\t      999999990" << " - " << chair->a->name << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t     HR" << endl;
		cout << "\t\t\t\t\t\t\t\t      999999991" << " - " << chair->h->name << endl << endl;
		map<int,Employee*>::iterator it;
		for(it = chair->h->empl.begin();it != chair->h->empl.end(); it++)
		{
			cout << "\t\t\t\t\t\t\t\t      " << it->first << " - " << it->second->name << endl;
		}
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "\t\t\t\t\tPress any key to Exit";
		getch();
	}
	else if(k == 5)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t     Welcome - Chairperson" << endl << endl;
		cout << endl;
		int count = 0;
		for(int i = 1; i < chair->h->levelWiseCount.size(); i++)
		{
			cout << "\t\t\t\t\t\t\t\t\t  Level " << i << ": " << chair->h->levelWiseCount[i] << endl;
			count += chair->h->levelWiseCount[i];
		}
		cout << "\t\t\t\t\t\t\t\t   Total Employee" << ": " << count << endl;
		cout << endl;
		cin.clear();
		cin.ignore();
		cout << "\t\t\t\t\t Press Any Key to Exit";
		getch();
	}
	else if (k == 6)
	{
		return;
	}
	masterscreen();
}

void masteremplid()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter Employee ID:";
	int k = 0;
	while(1)
	{
		cin >> k;
		if(k == -1) return;
		else if(k == 999999990)
		{
			masteracctscreen();
			return;
		}
		else if(k == 999999991)
		{
			masterhrscreen();
			return;
		}
		else if(!cin || chair->h->empl.count(k) == 0)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A valid Employee ID:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;	
		}
		else
		{
			masteremplscreen(k);
			return;
		}
	}
}

void masterhrscreen()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->h->name << endl;
	cout << "\t\t\t\t\t\t\t\t Employee ID:  999999991" << endl;
	cout << "\t\t\t\t\t\t\t\t Job Profile:  HR" << endl;
	cout << endl <<endl;
	cout << "\t\t\t\t\t1: Edit Name" << endl;
	cout << "\t\t\t\t\t2: Pay Salary" << endl;
	cout << "\t\t\t\t\t3: Reset Password" << endl;
	cout << "\t\t\t\t\t4: Back" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter An Option:";
	int k = 0;
	while(1)
	{
		cin >> k;
		if(!cin || k > 4 || k < 1)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->h->name << endl;
			cout << "\t\t\t\t\t\t\t\t Employee ID:  999999991" << endl;
			cout << "\t\t\t\t\t\t\t\t Job Profile:  HR" << endl;
			cout << endl <<endl;
			cout << "\t\t\t\t\t1: Edit Name" << endl;
			cout << "\t\t\t\t\t2: Pay Salary" << endl;
			cout << "\t\t\t\t\t3: Reset Password" << endl;
			cout << "\t\t\t\t\t4: Back" << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A Valid Option:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
	cin.clear();
	cin.ignore();
	if(k == 1)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->h->name << endl;
		cout << "\t\t\t\t\t\t\t\t Employee ID:  999999991" << endl;
		cout << "\t\t\t\t\t\t\t\t Job Profile:  HR" << endl;
		cout << endl <<endl;
		cout << "\t\t\t\t\tEnter New Name:" ;
		string s;
		getline(cin, s);
		chair->h->name = s;
		cout << endl;
		cout << "\t\t\t\t\tName Changed!" << endl;
		cout << "\t\t\t\t\tPress any key to continue";
		getch(); 
	}
	else if (k == 2)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->h->name << endl;
		cout << "\t\t\t\t\t\t\t\t Employee ID:  999999991" << endl;
		cout << "\t\t\t\t\t\t\t\t Job Profile:  HR" << endl;
		cout << endl <<endl;
		cout << "\t\t\t\t\tEnter Salary:";
		double sal;
		while(1)
		{
			cin >> sal;
			if(!cin)
			{
				topscreendisp();
				cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
				cout << endl;
				cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->h->name << endl;
				cout << "\t\t\t\t\t\t\t\t Employee ID:  999999991" << endl;
				cout << "\t\t\t\t\t\t\t\t Job Profile:  HR" << endl;
				cout << endl <<endl;
				cout << "\t\t\t\t\tEnter A Valid Salary:";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				string ab;
				ab = "./" + org_name + "/Bank Details";
				ab = ab + "/Statement.txt";
				time_t edittime;
				edittime = time(NULL);
				tm *data = localtime(&edittime);
				ofstream output;
				output.open(ab.c_str(), ios :: app);
				output << setw(2) << data->tm_mday << "/" << setw(2) << 1 + data->tm_mon << "/"  <<1900 + data->tm_year << "     ";
				output << fixed << setprecision(3) << left << setw(20) << sal;
				output << left << setw(20) << "-";
				chair->a->balance = chair->a->balance - sal;
				chair->a->report[1] = chair->a->report[1] + sal;
				output << fixed << setprecision(3) << left << setw(20) << chair->a->balance;
				output << "Salary: 999999991 - HR" << endl << endl;
				output.close();
				cout << endl;
				cout << "\t\t\t\t\tSalary Paid To 999999991 - HR" << endl;
				cout << fixed << setprecision(3) << "\t\t\t\t\tRemaining Balance: " << chair->a->balance << endl;
				if(chair->a->balance < 0)
				{
					cout << "\t\t\t\t\tWarning: Balance is less than zero, add money in bank account" << endl;
				}
				cin.clear();
				cin.ignore();
				cout << "\t\t\t\t\tPress Any key to Continue";
				getch();
				break;
			}
		}
	}
	else if(k == 3)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->h->name << endl;
		cout << "\t\t\t\t\t\t\t\t Employee ID:  999999991" << endl;
		cout << "\t\t\t\t\t\t\t\t Job Profile:  HR" << endl;
		cout << endl <<endl;
		chair->h->pswd = "0";
		cout << "\t\t\t\t\tPassword has been Succesfully reset" << endl;
		cout << "\t\t\t\t\tPress any key to Continue";
		getch();
	}
	else if(k == 4) return;
	masterhrscreen();
}

void masteracctscreen()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->a->name << endl;
	cout << "\t\t\t\t\t\t\t\t Employee ID:  999999990" << endl;
	cout << "\t\t\t\t\t\t\t\t Job Profile:  Accountant" << endl;
	cout << endl <<endl;
	cout << "\t\t\t\t\t1: Edit Name" << endl;
	cout << "\t\t\t\t\t2: Pay Salary" << endl;
	cout << "\t\t\t\t\t3: Reset Password" << endl;
	cout << "\t\t\t\t\t4: Back" << endl;
	cout << endl;
	cout << "\t\t\t\t\tEnter An Option:";
	int k = 0;
	while(1)
	{
		cin >> k;
		if(!cin || k > 4 || k < 1)
		{
			topscreendisp();
			cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->a->name << endl;
			cout << "\t\t\t\t\t\t\t\t Employee ID:  999999990" << endl;
			cout << "\t\t\t\t\t\t\t\t Job Profile:  Accountant" << endl;
			cout << endl <<endl;
			cout << "\t\t\t\t\t1: Edit Name" << endl;
			cout << "\t\t\t\t\t2: Pay Salary" << endl;
			cout << "\t\t\t\t\t3: Reset Password" << endl;
			cout << "\t\t\t\t\t4: Back" << endl;
			cout << endl;
			cout << "\t\t\t\t\tEnter A Valid Option:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
	cin.clear();
	cin.ignore();
	if(k == 1)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->a->name << endl;
		cout << "\t\t\t\t\t\t\t\t Employee ID:  999999990" << endl;
		cout << "\t\t\t\t\t\t\t\t Job Profile:  Accountant" << endl;
		cout << endl <<endl;
		cout << "\t\t\t\t\tEnter New Name:" ;
		string s;
		getline(cin, s);
		chair->a->name = s;
		cout << endl;
		cout << "\t\t\t\t\tName Changed!" << endl;
		cout << "\t\t\t\t\tPress any key to continue";
		getch(); 
	}
	else if (k == 2)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->a->name << endl;
		cout << "\t\t\t\t\t\t\t\t Employee ID:  999999990" << endl;
		cout << "\t\t\t\t\t\t\t\t Job Profile:  Accountant" << endl;
		cout << endl <<endl;
		cout << "\t\t\t\t\tEnter Salary:";
		double sal;
		while(1)
		{
			cin >> sal;
			if(!cin)
			{
				topscreendisp();
				cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
				cout << endl;
				cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->a->name << endl;
				cout << "\t\t\t\t\t\t\t\t Employee ID:  999999990" << endl;
				cout << "\t\t\t\t\t\t\t\t Job Profile:  Accountant" << endl;
				cout << endl <<endl;
				cout << "\t\t\t\t\tEnter A Valid Salary:";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				string ab;
				ab = "./" + org_name + "/Bank Details";
				ab = ab + "/Statement.txt";
				time_t edittime;
				edittime = time(NULL);
				tm *data = localtime(&edittime);
				ofstream output;
				output.open(ab.c_str(), ios :: app);
				output << setw(2) << data->tm_mday << "/" << setw(2) << 1 + data->tm_mon << "/"  <<1900 + data->tm_year << "     ";
				output << fixed << setprecision(3) << left << setw(20) << sal;
				output << left << setw(20) << "-";
				chair->a->balance = chair->a->balance - sal;
				chair->a->report[1] = chair->a->report[1] + sal;
				output << fixed << setprecision(3) << left << setw(20) << chair->a->balance;
				output << "Salary: 999999990 - Accountant" << endl << endl;
				output.close();
				cout << endl;
				cout << "\t\t\t\t\tSalary Paid To 999999990 - Accountant" << endl;
				cout << fixed << setprecision(3) << "\t\t\t\t\tRemaining Balance: " << chair->a->balance << endl;
				if(chair->a->balance < 0)
				{
					cout << "\t\t\t\t\tWarning: Balance is less than zero, add money in bank account" << endl;
				}
				cin.clear();
				cin.ignore();
				cout << "\t\t\t\t\tPress Any key to Continue";
				getch();
				break;
			}
		}
	}
	else if(k == 3)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\tName:  " << chair->a->name << endl;
		cout << "\t\t\t\t\t\t\t\t Employee ID:  999999990" << endl;
		cout << "\t\t\t\t\t\t\t\t Job Profile:  Accountant" << endl;
		cout << endl <<endl;
		chair->a->pswd = "0";
		cout << "\t\t\t\t\tPassword has been Succesfully reset" << endl;
		cout << "\t\t\t\t\tPress any key to Continue";
		getch();
	}
	else if(k == 4) return;
	masteracctscreen();
}

void masteremplscreen(int eid)
{
	Employee* temp = chair->h->empl[eid];
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t      Chairperson's Portal" << endl << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t  Name :  " << temp->name << endl;
	cout << "\t\t\t\t\t\t\t\t   Employee ID :  " << temp->id << endl;
	cout << "\t\t\t\t\t\t\t\t   Job Profile :  " << temp->profile << endl;
	cout << fixed << setprecision(3) << "\t\t\t\t\t\t\t\t        Salary :  " << temp->salary << endl;
	cout << "\t\t\t\t\t\t\t\t  Joining Date :  " << temp->jointime<< endl;
	cout << "\t\t\t\t\t\t      Number of Employee under :  " << temp->under << endl;
	cout << endl << endl;
	string ab;
	ab = "./" + org_name + "/Employee Log Files/";
	ostringstream num;
	num << eid;
	ab = ab + num.str();
	ab = ab + ".txt";
	ifstream read (ab.c_str());
	if(!read)
	{
		cout << "Unable to Open, Press any key to Try Again" << endl;
		getch();
		masteremplscreen(eid);
		//read.close();
		return;
	}
	else
	{
		string line;
		while(getline(read,line))
		{
			cout << line << endl;
		}
		read.close();
		cout << "Press any key to Exit";
		getch();
		return;
	}
}

void save()
{
	string sfile;
	sfile = "./" + org_name + ".txt";
	ofstream fileout;
	fileout.open(sfile.c_str(), ios::trunc);
	fileout << "va_lid@file" << endl;
	fileout << org_name << endl;
	fileout << chair->name << endl;
	fileout << chair->pswd << endl;
	fileout << chair->h->name << endl;
	fileout << chair->h->pswd << endl;
	for(int i = 0; i < 9; i++)
	{
		fileout << chair->h->levelWiseCount[i] << " ";
	}
	fileout << "-1" << endl;
	fileout << chair->a->name << endl;
	fileout << chair->a->balance << endl;
	fileout << chair->a->pswd << endl;
	for(int i = 0; i < 5; i++)
	{
		fileout << chair->a->report[i] << " ";
	}
	fileout << "-1" << endl;
	string fread;
	fread = "./" + org_name + "/Bank Details";
	fread = fread + "/Statement.txt";
	ifstream read (fread.c_str());
	string line;
	while(getline(read,line))
	{
		fileout << line << endl;
	}
	read.close();
	fileout << "end" << endl;
	map<int,Employee*>::iterator it;
	for(it = chair->h->empl.begin();it != chair->h->empl.end(); it++)
	{
		Employee *temp = it->second;
		fileout << temp->id << endl;
		fileout << temp->name << endl;
		fileout << temp->profile << endl;
		fileout << temp->pswd << endl;
		fileout << temp->salary << endl;
		fileout << temp->under << endl;
		fileout << temp->jointime << endl;
		string eread;
		eread = "./" + org_name + "/Employee Log Files/";
		ostringstream num;
		num << temp->id;
		eread = eread + num.str();
		eread = eread + ".txt";
		ifstream erd (eread.c_str());
		string fline;
		while(getline(erd,fline))
		{
			fileout << fline << endl;
		}
		erd.close();
		fileout << "end" << endl;
	}
	fileout << "-1";
	fileout.close();
}

void loadproject()
{
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t\tLoad File" << endl << endl;
	cout << "\t\t\t\t\tMake sure the file exists" << endl;
	cout << "\t\t\t\t\tName of the file (without .txt):";
	string fname;
	cin.ignore();
	getline(cin, fname);
	fname = "./" + fname + ".txt";
	ifstream ld (fname.c_str());
	while(!ld)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t\t\tLoad File" << endl << endl;
		cout << "\t\t\t\t\tFile Doesn't Exists, Try Again" << endl;
		cout << "\t\t\t\t\tName of the file (without .txt):";
		getline(cin, fname);
		fname = "./" + fname + ".txt";
		ld.open(fname.c_str());
	}
	string gen;
	getline(ld,gen);
	if(gen != "va_lid@file")
	{
		cout << "\t\t\t\t\tThis is not a Valid File" << endl;
		cout << "\t\t\t\t\tPress any key to continue";
		getch();
		loadproject();
		return;
	}
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t\tLoad File" << endl << endl;
	cout << "\t\t\t\t\tLoading: 0%"; 
	getline(ld,org_name);
	string dir;
	dir = "./" + org_name;
	mkdir(dir.c_str());
	dir = dir + "/Bank Details";
	mkdir(dir.c_str());
	dir = "./" + org_name + "/Employee Log Files";
	mkdir(dir.c_str());
	chair = new master;
	getline(ld,chair->name);
	getline(ld,chair->pswd);
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t\tLoad File" << endl << endl;
	cout << "\t\t\t\t\tLoading: 25%"; 
	getline(ld,gen);
	chair->h = new HR(gen);
	getline(ld,chair->h->pswd);
	for(int i = 0; i < 9; i++)
	{
		ld >> chair->h->levelWiseCount[i];
	}
	int check;
	ld >> check;
	if(check == -1)
	{
		topscreendisp();
		cout << "\t\t\t\t\t\t\t\t\t\tLoad File" << endl << endl;
		cout << "\t\t\t\t\tLoading: 50%"; 
	}
	ld.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(ld,gen);
	double balan;
	ld >> balan;
	chair->a = new accountant(gen, balan);
	ld.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(ld,chair->a->pswd);
	for(int i = 0; i < 5; i++)
	{
		ld >> chair->a->report[i];
	}
	ld >> check;
	/*if(check == -1)
	{
		cout << "Success 2" << endl;
	}*/
	ld.ignore(numeric_limits<streamsize>::max(), '\n');
	string fread;
	fread = "./" + org_name + "/Bank Details";
	fread = fread + "/Statement.txt";
	ofstream outfile;
	outfile.open(fread.c_str(), ios::trunc);
	string ladd;
	while(1)
	{
		getline(ld,ladd);
		if(ladd == "end") break;
		outfile << ladd << endl;
	}
	outfile.close();
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t\tLoad File" << endl << endl;
	cout << "\t\t\t\t\tLoading: 75%"; 
	while(1)
	{
		int tempid;
		string tempname;
		string tempprof;
		ld >> tempid;
		if(tempid == -1) break;
		ld.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(ld, tempname);
		getline(ld, tempprof);
		Employee* temp = new Employee(tempid, tempname, tempprof);
		chair->h->empl[tempid] = temp;
		getline(ld,temp->pswd);
		ld >> temp->salary;
		ld >> temp->under;
		ld.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(ld, temp->jointime);
		string eread;
		eread = "./" + org_name + "/Employee Log Files/";
		ostringstream num;
		num << temp->id;
		eread = eread + num.str();
		eread = eread + ".txt";
		outfile.open(eread.c_str(), ios::trunc);
		string logadd;
		while(1)
		{
			getline(ld,logadd);
			if(logadd == "end") break;
			outfile << logadd << endl;
		}
		outfile.close();
	}
	ld.close();
	topscreendisp();
	cout << "\t\t\t\t\t\t\t\t\t\tLoad File" << endl << endl;
	cout << "\t\t\t\t\tLoading Complete" << endl << endl;
	cout << "\t\t\t\t\tPress any key to continue"; 
	getch();
}