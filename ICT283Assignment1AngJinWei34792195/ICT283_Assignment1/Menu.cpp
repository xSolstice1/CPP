#include "Menu.h"

Menu::Menu()
{
}

void Menu::ReadData()
{
    WindLog wObj;
    string const DATA_PATH = "Data/data_source.txt"; //set path of data_source.txt
    string filename;
    string line;

    ifstream infile(DATA_PATH);

    if(!infile)
    {
        cout << "\nError reading data source!\n";
        exit(0);
    }
    else
    {
        while(!infile.eof())
        {
            getline(infile,filename);
            cout << "Reading from " << filename << "\n" << endl;

            ifstream infile2("Data/"+filename);

            if(!infile2)
            {
                cout << "Error reading data file!";
                exit(0);
            }
            else
            {
                getline(infile2, line); //Skip header column of file
                while(!infile2.eof())
                {
                    if((infile2.peek() == '\n') || infile2.eof())
                    {
                        getline(infile2, line, '\n');
                        continue;
                    }
                    else
                    {
                        infile2 >> wObj;
                        wVector.pushBack(wObj);
                    }
                }
                cout << "Successfully read data from " << filename << "\n" << endl;
                infile2.close();
                infile2.clear();
            }
        }

        infile.close();
        infile.clear();
        getline(infile,filename);
    }

}

//Average wind speed and sample deviation for this wind speed given a specific month and year.
void Menu::OptionOne()
{
    cout << "\n- Option 1 -\n" << endl;

    int year = 0;
    int tempYear = 0;
    int month = 0;
    int tempMonth = 0;
    int count = 0;
    float sum = 0.0;
    float avg = 0.0;
    float SD = 0.0;
    Date d;

    while (month <= 0 || month > 12)
    {
        cout << "Please enter a month between 1-12: " << endl;
        cin >> month;
    }

    cout << "\nPlease enter the year: " << endl;
    cin >> year;

    for(int i=0; i< wVector.Size(); i++)
    {
        tempYear = wVector.At(i).getDate().getYear();
        tempMonth = wVector.At(i).getDate().getMonth();
        if (tempYear == year && tempMonth == month)
        {
            sum += wVector.At(i).getWeather().getSpeed();
            count++;
        }
    }

    //calculate avg speed (sum of all windspeed divide by the number of windspeeds)
    avg = sum/count;

    //calculate sd (square the speed minus avg(mean) and add them up, then squareroot the sum divided by the count)
    for (int i=0; i<wVector.Size(); i++)
    {
        tempYear = wVector.At(i).getDate().getYear();
        tempMonth = wVector.At(i).getDate().getMonth();
        if (tempYear == year && tempMonth == month)
        {
            SD += pow(wVector.At(i).getWeather().getSpeed() - avg, 2);
        }
    }

    SD = sqrt(SD/count);

    //output
    if (count > 0 && avg > 0)
    {
         cout << "\n" << std::fixed << std::setprecision(1) << d.monthName(month) << " " << year << ": " << endl
        << "Average speed: " << avg << " km/h" << endl
        << "Sample stdev: " << SD << endl << endl;;
    }
    else
    {
        cout << "\n" << d.monthName(month) << " " << year << ": No Data" << endl << endl;
    }
}

//Average ambient air temperature and sample standard deviation for each month of a specific year
void Menu::OptionTwo()
{
    cout << "\n- Option 2 -" << endl;

    int year;
    int tempYear;
    int tempMonth;
    int count;
    float sum;
    float avg;
    float SD;
    Date d;

    cout << "\nPlease enter the year:" << endl;
    cin >> year;
    cout << "\n" << year << endl;
    for (int i = 1; i<=12; i++)
    {
        //reset at every start of month
        count = 0;
        avg = 0;
        SD = 0;
        sum = 0;

        for (int j=0; j<wVector.Size(); j++)
        {
            tempMonth = wVector.At(j).getDate().getMonth();
            tempYear = wVector.At(j).getDate().getYear();
            if (tempMonth == i && tempYear == year)
            {
                sum += wVector.At(j).getWeather().getTemp();
                count++;
            }
        }
        //calculate average
        avg = sum/count;

        //calculate SD
        for (int j=0; j<wVector.Size(); j++)
        {
            tempMonth = wVector.At(j).getDate().getMonth();
            tempYear = wVector.At(j).getDate().getYear();
            if (tempMonth == i && tempYear == year)
            {
                SD += pow(wVector.At(j).getWeather().getTemp() - avg, 2);
            }
        }

        SD = sqrt(SD/count);

        //output
        if (count > 0 && avg > 0)
        {
            cout << std::fixed << std::setprecision(1) << d.monthName(i) << ": average: " << avg << " degrees C, stdev: " << SD << endl;
        }
        else
        {
            cout << d.monthName(i) << ": No Data" << endl;
        }
    }
    cout << endl;
}

//Total solar radiation in kWh/m^2 for each month of a specific year.
void Menu::OptionThree()
{

    cout << "\n - Option 3 - " << endl;

    int year;
    int tempYear;
    int tempMonth;
    int count;
    float sum;
    Date d;

    cout << "\nPlease enter the year: " << endl;
    cin >> year;

    cout << "\n" << year << endl;

    for (int i=1; i<=12; i++)
    {
        //reset at start of every month
        sum = 0;
        count = 0;

        for (int j=0; j<wVector.Size(); j++)
        {
            tempMonth = wVector.At(j).getDate().getMonth();
            tempYear = wVector.At(j).getDate().getYear();
            if (tempMonth == i && tempYear == year)
            {
                if (wVector.At(j).getWeather().getSR() >= 100)
                {
                    sum += wVector.At(j).getWeather().getSR();
                    count++;
                }
            }
        }

        //convert to kWh/m^2
        sum = sum/6; //Wh/m^2
        sum = sum/1000; //kWh/m^2


        //output
        if (count > 0 && sum > 0)
        {
            cout << std::fixed << std::setprecision(1) << d.monthName(i) << ": " << sum << " kWh/m^2" << endl;
        }
        else
        {
            cout << d.monthName(i) << ": No Data" << endl;
        }
    }
    cout << endl;
}

//Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m^2 for each month of a specific year.
//Standard deviation is printed in () next to the average. Output to WindTempSolar.csv
void Menu::OptionFour()
{
    cout << "\n - Option 4 - " << endl;

    string const OUTPUT_PATH = "Data/WindTempSolar.csv";
    int year;
    int tempYear;
    int tempMonth;
    int count = 0;
    int yearCount = 0;
    float speedSum = 0;
    float SRSum = 0;
    float tempSum = 0;
    float speedSD = 0;
    float tempSD = 0;
    float speedAvg = 0;
    float tempAvg = 0;
    Date d;
    ofstream output;

    cout << "\nPlease enter the year: " << endl;
    cin >> year;

    output.open(OUTPUT_PATH);
    output << year << endl;

    //check if year is empty
    for (int i=1; i<=12; i++)
    {
        for( int j=0; j<wVector.Size(); j++)
            {
                tempMonth = wVector.At(j).getDate().getMonth();
                tempYear = wVector.At(j).getDate().getYear();
                if (tempMonth == i && tempYear == year)
                {
                    if (wVector.At(j).getWeather().getSR() >= 100)
                    {
                        SRSum += wVector.At(j).getWeather().getSR();
                    }
                    speedSum += wVector.At(j).getWeather().getSpeed();
                    tempSum += wVector.At(j).getWeather().getTemp();
                }
            }
    }

    if (speedSum > 0 && SRSum > 0 && tempSum > 0)
    {
        yearCount++;
    }

    if (yearCount > 0)
    {
        for (int i=1; i<=12; i++)
        {
            //reset at start of every month
            count = 0;
            speedSum = 0;
            SRSum = 0;
            tempSum = 0;
            speedSD = 0;
            tempSD = 0;
            speedAvg = 0;
            tempAvg = 0;

            for( int j=0; j<wVector.Size(); j++)
            {
                tempMonth = wVector.At(j).getDate().getMonth();
                tempYear = wVector.At(j).getDate().getYear();
                if (tempMonth == i && tempYear == year)
                {
                    speedSum += wVector.At(j).getWeather().getSpeed();
                    tempSum += wVector.At(j).getWeather().getTemp();
                    count++;
                }
            }

            speedAvg = speedSum/count;
            tempAvg = tempSum/count;

            for (int j=0; j<wVector.Size(); j++)
            {
                tempMonth = wVector.At(j).getDate().getMonth();
                tempYear = wVector.At(j).getDate().getYear();
                if (tempMonth == i && tempYear == year)
                {
                    if (wVector.At(j).getWeather().getSR() >= 100)
                    {
                        SRSum += wVector.At(j).getWeather().getSR();
                    }
                    speedSD += pow(wVector.At(j).getWeather().getSpeed() - speedAvg, 2);
                    tempSD += pow(wVector.At(j).getWeather().getTemp() - tempAvg, 2);
                }
            }

            //calculate SD for speed and temp
            speedSD = sqrt(speedSD/count);
            tempSD = sqrt(tempSD/count);

            //convert W/m^2 to kWh/m^2
            SRSum = SRSum/6;
            SRSum = SRSum / 1000;

            //check if month contains data and what data does it not contain
            if (count > 0)
            {
                output << d.monthName(i);
                if (speedAvg > 0)
                {
                    output << std::fixed << std::setprecision(1) << "," << speedAvg;
                }
                else
                {
                    output << ",";
                }
                if (speedSD > 0)
                {
                    output << "(" << speedSD << ")";
                }
                if (tempAvg > 0)
                {
                    output << "," << tempAvg;
                }
                else
                {
                    output << ",";
                }
                if (tempSD > 0)
                {
                    output << "(" << tempSD << ")";
                }
                if (SRSum > 0)
                {
                    output << "," << SRSum;
                }
                output << endl;
            }
        }
    }
    else
    {
        output << "No Data" << endl;
    }

    cout << "File successfully output to (" + OUTPUT_PATH + ")!" << endl << endl;
    output.close();
}

void Menu::LoadMenu()
{
    int choice = 0;

    cout << "\n(1) The average wind speed and sample standard deviation for this wind speed given a specific month and year." << endl;
    cout << "(2) Average ambient air temperature and sample standard deviation for each month of a year." << endl;
    cout << "(3) Total solar radiation in kWh/m2 for each month of a specific year." <<endl;
    cout << "(4) Average wind speed (km/h), average ambient temperature and total solar radiation in kWh/m2 for each month of a specific year." << endl;
    cout << "(5) Exit the program. \n" << endl;

    while (choice != 5)
    {
        cout << "Enter a menu option: " << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                {
                    OptionOne();
                    break;
                }
            case 2:
                {
                    OptionTwo();
                    break;
                }
            case 3:
                {
                    OptionThree();
                    break;
                }
            case 4:
                {
                    OptionFour();
                    break;
                }
            case 5:
                {
                    cout << "\nThanks for using, the program will now exit. " << endl;
                    break;
                }
            default:
                {
                    cout << "\nInvalid option, please try again. " << endl;
                }
        }
    }
}
