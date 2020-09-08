#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <algorithm>
#include "Define.h"
using namespace std;

int RandInt(int x, int y) { return rand() % (y - x + 1) + x; }

//returns a random float between zero and 1
float RandFloat() { return (rand()) / (RAND_MAX + 1.0); }

void copyChrom(int baby, int mom);
void copyChromP();
int BestFit();
int BestFit2(int n);
int WorstFit();
int TotalFit();
void CalculateBestWorstAvTot();
void fit(int n);
void RankScaling();
void SigmaScaling();
void BoltzmannScaling();
void FitnessScaleSwitch();
void SinglePoint(int Mom, int Dad, int n);
void TwoPoint(int Mom, int Dad, int n);
void MultiPoint(int Mom, int Dad, int n);
int Roulette();
int Tournament();
void Elitism(int BF1, int BF2);
void SUS(int NumofGen);
void doCrossover(int i);
void SM(int Mom);
void IM(int Mom);
void doMutation(int i);
void init();
void GA();