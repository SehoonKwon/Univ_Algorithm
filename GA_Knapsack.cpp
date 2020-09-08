#include "Func.h"
#include <math.h>
#include <chrono> //마이크로 초, 나노 초 단위를 측정하기 위한 C++라이브러리
using namespace std;

int weight = 0; //제한 무게 변수
int BestFitness = 0, BestFitness2 = 0, WorstFitness = 0, TotalFitness = 0, AveFitness = 0; //각 적합도 값들
int Not_Crossover_Mutation = 0, Not_Crossover = 0, Not_Mutation = 0; //SUS의 범위를 구하기 위해 사용할 변수
int for_sus = 0; //SUS의 유전자 번호를 위한 변수

int m_ScaleType = 0, SelectionSwitch = 1, CrossSwitch = 1, MutationSwitch = 1, ElitismSwitch = false; //스케일, 선택, 크로스오버, 돌연변이, 엘리티즘 종류 선택변수
int m_bSorted = false; //is Sorted ?

int Chrom[CN][N]; //처음 유전자. 이후 부모로 쓰임
int HChrom[CN][N]; //다음세대 유전자.
int Fitness[CN]; //각 유전자의 적합도 값을 담은 배열
int P[N], W[N]; //가치 값, 무게 값을 담은 배열

//유전자 복사
void copyChrom(int baby, int mom)
{
	for (int i = 0; i < N; i++)
		HChrom[baby][i] = Chrom[mom][i];
}

//바뀐 유전자 부모로 복사. 다음 세대 진화를 위해
void copyChromP()
{
	for (int i = 0; i < CN; i++)
		for (int j = 0; j < N; j++)
			Chrom[i][j] = HChrom[i][j];
}

//최고의 적합도
int BestFit()
{
	int i=0;
	for (int j = 0; j < CN; j++)
		if (Fitness[j] > Fitness[i]) i = j; //가장 큰 적합도의 인덱스를 리턴한다.
	return i;
}

//엘리티즘 용. 적응도가 가장 높은 유전자2 인덱스 구하기
int BestFit2(int n)
{
	int i = 0;
	for (int j = 0; j < CN; j++)
	{
		if (j == n) continue; //BestFitness면 넘어감. 두번째 최고적합도를 구하기 위해
		if (Fitness[j] > Fitness[i]) i = j;
	}
	return i;
}

//Best와 반대
int WorstFit()
{
	int i = 0;
	for (int j = 0; j < CN; j++)
		if (Fitness[j] < Fitness[i]) i = j;
	return i;
}

//적합도의 총합
int TotalFit()
{
	int sum = 0;
	for (int i = 0; i < CN; i++) sum += Fitness[i];
	return sum;
}

//모든 적합도 계산모음 함수
void CalculateBestWorstAvTot()
{
	BestFitness = BestFit();
	BestFitness2 = BestFit2(BestFitness);
	WorstFitness = WorstFit();
	TotalFitness = TotalFit();
	AveFitness = TotalFitness / CN;
}

//랭크 스케일링
void RankScaling()
{
	//sort population into ascending order
	if (!m_bSorted)
	{
		sort(Fitness, Fitness+CN);

		m_bSorted = true;
	}

	//now assign fitness according to the genome's position on
	//this new fitness 'ladder'
	for (int i = 0; i<CN; i++)
	{
		Fitness[i] = i;
	}

	//recalculate values used in selection
	CalculateBestWorstAvTot();
}

//시그마 스케일링
void SigmaScaling()
{
	double RunningTotal = 0;

	//first iterate through the population to calculate the standard
	//deviation
	for (int gen = 0; gen<CN; gen++)
	{
		RunningTotal += (Fitness[gen] - AveFitness) *
			(Fitness[gen] - AveFitness);
	}

	double variance = RunningTotal / (double)CN;

	//standard deviation is the square root of the variance
	double m_dSigma = sqrt(variance);

	//now iterate through the population to reassign the fitness scores
	for (int gen = 0; gen<CN; gen++)
	{
		double OldFitness = Fitness[gen];

		Fitness[gen] = (OldFitness - AveFitness) /
			(2 * m_dSigma);
	}

	//recalculate values used in selection
	CalculateBestWorstAvTot();

}

