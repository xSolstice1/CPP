#include "Menu.h"

//initialize collector variables
float Collector::m_max = 0;
float Collector::m_min = 9999;
float Collector::m_total = 0;

//operators
bool operator>(const Value &L, const Value &R);
bool operator==(const Value &L, const Value &R);

Menu::Menu()
{
}

void Menu::ReadData()
{
    WindLog wObj;
    BST<Value> yearTree;
    Collector c;
    Value v;
    string const DATA_PATH = "Data/data_source.txt"; //set path of data_source.txt
    string filename;
    string line;
    vector<string> data;
    int const NUM_OF_COLUMNS = 17; //enter number of columns excluding date/time

    //enter the index position of speed, sr and temp excluding date/time
    int const SPEED_INDEX = 10;
    int const SR_INDEX = 11;
    int const TEMP_INDEX = 0;

    //variables storage
    string storeDay, storeMonth, storeYear, storeHour, storeMinute, storeSR, storeTemp, storeSpeed;

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
            if((infile.peek() == '\n') || infile.eof())
            {
                getline(infile, line, '\n');
                continue;
            }
            else
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
                    infile2.ignore(999,'\n'); //Skip header column of file
                    while(!infile2.eof())
                    {
                        if((infile2.peek() == '\n') || infile2.eof() || !isdigit(infile2.peek())) //check if next is empty, end of file or not a digit
                        {
                            getline(infile2, line, '\n');
                            continue;
                        }
                        else
                        {
                            getline(infile2, storeDay, '/');
                            getline(infile2, storeMonth, '/');
                            getline(infile2, storeYear, ' ');
                            getline(infile2, storeHour, ':');
                            getline(infile2, storeMinute, ',');

                            for(int i=0; i<NUM_OF_COLUMNS-1; i++)
                            {
                                getline(infile2,line,',');
                                data.push_back(line);
                            }
                            storeSR = data[SR_INDEX];
                            storeSpeed = data[SPEED_INDEX];
                            storeTemp = data[TEMP_INDEX];
                            data.clear();
                            getline(infile2,line,'\n');

                            if(storeSpeed != "N/A" && storeSR != "N/A" && storeTemp != "N/A" && storeHour != "N/A" && storeMinute != "N/A" && storeDay != "N/A" && storeMonth != "N/A" && storeYear != "N/A")
                            {
                                Weather weatherObj = Weather(stof(storeSpeed),stof(storeSR),stof(storeTemp));
                                Time timeObj = Time(stoi(storeHour),stoi(storeMinute));
                                Date dateObj = Date(stoi(storeDay),stoi(storeMonth),stoi(storeYear));
                                WindLog windlogObj = WindLog(dateObj,timeObj,weatherObj);

                                v.SetValue(dateObj.GetYear());

                                //check if year already exist in tree
                                if (!yearTree.SearchItem(v))
                                {
                                    yearTree.InsertItem(v);
                                }

                                mapObject[dateObj.GetYear()][dateObj.GetMonth()].push_back(windlogObj);
                            }
                        }
                    }

                    //find max year in tree
                    yearTree.InOrderTraversal(Collector::Max);
                    MAX_YEAR = c.GetMax();

                    //find min year in tree
                    yearTree.InOrderTraversal(Collector::Min);
                    MIN_YEAR = c.GetMin();

                    cout << "Successfully read data from " << filename << "\n" << endl;
                    infile2.close();
                    infile2.clear();
                }
            }
        }

        infile.close();
        infile.clear();
        getline(infile,filename);
    }
}

float Menu::CalculateAverageSpeed(map<int,map<int,vector<WindLog>>> &m, int month, int year)
{
    float sum = 0;
    int count = 0;
    float avg = 0;
    BST<Value> valueTree;
    Value v;
    Collector c;

    for (unsigned int i=0; i<m[year][month].size(); i++)
    {
        v.SetValue(m[year][month].at(i).GetWeather().GetSpeed());
        valueTree.InsertItem(v);
        count++;
    }

    valueTree.InOrderTraversal(Collector::Sum);
    sum = c.GetSum();
    avg = sum/count;
    valueTree.~BST();

    return avg;
}

float Menu::CalculateSpeedSD(map<int,map<int,vector<WindLog>>> &m, int month, int year, float avg)
{
    int count = 0;
    float SD = 0.0;

    for (unsigned int i=0; i<m[year][month].size(); i++)
    {
        SD += pow(m[year][month].at(i).GetWeather().GetSpeed() - avg, 2);
        count++;
    }

    SD = sqrt(SD/count);

    return SD;
}

float Menu::CalculateTempSD(map<int,map<int,vector<WindLog>>> &m, int month, int year, float avg)
{
    int count = 0;
    float SD = 0.0;

    for (unsigned int i=0; i<m[year][month].size(); i++)
    {
        SD += pow(m[year][month].at(i).GetWeather().GetTemp() - avg, 2);
        count++;
    }

    SD = sqrt(SD/count);

    return SD;
}

