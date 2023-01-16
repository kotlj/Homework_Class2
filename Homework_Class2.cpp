
#include <iostream>
#include <fstream>

using namespace std;

class phoneBookUnit
{
private:
    char* fullName;
    char* homeNumber = new char[15];
    char* workNumber = new char[15];
    char* mobNumber = new char[15];
    char* additional;

public:
    phoneBookUnit()
    {
        fullName = new char[22];
        additional = new char[2];
        additional[0] = '0';
        additional[1] = '\0';
        for (int i = 0; i < 21; i++)
        {
            fullName[i] = ' ';
        }
        fullName[21] = '\0';
        for (int i = 0; i < 14; i++)
        {
            homeNumber[i] = '0';
            workNumber[i] = '0';
            mobNumber[i] = '0';
        }
        homeNumber[14] = '\0';
        workNumber[14] = '\0';
        mobNumber[14] = '\0';
    }
    phoneBookUnit(char* _fullName, char* _homeNumber = nullptr, char* _workNumber = nullptr, char* _mobNumber = nullptr,
        char* _additional = nullptr)
    {
        setFullName(_fullName);
        if (_homeNumber != nullptr)
        {
            setHomeNumber(_homeNumber);
        }
        else
        {
            for (int i = 0; i < 14; i++)
            {
                homeNumber[i] = '0';
            }
            homeNumber[14] = '\0';
        }
        if (_workNumber != nullptr)
        {
            setWorkNumber(_workNumber);
        }
        else
        {
            for (int i = 0; i < 14; i++)
            {
                workNumber[i] = '0';
            }
            workNumber[14] = '\0';
        }
        if (_mobNumber != nullptr)
        {
            setMobNumber(_mobNumber);
        }
        else
        {
            for (int i = 0; i < 14; i++)
            {
                mobNumber[i] = '0';
            }
            mobNumber[14] = '\0';
        }
        if (_additional != nullptr)
        {
            setAdditional(_additional);
        }
        else
        {
            additional = new char[2];
            additional[0] = '0';
            additional[1] = '\0';
        }
    }
    phoneBookUnit(phoneBookUnit& obj)
    {
        this->setFullName(obj.getFullName());
        this->setHomeNumber(obj.getHomeNumber());
        this->setWorkNumber(obj.getWorkNumber());
        this->setMobNumber(obj.getMobNumber());
        this->setAdditional(obj.getAdditional());
    }

    void copy(phoneBookUnit& obj)
    {
        this->setFullName(obj.getFullName());
        this->setHomeNumber(obj.getHomeNumber());
        this->setWorkNumber(obj.getWorkNumber());
        this->setMobNumber(obj.getMobNumber());
        this->setAdditional(obj.getAdditional());
    }

    char* getFullName() const
    {
        return fullName;
    }
    char* getHomeNumber() const
    {
        return homeNumber;
    }
    char* getWorkNumber() const
    {
        return workNumber;
    }
    char* getMobNumber() const
    {
        return mobNumber;
    }
    char* getAdditional() const
    {
        return additional;
    }

    void setFullName(char* _fullName)
    {
        int size;
        for (size = 0; _fullName[size] != '\0'; size++)
        {

        }
        fullName = new char[size + 1];
        fullName[size] = '\0';
        for (int i = 0; _fullName[i] != '\0'; i++)
        {
            fullName[i] = _fullName[i];
        }
    }
    void setHomeNumber(char* _homeNumber)
    {
        for (int i = 0; i < 14; i++)
        {
            homeNumber[i] = ' ';
        }
        for (int i = 0; i < 14 && _homeNumber[i] != '\0'; i++)
        {
            homeNumber[i] = _homeNumber[i];
        }
        homeNumber[14] = '\0';
    }
    void setWorkNumber(char* _workNumber)
    {
        for (int i = 0; i < 14; i++)
        {
            workNumber[i] = ' ';
        }
        for (int i = 0; i < 14 && _workNumber[i] != '\0'; i++)
        {
            workNumber[i] = _workNumber[i];
        }
        workNumber[14] = '\0';
    }
    void setMobNumber(char* _mobNumber)
    {
        for (int i = 0; i < 14; i++)
        {
            mobNumber[i] = ' ';
        }
        for (int i = 0; i < 14 && _mobNumber[i] != '\0'; i++)
        {
            mobNumber[i] = _mobNumber[i];
        }
        mobNumber[14] = '\0';
    }
    void setAdditional(char* _additional)
    {
        int size;
        for (size = 0; _additional[size] != '\0'; size++)
        {

        }
        additional = new char[size + 1];
        additional[size] = '\0';
        for (int i = 0; _additional[i] != '\0'; i++)
        {
            additional[i] = _additional[i];
        }
    }

    ~phoneBookUnit()
    {
        if (fullName != nullptr)
        {
            delete[] fullName;
        }
        if (homeNumber != nullptr)
        {
            delete[] homeNumber;
        }
        if (workNumber != nullptr)
        {
            delete[] workNumber;
        }
        if (mobNumber != nullptr)
        {
            delete[] mobNumber;
        }
        if (additional != nullptr)
        {
            delete[] additional;
        }
    }
};

void inline showPhoneBook(phoneBookUnit* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "--------------------------\n";
        cout << "Full name: " << arr[i].getFullName() << "\nHome phone number: " << arr[i].getHomeNumber() <<
            "\nWork phone number: " << arr[i].getWorkNumber() << "\nMobyle phone number: " << arr[i].getMobNumber() <<
            "\nAddition: " << arr[i].getAdditional() << "\n";
    }
}

