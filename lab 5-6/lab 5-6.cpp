#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 
#include <iostream>
#include <cstring>
using namespace std;

class Language
{
private:
	char* name;
	long int wordAmount;
	int difficulty;
	long int speakerAmount;
public:
	//Конструктор без параметров
	Language()
	{
		name = nullptr;
		wordAmount = 0;
		difficulty = 1;
		speakerAmount = 0;
	}
	//Конструктор с параметром
	Language(const char* nameValue, long int wordAmountValue, int difficultyValue, long int speakerAmountValue)
	{
		if (difficultyValue >= 1 && difficultyValue <= 5)
		{
			name = new char[strlen(nameValue) + 1];
			strcpy(name, nameValue);
			wordAmount = wordAmountValue;
			difficulty = difficultyValue;
			speakerAmount = speakerAmountValue;
		}
		else
		{
			cout << "Incorrect value!" << endl;
		}
	}
	//Конструктор копирования
	Language(const Language& other)
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		wordAmount = other.wordAmount;
		difficulty = other.difficulty;
		speakerAmount = other.speakerAmount;
	}
	//Деструктор
	~Language()
	{
		delete[] name;
	}
	//Получение значений каждого поля
	char* getName() const
	{
		return name;
	}
	long int getWordAmount() const
	{
		return wordAmount;
	}
	int getDifficulty() const
	{
		return difficulty;
	}
	long int getSpeakerAmount() const
	{
		return speakerAmount;
	}
	//Редактирование каждого поля
	void setName(const char* newName)
	{
		delete[] name;
		name = new char[strlen(newName) + 1];
		strcpy(name, newName);
	}
	void setWordAmount(long int wordAmountValue)
	{
		wordAmount = wordAmountValue;
	}
	void setDifficulty(int difficultyValue)
	{
		if (difficultyValue >= 1 && difficultyValue <= 5)
		{
			difficulty = difficultyValue;
		}
		else
		{
			cout << "Incorrect value!" << endl;
		}
	}
	void setSpeakerAmount(long int speakerAmountValue)
	{
		speakerAmount = speakerAmountValue;
	}
	//вывод на экран каждого поля
	void printName()
	{
		cout << "Language: " << name << endl;
	}
	void printWordAmount()
	{
		cout << "Words Amount: " << wordAmount << endl;
	}
	void printDifficulty()
	{
		cout << "Difficulty: " << difficulty << endl;
	}
	void printSpeakerAmount()
	{
		cout << "Speakers Amount: " << speakerAmount << endl;
	}
	void printAll()
	{
		cout << "Language: " << name << endl;
		cout << "Words Amount: " << wordAmount << endl;
		cout << "Difficulty: " << difficulty << endl;
		cout << "Speakers Amount: " << speakerAmount << endl;
	}
	//Список мертвых языков, отсортированный по количеству слов
	static void DeadLanguages(Language** languages, int count)
	{
		for (int i = 0; i < count; i++) 
		{
			for (int j = i+1; j < count; j++)
			{
				if (languages[i]->speakerAmount == 0 && languages[j]->speakerAmount == 0 && languages[i]->wordAmount < languages[j] -> wordAmount)
				{
					swap(languages[i], languages[j]);
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			if (languages[i]->speakerAmount == 0)
			{
				cout << "Language: " << languages[i]->name << endl;
				cout << "Words Amount: " << languages[i]->wordAmount << endl;
				cout << "Difficulty: " << languages[i]->difficulty << endl;
				cout << "Speakers Amount: " << languages[i]->speakerAmount << endl;
				cout << endl;
			}
		}
	}
	//Среднее количество носителей среди всех языков
	static void AverageSpeakers(Language** languages, int count)
	{
		long int sum = 0;
		for (int i = 0; i < count; i++)
		{
			sum += languages[i]->speakerAmount;
		}
		long double average = sum / count;
		cout << "Average number of native speakers: " << average << endl;
	}
	//Среднее количество слов среди языков сложности N
	static void AverageWords(Language** languages, int count, int N)
	{
		long int sum = 0;
		int n = 0;
		for (int i = 0; i < count; i++)
		{
			if (languages[i]->difficulty == N)
			{
				sum += languages[i]->wordAmount;
				n++;
			}
		}
		if (n > 0)
		{
			long double average = sum / n;
			cout << "Average number of languages of a given complexity: " << average << endl;
		}
		else 
		{
			cout << "Average number of languages of a given complexity is 0"  << endl;
		}
		
	}
};
	int main()
	{
		Language first;
		//редактирование полей
		first.setName("English");
		first.setWordAmount(100000);
		first.setDifficulty(4);
		first.setSpeakerAmount(1000);
		//вывод на экран
		cout << "Information about first language: " << endl;
		first.printName();
		first.printWordAmount();
		first.printDifficulty();
		first.printSpeakerAmount();
		cout << endl;

		Language second("German", 23000, 3, 0);
		cout << "Information about second language: " << endl;
		second.printAll();//вывод на экран полной информации о языке
		cout << endl;

		Language third(first);
		cout << "Information about third language: " << endl;
		third.setWordAmount(485845);
		third.setSpeakerAmount(0);
		third.printAll();
		cout << endl;

		
		Language* languages[3] = { &first,  &second,  &third };
		cout << "List of dead languages sorted by word count: " << endl;
		Language::DeadLanguages(languages, 3);
		Language::AverageSpeakers(languages, 3);
		Language::AverageWords(languages, 3, 3);

	}