//볼츠만 스케일링
void BoltzmannScaling()
{
	//reduce the temp a little each generation
	double m_dBoltzmannTemp = N * 2;
	m_dBoltzmannTemp -= BOLTZMANN_DT;

	//make sure it doesn't fall below minimum value
	if (m_dBoltzmannTemp< BOLTZMANN_MIN_TEMP)
	{
		m_dBoltzmannTemp = BOLTZMANN_MIN_TEMP;
	}

	int gen = 0;
	double dFitnessSum = 0;
	double dFitnessAvg = 0;

	for (gen = 0; gen<CN; gen++)
	{
		double OldFitness = Fitness[gen] / m_dBoltzmannTemp;
		dFitnessSum += exp(OldFitness);
	}
	dFitnessAvg = dFitnessSum / CN;

	for (gen = 0; gen<CN; gen++)
	{
		double OldFitness = Fitness[gen] / m_dBoltzmannTemp;
		Fitness[gen] = exp(OldFitness) / dFitnessAvg;
	}

	//recalculate values used in selection
	CalculateBestWorstAvTot();
}

//어떤 스케일을 사용할 것인가 ?
void FitnessScaleSwitch()
{
	switch (m_ScaleType)
	{

	case 0:

		break;

	case 1:

		RankScaling();

		break;

	case 2:

		SigmaScaling();

		break;

	case 3:

		BoltzmannScaling();

		break;
	}
}

//적합도 검사
void fit(int n)
{
	int Value = 0;
	int overWeight = 0;
	for (int i = 0; i < N; i++)
	{
		Value += Chrom[n][i] * P[i];
		overWeight += Chrom[n][i] * W[i];
	}

	if (overWeight > weight) Fitness[n] = 0; //담을 수 있는 무게를 초과한 경우 룰렛 선택 안되게 적합도를 0으로 설정
	else Fitness[n] = Value;

	CalculateBestWorstAvTot();
	FitnessScaleSwitch();
}

//싱글포인트 크로스오버
void SinglePoint(int Mom, int Dad, int n)
{
	if ((Mom == Dad))	return; //부모가 같은 유전자일경우 리턴

	int Baby1;

	Baby1 = n;

	//부모1 유전자 할당
	copyChrom(Baby1, Mom);

	int beg = RandInt(0, N - 2); //임의의 지점 구하기

	//임의의 지점 이후로는 부모2의 유전자 할당
	for (int i = beg; i < N; i++)
		HChrom[Baby1][i] = Chrom[Dad][i];
}

//투 포인트 크로스오버
void TwoPoint(int Mom, int Dad, int n)
{
	if ((Mom == Dad))	return; //부모가 같은 유전자일경우 리턴

	int Baby1;

	Baby1 = n;

	//부모1 유전자 할당
	copyChrom(Baby1, Mom);

	//first we choose a section of the chromosome
	int beg = RandInt(0, N - 2);

	int end = beg;

	//find an end
	while (end <= beg)
		end = RandInt(0, N - 1);

	//임의의 두 지점 사이에는 부모2 유전자 할당
	for (int i = beg; i < end + 1; i++)
		HChrom[Baby1][i] = Chrom[Dad][i];
}

//멀티 포인트 크로스오버
void MultiPoint(int Mom, int Dad, int n)
{
	if (Mom == Dad) return; //부모가 같은 유전자일 경우 리턴

	//조건에 따라 부모1, 부모2의 유전자 할당
	for (int gen = 0; gen < N; gen++)
	{
		//치환한다(부모2 유전자 할당)
		if (RandFloat() > MultiCrossoverRate)
			HChrom[n][gen] = Chrom[Dad][gen];

		//치환하지 않는다(부모1 유전자 할당)
		else
			HChrom[n][gen] = Chrom[Mom][gen];
	}
}

//룰렛 선택
int Roulette()
{
	double fSlice = RandFloat() * TotalFitness;

	double cfTotal = 0.0;

	int	SelectedGenome = 0;

	for (int i = 0; i<CN; ++i)
	{

		cfTotal += Fitness[i];

		if (cfTotal > fSlice)
		{
			SelectedGenome = i;

			break;
		}
	}

	return SelectedGenome;
}

//토너먼트 선택
int Tournament()
{
	double BestFitnessTour = 0;

	int ChosenOne = 0;

	//Select N members from the population at random testing against 
	//the best found so far
	for (int i = 0; i<NUM_TO_COMPARE; ++i)
	{
		int ThisTry = RandInt(0, CN - 1);

		if (Fitness[ThisTry] > BestFitnessTour)
		{
			ChosenOne = ThisTry;

			BestFitnessTour = Fitness[ThisTry];
		}
	}

	//return the champion
	return ChosenOne;
}

