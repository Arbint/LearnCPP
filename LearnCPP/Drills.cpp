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
			iter->convertTo("m", 0.3048);
			totalAmount += iter->getAmount();
		}
	}
	sortVectorFromSmallToBig(lengthes);
	printVector(lengthes);
	std::cout << "there are " << lengthes.size() << " values" << std::endl;
	std::cout << "it's " << totalAmount << " meters in total.\n";
	std::cout << "the shortest is: " << lengthes[0] << "\n";
	std::cout << "the longest is: " << *(lengthes.end() - 1) << "\n";
}

void ReadMultipleNumbersAndExportMedian()
{
	std::vector<double> numbers;
	io::getMultiUserInputs("please give me a few decimal numbers", numbers);
	printVector(numbers);
	sort(numbers.begin(), numbers.end(), [](double lhs, double rhs)->bool {return lhs < rhs; });
	printVector(numbers);
	std::size_t numberSize = numbers.size();
	std::cout << "there are " << numberSize << " values" << std::endl;
	if (numberSize%2 == 1)
	{
		std::cout << "the median number is: " << numbers[numberSize/2 + 1] << std::endl;
	}
	else
	{
		std::cout << "the median number is: " << 0.5 * (numbers[(numberSize -1)/ 2] + numbers[(numberSize-1) / 2 + 1]) << "\n";
	}
}

void GuessingNumber()
{
	int uerInput = io::GetUerInput<int>("please choice a number between 1 and 100: I will guess it in 7 tries.");
	while (uerInput < 0 || uerInput> 100)
	{
		uerInput = io::GetUerInput<int>("well, your number is out of range(1 - 100): ");
	}
	int RangeMin = 0;
	int RangeMax = 100;
	int guessing = 50;
	int respond = 1;
	int tryCount = 0;
	while(true)
	{
		//check if the computer our of tries
		if (tryCount >= 7)
		{
			if (uerInput > RangeMax || uerInput < RangeMin)
			{
				std::cout << "you give me the wrong hint...\n" << "Fucking cheater!!" << std::endl;
			}
			else
			{
				std::cout << "guess I can never get it then..." << std::endl;
			}
			break;
		}

		//ask if the new guess correct.
		std::cout << "is " << guessing << " the number ?\n" << "1. Higher\n2.lower\n3.correct" << std::endl;
		std::cin >> respond;
		while (respond != 1 && respond !=2 && respond !=3)
		{
			std::cout << "not the available choice, please chose:\n1. Higher\n2.lower\n3.correct" << std::endl;
			std::cin >> respond;
		}
		
		//check if the user is cheating
		if (uerInput == guessing && respond < 3)
		{
			std::cout << "you are cheating!!" << std::endl;
			break;
		}
		//check if the user forget the number:
		if (uerInput != guessing && respond == 3)
		{
			std::cout << "I think you forget your original number.." << std::endl;
			break;
		}

		if (respond == 1 && uerInput != guessing)
		{
			RangeMin = guessing;
			RangeMax = RangeMax;
			guessing = (RangeMin + RangeMax) / 2;
		}else if (respond == 2 && uerInput != guessing)
		{
			RangeMin = RangeMin;
			RangeMax = guessing;
			guessing = (RangeMin + RangeMax) / 2;
		}else if (respond == 3 && uerInput == guessing)
		{
			std::cout << "told you I will guess it with in 7 tries! it's " << uerInput << std::endl;
			break;
		}
		tryCount += 1;
	}
}

void Calculator()
{
	std::cout << "please type in the simple binary calculation you want: " << std::endl;
	double lhs;
	char operation;
	double rhs;
	std::cin >> lhs >> operation >> rhs;
	while (std::cin.fail() || (!(operation == '+' || operation == '-' || operation == '*' || operation == '/')))
	{
		std::cout << "not the right format, the format should be like\n 1 * 2\nPlease try again:\n";
		flushAndResetBuffer();
		std::cin >> lhs >> operation >> rhs;
	}
	switch (operation)
	{
	case '+':
		std::cout << "the sum of " << lhs << " and " << rhs << " is: " << lhs + rhs << "\n";
		break;
	case '-':
		std::cout << "the subtraction of " << lhs << " and " << rhs << " is: " << lhs - rhs << "\n";
		break;
	case '*':
		std::cout << "the multiplication of " << lhs << " and " << rhs << " is: " << lhs * rhs << "\n";
		break;
	case '/':
		if (rhs == 0)
		{
			std::cout << " it is not possible to divide something by 0 " << std::endl;
			break;
		}
		std::cout << "the division of " << lhs << " and " << rhs << " is: " << lhs / rhs << "\n";
		break;
	default:
		break;
	}
}

