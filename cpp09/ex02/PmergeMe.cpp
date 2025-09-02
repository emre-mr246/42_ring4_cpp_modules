/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:56:54 by emgul            #+#    #+#              */
/*   Updated: 2025/09/02 03:39:22 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &src)
{
    (void)src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    (void)src;
    return (*this);
}

double PmergeMe::getTime()
{
    return (static_cast<double>(clock()) / CLOCKS_PER_SEC);
}

template <typename Container>
double PmergeMe::measureSortTime(Container &sequence)
{
    double startTime;
    double endTime;

    startTime = getTime();
    mergeInsertionSort(sequence);
    endTime = getTime();
    return ((endTime - startTime) * 1000000.0);
}

void PmergeMe::printSortTime(double time, size_t size, const std::string &containerName)
{
    std::cout << "Time to process a range of " << size << " elements with "
    << containerName << " : " << time << " us" << std::endl;
}

template <typename Container>
void PmergeMe::printSequence(Container &c, const std::string &prefix)
{
    size_t i;

    std::cout << prefix;
    i = 0;
    while (i < c.size())
    {
        std::cout << c[i] << (i == c.size() - 1 ? "" : " ");
        i++;
    }
    std::cout << std::endl;
}

void PmergeMe::sort(int argc, char **argv)
{
    std::vector<int> vectorData;
    std::deque<int> dequeData;
    double vectorTime;
    double dequeTime;

    parseAndValidateInput(argc, argv, vectorData, dequeData);
    printSequence(vectorData, "Before:  ");
    vectorTime = measureSortTime(vectorData);
    dequeTime = measureSortTime(dequeData);
    printSequence(vectorData, "After:   ");
    printSortTime(vectorTime, vectorData.size(), "std::vector");
    printSortTime(dequeTime, dequeData.size(), "std::deque");
}

int PmergeMe::parseSingleToken(const std::string &token)
{
    char *endptr;
    size_t number;

    endptr = NULL;
    number = std::strtol(token.c_str(), &endptr, 10);
    if (token.empty() || *endptr != '\0' || number <= 0 || number > INT_MAX)
        throw(std::runtime_error("Error: Invalid number"));
    return (static_cast<int>(number));
}

void PmergeMe::parseAndValidateInput(int argc, char **argv, std::vector<int> &vectorData, std::deque<int> &dequeData)
{
    int i;
    int value;

    if (argc < 2)
        throw(std::runtime_error("Error: Invalid input"));
    i = 1;
    while (i < argc)
    {
        value = parseSingleToken(argv[i]);
        vectorData.push_back(value);
        dequeData.push_back(value);
        i++;
    }
}

template <typename Container>
void PmergeMe::mergeInsertionSort(Container &sequence)
{
    std::vector<std::pair<int, int> > p;
    int strandedElement;

    if (sequence.size() <= 1)
        return;
    strandedElement = -1;
    createPairs(sequence, p, strandedElement);
    sortPairs(p);
    sequence.clear();
    insertPairsIntoChain(p, sequence, strandedElement);
}

template <typename Container, typename PairContainer>
void PmergeMe::createPairs(Container &sequence, PairContainer &p, int &strandedElement)
{
    int first;
    int second;
    size_t i;

    i = 0;
    while (i < sequence.size() / 2)
    {
        first = sequence[i * 2];
        second = sequence[i * 2 + 1];
        if (first < second)
            std::swap(first, second);
        p.push_back(std::make_pair(second, first));
        i++;
    }
    if (sequence.size() % 2 != 0)
        strandedElement = sequence.back();
}

bool PmergeMe::compareSecond(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return (a.second < b.second);
}

template <typename PairContainer> void PmergeMe::sortPairs(PairContainer &p)
{
    if (p.size() <= 1)
        return;
    std::sort(p.begin(), p.end(), compareSecond);
}

template <typename PairContainer, typename Container>
void PmergeMe::createMainChain(PairContainer &p, Container &mainChain)
{
    size_t i;

    i = 0;
    while (i < p.size())
    {
        mainChain.push_back(p[i].second);
        i++;
    }
    mainChain.insert(mainChain.begin(), p[0].first);
}


template <typename Container>
int PmergeMe::binarySearch(const Container &c, int value, int high)
{
    int low;
    int mid;

    low = 0;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (c[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return (low);
}

std::vector<int> PmergeMe::generateJacobsthalNumbers(int limit)
{
    std::vector<int> jacobsthalSequence;
    int j0;
    int j1;
    int j2;

    if (limit <= 0)
        return (jacobsthalSequence);
    j0 = 0;
    j1 = 1;
    jacobsthalSequence.push_back(j0);
    jacobsthalSequence.push_back(j1);
    while (jacobsthalSequence.back() < limit)
    {
        j2 = j1 + (2 * j0);
        jacobsthalSequence.push_back(j2);
        j0 = j1;
        j1 = j2;
    }
    return (jacobsthalSequence);
}

std::vector<int> PmergeMe::createJacobsthalOrder(size_t size)
{
    size_t currentJac;
    size_t currentIndex;
    size_t lastJac;
    size_t i;
    std::vector<int> jacNumbers;
    std::vector<int> sequence;

    jacNumbers = generateJacobsthalNumbers(size);
    lastJac = 0;
    i = 1;
    while (i < jacNumbers.size())
    {
        currentJac = jacNumbers[i];
        currentIndex = (currentJac < size) ? currentJac : size - 1;
        while (currentIndex > lastJac)
            sequence.push_back(currentIndex--);
        lastJac = currentJac;
        i++;
    }
    return (sequence);
}

template <typename PairContainer, typename Container>
void PmergeMe::insertionSequence(PairContainer &p, Container &mainChain)
{
    std::vector<int> insertionSequence;
    size_t i;
    int pairIndex;
    int valueToInsert;
    int insertPosition;

    insertionSequence = createJacobsthalOrder(p.size());
    i = 0; 
    while (i < insertionSequence.size())
    {
        pairIndex = insertionSequence[i];
        valueToInsert = p[pairIndex].first;
        insertPosition = binarySearch(mainChain, valueToInsert, mainChain.size());
        mainChain.insert(mainChain.begin() + insertPosition, valueToInsert);
        i++;
    }
}

template <typename PairContainer, typename Container>
void PmergeMe::insertPairsIntoChain(PairContainer &p, Container &mainChain, int strandedElement)
{
    int insertPos;

    if (p.empty())
    {
        if (strandedElement != -1)
            mainChain.insert(mainChain.begin(), strandedElement);
        return;
    }
    createMainChain(p, mainChain);
    insertionSequence(p, mainChain);
    if (strandedElement != -1)
    {
        insertPos = binarySearch(mainChain, strandedElement, mainChain.size());
        mainChain.insert(mainChain.begin() + insertPos, strandedElement);
    }
}
