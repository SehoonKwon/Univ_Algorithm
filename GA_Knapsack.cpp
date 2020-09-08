#include "Func.h"
#include <math.h>
#include <chrono> //����ũ�� ��, ���� �� ������ �����ϱ� ���� C++���̺귯��
using namespace std;

int weight = 0; //���� ���� ����
int BestFitness = 0, BestFitness2 = 0, WorstFitness = 0, TotalFitness = 0, AveFitness = 0; //�� ���յ� ����
int Not_Crossover_Mutation = 0, Not_Crossover = 0, Not_Mutation = 0; //SUS�� ������ ���ϱ� ���� ����� ����
int for_sus = 0; //SUS�� ������ ��ȣ�� ���� ����

int m_ScaleType = 0, SelectionSwitch = 1, CrossSwitch = 1, MutationSwitch = 1, ElitismSwitch = false; //������, ����, ũ�ν�����, ��������, ����Ƽ�� ���� ���ú���
int m_bSorted = false; //is Sorted ?

int Chrom[CN][N]; //ó�� ������. ���� �θ�� ����
int HChrom[CN][N]; //�������� ������.
int Fitness[CN]; //�� �������� ���յ� ���� ���� �迭
int P[N], W[N]; //��ġ ��, ���� ���� ���� �迭

//������ ����
void copyChrom(int baby, int mom)
{
	for (int i = 0; i < N; i++)
		HChrom[baby][i] = Chrom[mom][i];
}

//�ٲ� ������ �θ�� ����. ���� ���� ��ȭ�� ����
void copyChromP()
{
	for (int i = 0; i < CN; i++)
		for (int j = 0; j < N; j++)
			Chrom[i][j] = HChrom[i][j];
}

//�ְ��� ���յ�
int BestFit()
{
	int i=0;
	for (int j = 0; j < CN; j++)
		if (Fitness[j] > Fitness[i]) i = j; //���� ū ���յ��� �ε����� �����Ѵ�.
	return i;
}

//����Ƽ�� ��. �������� ���� ���� ������2 �ε��� ���ϱ�
int BestFit2(int n)
{
	int i = 0;
	for (int j = 0; j < CN; j++)
	{
		if (j == n) continue; //BestFitness�� �Ѿ. �ι�° �ְ����յ��� ���ϱ� ����
		if (Fitness[j] > Fitness[i]) i = j;
	}
	return i;
}

//Best�� �ݴ�
int WorstFit()
{
	int i = 0;
	for (int j = 0; j < CN; j++)
		if (Fitness[j] < Fitness[i]) i = j;
	return i;
}

//���յ��� ����
int TotalFit()
{
	int sum = 0;
	for (int i = 0; i < CN; i++) sum += Fitness[i];
	return sum;
}

//��� ���յ� ������ �Լ�
void CalculateBestWorstAvTot()
{
	BestFitness = BestFit();
	BestFitness2 = BestFit2(BestFitness);
	WorstFitness = WorstFit();
	TotalFitness = TotalFit();
	AveFitness = TotalFitness / CN;
}

//��ũ �����ϸ�
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

//�ñ׸� �����ϸ�
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

//������ �����ϸ�
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

//� �������� ����� ���ΰ� ?
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

//���յ� �˻�
void fit(int n)
{
	int Value = 0;
	int overWeight = 0;
	for (int i = 0; i < N; i++)
	{
		Value += Chrom[n][i] * P[i];
		overWeight += Chrom[n][i] * W[i];
	}

	if (overWeight > weight) Fitness[n] = 0; //���� �� �ִ� ���Ը� �ʰ��� ��� �귿 ���� �ȵǰ� ���յ��� 0���� ����
	else Fitness[n] = Value;

	CalculateBestWorstAvTot();
	FitnessScaleSwitch();
}

