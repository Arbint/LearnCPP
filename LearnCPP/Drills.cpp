#include "stdafx.h"
#include "Drills.h"
#include "UniversalFuc.h"
#include "UniversialInclude.h"



void writeLetter()
{
	std::string letterText = " ";
	std::string userName = io::GetUerInput<std::string>("please tell me your first name:");
	io::printWithEndl("hello " + userName);
	std::string reciverName = io::GetUerInput<std::string>("who do you want to send to?");
	AddNewLineToString(letterText, reciverName);
	AddNewLineToString(letterText, "How are you?");

	std::string friendName = io::GetUerInput<std::string>("please tell me the fried you want to mention: ");
	AddNewLineToString(letterText, "have you seen " + friendName + " lately?");

	char gender = io::GetUerInput<char>("please tell me the gender of your friend:(m for male, f for female)");
	if (gender == 'm')
	{
		letterText += " If you see " + friendName + ", Please tell him to call me.";
	}
	else
	{
		letterText += " If you see " + friendName + ", Please tell her to call me.";
	}

	int reciverAge = io::GetUerInput<int>("please tell me the age of the reciver: ");
	while (reciverAge <= 0 && reciverAge > 110)
	{
		reciverAge = io::GetUerInput<int>("you are kidding right? give me " + reciverName + "'s real age:");
	}

	AddNewLineToString(letterText, "I have heard your just had a birth day and your are " + std::to_string(reciverAge) + " years old.");

	if (reciverAge < 12)
	{
		AddNewLineToString(letterText, "next year you will be " + std::to_string(reciverAge + 1) + " years old!");
	}
	else if (reciverAge == 17)
	{
		AddNewLineToString(letterText, "next year you will be able to vote");
	}
	else if (reciverAge > 70)
	{
		AddNewLineToString(letterText, "I hope you are enjoying retirement!");
	}
	AddNewLineToString(letterText, "yours sincerely:");
	AddNewLinesToString(letterText, 2);
	AddNewLineToString(letterText, userName);
	io::printWithEndl(letterText);
}

double milesToKilometer(double inMiles)
{
	return inMiles * 1.609;
}

void MileToKilometerConverter()
{
	double uerInputMiles = io::GetUerInput<double>("how many miles do you want to convert");
	io::printWithEndl<double>(milesToKilometer(uerInputMiles), "it is ", " kilometers");
}

void compareValues(int intX, int intY)
{
	float x = (float)intX;
	float y = (float)intY;
	if (x > y)
	{
		std::cout << "value one is bigger than value two" << "\n";
	}
	else if(x < y)
	{
		std::cout << "value two is bigger than value one" << '\n';
	}
	else
	{
		std::cout << "values are equal" << std::endl;
	}
	std::cout << "their sum is: " << x + y << std::endl;
	std::cout << "their subtraction is : " << x - y << std::endl;
	std::cout << "their multiplication is: " << x * y << std::endl;
	std::cout << "their division is: " << x / y << std::endl;
	std::cout << "their average is: " << (x + y) / 2 << std::endl;
	std::cout << "value one powered by value two is: " << std::pow(x, y) << std::endl;
	std::cout << "value two powered by value one is: " << std::pow(y, x) << std::endl;

}

void getNumberAndDecideOddOrEven()
{
	int x = io::GetUerInput<int>("please give me an int");
	if (isIntOdd(x))
	{
		std::cout << x << " is an odd number" << std::endl;
	}
	else
	{
		std::cout << x << " in an even number." << std::endl; 
	}
}

void getLiteralNumAndPrintDigit()
{
	std::cout << "please give me a number in literal:" << std::endl;
	
	int TryInt;
	std::cin >> TryInt;
	if (!std::cin.fail())
	{
		std::cout << TryInt << std::endl;
	}
	else {
			std::string uerInput;
			std::cin.clear();
			std::cin >> uerInput;
			if (uerInput == "one")
			{
				std::cout << 1 << std::endl;
			}
			else if (uerInput == "two")
			{
				std::cout << 2 << std::endl;
			}
			else if (uerInput == "three")
			{
				std::cout << 3 << std::endl;
			}
			else if (uerInput == "four")
			{
				std::cout << 4 << std::endl;
			}
			else
			{
				std::cout << "not a number I know" << std::endl;
			}
	}
	
}

