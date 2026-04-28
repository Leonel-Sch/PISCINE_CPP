#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_sortVector(std::vector<int> arr) {

    if (arr.size() < 2) {
        return arr;
    }

    bool hasStraggler = false;
    int straggler = -1;
    if (arr.size() % 2 != 0) {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector< std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }

    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }

    std::vector<int> mainChain;
    std::vector<int> loosers;

    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        loosers.push_back(pairs[i].second); 
    }

    mainChain.insert(mainChain.begin(), loosers[0]);
    
    std::vector<int> insertionSeq = _generateInsertionSequence(loosers.size());

    for (size_t i = 0; i < insertionSeq.size(); i++) {
        int indexToInsert = insertionSeq[i];
        int valueToInsert = loosers[indexToInsert];

        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
        
        mainChain.insert(insertPos, valueToInsert);
    }

    if (hasStraggler) {
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(insertPos, straggler);
    }

    return mainChain;
}

std::deque<int> PmergeMe::_sortDeque(std::deque<int> arr) {

    if (arr.size() < 2) {
        return arr;
    }

    bool hasStraggler = false;
    int straggler = -1;
    if (arr.size() % 2 != 0) {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque< std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }

    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }

    std::deque<int> mainChain;
    std::deque<int> loosers;

    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first); 
        loosers.push_back(pairs[i].second); 
    }

    mainChain.insert(mainChain.begin(), loosers[0]);
    
    std::vector<int> insertionSeq = _generateInsertionSequence(loosers.size());

    for (size_t i = 0; i < insertionSeq.size(); i++) {
        int indexToInsert = insertionSeq[i];
        int valueToInsert = loosers[indexToInsert];

        std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), valueToInsert);
        
        mainChain.insert(insertPos, valueToInsert);
    }

    if (hasStraggler) {
        std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(insertPos, straggler);
    }

   return mainChain;
}

void PmergeMe::_parseInput(int argc, char **argv) {

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg.empty()) {
            throw InvalidInputException();
        }

        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                throw InvalidInputException();
            }
        }

        long value = std::atol(arg.c_str());
        
        if (value > 2147483647) {
            throw InvalidInputException();
        }

        _rawInput.push_back(static_cast<int>(value));
    }
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
    _parseInput(argc, argv);
}
PmergeMe::PmergeMe(const PmergeMe& other) {
    _rawInput = other._rawInput;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
        this->_rawInput = other._rawInput;
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::_generateInsertionSequence(int loosersSize) {
    std::vector<int> seq;
    if (loosersSize <= 1) 
        return seq;

    int lastJ = 1;
    int prevJ = 1;
    int nextJ = 3;

    while (lastJ < loosersSize) {
        int maxIndex = std::min(nextJ, loosersSize) - 1;
        
        for (int i = maxIndex; i >= lastJ; i--) {
            seq.push_back(i);
        }

        lastJ = nextJ;
        int temp = nextJ;
        nextJ = nextJ + 2 * prevJ;
        prevJ = temp;
    }
    
    return seq;
}

void PmergeMe::run() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _rawInput.size(); ++i) {
        std::cout << _rawInput[i] << " ";
        if (i == 4 && _rawInput.size() > 10) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;

    std::vector<int> vecArr(_rawInput.begin(), _rawInput.end());
    struct timeval start_vec, end_vec;
    gettimeofday(&start_vec, NULL);
    
   vecArr =  _sortVector(vecArr);
    
    gettimeofday(&end_vec, NULL);
    double time_vec = (end_vec.tv_sec - start_vec.tv_sec) * 1000000.0 + (end_vec.tv_usec - start_vec.tv_usec);


    std::deque<int> deqArr(_rawInput.begin(), _rawInput.end());
    struct timeval start_deq, end_deq;
    gettimeofday(&start_deq, NULL);

    deqArr = _sortDeque(deqArr);
    
    gettimeofday(&end_deq, NULL);
    double time_deq = (end_deq.tv_sec - start_deq.tv_sec) * 1000000.0 + (end_deq.tv_usec - start_deq.tv_usec);

    std::cout << "After:  ";
    for (size_t i = 0; i < vecArr.size(); ++i) {
        std::cout << vecArr[i] << " ";
        if (i == 4 && vecArr.size() > 10) {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _rawInput.size() 
              << " elements with std::vector : " << time_vec << " us" << std::endl;
              
    std::cout << "Time to process a range of " << _rawInput.size() 
              << " elements with std::deque  : " << time_deq << " us" << std::endl;
}