//�̱�����Ʈ ũ�ν�����
void SinglePoint(int Mom, int Dad, int n)
{
	if ((Mom == Dad))	return; //�θ� ���� �������ϰ�� ����

	int Baby1;

	Baby1 = n;

	//�θ�1 ������ �Ҵ�
	copyChrom(Baby1, Mom);

	int beg = RandInt(0, N - 2); //������ ���� ���ϱ�

	//������ ���� ���ķδ� �θ�2�� ������ �Ҵ�
	for (int i = beg; i < N; i++)
		HChrom[Baby1][i] = Chrom[Dad][i];
}

//�� ����Ʈ ũ�ν�����
void TwoPoint(int Mom, int Dad, int n)
{
	if ((Mom == Dad))	return; //�θ� ���� �������ϰ�� ����

	int Baby1;

	Baby1 = n;

	//�θ�1 ������ �Ҵ�
	copyChrom(Baby1, Mom);

	//first we choose a section of the chromosome
	int beg = RandInt(0, N - 2);

	int end = beg;

	//find an end
	while (end <= beg)
		end = RandInt(0, N - 1);

	//������ �� ���� ���̿��� �θ�2 ������ �Ҵ�
	for (int i = beg; i < end + 1; i++)
		HChrom[Baby1][i] = Chrom[Dad][i];
}

//��Ƽ ����Ʈ ũ�ν�����
void MultiPoint(int Mom, int Dad, int n)
{
	if (Mom == Dad) return; //�θ� ���� �������� ��� ����

	//���ǿ� ���� �θ�1, �θ�2�� ������ �Ҵ�
	for (int gen = 0; gen < N; gen++)
	{
		//ġȯ�Ѵ�(�θ�2 ������ �Ҵ�)
		if (RandFloat() > MultiCrossoverRate)
			HChrom[n][gen] = Chrom[Dad][gen];

		//ġȯ���� �ʴ´�(�θ�1 ������ �Ҵ�)
		else
			HChrom[n][gen] = Chrom[Mom][gen];
	}
}

//�귿 ����
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

//��ʸ�Ʈ ����
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

//����Ƽ��. ���� ����� ������ 2���� ���� ���� ������ �� ������ �����Ѵ�. 100�� 2%�� 2�� ����
void Elitism(int BF1, int BF2)
{
	copyChrom(0, BF1);
	copyChrom(1, BF2);
}

//SUS ����
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

//ũ�ν� ���� ���� �Լ�
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
	//SUS�� �ƴ� ���
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

	else //SUS �ΰ��
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

//�������� ���1 SM
void SM(int Mom)
{
	int Baby1;
	Baby1 = Mom; //�θ� ������ �ε����� �޴´�. ��� �����ڷκ��� �������� �Ǿ��°��� �� �� �ִ�.

	copyChrom(Baby1, Mom); //������ ����

	int start = RandInt(0, N - 2); //������ ���� ����

	int end = start;

	//find an end
	while (end <= start)
		end = RandInt(0, N - 1); //������ start���� Ŀ�� ���ѷ����� ������ �ʴ´�.

	//2ĭ ���� �ִ� ���� ���´�.
	for (int i = start; i < end + 1; ++i)
	{
		if (i + 2 <= end) Chrom[Baby1][i] = Chrom[Baby1][i + 2];
	}
}

//�������� ���2 IM
void IM(int Mom)
{
	int Baby1;
	Baby1 = Mom; //�θ� ������ �ε��� �ޱ�. ������ SM�� ����

	copyChrom(Baby1, Mom);

	int start = RandInt(0, N - 2); //SM�� ����

	int end = start;

	//find an end
	while (end <= start)
	{
		end = RandInt(0, N - 1); //SM�� ����
	}

	int temp = Chrom[Baby1][start]; //������ ���� �ӽ� �����

	//����
	Chrom[Baby1][start] = Chrom[Baby1][end];
	Chrom[Baby1][end] = temp;
}

//�������� ��������
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