void calculateTwoValues()
{
	std::cout << "please type in opeartion and 2 numbers:\n(example: * 10 12)" << std::endl;
	char operation;
	std::cin >> operation;
	double valOne, valTwo;
	std::cin >> valOne >> valTwo;
	if (operation == '+')
	{
		std::cout << calculateValues<double, double>(valOne, valTwo, EMath::add) << std::endl;
	}else if (operation == '-')
	{
		std::cout << calculateValues<double, double>(valOne, valTwo, EMath::subtract) << std::endl;
	}
}

void HowMuchMoneyDoYouHave()
{
	unitInt pennies{ io::GetUerInput<double>("how much pennies do you have?"), "penny" };
	unitInt nickels{ io::GetUerInput<double>("how much nickels do you have?"), "nickel" };
	unitInt dimes{ io::GetUerInput<double>("how much dimes do you have?"), "dime"};
	unitInt quarters {io::GetUerInput<double>("how much quarters do you have?"), "quarter"};
	unitInt halfDollars{ io::GetUerInput<double>("how much half dollars do you have?"), "half dollar"};
	unitInt dollars{ io::GetUerInput<double>("how much dollars do you have?"), "dollar"};
	std::cout << "so you have:\n" << pennies << ".\n" << nickels << ".\n" << dimes << ".\n" << quarters << ".\n" << halfDollars << ".\n" << dollars << ".\n" << std::endl;
	double totalDollars = dollars.getAmount() + halfDollars.getAmount() * 0.5 + quarters.getAmount() * 0.25 + dimes.getAmount() * 0.1 + nickels.getAmount() * 0.05 + pennies.getAmount()/100;
	std::cout << "your total money is: " << totalDollars <<" dollars."<<std::endl;
}

void InchesCmConverter(unitInt& unit)
{

	if (unit.getUnit() == ElengthTypeToString(ELengthType::inch))
	{
		unit.setAmount(unit.getAmount() * 2.54);
		unit.setUnit(ElengthTypeToString(ELengthType::cm));
	}
	else if (unit.getUnit() == ElengthTypeToString(ELengthType::cm))
	{
		unit.setAmount(unit.getAmount() * 0.393701);
		unit.setUnit(ElengthTypeToString(ELengthType::inch));
	}
	else
	{
		io::printWithEndl("Not a type I recognize...");
	}
}

void GetLengthAndConvert()
{
	std::cout << "please tell me what you want to convert: " << std::endl;
	std::cout << "(12 cm, don't use 12 cms)" << std::endl;
	double amount;
	std::string unit;
	std::cin >> amount >> unit;
	unitInt units{amount, unit};
	InchesCmConverter(units);
	std::cout << units << std::endl;
}

void convertMoney(unitInt& money)
{
	if (money.getUnit() == "yuan")
	{
		money.setAmount(money.getAmount() / 6);
		money.setUnit("dollar");
		std::cout << "it means: " << money << std::endl;
		money.setAmount(money.getAmount() / 2);
		money.setUnit("Euro");
		std::cout << "it also means: " << money << std::endl;
	}else if (money.getUnit() == "dollar")
	{	
		money.setAmount(money.getAmount() / 2);
		money.setUnit("Euro");
		std::cout << "it means: " << money << std::endl;
		money.setAmount(money.getAmount() * 6);
		money.setUnit("yuan");
		std::cout << "it also means: " << money << std::endl;
	}else if (money.getUnit() == "euro")
	{
		money.setAmount(money.getAmount() * 2);
		money.setUnit("dollar");
		std::cout << "it means: " << money << std::endl;
		money.setAmount(money.getAmount() * 6);
		money.setUnit("yuan");
		std::cout << "it also means: " << money << std::endl;
	}
	else
	{
		io::printWithEndl(money.getUnit(), "I have no idea what ", " is.");
	}
}

void getMonyAndConvert()
{
	unitInt userInput = io::GetUerInput<unitInt>("please give me some money:\n(example: 12 yuan)");
	convertMoney(userInput);
}

