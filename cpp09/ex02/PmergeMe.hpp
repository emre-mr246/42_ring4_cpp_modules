/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:56:54 by emgul            #+#    #+#              */
/*   Updated: 2025/09/02 03:39:22 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

class PmergeMe
{
  public:
    static void sort(int argc, char **argv);

  private:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &src);

    static int parseSingleToken(const std::string &token);
    static void parseAndValidateInput(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq);
    static double getTime();
    static void printSortTime(double time, size_t size, const std::string &containerName);
    static bool compareSecond(const std::pair<int, int> &a, const std::pair<int, int> &b);
    static std::vector<int> generateJacobsthalNumbers(int limit);

    template <typename Container>
    static double measureSortTime(Container &sequence);

    template <typename Container>
    static void mergeInsertionSort(Container &sequence);

    template <typename Container>
    static void printSequence(Container &container, const std::string &label);

    template <typename Container>
    static int binarySearch(const Container &container, int value, int end);

    template <typename PairContainer>
    static void sortPairs(PairContainer &pairList);

    template <typename Container, typename PairContainer>
    static void createPairs(Container &sequence, PairContainer &pairList, int &strandedElement);

    template <typename PairContainer, typename Container>
    static void insertPairsIntoChain(PairContainer &pairList, Container &mainChain, int strandedElement);

    template <typename PairContainer, typename Container>
    static void createMainChain(PairContainer &pairList, Container &mainChain);

    static std::vector<int> createJacobsthalOrder(size_t size);

    template <typename PairContainer, typename Container>
    static void insertionSequence(PairContainer &pairList, Container &mainChain);
};
