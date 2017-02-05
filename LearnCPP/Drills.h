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

void FindModeInVector();

void FindMinMaxModeInStringVector();

void SolveQuadraticEquation();

void NameScoreRecorder();

double ctok(double c);
Temperature CelsiusKalvienConverter(Temperature inTemperature);

EWinLose PaperRockScissorsCompare(RockPaperScissors PlayerOneChoice, RockPaperScissors PlayerTwoChoice);

std::string PaperRockScissorsToString(RockPaperScissors inEnum);

void TemperatureConverter();

void GetFirstNNumbersAddedTogether();

void GetNumbersAndShowDifferences();

void GetBigestFibonacci();

void BullsAndCows();

void DayOfTheWeekValue();

void ExpressionCalculator();

void BookExpresionCalculator();

void WorkingCalculator();

bool isOperationValid(char operation);

void ScoreRecorderV2();

//an expression is simply a number, or a number * or / by another number or a number * or / by and expression inside ()
//or, it can be an expression + or - another expression
double expression(Token_Stream& InputReader);

//Term is made of a number, or a number * or / by another number or a number * or / by and expression inside ()
double term(Token_Stream& InputReader);

//a primary is a number or another thing inside()
double primary(Token_Stream& InputReader);