void checkEmail()
{
	EmailProcessor MyEmailprosessor;
	MessageSizeStore MyMessageSizeStore;
	
	//using lambdas to setup delegates between myEmailProsessor and MyMessageSizeStore, so when my email gets 
	//message, MyMessagesSizeStore will be notified and run checkMessage on the new message to update it's member
	//_max_size
	MyEmailprosessor.setHandlerFunc([&](const std::string& gaga) {MyMessageSizeStore.checkMessage(gaga); });
	std::cout << MyMessageSizeStore.getSize() << std::endl;

	std::vector<std::string> messages;
	io::getMultiUserInputs<std::string>("Please give me a bouch of strings", messages);
	for (std::string gaga : messages)
	{
		MyEmailprosessor.receiveMessage(gaga);
	}
	std::cout <<"the longest message has: "<< MyMessageSizeStore.getSize() << " characters" << std::endl;
}

void mimicAddDynamics()
{

	Trigger A{ "A says: happy." };
	Trigger B{ "B says: who summoned me?" };
	Trigger C{ "C says: the sleeper has awake." };
	A.AddDynamic([&]() {B.triggered(); });
	A.AddDynamic([&]() {C.triggered(); });

	A.triggerDynamic();
}

void getWordsAndBeepInApproporateOnes()
{
	std::vector<std::string> userInput;
	io::getMultiUserInputs("please give me a sentence: ", userInput);
	std::vector<std::string> badWords;
	io::getMultiUserInputs("What words should be considered bad? ", badWords);
	for (auto iter = userInput.begin(), end = userInput.end(); iter != end; ++iter)
	{
		replaceWord(*iter, badWords, "beep");
	}
	printVector(userInput);
}

void readTwoIntsAndPrintsThem()
{
	std::vector<int> inInt;
	io::getMultiUserInputs<int>("please give two int",inInt, 2);
	printVector(inInt);
}

void readTwoIntsAndPrintTheBiggrOne()
{
	std::vector<double> userInput;
	io::getMultiUserInputs("please give me 2 inputs", userInput, 2);
	sortVectorFromSmallToBig(userInput);
	if (userInput[0] == userInput[1])
	{
		std::cout << "the two numbers are all: " <<userInput[0]<< std::endl;
	}
	else
	{
		std::cout << "the smallest number is: " << userInput[0] << std::endl;
		std::cout << "the biggest number is: " << userInput[1] << std::endl;
		if (std::abs(userInput[0] - userInput[1]) < 0.01)
		{
			std::cout << "the two value is real close though.." << std::endl;
		}
	}
}

void askAndPrintBiggestAndSmallestValueSofar()
{
	std::vector<int> inputs;
	while (true)
	{
		std::cout << "please give me a int:(type 'exit' to quit) " << std::endl;
		int input;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::string captureString;
			std::cin >> captureString;
			if (captureString == "exit")
			{
				break;
			}
			else
			{
				std::cout << "not an int or a command" << std::endl;
				flushAndResetBuffer();
				continue;
			}
		}
	
		inputs.push_back(input);
		sortVectorFromSmallToBig(inputs);
		std::cout << "the smallest we got so far is: " << *(inputs.begin()) << std::endl;
		std::cout << "the biggest we got so far is: " << *(inputs.end()-1) << std::endl;
	}
}

void ReadLengthInMultiUnits()
{
	std::vector<unitInt> lengthes;

	io::getMultiUserInputs<unitInt>("please give me some lengthes",lengthes);
	sortVectorFromSmallToBig(lengthes);
	printVector(lengthes);
	double totalAmount = 0;
	for (auto iter = lengthes.begin(), end = lengthes.end(); iter != end; ++iter)
	{
		if (iter->getUnit() == "m")
		{
			totalAmount += iter->getAmount();
			continue;
		}
		else if (iter->getUnit() == "cm")
		{
			iter->convertTo("m", 0.01);
			totalAmount += iter->getAmount();
		}
		else if (iter->getUnit() == "inch")
		{
			iter->convertTo("m", 0.0254);
			totalAmount += iter->getAmount();
		}
		else if (iter->getUnit() == "foot")
		{
			totalAmount += iter->getAmount();
			iter->convertTo("m", 0.3048);
		}
	}
	sortVectorFromSmallToBig(lengthes);
	printVector(lengthes);
	std::cout << "it's " << totalAmount << " meters in total.\n";
	std::cout << "the shortest is: " << lengthes[0] << "\n";
	std::cout << "the longest is: " << *(lengthes.end() - 1) << "\n";
}