void SingleDigitCalculator()
{
	
	std::vector<Typepairs<int, std::string>> pairs{
		Typepairs<int, std::string>(0, "zero"),
		Typepairs<int, std::string>(1, "one"),
		Typepairs<int, std::string>(2, "two"),
		Typepairs<int, std::string>(3, "three"),
		Typepairs<int, std::string>(4, "four"),
		Typepairs<int, std::string>(5, "five"),
		Typepairs<int, std::string>(6, "six"),
		Typepairs<int, std::string>(7, "seven"),
		Typepairs<int, std::string>(8, "eight"),
		Typepairs<int, std::string>(9, "nine"),
	};

	Library<int, string> SingleDigitNmubers(pairs);

	std::cout << "please type in the single digit binary calculation you want: " << std::endl;
	
	std::string lhsString;
	std::string rhsString;
	int lhs;
	char operation;
	int rhs;

	bool lsFormatChecker = true;
	bool rsFormatChecter = true;
	
	bool bShouldErrorMessageOn = false;

	do 
	{
		if (bShouldErrorMessageOn)
		{
			std::cout << "Wrong Formate.." << std::endl;
			lsFormatChecker = true;
			rsFormatChecter = true;
			flushAndResetBuffer();
		}
		std::cin >> lhs;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin >> lhsString;
			if (SingleDigitNmubers.Check(lhsString))
			{
				lhs = SingleDigitNmubers.get(lhsString);
				lsFormatChecker = true;
			}
			else
			{
				lsFormatChecker = false;
			}
		}
		std::cin >> operation;
		std::cin >> rhs;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin >> rhsString;
			
			if (SingleDigitNmubers.Check(rhsString))
			{
				rhs = SingleDigitNmubers.get(rhsString);
				rsFormatChecter = true;
			}
			else
			{
				rsFormatChecter = false;
			}
		}
		bShouldErrorMessageOn = true;
	} while ( !lsFormatChecker || !rsFormatChecter || !isSingleDigit(lhs) || !isSingleDigit(rhs) || (!(operation == '+' || operation == '-' || operation == '*' || operation == '/')));


	switch (operation)
	{
	case '+':
		std::cout << "the sum of " << lhs << " and " << rhs << " is: " << lhs + rhs << "\n";
		break;
	case '-':
		std::cout << "the subtraction of " << lhs << " and " << rhs << " is: " << lhs - rhs << "\n";
		break;
	case '*':
		std::cout << "the multiplication of " << lhs << " and " << rhs << " is: " << lhs * rhs << "\n";
		break;
	case '/':
		if (rhs == 0)
		{
			std::cout << " it is not possible to divide something by 0 " << std::endl;
			break;
		}
		std::cout << "the division of " << lhs << " and " << rhs << " is: " << lhs / rhs << "\n";
		break;
	default:
		break;
	}
	flushAndResetBuffer();
}

void NumberStringConverter()
{
	std::vector<int> numbers;
	std::vector<string> numberStrings;
	io::getMultipleImputOfTwoDifferentTypes(numbers, numberStrings, "please give me number and corresponding strings:\n example number:\n example: 12 twelve");
	
	//get element to search:
	std::cout << "please give me one element of one of the pairs: put 'string' if you want to indicate it it string" << std::endl;
	int tryNumber;
	std::string tryString;
	std::string catchString;
	std::cin >> tryNumber;
	bool bIsString = false;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin >> tryString;
		bIsString = true;
	}
	if (!isBufferClean() && !bIsString)
	{
		std::cin >> catchString;
		if (catchString == "string")
		{
			bIsString = true;
			tryString = std::to_string(tryNumber);
		}
	}

	//getting element based on input
	std::vector<int> indexesFound;
	if (bIsString)
	{
		indexesFound = getIndexOfElementValue(numberStrings, tryString);
	
	}
	else
	{
		indexesFound = getIndexOfElementValue(numbers, tryNumber);
	}

	//check if we found something:
	if (indexesFound.size() == 0)
	{
		std::cout << "nothing found..." << std::endl;
	}
	else
	{
		if (bIsString)
		{
			std::cout << "the corresponds pairs :\n";
			printVector(numbers, true, indexesFound);
		}
		else
		{
			std::cout << "the corresponds pairs :\n";
			printVector(numberStrings, true, indexesFound);
		}
	}
	
}

