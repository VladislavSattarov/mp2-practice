#pragma once 
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

//Класс записи;
template <typename TableKey, typename TableData>
class TabRecord
{
protected:
	TableKey Key;            // Ключ;
	TableData* Data;        //  Указатель на данные;
public:

	TabRecord(TableKey key_, TableData data_)
	{
		Key = key_; Data = new TableData(data_);
	}
	TabRecord(TableKey key_)
	{
		Key = key_; Data = nullptr;
	}
	TabRecord(const TabRecord& Tab_)
	{
		Key = Tab_.Key; Data = new TableData(*(Tab_.Data));
	}
	~TabRecord() { delete Data; }

	void SetKey(const TableKey key_) { Key = key_; }
	TableKey GetKey() const { return Key; }

	void SetData(TableData data_) { Data = new TableData(data_); }
	TableData* GetData() const { return Data; }

	TabRecord& operator=(const TabRecord& Tab_)
	{
		Data = new TableData(*(Tab_.Data)); Key = Tab_.Key; return *this;
	}
};


//Класс таблиц;
template <typename TableKey, typename TableData>
class Table
{
protected:
	int DataCount;      // Текущее количество записей;
public:
	Table() { DataCount = 0; }
	virtual ~Table() {};

	// информационные методы; 
	int GetDataCount() const { return DataCount; }                                    // к-во записей;
	int IsEmpty() const { return DataCount == 0; }                                   // пуста?;
	virtual int IsFull() const = 0;                                                 // заполнена?;

	// основные методы;
	virtual TableData* FindRecord(const TableKey key_) = 0;                      // найти запись;
	virtual void InsRecord(const TableKey Key_, const TableData Data_) = 0;     // вставить;
	virtual void DelRecord(const TableKey Key_) = 0;                           // удалить запись;


	// навигация;
	virtual void Reset() = 0;                                               // установить на первую запись;
	virtual int IsTabEnded() const = 0;                                    // таблица завершена?;
	virtual void GoNext() = 0;                                            // переход к следующей записи


	virtual TableKey GetKey() const = 0;
	virtual TableData* GetData() const = 0;


	friend std::ostream& operator<<(std::ostream& os, Table<TableKey, TableData>& tab)
	{
		//cout << "|\t" << "Key" << "\t" << "|" << "\t" << "Data" << "\t|" << endl;
		//cout << "+-------------------------------+\t" << endl;
		for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
		{
			//os << "|\t" << tab.GetKey() << "\t" << "|" << "\t" << *tab.GetData() << "\t|" << endl;
			os << "|\t" << *tab.GetData() << endl;
		}
		return os;
	}

};
