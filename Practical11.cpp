#include <iostream>
#include <fstream>
using namespace std;

class student
{
public:
	int roll;
	char div;
	char name[10];

	void take()
	{
		cout << "\nEnter name:";
		cin >> name;
		cout << "\nEnter roll no:";
		cin >> roll;
		cout << "\nEnter div:";
		cin >> div;
	}

	void put()
	{
		cout << "Name:" << name << endl;
		cout << "Roll no:" << roll << endl;
		cout << "Div:" << div << endl;
	}
};

int main()
{
	int ch;
	int n;

	do
	{
		cout << "1.create and write\n2.read\n3.search\n4.append\n5.delete\n";
		cout << "Choose option:";
		cin >> ch;

		switch (ch)
		{

		case 1:
		{
			cout << "Enter no of students:";
			cin >> n;
			student s[10];
			int i;
			fstream fp;
			fp.open("student.txt", ios::out);
			cout << endl;
			for (i = 0; i < n; i++)
			{
				s[i].take();
				fp.write((char *)&s[i], sizeof(s[i]));
			}
			break;
		}
		case 2:
		{
			fstream fr;
			fr.open("student.txt", ios::in);
			student s1;
			while (fr.read((char *)&s1, sizeof(s1)))
			{
				// fr.read((char*)&s1[i],sizeof(s1[i]));
				s1.put();
			}
			break;
		}
		case 3:
		{

			student s;
			int r;
			int flag = 0;
			cout << "Enter roll no to be searched:";
			cin >> r;
			fstream fs;
			fs.open("student.txt", ios::in);
			while (fs.read((char *)&s, sizeof(s)))
			{
				if (s.roll == r)
				{
					cout << "record found\n";
					s.put();
					flag = 1;
				}
			}
			if (flag == 0)
				cout << "Record not found\n";
			break;
		}
		case 4:
		{
			student s[10];
			int i;
			int n1;
			fstream fa;
			fa.open("student.txt", ios::app);
			cout << "Enter no of student you want to add:";
			cin >> n1;
			for (i = 0; i < n1; i++)
			{
				s[i].take();
				fa.write((char *)&s[i], sizeof(s[i]));
			}
			break;
		}
		case 5:
		{
			fstream fp;
			fstream fp1;
			int delroll;
			int flag = 0;
			student s;
			fp.open("student.txt", ios::in);
			fp1.open("stud.txt", ios::out);
			cout << "Enter roll to be deleted:";
			cin >> delroll;
			while (fp.read((char *)&s, sizeof(s)))
			{
				if (s.roll == delroll)
				{
					cout << "record found\n";
					s.put();
					flag = 1;
				}
				else
					fp1.write((char *)&s, sizeof(s));
			}
			fp.close();	 // Close file stream for reading
			fp1.close(); // Close file stream for writing
			remove("student.txt");
			rename("stud.txt", "student.txt");
			if (flag == 0)
				cout << "Record not found\n";
			break;
		}
		}
	} while (ch != 0);
	return 0;
}
