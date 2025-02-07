#pragma once
#include "Table.h" 
#include "TArrayTable.h"

//Просматриваемые таблицы:
//Записи хранятся в порядке их добавления. Храним в виде массива;


template <typename TableKey, typename TableData>
class  ScanTable : public TArrayTable<TableKey, TableData>
{
public:
	ScanTable(int Size = TabMaxSize) : TArrayTable<TableKey, TableData>(Size) {};        //конструктор;
	ScanTable(const ScanTable<TableKey, TableData>& Table_);
	
	
	// основные методы 
	virtual TableData* FindRecord(const TableKey key_);                             //найти запись;                       
	virtual void InsRecord(const TableKey key_, const TableData data_);            //вставить;                         
	virtual void DelRecord(const TableKey key_);                                  //удалить запись;                    
};


template <typename TableKey, typename TableData>
ScanTable<TableKey, TableData>::ScanTable(const ScanTable<TableKey, TableData>& Table_)
{
	TabSize = Table_.TabSize;
	DataCount = Table_.DataCount;
	CurrPos = Table_.CurrPos;
	pRecs = new TabRecord<TableKey, TableData> * [TabSize];
	for (int i = 0; i < DataCount; i++)
	{
		pRecs[i] = new TabRecord<TableKey, TableData>(*(Table_.pRecs[i]));
	}
}

template <typename TableKey, typename TableData>
TableData* ScanTable<TableKey, TableData>::FindRecord(const TableKey key_)
{
		if (IsEmpty())
		{
			throw "ScanTable Пуста;";
		}

		Reset();
		for (CurrPos; CurrPos < DataCount; CurrPos++)
			if (pRecs[CurrPos]->GetKey() == key_)
				break;
		if (CurrPos < DataCount)
		{
			return pRecs[CurrPos]->GetData();
		}
		return nullptr;
}

template <typename TableKey, typename TableData>
void ScanTable<TableKey, TableData>::InsRecord(const TableKey key_, const TableData data_)
{
		if (IsFull())  //Переполнение;
		{
			throw "ScanTable Полна;";
		}

		Reset();
		if ((IsEmpty()) || (FindRecord(key_) == nullptr))
		{
			pRecs[DataCount] = new TabRecord<TableKey, TableData>(key_, data_);
			DataCount++;
		}
		else throw "Такая запись уже есть;";
}

template <typename TableKey, typename TableData>
void ScanTable<TableKey, TableData>::DelRecord(const TableKey key_)
{
		if (FindRecord(key_) == nullptr) // не нашел;
			throw "ScanTable - запись не найдена;";
		else
		{
			pRecs[CurrPos] = pRecs[DataCount - 1];
			pRecs[DataCount - 1] = nullptr;
			DataCount--;
		}
}