//ó�� ������ ���� �Լ�
void init()
{
	srand((unsigned int)time(NULL));	//srand�� ���ڷ� time�Լ��� �־� �Ź� �õ尪�� ����

	int x;

	for (int j = 0; j < CN; j++)
	{
		//��ǰ ������ŭ 0 �Ǵ� 1�� ���� ����. 0�� ���� �ʴ´�, 1�� �ִ´��� �ǹ�
		for (int i = 0; i < N; i++)
		{
			x = rand() % 100;
			if (x > 50) Chrom[j][i] = 1;
			else Chrom[j][i] = 0;
			fit(j);
		}
	}
}

//������ �˰���
void GA()
{
	int Max_Value = 0; //�ִ� ��
	int i=0, Gen=0; //i�� �ݺ����� ���� ����, Gen���� �ݺ����� ���� �����Ӱ� ���ÿ� ���� ���� ��Ÿ����.

	//����Ƽ��
	if (ElitismSwitch)
		Elitism(BestFitness, BestFitness2);

	for (Gen = 0; Gen < Generation; Gen++)
	{
		int GA_Value = 0, GA_Weight = 0, Not_Crossover_Mutation = 0;
		if (ElitismSwitch) i = 2;
		else i = 0;

		//i�� ���ο� ������ �ε���. ����, ���� �� ���ΰ� �� ���ΰ�
		for (; i < CN; i++)
		{
			Not_Crossover = 0, Not_Mutation = 0;
			if ((RandFloat() < CrossoverRate)) doCrossover(i); //Ȯ���� ���� ũ�ν�����.
			else Not_Crossover = 1;

			if ((RandFloat() < MutationRate)) doMutation(i); //Ȯ���� ���� ��������
			else Not_Mutation = 1;

			if ((Not_Crossover == 1) && (Not_Mutation == 1)) Not_Crossover_Mutation++; //������ �������̰� ���� ���� �������� ��쿡 ���� + 1. SUS������
			fit(i); //��ȭ�� �������� ���յ� �˻�
		}

		copyChromP(); //���� ���� ��ȭ�� ���� ���ο� �����ڵ��� �θ� �����ڿ� ����

		//�������� �ε��� ã��
		BestFitness = BestFit();

		for (int k = 0; k < N; k++)
		{
			GA_Value += Chrom[BestFitness][k] * P[k]; //�������϶��� �� ��ġ ���
			GA_Weight += Chrom[BestFitness][k] * W[k]; //�������϶��� �� ��ġ ���
		}

		//���Ը� ���� �ʴ� ������ ���� ���� ��ġ�հ谡 ���� �ƽ� �� ���� ũ�� ����
		if (GA_Weight < weight && Max_Value < GA_Value) Max_Value = GA_Value;

		//DP�� ���� ���� ���� �����ϸ� ��� �� ����
		if (Max_Value == 433)
		{
			cout <<"�ִ� ��ġ���� : "<< Max_Value << "  ���� �� : " << Gen << endl;
			break;
		}
	}

	if(Max_Value !=433) cout << "�ִ밡ġ ���� �������� GA�� ������ �ִ� ��ġ �� : " << Max_Value << endl;
	cout << endl;
}

int main()
{
	std::chrono::system_clock::time_point start, stop; //Ž���ϴµ� �ɸ��� �ð� �����ϱ� ���� ����

	cout << "12131649 �Ǽ��� GA_0-1 Knapsack" << endl << endl;

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


	cout << "ǰ�� �� ����/��ġ �Է�" << endl;

	for (int i = 0; i < N; i++)
	{
		cin >> W[i] >> P[i];
		weight += W[i];
	}

	weight = weight*0.7; //���Դ� ��ü ��ǰ �������� 70%�� ����
	cout << "���� ���� : " << weight << endl;

	//����ü ����
	init();

	start = std::chrono::system_clock::now(); //GA ���� �� �ð�����
	GA();
	stop = std::chrono::system_clock::now(); //GA  ���� �� �ð� ����

	chrono::microseconds micro; //����ũ�� ���� �� ������ ���� ���뼼����Ÿ�� ����
	micro = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "����ð� : " << micro.count() << "ms" << endl;

	return 0;
}