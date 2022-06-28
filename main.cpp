#include <iostream>
#include <string>
#include <fstream>

void stringMixer(std::string str, int key)
{
    int arsize = str.size();
    char arr[arsize];

    for(int i = 0; i < arsize; i ++)
        arr[i] = str[i];

    if(key > 0)
    {
        for(int i = 0; i < key; i++)
        {

            int temp = arr[arsize-1];

            for(int i = arsize-1; i > 0; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[0] = temp;
        }
    }
}

void stringUnmixer(std::string str, int key)
{
    int arsize = str.size();
    char arr[arsize];

    for(int i = 0; i < arsize; i ++)
        arr[i] = str[i];

    if(key > 0)
    {
        for(int i = 0; i < key; i++)
        {

            int temp = arr[0];

            for(int i = 0; i < arsize-1; i++)
            {
                arr[i] = arr[i+1];
            }
            arr[arsize-1] = temp;
        }
    }
}


void encrypt(std::string filename, std::string newfile, int key)
{
    srand(key);
    std::string buf1{0};
    char cr;


    std::ofstream fout(newfile);
    std::ifstream fin1(filename);
    if (fin1.is_open())
    {
        while(!fin1.eof())
        {
            getline(fin1, buf1);

            int strSize = buf1.size();

            for(int i = 0; i < strSize; i++)
            {
                int j = rand() % 32;
                cr = buf1[i];
                for(int k = 0; k < j; k++)
                {
                    cr++;
                }
                buf1[i] = cr;

            }
            stringMixer(buf1, key);


            fout << buf1 << std::endl;
        }

    }
    fin1.close();
    fout.close();

}

void decrypt(std::string filename, std::string newfile, int key)
{
    srand(key);
    std::string buf1;
    char cr;



    std::ofstream fout(newfile);
    std::ifstream fin1(filename);
    if (fin1.is_open())
    {
        while(!fin1.eof())
        {
            getline(fin1, buf1);

            int strSize = buf1.size();

            for(int i = 0; i < strSize; i++)
            {
                int j = rand() % 32;
                cr = buf1[i];
                for(int k = 0; k < j; k++)
                {
                    cr--;
                }
                buf1[i] = cr;
            }
            stringUnmixer(buf1, key);

            fout << buf1 << std::endl;
        }

    }
    fin1.close();
    fout.close();

}







int main()
{
    std::string file;
    std::string newfile;
    int key;
    int var;

    label1:

    std::cout << "Welcome to crypt1." << std::endl << "Encrypt(1) or decrypt(2)?" << std::endl;
    std::cin >> var;

    if(var == 1)
    {
        std::cout << "Enter the filename:" << std::endl;
        std::cin >> file;
        std::cout << "Enter the new filename:" << std::endl;
        std::cin >> newfile;
        std::cout << "Enter the key:" << std::endl;
        std::cin >> key;

        encrypt(file, newfile, key);
    }

    else if(var == 2)
    {
        std::cout << "Enter the filename:" << std::endl;
        std::cin >> file;
        std::cout << "Enter the new filename:" << std::endl;
        std::cin >> newfile;
        std::cout << "Enter the key:" << std::endl;
        std::cin >> key;

        decrypt(file, newfile, key);
    }

    else
        goto label1;




    return 0;
}
