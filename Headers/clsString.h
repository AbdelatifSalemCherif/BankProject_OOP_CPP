#pragma once

#include<iostream>
#include<vector>
#include<cctype>
#include<string>
#include<cmath>


using namespace std;


class clsString
{
private:

	string _Value;



public:

	enum enLeftRightMiddle { Left = 0, Right = 1, Middle = 2 };

	clsString()
	{
		_Value = "";
	};

	clsString(string Value)
	{
		_Value = Value;
	};

	void SetValue(string Value)
	{
		_Value = Value;
	};

	string GetValue()
	{
		return _Value;
	};

	__declspec(property(get = GetValue, put = SetValue)) string Value;




	static char InvertCharacter(char Char)
	{
		return (isupper(Char)) ? tolower(Char) : toupper(Char);
	}

	static bool CheckVowelLetter(char Letter)
	{
		Letter = tolower(Letter);

		return Letter == 'a' || Letter == 'o' || Letter == 'e' || Letter == 'i' || Letter == 'u';
	}






	static short CountAllUpperCase(string Phrase)
	{
		short UpperCase = 0;

		for (short i = 0; i < Phrase.length(); i++)
		{
			if (isupper(Phrase[i]))
			{
				UpperCase++;
			}
		}

		return UpperCase;
	};

	short CountAllUpperCase()
	{
		return CountAllUpperCase(_Value);
	};

	static short CountAllLowerCase(string Phrase)
	{
		short LowerCase = 0;

		for (short i = 0; i < Phrase.length(); i++)
		{
			if (islower(Phrase[i]))
			{
				LowerCase++;
			}
		}

		return LowerCase;
	};

	short CountAllLowerCase()
	{
		return CountAllLowerCase(_Value);
	};

	static short CountAllVowels(string Phrase)
	{
		short Counter = 0;

		for (short i = 0; i < Phrase.length(); i++)
		{
			if (CheckVowelLetter(Phrase[i]))
			{
				Counter++;
			}
		}

		return Counter;
	};

	short CountAllVowels()
	{
		return CountAllVowels(_Value);
	};

	static short CountAllLetters(string Phrase, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < Phrase.length(); i++)
		{
			if (MatchCase)
			{
				if (Phrase[i] == Letter)
				{
					Counter++;
				}
			}
			else
			{
				if (toupper(Phrase[i]) == toupper(Letter))
				{
					Counter++;
				}
			}
		}

