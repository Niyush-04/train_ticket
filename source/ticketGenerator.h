#include <iostream>
#include <fstream>
#include <string>
using namespace std;


string firstPart = R"(
    <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Ticket Portal</title>
    <link rel="icon" src="img/favicon.png">
    <style>
        body, h1, h2, p, ul {
            margin: 0;
            padding: 0;
            text-align: center;
        }

        body {
            font-family: Arial, Helvetica, sans-serif;
            background-color: #7ec7c4;
        }

        header, footer {
            background-color: #599896;
            color: aliceblue;
            text-align: center;
            padding: 10px;
        }

        .Ticketinfo, .passinfo, .guide {
            max-width: 80%;
            margin: 20px auto;
            padding: 20px;
            background-color: #599896;
            border-radius: 20px;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            text-align: center;
            margin-top: 20px;
            margin-bottom: 20px;
        }
        h3{
            margin-top: 10px;
            margin-bottom: 10px;
            text-align: left;

        }

        th, td {
            border: 2px solid #215755;
            padding: 10px;
        }
    </style>
</head>
<body>
<header>
    <h1>Welcome to the Train Booking System</h1>
    <p>Wishing a happy and safer journey.</p>
</header>

<section class="Ticketinfo">
    <h2>Train Ticket Booking Information :</h2>
)";

string secondPart = R"(
</section>

<section class="passinfo">
    <h2>Passenger details :</h2>
    <table>
        <tr>
            <th>S.No</th>
            <th>Passenger Name</th>
            <th>age</th>
            <th>gender</th>
            <th>seat No.</th>
        </tr>

)";

string thirdPart = R"(
    </table>
</section>

<section class="guide">
    <h2>Printing Guide :</h2>
    <p>To print the ticket press ctrl + p.</p>
    <p>It will open a new tab where you can now print the ticket.</p>
</section>

<footer>
    <p>&copy; 2023 Train Booking. All rights reserved.</p>
    <p>Powered by ticket portal</p>
    <p><a href="#top">Back to top</a></p>
</footer>
</body>
</html>
    )";

string tin,traindetail,totalnumberofpassenger, passengername, gender, age, seat, ticketInfo;
int nop , i;

void printTicket();

void searchBooking()
	{
        fstream fin;
        fin.open("Tickets.txt", ios::in);
		string search;
		cout << "Enter ticket inquiry number: ";
		cin >> search;
		string y;
		while (getline(fin, y))
		{
			if (y.find("Ticket inquiry number: " + search) != string::npos)
			{
                tin = y;

				getline(fin, y);
                traindetail = y;
                
                getline(fin, y);
                totalnumberofpassenger = y;
                nop = stoi((totalnumberofpassenger).substr(28,1));
                getline(fin, y);

                for(i=1;i<=nop;i++)
                {
                getline(fin, y);
                passengername = y.substr(15,y.length()-15);

                getline(fin, y);
                gender = y.substr(7,8);
                age = y.substr(24,y.length()-24);

                getline(fin, y);
                seat = y.substr(12,y.length()-12);
               
                getline(fin,y); //it is for the extra empty line in the Trainfile
               
                printTicket();
                }
			}
		}
		fin.close();
	}

void printTicket() {

if(i==1){
    ofstream outputFile("yourTicket.html");
    outputFile << firstPart;
    outputFile << "<h3>" + tin + "</h3> <h3>" + traindetail + "</h3> <h3> " + totalnumberofpassenger + "</h3>";
    outputFile << secondPart;
    outputFile.close();
}

    {
    ofstream outputFile("yourTicket.html", ios::app);
    outputFile << "<tr> <td>" + to_string(i) + "</td> <td>" + passengername + "</td> <td>" + age + "</td> <td>" + gender + "</td> <td>" + seat + "</td> </tr>"<<endl;
    outputFile.close();
    }
    
    if(i==nop){
        ofstream outputFile("yourTicket.html", ios::app);
    outputFile << thirdPart;
    outputFile.close();
    cout << "Your Ticket generated successfully." << std::endl;
    }
}