//엘리티즘. 가장 우수한 유전자 2개를 다음 세대 유전자 맨 앞으로 설정한다. 100의 2%인 2로 선택
void Elitism(int BF1, int BF2)
{
	copyChrom(0, BF1);
	copyChrom(1, BF2);
}

//SUS 선택
void SUS(int NumofGen)
{
	int curGen = 0;
	double sum = 0;

	//NumToAdd is the amount of individuals we need to select using SUS.
	//Remember, some may have already been selected through elitism
	int NumToAdd = CN - NumofGen;

	//calculate the hand spacing
	double PointerGap = TotalFitness / (double)NumToAdd;

	//choose a random start point for the wheel
	float ptr = RandFloat() * PointerGap;

	for(curGen=0; curGen<NumToAdd; curGen++)
	{
		for (sum += Fitness[curGen]; sum > ptr; ptr += PointerGap)
		{
			copyChrom(curGen, curGen);
		}
	}
}

//크로스 오버 수행 함수
void doCrossover(int i)
{
	int Mom, Dad;
	if (for_sus == CN-2) for_sus = 0;

	//doSelection
	switch (SelectionSwitch)
	{

	case 1:
		Mom = Roulette();
		Dad = Roulette();
		break;
	case 2:
		Mom = Tournament();
		Dad = Tournament();
		break;
	case 3:
		SUS(Not_Crossover_Mutation);
		break;
	default:
		break;

	}

	//doCrossover
	//SUS가 아닌 경우
	if (SelectionSwitch == 1 || SelectionSwitch == 2)
	{
		switch (CrossSwitch)
		{
		case 1:
			SinglePoint(Mom, Dad, i);
			break;
		case 2:
			TwoPoint(Mom, Dad, i);
			break;
		case 3:
			MultiPoint(Mom, Dad, i);
		default:
			break;
		}
	}

	else //SUS 인경우
	{
		switch (CrossSwitch)
		{
		case 1:
			SinglePoint(for_sus, for_sus+1, i);
			break;
		case 2:
			TwoPoint(for_sus, for_sus+1, i);
			break;
		case 3:
			MultiPoint(for_sus, for_sus + 1, i);
			break;
		default:
			break;
		}

		for_sus = for_sus + 2;
	}
}

//돌연변이 기법1 SM
void SM(int Mom)
{
	int Baby1;
	Baby1 = Mom; //부모 유전자 인덱스를 받는다. 몇번 유전자로부터 돌연변이 되었는가를 알 수 있다.

	copyChrom(Baby1, Mom); //유전자 복사

	int start = RandInt(0, N - 2); //임의의 지점 선택

	int end = start;

	//find an end
	while (end <= start)
		end = RandInt(0, N - 1); //범위가 start보다 커야 무한루프가 생기지 않는다.

	//2칸 뒤의 있는 값과 섞는다.
	for (int i = start; i < end + 1; ++i)
	{
		if (i + 2 <= end) Chrom[Baby1][i] = Chrom[Baby1][i + 2];
	}
}

//돌연변이 기법2 IM
void IM(int Mom)
{
	int Baby1;
	Baby1 = Mom; //부모 유전자 인덱스 받기. 이유는 SM과 같다

	copyChrom(Baby1, Mom);

	int start = RandInt(0, N - 2); //SM과 동일

	int end = start;

	//find an end
	while (end <= start)
	{
		end = RandInt(0, N - 1); //SM과 동일
	}

	int temp = Chrom[Baby1][start]; //스왑을 위한 임시 저장소

	//스왑
	Chrom[Baby1][start] = Chrom[Baby1][end];
	Chrom[Baby1][end] = temp;
}

//유전자의 돌연변이
void doMutation(int i)
{
	switch (MutationSwitch)
	{
	case 1:
		SM(i);
		break;

	case 2:
		IM(i);
		break;
	default:
		break;
	}

	fit(i);
}

