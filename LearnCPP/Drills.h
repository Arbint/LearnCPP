#pragma once
#include "UniversialInclude.h"
#include "Trigger.h"



void writeLetter();

double milesToKilometer(double inMiles);

void MileToKilometerConverter();

void compareValues(int x, int y);

void getNumberAndDecideOddOrEven();

void getLiteralNumAndPrintDigit();

void calculateTwoValues();

void HowMuchMoneyDoYouHave();

//portaintial error
void InchesCmConverter(unitInt& unit);
void GetLengthAndConvert();

void convertMoney(unitInt& money);
void getMonyAndConvert();

void checkEmail();

void mimicAddDynamics();

void getWordsAndBeepInApproporateOnes();

void readTwoIntsAndPrintsThem();

void readTwoIntsAndPrintTheBiggrOne();

void askAndPrintBiggestAndSmallestValueSofar();

void ReadLengthInMultiUnits();

void ReadMultipleNumbersAndExportMedian();

void GuessingNumber();

void Calculator();

void SingleDigitCalculator();

void NumberStringConverter();

void PlayBox(std::function<void()> GameToPlay);

void IntGrains();

void doubleGrains();

void PaperRockScissors();

void GetPrimNumberBetween();

EWinLose PaperRockScissorsCompare(RockPaperScissors PlayerOneChoice, RockPaperScissors PlayerTwoChoice);

std::string PaperRockScissorsToString(RockPaperScissors inEnum);