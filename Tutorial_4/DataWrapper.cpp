#include <iostream>
#include <fstream>
#include <string>
#include "DataWrapper.h"

DataWrapper::DataWrapper() :
    fSize(0),
    fData(nullptr)
{} 

DataWrapper::~DataWrapper()
{
    delete[] fData;
}

bool DataWrapper::load(const std::string &aFileName)
{
    std::string inputData, firstNumber, secondNumber;
    
    try
    {
        std::ifstream DataFile(aFileName);
        getline(DataFile, inputData);
        fSize = stoi(inputData);

        fData = new DataMap[fSize];

        for(int i = 0; i < fSize; i++){

            getline(DataFile, inputData, ' ');
            firstNumber = inputData;
            getline(DataFile, inputData);
            secondNumber = inputData;

            DataMap map {stoi(firstNumber), stoi(secondNumber)};

            fData[i] = map;
        }
        DataFile.close();
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

size_t DataWrapper::size() const noexcept
{
    return fSize;
}

const DataMap &DataWrapper::operator[](size_t aIndex) const
{
    assert( aIndex < fSize );
    return fData[aIndex];
}