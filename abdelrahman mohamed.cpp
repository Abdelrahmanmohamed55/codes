// abdelrahman mohamed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Function 1: Read scores into array
void readScores(int scores[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
}

// Function 2: Compute average
double computeAverage(const int scores[], const int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += scores[i];
    }

    return static_cast<double>(sum) / n;
}

// Function 3: Analyze results
void analyzeResults(const int scores[], const int n,
    int& maxScore, int& minScore,
    int& passed, int& failed)
{
    maxScore = scores[0];
    minScore = scores[0];
    passed = 0;
    failed = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] > maxScore)
            maxScore = scores[i];

        if (scores[i] < minScore)
            minScore = scores[i];

        if (scores[i] >= 50)
            passed++;
        else
            failed++;
    }
}

int main()
{
    int n;

    cin >> n;

    if (n < 1 || n > 100)
        return 0;

    int scores[100];

    readScores(scores, n);

    double average = computeAverage(scores, n);

    int maxScore, minScore, passed, failed;

    analyzeResults(scores, n, maxScore, minScore, passed, failed);

    cout << "Average score: " << average << endl;
    cout << "Maximum score: " << maxScore << endl;
    cout << "Minimum score: " << minScore << endl;
    cout << "Number of passed students: " << passed << endl;
    cout << "Number of failed students: " << failed << endl;

    cout << "Scores above average: ";

    for (int i = 0; i < n; i++)
    {
        if (scores[i] > average)
            cout << scores[i] << " ";
    }

    cout << endl;

    return 0;
}