//처음 유전자 생성 함수
void init()
{
	srand((unsigned int)time(NULL));	//srand의 인자로 time함수를 넣어 매번 시드값을 변경

	int x;

	for (int j = 0; j < CN; j++)
	{
		//물품 개수만큼 0 또는 1의 난수 생성. 0은 넣지 않는다, 1은 넣는다의 의미
		for (int i = 0; i < N; i++)
		{
			x = rand() % 100;
			if (x > 50) Chrom[j][i] = 1;
			else Chrom[j][i] = 0;
			fit(j);
		}
	}
}

//유전자 알고리즘
void GA()
{
	int Max_Value = 0; //최대 값
	int i=0, Gen=0; //i는 반복문을 위한 변수, Gen역시 반복문을 위한 변수임과 동시에 세대 수를 나타낸다.

	//엘리티즘
	if (ElitismSwitch)
		Elitism(BestFitness, BestFitness2);

	for (Gen = 0; Gen < Generation; Gen++)
	{
		int GA_Value = 0, GA_Weight = 0, Not_Crossover_Mutation = 0;
		if (ElitismSwitch) i = 2;
		else i = 0;

		//i는 새로운 유전자 인덱스. 교차, 변이 할 것인가 말 것인가
		for (; i < CN; i++)
		{
			Not_Crossover = 0, Not_Mutation = 0;
			if ((RandFloat() < CrossoverRate)) doCrossover(i); //확률을 통한 크로스오버.
			else Not_Crossover = 1;

			if ((RandFloat() < MutationRate)) doMutation(i); //확률을 통한 돌연변이
			else Not_Mutation = 1;

			if ((Not_Crossover == 1) && (Not_Mutation == 1)) Not_Crossover_Mutation++; //교차와 돌연변이가 되지 않은 유전자의 경우에 숫자 + 1. SUS범위용
			fit(i); //진화된 유전자의 적합도 검사
		}

		copyChromP(); //다음 세대 진화를 위해 새로운 유전자들을 부모 유전자에 복사

		//최적값인 인덱스 찾기
		BestFitness = BestFit();

		for (int k = 0; k < N; k++)
		{
			GA_Value += Chrom[BestFitness][k] * P[k]; //최적값일때의 총 가치 계산
			GA_Weight += Chrom[BestFitness][k] * W[k]; //최적값일때의 총 가치 계산
		}

		//무게를 넘지 않는 선에서 새로 구한 가치합계가 이전 맥스 값 보다 크면 갱신
		if (GA_Weight < weight && Max_Value < GA_Value) Max_Value = GA_Value;

		//DP로 구한 최적 값에 도달하면 출력 후 종료
		if (Max_Value == 433)
		{
			cout <<"최대 가치도달 : "<< Max_Value << "  세대 수 : " << Gen << endl;
			break;
		}
	}

	if(Max_Value !=433) cout << "최대가치 도달 못했지만 GA로 결정한 최대 가치 값 : " << Max_Value << endl;
	cout << endl;
}

int main()
{
	std::chrono::system_clock::time_point start, stop; //탐색하는데 걸리는 시간 측정하기 위한 변수

	cout << "12131649 권세훈 GA_0-1 Knapsack" << endl << endl;

	cout << "Scaling Techniques : 0.None  1.Rank  2.Sigma  3.Boltzmann" << endl;
	cin >> m_ScaleType;

	cout << "Select Techniques : 1.Roulette  2.Tournament  3.SUS" << endl;
	cin >> SelectionSwitch;

	cout << "Crossover Techniques : 1.SinglePoint  2.TwoPoint  3.MultiPoint" << endl;
	cin >> CrossSwitch;

	cout << "Mutation Techniques : 1.SM  2.IM" << endl;
	cin >> MutationSwitch;

	cout << "Elitism : 1.On  2.Off" << endl;
	cin >> ElitismSwitch;


	cout << "품목 별 무게/가치 입력" << endl;

	for (int i = 0; i < N; i++)
	{
		cin >> W[i] >> P[i];
		weight += W[i];
	}

	weight = weight*0.7; //무게는 전체 물품 무게합의 70%로 설정
	cout << "무게 제한 : " << weight << endl;

	//염색체 생성
	init();

	start = std::chrono::system_clock::now(); //GA 시작 전 시간측정
	GA();
	stop = std::chrono::system_clock::now(); //GA  종료 후 시간 측정

	chrono::microseconds micro; //마이크로 단위 초 측정을 위한 나노세컨즈타입 변수
	micro = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "수행시간 : " << micro.count() << "ms" << endl;

	return 0;
}