		return Counter;
	};

	short CountAllLetters(char Letter, bool MatchCase = true)
	{
		return CountAllLetters(_Value, Letter, MatchCase);
	};

	static short CountAllWords(string Phrase, string Separator)
	{
		short Counter = 0, SeparatorPosition = Phrase.find(Separator);

		string Word = Phrase.substr(0, SeparatorPosition);

		while (SeparatorPosition != Phrase.npos)
		{

			if (Word != Separator && Word != "")
			{
				Counter++;
			}

			Phrase.erase(0, SeparatorPosition + Separator.length());

			SeparatorPosition = Phrase.find(Separator);

			Word = Phrase.substr(0, SeparatorPosition);
		}



		return (Word != Separator && Word != "") ? Counter + 1 : Counter;
	};

	short CountAllWords(string Separator = " ")
	{
		return CountAllWords(_Value, Separator);
	};






	static void Split(string Phrase, vector <string>& vPhrase, string Separitor)
	{
		vPhrase.clear();

		short SeparitorPosition = Phrase.find(Separitor);
		string Word = Phrase.substr(0, SeparitorPosition);

		while (SeparitorPosition != Phrase.npos)
		{
			if (Word != Separitor && Word != "")
			{
				vPhrase.push_back(Word);
			}

			Phrase.erase(0, SeparitorPosition + Separitor.length());

			SeparitorPosition = Phrase.find(Separitor);
			Word = Phrase.substr(0, SeparitorPosition);
		}

		if (Word != Separitor && Word != "")
		{
			vPhrase.push_back(Word);
		}


	};

	void Split(vector <string>& vPhrase, string Separitor = " ")
	{
		Split(_Value, vPhrase, Separitor);
	};

	static vector<string> Split(string Phrase, string Separitor)
	{
		vector <string> vPhrase;

		short SeparitorPosition = Phrase.find(Separitor);
		string Word = Phrase.substr(0, SeparitorPosition);

		while (SeparitorPosition != Phrase.npos)
		{
			if (Word != Separitor && Word != "")
			{
				vPhrase.push_back(Word);
			}

			Phrase.erase(0, SeparitorPosition + Separitor.length());

			SeparitorPosition = Phrase.find(Separitor);
			Word = Phrase.substr(0, SeparitorPosition);
		}

		if (Word != Separitor && Word != "")
		{
			vPhrase.push_back(Word);
		}

		return vPhrase;
	};

	vector<string> Split(string Separitor = " ")
	{
		return Split(_Value, Separitor);
	};

	static string Join(vector <string>& vPhrase, string Separator = " ")
	{
		string Phrase = "";

		for (string& i : vPhrase)
		{
			Phrase.append(i + Separator);
		}

		//Phrase.erase(Phrase.length() - Separator.length(), Separator.length());

		return Phrase.substr(0, Phrase.length() - Separator.length());
	};

	static string ToLowerAllPhrase(string Phrase)
	{

		for (short i = 0; i < Phrase.length(); i++)
		{
			Phrase[i] = tolower(Phrase[i]);
		}

		return Phrase;
	};

	void ToLowerAllPhrase()
	{
		_Value = ToLowerAllPhrase(_Value);
	};

	static string ToUpperAllPhrase(string Phrase)
	{

		for (short i = 0; i < Phrase.length(); i++)
		{
			Phrase[i] = toupper(Phrase[i]);
		}

		return Phrase;
	};

	void ToUpperAllPhrase()
	{
		_Value = ToUpperAllPhrase(_Value);
	};

	static string ToUpperAllFirstLetters(string Phrase)
	{
		Phrase[0] = toupper(Phrase[0]);

		for (short i = 1; i < Phrase.length(); i++)
		{
			if (Phrase[i] == ' ')
			{
				Phrase[i + 1] = toupper(Phrase[i + 1]);
				i++;
			}
		}

		return Phrase;
	};

	void ToUpperAllFirstLetters()
	{
		_Value = ToUpperAllFirstLetters(_Value);
	};

	static string ToLowerAllFirstLetters(string Phrase)
	{
		Phrase[0] = tolower(Phrase[0]);

		for (short i = 1; i < Phrase.length(); i++)
		{
			if (Phrase[i] == ' ')
			{
				Phrase[i + 1] = tolower(Phrase[i + 1]);
				i++;
			}
		}

		return Phrase;
	};

	void ToLowerAllFirstLetters()
	{
		_Value = ToLowerAllFirstLetters(_Value);
	};

	static string ReverseString(string Phrase)
	{
		string Copy = Phrase;
		short Length = Phrase.length();

		for (short i = 0; i < Length; i++)
		{
			Phrase[i] = Copy[Length - 1 - i];
		}

		return Phrase;
	};

	void ReverseString()
	{
		_Value = ReverseString(_Value);
	};

	static string TrimLeft(string Phrase, string Delim)
	{
		short DelimPosition = Phrase.find(Delim);


		while (DelimPosition == 0)
		{
			Phrase.erase(0, Delim.length());

			DelimPosition = Phrase.find(Delim);
		}

		return Phrase;
	};

	void TrimLeft(string Delim = " ")
	{
		_Value = TrimLeft(_Value, Delim);
	};

	static string TrimRight(string Phrase, string Delim)
	{

		Phrase = TrimLeft(ReverseString(Phrase), ReverseString(Delim));

		return ReverseString(Phrase);
	};

	void TrimRight(string Delim = " ")
	{
		_Value = TrimRight(_Value, Delim);
	};

	static string Trim(string Phrase, string Delim)
	{
		return TrimLeft(TrimRight(Phrase, Delim), Delim);
	};

	void Trim(string Delim = " ")
	{
		_Value = Trim(_Value, Delim);
	};

	static string ReverseWordsOrder(string Phrase, string Separator)
	{
		vector <string> vPhrase;

		vPhrase = Split(Phrase, Separator);

		vector <string>::iterator WordPointer = vPhrase.end();

		Phrase.clear();

		while (WordPointer != vPhrase.begin())
		{
			WordPointer--;

			Phrase.append(*WordPointer + Separator);
		}


		return Phrase.substr(0, Phrase.length() - Separator.length());
	};

	void ReverseWordsOrder(string Separator = " ")
	{
		_Value = ReverseWordsOrder(_Value, Separator);
	};

	static string Erase(string Phrase, short From, short WordLength)
	{
		string Word = "";

		if (Phrase == "")
		{
			return Word;
		}

		short To = (From + WordLength >= Phrase.length()) ? Phrase.length() : From + WordLength;


		for (short i = 0; i < From; i++)
		{
			Word += Phrase[i];
		}

		for (short i = To; i < Phrase.length(); i++)
		{
			Word += Phrase[i];
		}


		return Word;
	};

	void Erase(short From, short WordLength)
	{
		_Value = Erase(_Value, From, WordLength);
	};

	static string Substr(string Phrase, short From, short WordLength)
	{
		string Word = "";

		if (Phrase == "")
			return Word;

		short To = (From + WordLength >= Phrase.length()) ? Phrase.length() : From + WordLength;


		for (short i = From; i < To; i++)
		{
			Word += Phrase[i];
		}

		return Word;

	};

	void Substr(short From, short WordLength)
	{
		_Value = Substr(_Value, From, WordLength);
	};

	static string ReplaceWord(string Phrase, string NewWord, short LastWordPosition, short LastWordLength)
	{
		short& From = LastWordPosition;
		short To = From + LastWordLength;

		//return Substr(Phrase, 0, From) + NewWord + Substr(Phrase, To, Phrase.length() - To);

		return Phrase.substr(0, From) + NewWord + Phrase.substr(To, Phrase.length() - To);
	};

	void ReplaceWord(string NewWord, short LastWordPosition, short LastWordLength)
	{
		_Value = ReplaceWord(_Value, NewWord, LastWordPosition, LastWordLength);
	};

	static short Find(string Phrase, string Word, bool MuchCase = true)
	{

		if (MuchCase)
		{
			for (short i = 0; i < Phrase.length() - Word.length() + 1; i++)
			{

				if (Word == Substr(Phrase, i, Word.length()))
				{
					return i;
				}

			}
		}

		else
		{

			string PhraseUpperCase = ToUpperAllPhrase(Phrase), WordUpperCase = ToUpperAllPhrase(Word);

			for (short i = 0; i < Phrase.length() - Word.length() + 1; i++)
			{

				if (WordUpperCase == Substr(PhraseUpperCase, i, Word.length()))
				{
					return i;
				}

			}
		}

		return -1;
	};

	short Find(string Word, bool MuchCase = true)
	{
		return Find(_Value, Word, MuchCase);
	};

	static bool Find(string Phrase, string Word, short& Position, bool MuchCase = true)
	{

		if (MuchCase)
		{
			for (short i = 0; i < Phrase.length() - Word.length() + 1; i++)
			{

				if (Word == Substr(Phrase, i, Word.length()))
				{
					Position = i;
					return true;
				}

			}
		}

		else
		{

			string PhraseUpperCase = ToUpperAllPhrase(Phrase), WordUpperCase = ToUpperAllPhrase(Word);

			for (short i = 0; i < Phrase.length() - Word.length() + 1; i++)
			{

				if (WordUpperCase == Substr(PhraseUpperCase, i, Word.length()))
				{
					Position = i;
					return true;
				}

			}
		}

		Position = -1;
		return false;
	};

	bool Find(string Word, short& Position, bool MuchCase = true)
	{
		return Find(_Value, Word, Position, MuchCase);
	};

	static string ReplaceAllWords_UsingOwnFind(string Phrase, string LastWord, string NewWord, bool MuchCase = true)
	{

		short LastWordPosition = Find(Phrase, LastWord, MuchCase), LastWordLength = LastWord.length();

		while (LastWordPosition != Phrase.npos)
		{
			//Phrase = Phrase.replace(LastWordPosition, LastWordLength, NewWord);

			Phrase = ReplaceWord(Phrase, NewWord, LastWordPosition, LastWordLength);

			LastWordPosition = Find(Phrase, LastWord, MuchCase);
		}


		return Phrase;
	};

	void ReplaceAllWords_UsingOwnFind(string LastWord, string NewWord, bool MuchCase = true)
	{
		_Value = ReplaceAllWords_UsingOwnFind(_Value, LastWord, NewWord, MuchCase);
	};

	static string ReplaceAllWords_UsingSplitVector(string Phrase, string LastWord, string NewWord, bool MuchCase = true, string Separator = " ")
	{
		vector <string> vPhrase = Split(Phrase, Separator);

		if (MuchCase)
		{
			for (string& i : vPhrase)
			{
				if (i == LastWord)
				{
					i = NewWord;
				}
			}
		}
		else
		{
			LastWord = ToUpperAllPhrase(LastWord);

			for (string& i : vPhrase)
			{
				if (ToUpperAllPhrase(i) == LastWord)
				{
					i = NewWord;
				}
			}
		}



		return Join(vPhrase, Separator);
	};

	void ReplaceAllWords_UsingSplitVector(string LastWord, string NewWord, bool MuchCase = true, string Separator = " ")
	{
		_Value = ReplaceAllWords_UsingSplitVector(_Value, LastWord, NewWord, MuchCase, Separator);
	};

	static string DeleteAllPunctuations(string Phrase)
	{
		string PhraseWithoutPuctuations = "";

		for (short i = 0; i < Phrase.length(); i++)
		{
			if (!ispunct(Phrase[i]))
			{
				PhraseWithoutPuctuations += Phrase[i];
			}
		}

		return PhraseWithoutPuctuations;
	};

	void DeleteAllPunctuations()
	{
		_Value = DeleteAllPunctuations(_Value);
	};

	static void ReapetWord(string& Phrase, string Word, short NumberOfRepetition)
	{
		Phrase = "";

		for (short i = 1; i <= NumberOfRepetition; i++)
		{
			Phrase += Word;
		}
	};

	void ReapetWord(string Word, short NumberOfRepetition)
	{
		ReapetWord(_Value, Word, NumberOfRepetition);
	}

	static void FillWordSideWithSameCaracter(string& Phrase, string Word, char Caracter, short TotalLength,
		enLeftRightMiddle LiftRightMiddle = Left)
	{
		Phrase = Word;

		if (LiftRightMiddle == Left)
		{
			for (short i = TotalLength - Word.length(); i > 0; i--)
			{
				Phrase += Caracter;
			}
		}
		else if (LiftRightMiddle == Right)
		{
			for (short i = TotalLength - Word.length(); i > 0; i--)
			{
				Phrase = Caracter + Phrase;
			}
		}
		else if (LiftRightMiddle == Middle)
		{
			for (short i = (TotalLength - Word.length()) / 2; i > 0; i--)
			{
				Phrase = Caracter + Phrase + Caracter;
			}
		}
	};

	void FillWordSideWithSameCaracter(string Word, char Caracter, short TotalLength, enLeftRightMiddle LiftRightMiddle = Left)
	{
		FillWordSideWithSameCaracter(_Value, Word, Caracter, TotalLength, LiftRightMiddle);
	}

	static void ManipilatorSpaces(string& Word, short TotalLength)
	{
		short SpacesLength = abs(TotalLength - (short)Word.length());



		for (short i = 0; i < SpacesLength; i++)
		{
			Word += " ";
		}
	}

	void ManipilatorSpaces(short TotalLength)
	{
		ManipilatorSpaces(_Value, TotalLength);
	}








	static void PrintAllVowels(string Phrase)
	{
		short Counter = 0;

		for (short i = 0; i < Phrase.length(); i++)
		{
			if (CheckVowelLetter(Phrase[i]))
			{
				cout << Phrase[i] << "   ";
			}
		}
	};

	void PrintAllVowels()
	{
		PrintAllVowels(_Value);
	};

	static void PrintAllWords(string Phrase, string Separator)
	{
		short SeparatorPosition = Phrase.find(Separator);

		string Word = Phrase.substr(0, SeparatorPosition);

		while (SeparatorPosition != Phrase.npos)
		{

			if (Word != Separator && Word != "")
			{
				cout << Word << endl;
			}

			Phrase.erase(0, SeparatorPosition + Separator.length());


			SeparatorPosition = Phrase.find(Separator);

			Word = Phrase.substr(0, SeparatorPosition);
		}

		if (Word != Separator && Word != "")
		{
			cout << Word << endl;
		}

	};

	void PrintAllWords(string Separator = " ")
	{
		return PrintAllWords(_Value, Separator);
	};

	static bool IsANumber(string Number)
	{
		for (short i = Number.length() - 1; i >= 0; i--)
		{
			if ((short)Number[i] < 48 || (short)Number[i] > 57)
			{
				return false;
			}
		}

		return true;
	};

	bool IsANumber()
	{
		return IsANumber(_Value);
	};





	static void MakeCard(string& Card, string Title, short NumberOfRepeterion, string LineForme = "-",
		enLeftRightMiddle TitleStayIn = enLeftRightMiddle::Left)
	{

		string Phrase = "";

		short TotalLength = NumberOfRepeterion * LineForme.length();

		ReapetWord(Phrase, LineForme, NumberOfRepeterion);
		Card = Phrase + '\n';

		FillWordSideWithSameCaracter(Phrase, Title, ' ', TotalLength, TitleStayIn);
		Card += Phrase + '\n';

		ReapetWord(Phrase, LineForme, NumberOfRepeterion);
		Card += Phrase + '\n';
	}

	void MakeCard(string Title, short NumberOfRepeterion, string LineForme = "-", enLeftRightMiddle TitleStayIn = enLeftRightMiddle::Left)
	{
		MakeCard(_Value, Title, NumberOfRepeterion, LineForme, TitleStayIn);
	}

	static void MakeMenue(string& Menue, string Title, string ItemsNames_ORDRED[], short NumberOfItems, short NumberOfRepeterion,
		string LineForme = "=", enLeftRightMiddle TitleStayIn = enLeftRightMiddle::Left)
	{

		string Phrase = "";

		MakeCard(Phrase, Title, NumberOfRepeterion, LineForme, TitleStayIn);

		Menue = Phrase;
		Phrase = "";

		for (short i = 0; i < NumberOfItems; i++)
		{
			Phrase += "[" + to_string(i + 1) + "]" + ItemsNames_ORDRED[i] + "." + '\n';
		}

		Menue += Phrase;
		Phrase = "";

		ReapetWord(Phrase, LineForme, NumberOfRepeterion);

		Menue += Phrase + '\n';
	}

	void MakeMenue(string Title, string ItemsNames_ORDRED[], short NumberOfItems, short NumberOfRepeterion,
		string LineForme = "=", enLeftRightMiddle TitleStayIn = enLeftRightMiddle::Left)
	{
		MakeMenue(_Value, Title, ItemsNames_ORDRED, NumberOfItems, NumberOfRepeterion, LineForme, TitleStayIn);
	}




	static void  EncryptText(string& Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}
	}

	void  EncryptText(short EncryptionKey)
	{
		EncryptText(_Value, EncryptionKey);
	}

	static void  DecryptText(string& Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
	}

	void  DecryptText(short EncryptionKey)
	{
		DecryptText(_Value, EncryptionKey);
	}

	static void  Tabs(string& Word, short NumberOfTabs)
	{
		Word = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			Word = Word + "\t";
			cout << Word;
		}
	}

	void  Tabs(short NumberOfTabs)
	{
		Tabs(_Value, NumberOfTabs);
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	void Swap(string& Text2)
	{
		Swap(_Value, Text2);
	}

	static  void Swap(clsString& A, clsString& B)
	{
		Swap(A._Value, B._Value);
	}

	void Swap(clsString& Text2)
	{
		Swap(*this, Text2);
	}






};