float Menu::CalculateAverageTemp(map<int,map<int,vector<WindLog>>> &m, int month, int year)
{
    float sum = 0;
    int count = 0;
    float avg = 0;
    BST<Value> valueTree;
    Value v;
    Collector c;

    for (unsigned int i=0; i<m[year][month].size(); i++)
    {
        v.SetValue(m[year][month].at(i).GetWeather().GetTemp());
        valueTree.InsertItem(v);
        count++;
    }

    valueTree.InOrderTraversal(Collector::Sum);
    sum = c.GetSum();
    avg = sum/count;
    valueTree.~BST();

    return avg;
}

int Menu::InputYear()
{
    int m_year = 9999;

    cout << "Please enter a year: " << endl;
    cin >> m_year;

    //year validation
    while (m_year > MAX_YEAR || m_year < MIN_YEAR)
    {
        cout << "Please enter a valid year!: (" << MIN_YEAR << " - " << MAX_YEAR << ")"  << endl;
        cin >> m_year;
    }

    return m_year;
}

int Menu::InputMonth()
{
    int m_month = 0;

    while (m_month <= 0 || m_month > 12)
    {
        cout << "Please enter a month between (1-12): " <<endl;
        cin >> m_month;
    }

    return m_month;
}

//Average wind speed and standard deviation for the windspeed given a specific month and year
void Menu::OptionOne()
{
    cout << "\n- Option 1 -\n" << endl;

    int m_month = InputMonth();
    int m_year = InputYear();
    float avg = CalculateAverageSpeed(mapObject, m_month, m_year);
    float SD = CalculateSpeedSD(mapObject, m_month, m_year, avg);
    Date d;

    //output
    if (avg > 0  && SD > 0)
    {
        cout << "\n" << std::fixed << std::setprecision(1) << d.MonthName(m_month) << " " << m_year << ": "
             << endl << "Average speed: " << avg << " km/h" << endl << "Sample stdev: " << SD << endl << endl;
    }
    else
    {
        cout << "\n" << d.MonthName(m_month) << " " << m_year << ": No Data" << endl << endl;
    }
}

//Average ambient air temperature and sample stdev for each month of a specific year
void Menu::OptionTwo()
{
    cout << "\n- Option 2 -" << endl;

    float avg;
    float SD;
    int m_year = InputYear();
    Date d;

    cout << endl << m_year << endl;
    for (int i=1; i<=12; i++)
    {
        avg = CalculateAverageTemp(mapObject, i, m_year); //calculate average temperature for the month
        SD = CalculateTempSD(mapObject, i, m_year, avg); //calculate SD for the month

        //output
        if (avg > 0)
        {
            cout << std::fixed << std::setprecision(1) << d.MonthName(i) << ": average: " << avg
                 << " degrees C, stdev: " << SD << endl;
        }
        else
        {
            cout << d.MonthName(i) << ": No Data" << endl;
        }
    }
}

//Sample Pearson Correlation Coefficient for specific month and combination of two data fields
void Menu::OptionThree()
{

    cout << "\n- Option 3    -" << endl;

    int m_month = InputMonth();
    vector<double> speed;
    vector<double> SR;
    vector<double> temp;
    float m_st;
    float m_sr;
    float m_tr;
    Date d;

    //loop through the years
    for (int i=MIN_YEAR; i < MAX_YEAR+1; i++)
    {
        for (unsigned int j=0; j<mapObject[i][m_month].size(); j++)
        {
            speed.push_back(mapObject[i][m_month].at(j).GetWeather().GetSpeed());
            temp.push_back(mapObject[i][m_month].at(j).GetWeather().GetTemp());
            SR.push_back(mapObject[i][m_month].at(j).GetWeather().GetSR());
        }
    }

    //test using sample data
    /*vector<double> test1;
    vector<double> test2;

    test1.push_back(9);
    test1.push_back(7);
    test1.push_back(5);
    test1.push_back(3);
    test1.push_back(1);
    test2.push_back(10);
    test2.push_back(6);
    test2.push_back(1);
    test2.push_back(5);
    test2.push_back(3);

    float testresult = CalculateSPCC(test1,test2);*/

    m_st = CalculateSPCC(speed,temp);
    m_sr = CalculateSPCC(speed,SR);
    m_tr = CalculateSPCC(temp,SR);

    //cout << endl << "Test Result: " << testresult << endl;

    cout << endl << "sPCC for " << d.MonthName(m_month) << endl;
    //set to 2 decimal points
    cout << std::fixed << std::setprecision(2) << endl << "S_T: " << m_st << endl;
    cout << endl << "S_R: " << m_sr << endl;
    cout << endl << "T_R: " << m_tr << endl << endl;
}


//Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m^2 for each month of a specific year.
//Standard deviation is printed in () next to the average. Output to WindTempSolar.csv
void Menu::OptionFour()
{
    cout << "\n - Option 4 - " << endl;

    string const OUTPUT_PATH = "Data/WindTempSolar.csv";
    int m_year = InputYear();
    int tempYear = 0;
    int tempMonth = 0;
    int count = 0;
    int yearCount = 0;
    float speedSum = 0.0;
    float SRSum = 0.0;
    float tempSum = 0.0;
    float speedSD = 0.0;
    float tempSD = 0.0;
    float speedAvg = 0.0;
    float tempAvg = 0.0;
    Date d;
    ofstream output;

    output.open(OUTPUT_PATH);
    output << m_year << endl;

    //check if year is empty
    for (int i=1; i<12; i++)
    {
        for (unsigned int j=0; j<mapObject[m_year][i].size(); j++)
        {
            tempMonth = mapObject[m_year][i].at(j).GetDate().GetMonth();
            tempYear = mapObject[m_year][i].at(j).GetDate().GetYear();
            if (tempMonth == i && tempYear == m_year)
            {
                if (mapObject[m_year][i].at(j).GetWeather().GetSR() >= 100)
                {
                    SRSum += mapObject[m_year][i].at(j).GetWeather().GetSR();
                }
                speedSum += mapObject[m_year][i].at(j).GetWeather().GetSpeed();
                tempSum += mapObject[m_year][i].at(j).GetWeather().GetTemp();
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
            //reset at start of month
            count = 0;
            speedSum = 0;
            SRSum = 0;
            tempSum = 0;
            speedSD = 0;
            tempSD = 0;
            speedAvg = 0;
            tempAvg = 0;

            for (unsigned int j=0; j<mapObject[m_year][i].size(); j++)
            {
                tempMonth = mapObject[m_year][i].at(j).GetDate().GetMonth();
                tempYear = mapObject[m_year][i].at(j).GetDate().GetYear();
                if (tempMonth == i && tempYear == m_year)
                {
                    speedSum += mapObject[m_year][i].at(j).GetWeather().GetSpeed();
                    tempSum += mapObject[m_year][i].at(j).GetWeather().GetTemp();
                    count++;
                }
            }

            speedAvg = speedSum/count;
            tempAvg = tempSum/count;

            for (unsigned int j=0; j<mapObject[m_year][i].size(); j++)
            {
                tempMonth = mapObject[m_year][i].at(j).GetDate().GetMonth();
                tempYear = mapObject[m_year][i].at(j).GetDate().GetYear();
                if (tempMonth == i && tempYear == m_year)
                {
                    if (mapObject[m_year][i].at(j).GetWeather().GetSR() >= 100)
                    {
                        SRSum += mapObject[m_year][i].at(j).GetWeather().GetSR();
                    }
                    speedSD += pow(mapObject[m_year][i].at(j).GetWeather().GetSpeed() - speedAvg, 2);
                    tempSD += pow(mapObject[m_year][i].at(j).GetWeather().GetTemp() - tempAvg, 2);
                }
            }

            //calculate SD
            speedSD = sqrt(speedSD/count);
            tempSD = sqrt(tempSD/count);

            //convert W/m^2 to kWh/m^2
            SRSum = SRSum/6;
            SRSum = SRSum/1000;

            //check if month contains data or not
            if (count > 0)
            {
                output << d.MonthName(i);
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
                    output << std::fixed << std::setprecision(1) << "(" << speedSD << ")";
                }
                if (tempAvg > 0)
                {
                    output << std::fixed << std::setprecision(1) << "," << tempAvg;
                }
                else
                {
                    output << ",";
                }
                if (tempSD > 0)
                {
                    output << std::fixed << std::setprecision(1) << "(" << tempSD << ")";
                }
                if (SRSum > 0)
                {
                    output << std::fixed << std::setprecision(1) << "," << SRSum;
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

double Menu::CalculateSPCC(const vector<double> &X, const vector<double> &Y)
{
    unsigned int n = X.size();

    //validation check if vector is empty or vectors size are not equal
    if (n < 1 || Y.size() != n)
    {
        cout << "Datasets are invalid\n";
        return 0.0;
    }

    double SumX = 0, SumY = 0, SquareX = 0, SumYY = 0, SumXY = 0;

    for (unsigned int i = 0; i < n; i++ )
    {
        SumX  += X[i];
        SumY  += Y[i];
        SquareX += X[i] * X[i];
        SumXY += X[i] * Y[i];
        SumYY += Y[i] * Y[i];
    }

    double spcc = ( SquareX - SumX * SumX / n ) * ( SumYY - SumY * SumY / n );
    spcc = (SumXY - SumX * SumY / n ) / sqrt(spcc);

    return spcc;
}

void Menu::LoadMenu()
{
    int choice = 0;

    cout << "\n(1) The average wind speed and sample standard deviation for this wind speed given a specific month and year." << endl;
    cout << "(2) Average ambient air temperature and sample standard deviation for each month of a year." << endl;
    cout << "(3) Pearson Correlation Coefficient for 3 combinations (S_T, S_R, T_R)" <<endl;
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

bool operator>(const Value &L, const Value &R)
{
    float a = L.GetValue();
    float b = R.GetValue();

    return a > b;
}

bool operator==(const Value &L, const Value &R)
{
    int a = L.GetValue();
    int b = R.GetValue();

    return a == b;
}