int findByName(phoneBookUnit* arr, int size, char* _fullName)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getFullName() == _fullName)
        {
            return i;
        }
    }
    return -1;
}

void addMember(phoneBookUnit* &arr, phoneBookUnit& memberNew, int& arrSize)
{
    phoneBookUnit* temple = new phoneBookUnit[arrSize + 1];
    temple[arrSize].copy(memberNew);
    for (int i = 0; i < arrSize; i++)
    {
        temple[i].copy(arr[i]);
    }
    delete[] arr;
    arr = temple;
    temple = nullptr;
    arrSize++;
}

void delMember(phoneBookUnit* &arr, int& arrSize, int& indx)
{
    phoneBookUnit* temple = new phoneBookUnit[arrSize - 1];
    for (int i = 0; i < arrSize; i++)
    {
        if (i < indx)
        {
            temple[i].copy(arr[i]);
        }
        else if (i > indx)
        {
            temple[i - 1].copy(arr[i]);
        }
    }
    arr = temple;
    arrSize -= 1;
}

int main()
{
    int arrSize = 10;
    int nameSize = 20;
    int additionSize = 100;
    int PNSize = 14;
    int indx = 0;
    char* HNumber = new char[PNSize];
    char* WNumber = new char[PNSize];
    char* MNumber = new char[PNSize];
    char* addition = nullptr;
    phoneBookUnit* arr = new phoneBookUnit[arrSize];
    char* fullName = new char[nameSize];
    fullName[5] = '\0';
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < nameSize; j++)
        {
            fullName[j] = char(65 + i);
        }
        fullName[nameSize - 1] = '\0';
        arr[i].setFullName(fullName);
    }
    int choise = 1;
    while (choise != 0)
    {
        cout << "1 - Show all members;\n2 - Find member by full name\n3 - Add member;\n4 - Delete member;\
            \n5 - Save to file;\n6 - Load from file(CAUTION: first you need to save something to file);\n0 - Exit\n";
        cin >> choise;
        if (choise == 1)
        {
            showPhoneBook(arr, arrSize);
        }
        else if (choise == 2)
        {
            cout << "Enter full name: ";
            gets_s(fullName, nameSize);
            gets_s(fullName, nameSize);
            cout << findByName(arr, arrSize, fullName) << '\n';
        }
        else if (choise == 3)
        {
            if (fullName != nullptr)
            {
                delete[] fullName;
                fullName = new char[nameSize];
            }
            if (HNumber != nullptr)
            {
                delete[] HNumber;
                HNumber = new char[PNSize];
            }
            if (WNumber != nullptr)
            {
                delete[] WNumber;
                WNumber = new char[PNSize];
            }
            if (MNumber != nullptr)
            {
                delete[] MNumber;
                MNumber = new char[PNSize];
            }
            if (addition != nullptr)
            {
                delete[] addition;
                addition = nullptr;
            }
            cout << "Enter full name:\n";
            gets_s(fullName, 20);
            gets_s(fullName, 20);
            cout << "Enter Home phone number:\n";
            gets_s(HNumber, PNSize);
            cout << "Enter Work phone number:\n";
            gets_s(WNumber, PNSize);
            cout << "Enter mobyle phone number:\n";
            gets_s(MNumber, PNSize);
            cout << "Add caption?\n1 - yes;\n2 - no;\n";
            cin >> choise;
            if (choise == 1)
            {
                cout << "Enter addition(max " << additionSize << " symbols):\n";
                addition = new char[additionSize];
                gets_s(addition, additionSize);
                gets_s(addition, additionSize);
            }
            phoneBookUnit adding(fullName, HNumber, WNumber, MNumber, addition);
            addMember(arr, adding, arrSize);
        }
        else if (choise == 4)
        {
            cout << "Input index of member you want to delete(-1 or above to cancle):\n";
            cin >> indx;
            if (indx > -1 && indx < arrSize)
            {
                delMember(arr, arrSize, indx);
            }
            else
            {
                cout << "ERROR: INVALID INDEX;";
            }
        }
        else if (choise == 5)
        {
            ofstream fileo("PhoneBookSave.txt");
            if (fileo.is_open())
            {
                fileo << arrSize << ' ';
                for (int i = 0; i < arrSize; i++)
                {
                    fileo << arr[i].getFullName() << '_' << arr[i].getHomeNumber() << '_' << arr[i].getWorkNumber() << '_' <<
                        arr[i].getMobNumber() << '_' << arr[i].getAdditional() << '_';
                }
                fileo.close();
            }
            else
            {
                cout << "ERROR: FILE WAS NOT OPENED";
            }
        }
        else if (choise == 6)
        {
            ifstream file("PhoneBookSave.txt");
            if (file.is_open())
            {
                delete[] arr;
                file >> arrSize;
                char* temple = new char[additionSize];
                arr = new phoneBookUnit[arrSize];
                for (int i = 0; i < arrSize; i++)
                {
                    file.getline(temple, additionSize, '_');
                    arr[i].setFullName(temple);
                    file.getline(temple, additionSize, '_');
                    arr[i].setHomeNumber(temple);
                    file.getline(temple, additionSize, '_');
                    arr[i].setWorkNumber(temple);
                    file.getline(temple, additionSize, '_');
                    arr[i].setMobNumber(temple);
                    file.getline(temple, additionSize, '_');
                    arr[i].setAdditional(temple);
                }
                delete[] temple;
                file.close();
            }
            else
            {
                cout << "ERROR: FILE WAS NOT OPENED";
            }
        }
    }

    delete[] addition;
    delete[] HNumber;
    delete[] WNumber;
    delete[] MNumber;
    delete[] fullName;
    delete[] arr;
}
