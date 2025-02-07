#pragma once
#include "HashTable.h"
#include "math.h"

//enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };
#define TabMaxSize 40
#define TabHashStep 7 //Шаг;



template <typename TableKey, typename TableData>
class  TArrayHash : public THashTable<TableKey, TableData> {
protected:
	TabRecord<TableKey, TableData>** pRecs;        // память для записей таблицы;
	int TabSize;                                  // макс. возм. к-во записей;
	int CurrPos;                                 // строка памяти при завершении поиска;
	int HashStep;                               // шаг вторичного перемешивания;
	TabRecord<TableKey, TableData>* pMark;     // маркер для индикации строк с удаленными записями;
	int FreePos;                              // первая свободная строка, обнаруженная при поиске;

	//Функция открытого перемешивания:
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; };

public:

	TArrayHash(int Size_ = TabMaxSize, int Step_ = TabHashStep);
	TArrayHash(const TArrayHash<TableKey, TableData>& Table_);
	~TArrayHash();


	// информационные методы
	virtual int IsFull() const { return DataCount >= TabSize; }     // заполнена?	
	int GetTabSize() const { return TabSize; }                     // к-во записей;

	// доступ
	virtual TableKey GetKey() const { return GetKey(CURRENT_POS); }             //получить ключ по текущей позиции;
	virtual TableData* GetData() const { return GetData(CURRENT_POS); }        //получить данные по текущей позиции;
	virtual TableKey GetKey(TDataPos mode) const;                             //Получить ключ по любой позиции;
	virtual TableData* GetData(TDataPos mode) const;                         // Получить данные по любой позиции;

	// основные методы
	virtual TableData* FindRecord(const TableKey key_);                           // найти запись;
	virtual void InsRecord(const TableKey key_, const TableData data_);          // вставить;
	virtual void DelRecord(const TableKey key_);                                // удалить запись;

	// навигация 
	virtual void Reset();                                                                       // установить на первую запись;
	virtual int IsTabEnded() const { return CurrPos >= TabSize; };                             // таблица завершена?
	virtual void GoNext();                                                                    // переход к следующей записи;														  


	virtual void SetCurrentPos(int pos);                   // установить текущую запись;
	int GetCurrentPos() const { return CurrPos; }         //получить номер текущей записи;
	virtual void Deleted();
};

template <typename TableKey, typename TableData>
TArrayHash<TableKey, TableData>::TArrayHash(int size_ = TabMaxSize, int step_ = TabHashStep) : THashTable<TableKey, TableData>()
{
	if (size_ <= 0)
		size_ = TabMaxSize;
	pRecs = new TabRecord<TableKey, TableData> * [size_];
	TabSize = size_;
	HashStep = step_;
	for (int i = 0; i < size_; i++)
	{
		pRecs[i] = nullptr;
	}
	CurrPos = DataCount;
	pMark = new TabRecord<TableKey, TableData>(std::string("deleted"));
}

template <typename TableKey, typename TableData>
TArrayHash<TableKey, TableData>::TArrayHash(const TArrayHash<TableKey, TableData>& Table_)
{
	TabSize = Table_.TabSize;
	HashStep = Table_.HashStep;
	DataCount = Table_.DataCount;
	CurrPos = Table_.CurrPos;
	pRecs = new TabRecord<TableKey, TableData> * [Table_.TabSize];
	pMark = new TabRecord<TableKey, TableData>(std::string("deleted"));
	for (int i = 0; i < TabSize; i++)
	{
		if (Table_.pRecs[i] == nullptr || Table_.pRecs[i] == Table_.pMark)
			pRecs[i] = nullptr;
		else {
			pRecs[i] = new TabRecord<TableKey, TableData>(*(Table_.pRecs[i]));
		}
	}
}

template <typename TableKey, typename TableData>
TArrayHash<TableKey, TableData>::~TArrayHash()
{

	for (int i = 0; i < TabSize; i++)
		if ((pRecs[i] != nullptr) && (pRecs[i] != pMark))
			delete pRecs[i];
	delete[] pRecs;
	delete pMark;
}

//---------------------------------------------------------------------------------------------//
template <typename TableKey, typename TableData>
TableKey TArrayHash<TableKey, TableData>::GetKey(TDataPos mode) const
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
TableData* TArrayHash<TableKey, TableData>::GetData(TDataPos mode) const
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
void TArrayHash<TableKey, TableData>::Deleted()
{
	for (this->Reset(); !this->IsTabEnded(); this->GoNext())
	{
		this->DelRecord(this->GetKey());
	}

}
template <typename TableKey, typename TableData>
void TArrayHash<TableKey, TableData>::Reset()
{
	CurrPos = 0;
	if (!IsTabEnded())
	{
		while (CurrPos < TabSize)
		{
			if ((pRecs[CurrPos] != nullptr) && (pRecs[CurrPos] != pMark))
				break;
			CurrPos++;
		}
	}
}

template <typename TableKey, typename TableData>
void TArrayHash<TableKey, TableData>::SetCurrentPos(int pos)
{
	CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
}

template <typename TableKey, typename TableData>
void TArrayHash<TableKey, TableData>::GoNext()
{
	if (IsTabEnded())
		throw "Error";
	while (++CurrPos < TabSize)
		if ((pRecs[CurrPos] != nullptr) && (pRecs[CurrPos] != pMark))
			break;
}

//---------------------------------------------------------------------------------------------//



template <typename TableKey, typename TableData>
void TArrayHash<TableKey, TableData>::InsRecord(const TableKey key_, const TableData data_)
{
		if (IsFull())
		{
			throw "TArrayHash Полна;";
		}

		if ((FindRecord(key_) == nullptr))
		{
			if (FreePos != -1)
				CurrPos = FreePos;
			pRecs[CurrPos] = new TabRecord<TableKey, TableData>(key_, data_);
			DataCount++;
		}
		else throw "Такая запись уже есть;";
}

template <typename TableKey, typename TableData>
TableData* TArrayHash<TableKey, TableData>::FindRecord(const TableKey key_)
{
	Reset();
	FreePos = -1;
	TableData* pValue = nullptr;
	CurrPos = abs(HashFunc(key_) % TabSize);
	for (int i = 0; i < TabSize; i++)
	{
		if (pRecs[CurrPos] == nullptr)  // свободная строка;
			break;
		else if (pRecs[CurrPos] == pMark) // Пустая строка;
		{
			if (FreePos == -1)
				FreePos = CurrPos;
		}
		else if (pRecs[CurrPos]->GetKey() == key_)
		{
			pValue = pRecs[CurrPos]->GetData();
			break;
		}
		CurrPos = abs(GetNextPos(CurrPos));
	}
	return pValue;
}

template <typename TableKey, typename TableData>
void TArrayHash<TableKey, TableData>::DelRecord(const TableKey key_)
{
		if (IsEmpty())
			throw "HashTable пуста;";

		Reset();
		TableData* tmp = FindRecord(key_);
		if (tmp == nullptr)
			throw "HashTable - Запись не найдена;";
		else
		{
			delete pRecs[CurrPos];
			pRecs[CurrPos] = pMark;
			DataCount--;
		}
}