void IntGrains()
{
	std::cout << "give me the maximum count you want: " << std::endl;
	int maxAmount = 0;
	std::cin >> maxAmount;
	int lastGrainCount = 1;
	int currentGrainCount = 0;
	int totalGrainCount = 1;
	int OneKGrainSquareAmount = 1;
	for (int i = 0; i < maxAmount; ++i)
	{
		std::cout << totalGrainCount << " " << OneKGrainSquareAmount << endl;
		currentGrainCount = lastGrainCount * 2;
		OneKGrainSquareAmount += 1;
		totalGrainCount = currentGrainCount + totalGrainCount;
		lastGrainCount = currentGrainCount;
	}
}

void doubleGrains()
{
	double currentSqureGrains = 0;
	double currentSqureNum = 2;
	double lastSqureGrains = 1;
	double TotalGrains = 1;
	for (currentSqureNum; TotalGrains <= std::numeric_limits<double>::max(); ++currentSqureNum)
	{
		std::cout << "in square " << currentSqureNum << " there are " << TotalGrains << " grains" << std::endl;

		currentSqureGrains = lastSqureGrains + lastSqureGrains;
		TotalGrains = currentSqureGrains + TotalGrains;
		lastSqureGrains = currentSqureGrains;
	}
}

void PaperRockScissors()
{
	
	std::cout << "Welcome to Paper Rock Scissors!\nplease choose your move:\n1.Rock\n2.Paper\n3.Scissors\n";
	
	//get user's choice and convert it to enum
	int userInput = io::GetUerInput<int>();
	RockPaperScissors UserChoice = static_cast<RockPaperScissors>(userInput); 

	//random an int form time and then convert it to enum
	int randomGuess = randomNmuberBasedOnCurrentTime(1, 3);
	RockPaperScissors ComputerChoice = static_cast<RockPaperScissors>(randomGuess);
	
	//do a count down to build up tension
	std::cout << "\nResult shows in: " << std::endl;
	DoCountDown(3);
	
	//print choices
	std::cout << "You: " << PaperRockScissorsToString(UserChoice) << std::endl;
	std::cout << "Me: " << PaperRockScissorsToString(ComputerChoice) << "\n"<< std::endl;
	
	//compare choices and then print out win lose result
	switch (PaperRockScissorsCompare(UserChoice, ComputerChoice))
	{
	case EWL_Win:
		std::cout << "you win!" << std::endl;
		break;
	case EWL_Lose:
		std::cout << "you lose!" << std::endl;
		break;
	case EWL_Even:
		std::cout << "we are even!" << std::endl;
	default:
		break;
	}
	std::cout << "\n" << std::endl;
}

void GetPrimNumberBetween()
{
	std::vector<int> range;
	io::getMultiUserInputs("please give the range you want to find prime number from: ", range, 2);
	std::vector<int> primeNumbers = GetPrimeNumberBetween(range[0], range[1]);
	std::cout << "the prime numbers between " << range[0] << " and " << range[1] << " are:\n ";
	printVector(primeNumbers);
}




EWinLose PaperRockScissorsCompare(RockPaperScissors PlayerOneChoice, RockPaperScissors PlayerTwoChoice)
{
	switch (PlayerOneChoice)
	{
	case ERPS_Rock:
		switch (PlayerTwoChoice)
		{
		case ERPS_Rock:
			return EWL_Even;
			break;
		case ERPS_Paper:
			return EWL_Lose;
			break;
		case ERPS_Scissors:
			return EWL_Win;
			break;
		default:
			return EWL_Even;
			break;
		}
		break;
	case ERPS_Paper:
		switch (PlayerTwoChoice)
		{
		case ERPS_Rock:
			return EWL_Win;
			break;
		case ERPS_Paper:
			return EWL_Even;
			break;
		case ERPS_Scissors:
			return EWL_Lose;
			break;
		default:
			return EWL_Even;
			break;
		}
		break;
	case ERPS_Scissors:
		switch (PlayerTwoChoice)
		{
		case ERPS_Rock:
			return EWL_Lose;
			break;
		case ERPS_Paper:
			return EWL_Win;
			break;
		case ERPS_Scissors:
			return EWL_Even;
			break;
		default:
			return EWL_Even;
			break;
		}
		break;
	default:
		break;
	}
	return EWL_Even;
}

std::string PaperRockScissorsToString(RockPaperScissors inEnum)
{
	switch (inEnum)
	{
	case ERPS_Rock:
		return "Rock";
		break;
	case ERPS_Paper:
		return "Paper";
		break;
	case ERPS_Scissors:
		return "Scissors";
		break;
	default:
		return "No Idea...";
		break;
	}
}

