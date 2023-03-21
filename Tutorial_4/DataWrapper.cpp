
#include "DataWrapper.h"


DataWrapper::DataWrapper() :
    fSize(0),
    fData(nullptr)
{} 

DataWrapper::~DataWrapper()
{
    delete[] this;
}