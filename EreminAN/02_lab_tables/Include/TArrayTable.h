﻿#pragma once
#include "Table.h" 


#define TabMaxSize 40
enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };




template <typename TableKey, typename TableData>
class  TArrayTable : public Table<TableKey, TableData>
{
protected:
	TabRecord<TableKey, TableData>** pRecs;      // память для записей таблицы (массив указателей);
	int TabSize;                                // макс. возм.количество записей в таблице;
	int CurrPos;                               // номер текущей записи (нумерация с 0);
public:


	TArrayTable(int Size = TabMaxSize)
	{
		if (Size <= 0)
			Size = TabMaxSize;
		pRecs = new TabRecord<TableKey, TableData> * [Size];
		for (int i = 0; i < Size; i++)
			pRecs[i] = nullptr;
		TabSize = Size;
		DataCount = CurrPos = 0;    //DataCount - Текущее количество записей;

	}
	~TArrayTable()
	{
		for (int i = 0; i < DataCount; i++)
			delete pRecs[i];
		delete[] pRecs;
	}

	// информационные методы
	virtual int IsFull() const { return DataCount >= TabSize; }    // заполнена?
	int GetTabSize() const { return TabSize; }                    // к-во записей

	// доступ
	virtual TableKey GetKey() const { return GetKey(CURRENT_POS); }             //получить ключ по текущей позиции;
	virtual TableData* GetData() const { return GetData(CURRENT_POS); }        //получить данные по текущей позиции;
	virtual TableKey GetKey(TDataPos mode) const;                             //Получить ключ по любой позиции;
	virtual TableData* GetData(TDataPos mode) const;                         // Получить данные по любой позиции;

	// основные методы
	virtual TableData* FindRecord(const TableKey key_) = 0;                           // найти запись;
	virtual void InsRecord(const TableKey key_, const TableData data_) = 0;          // вставить;
	virtual void DelRecord(const TableKey key_) = 0;                                // удалить запись;

	//навигация
	virtual void Reset() { CurrPos = 0; }                        // установить на первую запись
	virtual int IsTabEnded() const;                             // таблица завершена?
	virtual void GoNext();                                     // переход к следующей записи														  

	virtual void SetCurrentPos(int pos);                   // установить текущую запись
	int GetCurrentPos() const { return CurrPos; }         //получить номер текущей записи

	 TabRecord<TableKey, TableData>*  GetRecs( int index) const { return pRecs[index]; }
	 virtual void Deleted();
};


template <typename TableKey, typename TableData>
TableKey TArrayTable<TableKey, TableData>::GetKey(TDataPos mode) const
{
	int pos = -1;
	if (IsEmpty())
	{
		throw "Error";
	}
	switch (mode)
	{
	case FIRST_POS: pos = 0; break;
	case LAST_POS: pos = DataCount - 1; break;
	default: pos = CurrPos; break;
	}
	return  pRecs[pos]->GetKey();
}


template <typename TableKey, typename TableData>
TableData* TArrayTable<TableKey, TableData>::GetData(TDataPos mode) const
{
	int pos = -1;
	if (IsEmpty())
	{
		throw"Error";
	}
	switch (mode)
	{
	case FIRST_POS: pos = 0; break;
	case LAST_POS: pos = DataCount - 1; break;
	default: pos = CurrPos; break;
	}

	return pRecs[pos]->GetData();
}

template <typename TableKey, typename TableData>
int TArrayTable<TableKey, TableData>::IsTabEnded() const
{
	return CurrPos >= DataCount;
}

template <typename TableKey, typename TableData>
void TArrayTable<TableKey, TableData>::GoNext()
{
	if (IsTabEnded())
		throw "Error";
	CurrPos++;
}

template <typename TableKey, typename TableData>
void TArrayTable<TableKey, TableData>::Deleted()
{
	for (Reset(); !IsTabEnded(); CurrPos)
	{
		DelRecord(GetKey());
	}

}

template <typename TableKey, typename TableData>
void TArrayTable<TableKey, TableData>::SetCurrentPos(int pos)
{
	CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
}