void TemperatureConverter()
{
	Temperature temp(0, "C");
	std::cout << "Please give me the temperature:\n";
	std::cin >> temp;
	while (!cin || (temp.getUnit() != "C" && temp.getUnit() != "K"))
	{
		std::cin.clear();
		flushAndResetBuffer();
		std::cout << "Wrong Import" << std::endl;
		std::cin >> temp;
	}

	std::cout << "You typed in: " << temp << std::endl;

	Temperature ConvertTemp = CelsiusKalvienConverter(temp);
	std::cout << "that means: " << ConvertTemp << std::endl;
}

void GetFirstNNumbersAddedTogether()
{
	std::cout << "How many do you want to add Together: " << std::endl;
	int Number = io::GetUerInput<int>();

	while (Number <= 0)
	{
		std::cout << "Please give me a positive number: " << std::endl;
		std::cin >> Number;;
	}

	std::vector<int> numbers;
	io::getMultiUserInputs<int>("Please Give the numbers:", numbers);
	while (numbers.size() < Number)
	{
		std::string wrongInfo = "Not Enough Numbers to calculate, you need at least " + std::to_string(Number);
		io::getMultiUserInputs<int>(wrongInfo, numbers, -1, false);
	}
	double TestResult = 0;
	int Result = 0;
	for (int i = 0; i < Number; ++i)
	{
		TestResult += numbers[i];
		Result += numbers[i];
	}
	if (Result != TestResult)
	{
		std::cout << "The sum is out of the range of what an int can store." << std::endl;
		std::cout << TestResult << "\n";
	}
	else
	{
		std::cout << "The sum of the first " << Number << " is: " << Result << std::endl;
	}
}

void GetNumbersAndShowDifferences()
{
	std::vector<double> Numbers;
	io::getMultiUserInputs<double>("Please give me a few Numbers: ", Numbers);
	while (Numbers.size() < 2)
	{
		io::getMultiUserInputs<double>("I need at least 2 numbers, please re enter: ", Numbers, -1, false);
	}
	for (int i = 0; i < (Numbers.size() - 1); ++i)
	{
		std::cout << "The different between " << Numbers[i] << " and " << Numbers[i + 1] << " is: " << Numbers[i] - Numbers[i + 1] << std::endl;
	}
}

void GetBigestFibonacci()
{
	double PreviousFibnacci = 1;
	double PPreviousFibnacci = 0;
	int FIbnacciConuntedNow = 1;
	double TestFeb = 1;
	while (true)
	{
		FIbnacciConuntedNow = PreviousFibnacci + PPreviousFibnacci;
		TestFeb = PreviousFibnacci + PPreviousFibnacci;
		if (FIbnacciConuntedNow != TestFeb)
		{
			break;
		}
		PPreviousFibnacci = PreviousFibnacci;
		PreviousFibnacci = FIbnacciConuntedNow;
	}
	std::cout << "The biggest Fibonacci in Int is: " << static_cast<int>(PreviousFibnacci) << std::endl;
}

void PlayBox(std::function<void()> GameToPlay)
{
	int command = 0;
	while (command != 2)
	{
		GameToPlay();

		flushAndResetBuffer();
	
	
		std::cout << "do you want to play again?\n1.Yes\n2.No\n";
		std::cin >> command;
		while (command < 1 || command > 2)
		{
			std::cout << "please give me a valid command:\n1.Yes\n2.No\n";
			std::cin >> command;
		}
		flushAndResetBuffer();
	}
	std::cout << "Thanks for playing.." << std::endl;


}

void FindModeInVector()
{
	std::vector<int> numbers;
	io::getMultiUserInputs<int>("please give me some int", numbers);

	std::vector<int> modeNumbers = FindMode(numbers);

	printVector(modeNumbers);
}

void FindMinMaxModeInStringVector()
{
	std::vector<std::string> strings;
	io::getMultiUserInputs<std::string>("give me some string", strings);
	
	std::string smallest = FindInVectorBasedOnRule<std::string>(strings, [](std::string& stringOne, std::string& stringTwo)->bool {return stringOne < stringTwo; });
	std::string biggest = FindInVectorBasedOnRule<std::string>(strings, [](std::string& stringOne, std::string& stringTwo)->bool {return stringOne > stringTwo; });
	std::vector<std::string> modeStrings = FindMode(strings);

	std::cout << "The smallest string is: " << smallest << std::endl;
	std::cout << "The biggest string is: " << biggest << std::endl;

	std::cout << "all the modes are: ";
	printVector(modeStrings);
}

void SolveQuadraticEquation()
{
	std::vector<double> indexes;
	io::getMultiUserInputs("please give me the indexes of the equation:(the a, b, c in ax^2 + bx + c = 0)", indexes, 3);
	
	std::cout << "so the equation you want to solve is: " << indexes[0] << "x^2 + " << indexes[1] << "x + " << indexes[2] << " = 0." << std::endl;
	
	EquationResult<double> GetResultOfX = QuadraticEquation(indexes[0], indexes[1], indexes[2]);
	
	if (GetResultOfX.Successed())
	{
		std::cout << "the result(s) of x is: ";
		printVector(GetResultOfX.results);
	}
	else
	{
		std::cout << "there is no result for this equation." << std::endl;
	}
}

void NameScoreRecorder()
{
	std::vector<Typepairs<std::string, int>> pairs;
	std::vector<std::string> pairsStringElements;
	std::vector<int> pairsIntElements;

	io::getMultipleImputOfTwoDifferentTypes<std::string, int>(pairsStringElements, pairsIntElements, "give me the names and scores (example: Joe 17 Allie 21...): ");
	while(!isAllElementUnique(pairsStringElements))
	{
		std::vector<string> repeations = GetReaptedElements(pairsStringElements);
		std::cout << "you got more than one of name: ";
		printVector(repeations);
		std::cout << "please re-enter the name score paires(): (example: Joe 17 Allie 21...):";
		io::getMultipleImputOfTwoDifferentTypes<std::string, int>(pairsStringElements, pairsIntElements,"");
	}

	for (int iter = 0; iter < pairsIntElements.size(); ++iter)
	{
		pairs.push_back(Typepairs<std::string, int>(pairsStringElements[iter], pairsIntElements[iter]));
	}

	Library<std::string, int> NameScoreChart(pairs);

	bool bIsUserGivingMeInt = true;
	int UserFindingInputKey_TryInt;
	std::string UserFindingInputKey_TryString;
	
	std::function<void()> FindNameOrScore = [&]()
	{
		bIsUserGivingMeInt = true;
		std::cout << "Please give me the score or name you are checking:\n";
		std::cin >> UserFindingInputKey_TryInt;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin >> UserFindingInputKey_TryString;
			bIsUserGivingMeInt = false;
		}
		if (bIsUserGivingMeInt)
		{
			if (NameScoreChart.Check(UserFindingInputKey_TryInt))
			{
				std::vector<std::string> names = NameScoreChart.getMulti(UserFindingInputKey_TryInt);
				std::cout << "the play has score of " << UserFindingInputKey_TryInt << " is(are): " << std::endl;
				printVector(names);
			}
			else
			{
				std::cout << "No such name or score " << std::endl;
			}

		}
		else
		{
			if (NameScoreChart.Check(UserFindingInputKey_TryString))
			{
				int score = NameScoreChart.get(UserFindingInputKey_TryString);
				std::cout << UserFindingInputKey_TryString << "'s score is: " << score << std::endl;

			}
			else
			{
				std::cout << "No such name or score " << std::endl;
			}
		}
	};
	
	int userChoice = 0;
	while (userChoice != 2)
	{
		flushAndResetBuffer();
		FindNameOrScore();
		std::cout << "do you want to check another?\n1.Yes\n2.No\n";
		std::cin >> userChoice;
	}
}

double ctok(double c)
{
	//pre-check of the argument
	if (c < -273.15)
	{
		throw BadRange("Temperature cannot be lower than -273.15");
	}
	double k = c + 273.15;
	return k;
}

Temperature CelsiusKalvienConverter(Temperature inTemperature)
{
	if (inTemperature.getUnit() != "C" && inTemperature.getUnit() != "K")
	{
		error("Wrong Data Type of Temperature");
	}

	if (inTemperature.getUnit() == "C" && inTemperature.getAmount() < -273.15)
	{
		error("Temperature cannot be lower than -273.15 C");
	}

	if (inTemperature.getUnit() == "K" && inTemperature.getAmount() < 0)
	{
		error("Temperature cannot be lower than 0 K");
	}

	Temperature outTemperature(0, "C");
	if (inTemperature.getUnit() == "C")
	{
		outTemperature.SetAmountAndUnit(inTemperature.getAmount() - 273.15, "K");
	}
	else if (inTemperature.getUnit() == "K")
	{
		outTemperature.SetAmountAndUnit(inTemperature.getAmount() + 273.15, "C");
	}
	return outTemperature;
}
